//——————————————————————————————————————————————————————————————————————————————

#define _GNU_SOURCE

#include <unistd.h>

#define _POSIX_DYNAMIC_LINKING _POSIX_VERSION
#define _POSIX_NETWORKING _POSIX_VERSION
#define _POSIX_PATHLIB _POSIX_VERSION
#define _POSIX_LOCAL_SOCKETS 1

#define strideof(T, n) (n+sizeof(T)-1&~(sizeof(T)-1))
#define stridefill(T, n) (strideof(T, n)-n)

#define c__estr(v) #v
#define c__eval(v) v
#define C__EDEF(e, m) \
{   #m,\
    c__eval( e##_##m )\
}

#define C__EREF(k) { #k, k, ""}

#include "all.h"
#include "caveats.h"
#include "optimism.h"

int 
shexlenj(intmax_t j) {
    int s;
    if (j < 0) 
        j = ~j+1, s = 1;
    else 
        s = 0;
    return (j>0xffffffff?s+16:j>0xffff?s+8:j>0xff?s+4:s+2);
}

size_t Enum_length(Enum *self) {
    if (!self->size)
        for (Const *i=self->defs; i->key != NULL; i++)
            (self->size)++;
    return self->size;
}

int Enum_longestkey(Enum *d) {
    Const *i;
    size_t c = (size_t) d->ncol;
    if (c) {
        if (INT_MAX < c)
            return perror("INT_MAX < d->ncol"), errno=ERANGE, 0;
        return d->ncol;
    }
    if ((i=d->defs))
        for (size_t n; i->key;  i++) {
            n = strlen(i->key);
            if (c < n) 
                c = n;
            ++d->size;
        }
    return (d->ncol=(int) c);
}

int Enum_print(Enum *d, FILE *f) {
    char 
        vfmt,
        db[32] = {0},
        vs[256]= {0},
        *dp;
    int
        c = Enum_longestkey(d),
        m,
        v,
        hex;
    size_t n;
    Const 
        mid[1]  = {0},
        *min    = mid,
        *max    = mid,
        *i;
    if (!d->size)
        return 0;

    if (d->fmt) {
        vfmt = d->fmt[0];
        hex = (vfmt == 'x') || (vfmt == 'X');
    }
    else
        hex = 0, vfmt = 0;

    for (i=d->defs; i->key; i++) {
        if (i->val > max->val)
            max = i; 
        else if (i->val < min->val)
            min = i;
    }
    if (hex) {
        m = (min->val < 0) ? shexlenj(min->val) : 2;
        v = (max->val > 0) ? shexlenj(max->val) : 2;
        if (m < v)
            m = v;
        dp = stpcpy(vs, "    %-*s0x%0");
        if (snprintf(dp, 5, "%i%s", m, "x,\n") < 0)
            return perror("x"), -1;
    }
    else {
        char sf[2] = {vfmt, 0};
        if (min->val < 0) {
            m = snprintf(db, sizeof(db), "%jd", min->val);
            if (m < 0)
                return perror("jd"), -1;
            if (!vfmt)
                sf[0] = '+';
        }
        else
            m = 0;
        if (max->val > 0) {
            (void)memset(db,  0, sizeof(db));
            v = snprintf(db, sizeof(db), "%jd", max->val);
            if (v < 0)
                return perror("jd"), -1; 
        }
        else 
            v = 0;
        if (v > m)
            m = v;
        dp = stpcpy(vs, "    %-*s%");
        v = snprintf(dp, 128, "%s%iji,\n", sf, m);
        if (v < 0)
            return -1;
        v = 0;
    }

    v = 0;
    char b[256] = {34};
    char *q;
    char *p = stpcpy(b+1, d->name);
    if ((n=strlen(d->name))) {
        p = stpcpy(p, "_");
        n += 5;
    }
    else 
        n += 4;
    c += (int) n;

    if (c%4)
        c += 4-c%4;

    if (d->sort) {
        int(*key)(const void *, const void *) = Const_cmp[d->sort];
        if (!key) {
            errno = EINVAL;
            perror("unknown sort key specified");
            return -1;
        }
        qsort(d->defs, Enum_length(d), sizeof(Const), key); 
    }

    for (i=d->defs; i->key != NULL; i++) {
        q = stpcpy(p, i->key);
        q = stpcpy(q, "\":");
        m = fprintf(f, vs, c, b, i->val);
        if (m < 0) 
            return (perror("???"), -1);
        v += m;
    }
    return v;
}

int Header_print(Header *h, FILE *f) {
    int i = 0, j = 0;
    Enum *d = h->enums;
    Struct *t = h->structs;
    if (f == NULL)
        f = stdout;
    if (d != NULL) 
        for (; d->name; ++d) {
            if (0 > (j = Enum_print(d, f)))
                return j;
            i += j;
        }
    if (t != NULL)
        for (; t->name; ++t) {
            if (0 > (j = Struct_print(t, f)))
                return j;
            i += j;
        }
    return i;
}

int Const_print(Const *self, FILE *f) {
    int r = fprintf(
        f == NULL ? stdout : f, 
        "%s=%ji", 
        self->key == NULL ? "NULL" : self->key,
        self->val
    );
    if (!r) 
        return perror("Const_print"),-1; 
    return r;
}

int Const_vcmp(const void *a, const void *b) {
    const Const *z[2] = {a, b};
    return z[0]->val > z[1]->val ? 1 : -(z[0]->val < z[1]->val);
}

int Const_kcmp(const void *a, const void *b) {
    const Const *z[2] = {a, b};
    return strcmp(z[0]->key, z[1]->key);
}

int Struct_print(Struct *self, FILE *f) {
    int r, t;
    Member *l;
    unsigned n = self->ml_count;
    if (f == NULL) 
        f = stdout;
    if (!n)
        for (l=self->ml; l->name != NULL; ++l)
            ++n;
    if (!self->ml_sorted) {
        qsort(self->ml, n, sizeof(Member), &Member_cmp);
        self->ml_sorted = 1;
    }
    t = fprintf(f, "    \x22%s\x22: {\n", self->name);
    if (t < 0)
        goto error;
    r = t;
    for (l=self->ml; l->name != NULL; ++l) {
        t = fprintf(
            f, 
            "        \x22%s\x22: [\x22%s\x22, %zi],\n",
            l->name,
            l->spec,
            l->offset);
        if (t < 0)
            goto error;
        r += t;
    }
    l--;
    size_t e = l->offset+l->size;
    if (e < self->size) {
        t = fprintf(
            f, 
            "        \x22__pad_%s\x22: [\x22x#%zi\x22, %zi]\n",
            self->name,
            self->size-e,
            l->offset
        );
        if (t < 0)
            goto error;
        r += t;
    }
    t = fprintf(
        f, 
        "        \x22\x22: [\x22x#0\x22, %zi],\n",
        self->size
    );
    if (t < 0)
        goto error; 
    r += t;

    t = fprintf(f, "    },\n");
    if (t > 0)
        return (r+t);
    error:
    perror("Struct_print");
    return -1;
}


typedef struct {
    union {
        void    *memory;
        char    *bytestr;
        wchar_t *widestr;
    };
    size_t len;
} String;

int main(int argc, char *argv[]) {

    Lib libc  = {0};
    
    if (0) include_aio_h(&libc, stdout);
    if (0) include_arpa_inet_h(&libc, stdout);
    if (0) include_ctype_h(&libc, stdout);
  //if (0) include_assert_h(&libc, stdout);
  //if (0) include_complex_h(&libc, stdout);
    if (1) include_cpio_h(&libc, stdout);
    if (0) include_ctype_h(&libc, stdout);
    if (0) include_dirent_h(&libc, stdout);
    if (1) include_dlfcn_h(&libc, stdout);
    if (0) include_errno_h(&libc, stdout);
    if (0) include_fcntl_h(&libc, stdout);
  //if (0) include_fenv_h(&libc, stdout);
  //if (0) include_float_h(&libc, stdout);
    if (0) include_fmtmsg_h(&libc, stdout);
    if (0) include_fnmatch_h(&libc, stdout);
    if (0) include_ftw_h(&libc, stdout);
    if (0) include_glob_h(&libc, stdout);
    if (0) include_grp_h(&libc, stdout);
    if (0) include_iconv_h(&libc, stdout);
    if (0) include_inttypes_h(&libc, stdout);
  //if (0) include_iso646_h(&libc, stdout);
    if (0) include_langinfo_h(&libc, stdout);
    if (0) include_libgen_h(&libc, stdout);
    if (0) include_limits_h(&libc, stdout);
    if (0) include_locale_h(&libc, stdout);
    if (0) include_math_h(&libc, stdout);
    if (0) include_mqueue_h(&libc, stdout);
    if (0) include_monetary_h(&libc, stdout);
    if (0) include_ndbm_h(&libc, stdout);
    if (0) include_netdb_h(&libc, stdout);
    if (0) include_net_if_h(&libc, stdout);
    if (0) include_netinet_in_h(&libc, stdout);
    if (1) include_netinet_tcp_h(&libc, stdout);
    if (0) include_nl_types_h(&libc, stdout);
    if (0) include_poll_h(&libc, stdout);
    if (0) include_pthread_h(&libc, stdout);
    if (0) include_pwd_h(&libc, stdout);
    if (0) include_regex_h(&libc, stdout);
    if (0) include_sched_h(&libc, stdout);
    if (0) include_search_h(&libc, stdout);
    if (0) include_semaphore_h(&libc, stdout);
    if (0) include_setjmp_h(&libc, stdout);
    if (0) include_signal_h(&libc, stdout);
    if (0) include_spawn_h(&libc, stdout);
  //if (0) include_stdatomic_h(&libc, stdout);
  //if (0) include_stdarg_h(&libc, stdout);
  //if (0) include_stdbool_h(&libc, stdout);
  //if (0) include_stddef_h(&libc, stdout);
    if (0) include_stdint_h(&libc, stdout);
    if (0) include_stdio_h(&libc, stdout);
    if (0) include_stdlib_h(&libc, stdout);
    if (0) include_string_h(&libc, stdout);
    if (0) include_strings_h(&libc, stdout);
  //if (0) include_stropts_h(&libc, stdout);
    if (0) include_sys_ipc_h(&libc, stdout);
    if (0) include_sys_mman_h(&libc, stdout);
    if (0) include_sys_msg_h(&libc, stdout);
    if (0) include_sys_resource_h(&libc, stdout);
    if (0) include_sys_select_h(&libc, stdout);
    if (0) include_sys_sem_h(&libc, stdout);
    if (0) include_sys_shm_h(&libc, stdout);
    if (0) include_sys_socket_h(&libc, stdout);
    if (0) include_sys_stat_h(&libc, stdout);
    if (0) include_sys_statvfs_h(&libc, stdout);
    if (0) include_sys_time_h(&libc, stdout);
    if (0) include_sys_times_h(&libc, stdout);
    if (0) include_sys_uio_h(&libc, stdout);
    if (0) include_sys_utsname_h(&libc, stdout);
    if (0) include_sys_un_h(&libc, stdout);
    if (0) include_sys_wait_h(&libc, stdout);
    if (0) include_syslog_h(&libc, stdout);
    if (0) include_tar_h(&libc, stdout);
 // if (0) include_tgmath_h(&libc, stdout);
 // if (0) include_trace_h(&libc, stdout);
    if (0) include_termios_h(&libc, stdout);
    if (0) include_time_h(&libc, stdout);
    if (0) include_ulimit_h(&libc, stdout);
    if (0) include_unistd_h(&libc, stdout);
    if (0) include_utime_h(&libc, stdout);
    if (0) include_utmpx_h(&libc, stdout);
    if (0) include_wchar_h(&libc, stdout);
    if (0) include_wordexp_h(&libc, stdout);

    return errno ? EXIT_FAILURE : EXIT_SUCCESS;
}