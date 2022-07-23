
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#include "untime.h"

#define ONE_THOUSAND 1000
#define ONE_MILLION (1000*ONE_THOUSAND)
#define ONE_BILLION (1000*ONE_MILLION)

static inline bool
TIMENS_SEC_OK(time_t t) {
    return (TIMENS_SEC_MIN <= t) && (t <= TIMENS_SEC_MAX);
}

static inline bool
TIMENS_NSEC_OK(long t) {
    return (TIMENS_NSEC_MIN <= t) && (t <= TIMENS_SEC_MAX);
}

#define IN_SEC_RANGE(t) (t > TIM)
static const struct timens 
timens = {
    .t_nanosecond   = {.tv_nsec=1L},
    .t_microsecond  = {.tv_nsec=1L*ONE_THOUSAND},
    .t_millisecond  = {.tv_nsec=1L*ONE_MILLION},
    .t_second       = {.tv_sec =INT64_C(1)},
    .t_minute       = {.tv_sec =INT64_C(60)},
    .t_hour         = {.tv_sec =INT64_C(3600)},
    .t_day          = {.tv_sec =INT64_C(86400)},
    .t_week         = {.tv_sec =INT64_C(86400)*7},
    .t_nil          = {0},
    .t_min          = {.tv_sec=TIMENS_SEC_MIN},
    .t_max          = {
        .tv_sec=TIMENS_SEC_MAX,
        .tv_nsec=ONE_BILLION-1L,
    },
/*
    .ops = {
        [OP_CMP_LT] = timens_lt,
        [OP_CMP_LE] = timens_le,
        [OP_CMP_EQ] = timens_eq,
        [OP_CMP_NE] = timens_ne,
        [OP_CMP_GT] = timens_gt,
        [OP_CMP_GE] = timens_ge,
        [OP_BI_ADD] = timens_add,
        [OP_BI_SUB] = timens_sub,
        [OP_BI_MUL] = timens_mul,
        [OP_BI_MOD] = timens_mod,
        [OP_UN_NEG] = timens_neg,
        [OP_UN_POS] = timens_pos,
        [OP_UN_ABS] = timens_abs,
        [OP_UN_INC] = timens_inc,
        [OP_UN_DEC] = timens_dec,
    },
    */
};

timens_t *
timens_fromtm(timens_t *restrict v, const union timens_tm *restrict argv) { 
    timens_t t = {
        .tv_sec  = argv->t_seconds,
        .tv_nsec = argv->t_nanoseconds,
    };
    if ((t.tv_sec < INT64_C(0)) || (t.tv_nsec < 0L) ) {
        the_flowjob: {
            return unexc_ERANGE(0);
        }
    }
    intmax_t arg;
    int i;
    for (i=t_microseconds; i < t_minutes; ++i) {
        if (argv->t_list[i] < 0) {
            goto the_flowjob;
        }
        arg = timens.t_list[i].tv_nsec;
        arg *= argv->t_list[i];
        arg += t.tv_nsec;
        if (arg > TIMENS_NSEC_MAX) {
            imaxdiv_t x = imaxdiv(arg, ONE_BILLION);
            t.tv_sec += (time_t) x.quot;
            t.tv_nsec = (long) x.rem;
        }
        else {
            t.tv_nsec = (long) arg;
        }
    }
    for ( ; i <= t_weeks; ++i) {
        if (argv->t_list[i] < 0) {
            goto the_flowjob;
        }
        arg = timens.t_list[i].tv_sec;
        arg *= argv->t_list[i];
        arg += t.tv_sec;
        if (arg > TIMENS_SEC_MAX) {
            goto the_flowjob;
        }
        t.tv_sec = (time_t) arg;
    }
    if (argv->t_neg) {
        *v = (t.tv_nsec ? timens_POS_TO_NEG_1 : timens_POS_TO_NEG_0)(&t);
    }
    else {
        *v = t;
    }
    return v;
}

timens_t *
timens_fromkw(timens_t *v, ...) {
    intmax_t sec  = INTMAX_C(0);
    intmax_t nsec = INTMAX_C(0);
    intmax_t lim  = TIMENS_SEC_MAX;
    va_list  va;
    va_start(va, v);
    int s = 0;
    for (kw_t arg; ; ) {
        arg = va_arg(va, kw_t);
        intmax_t val = arg.u;
        if (arg.k < t_minutes) {
            if (arg.k == t_seconds) {
                if (val > lim) {
                    the_flowjob: {
                        va_end(va);
                        return unexc_ERANGE(0);
                    }
                }
                sec += val;
                break;
            }
            val *= (intmax_t) timens.t_list[arg.k].tv_nsec;
            val += nsec;
            if (val >= ONE_BILLION) {
                imaxdiv_t x = imaxdiv(val, ONE_BILLION);
                if (x.quot > lim) {
                    goto the_flowjob;
                }
                sec += x.quot;
                lim = TIMENS_SEC_MAX-sec;
                nsec = x.rem;
            }
            else {
                nsec = val;
            }
        }
        else {
            if (arg.k == t_neg) {
                s = 1;
                continue;
            }
            val *= (intmax_t) timens.t_list[arg.k].tv_sec;
            if (val > lim) {
                goto the_flowjob;
            }
            lim -= val;
            sec += val;
        }
    }
    if (s) {
        if (nsec) {
            *v = (timens_t) {
                .tv_sec  = (time_t) (INTMAX_C(0)-sec-INTMAX_C(1)),
                .tv_nsec = ONE_BILLION-(long) nsec,
            };
        }
        else {
            *v = (timens_t) {
                .tv_sec = (time_t) INTMAX_C(0)-sec,
                .tv_nsec = 0L,
            };
        }
    }
    else {
        *v = (timens_t) {
            .tv_sec =(time_t) sec,
            .tv_nsec=(long)  nsec,
        };
    }
    va_end(va);
    return v;
}

int
time_mul(time_t *v, time_t a, long b) {
    if (a && b) {
        if (a < INT64_C(0)) {
            if ((b < (INT64_MAX/a+1)) || (b > (INT64_MIN/a))) {
                return (errno=ERANGE);
            }
        }
        else {
            if ((b < (INT64_MIN/a+1)) || (b > (INT64_MAX/a))) {
                return (errno=ERANGE);
            }
        }
    }
    *v = a*b;
    return 0;
}

int 
timens_repr(const timens_t *t, FILE *f, const char *fmt) {
    char buf[128];
    if (f == NULL) {
        f = stdout;
    }
    if (fmt != NULL) {
        if (fprintf(f, "%s", fmt) < 0) {
            unthrow(0, "printf");
        }
    }
    return fprintf(
        f, 
        "{.tv_sec=%+jd, .tv_nsec=%jd}",
        (intmax_t) t->tv_sec,
        (intmax_t) t->tv_nsec);
}

int 
timens_cmp(const timens_t *a, const timens_t *b) {
    return       (a == b)           ? 0 :
        (a->tv_sec  >  b->tv_sec)   ? 1 : 
        (a->tv_sec  <  b->tv_sec)   ? 0-1:
        (a->tv_nsec == b->tv_nsec)  ? 0 :
        (a->tv_nsec <  b->tv_nsec)  ? 0-1: 1;
}

bool
timens_ok(const timens_t *t) {
    return timens_OK(t);
}

bool 
timens_is(const timens_t *t) {
    return timens_IS(t);
}

bool 
timens_not(const timens_t *t) {
    return !timens_IS(t);
}

bool 
timens_lt(const timens_t *a, const timens_t *b) {
    return (a   == b)           ? false : 
    (a->tv_sec  >  b->tv_sec)   ? false : 
    (a->tv_nsec <  b->tv_nsec);
}

bool 
timens_le(const timens_t *a, const timens_t *b) {
    return  (a == b)            ? true  : 
    (a->tv_sec  >  b->tv_sec)   ? false :
    (a->tv_sec  <  b->tv_sec)   ? true  :
    (a->tv_nsec <= b->tv_nsec);
}

bool 
timens_eq(const timens_t *a, const timens_t *b) {
    return (a   == b)           ? true  : 
    (a->tv_sec  != b->tv_sec)   ? false :
    (a->tv_nsec == b->tv_nsec);
}

bool 
timens_ne(const timens_t *a, const timens_t *b) {
    return (a   == b)           ? false : 
    (a->tv_sec  != b->tv_sec)   ? true : 
    (a->tv_nsec != b->tv_nsec);
}

bool 
timens_gt(const timens_t *a, const timens_t *b) {
    return (a   == b)           ? false : 
    (a->tv_sec  <  b->tv_sec)   ? false : 
    (a->tv_nsec >  b->tv_nsec);
}

bool 
timens_ge(const timens_t *a, const timens_t *b) {
    return (a      == b)        ? true  : 
    (a->tv_sec  <  b->tv_sec)   ? false :
    (a->tv_sec  >  b->tv_sec)   ? true  : 
    (a->tv_nsec >= b->tv_nsec);
}

time_t 
timens_time(const timens_t *t) {
    return t->tv_sec;
}

ftime_t 
timens_ftime(const timens_t *t) {
    return 1.0L*t->tv_sec+t->tv_nsec*1e-9L;
}

int 
timens_sgn(timens_t *v, const timens_t *t) {
    timens_t r = *t;
    if (r.tv_sec < INT64_C(0)) {
        if (r.tv_nsec) {
            r.tv_sec  = INT64_C(0)-(r.tv_sec+INT64_C(1));
            r.tv_nsec = ONE_BILLION-r.tv_nsec;
        }
        else {
            r.tv_sec = INT64_C(0)-r.tv_sec;
            r.tv_nsec = 0L;
        }
        return 0-1;
    }
    return (*v=r), 1;
}

timens_t *
timens_nil(timens_t *v) {
    return (*v=(timens_t){0}), v;
}

timens_t * 
timens_init(timens_t *t, time_t s, long ns) {
    if ((TIMENS_NSEC_MIN > ns) || (ns > TIMENS_NSEC_MAX)) {
        errno = EINVAL;
        return NULL;
    }
    *t = (timens_t){
        .tv_sec=s,
        .tv_nsec=ns,
    };
    return t;
}

timens_t *
timens_fromfsec(timens_t *v, ftime_t s) {
    if ((s < TIMENS_FSEC_MIN) || (TIMENS_FSEC_MAX < s)) {
        errno = ERANGE;
        return NULL;
    }
    return (*v=timens_FROMFSEC(s)), v;
}

timens_t *
timens_fromsec(timens_t *v, time_t s) {
    if ((s < TIMENS_SEC_MIN) || (TIMENS_SEC_MAX < s)) {
        errno = ERANGE;
        return NULL;
    }
    *v = (timens_t){
        .tv_sec=s,
        .tv_nsec=0L,
    };
    return v;
}

timens_t *
timens_frommsec(timens_t *v, time_t ms) {
    return timens_FRAC_INIT(v, ms, ONE_THOUSAND, ONE_MILLION);
}

timens_t *
timens_fromusec(timens_t *v, time_t us) {
    return timens_FRAC_INIT(v, us, ONE_MILLION, 1000L);
}

timens_t *
timens_fromnsec(timens_t *v, time_t ns) {
    return timens_FRAC_INIT(v, ns, ONE_BILLION, 1L);
}

timens_t *
timens_inc(timens_t *v) {
    if (v->tv_nsec < TIMENS_NSEC_MAX) {
        v->tv_nsec++;
    }
    else {
        if (v->tv_sec >= TIMENS_SEC_MAX) {
            errno = ERANGE;
            return v;
        }
        *v = ((timens_t) {
            .tv_sec=v->tv_sec+1,
            .tv_nsec=TIMENS_NSEC_MIN,
        });
    }
    return v;
}

timens_t *
timens_dec(timens_t *v) {
    if (v->tv_nsec > TIMENS_NSEC_MIN) {
        v->tv_nsec--;
    }
    else {
        if (v->tv_sec <= TIMENS_SEC_MIN) {
            errno = ERANGE;
            return NULL;
        }
        *v = ((timens_t) {
            .tv_sec=v->tv_sec-1,
            .tv_nsec=TIMENS_NSEC_MAX,
        });
    }
    return v;
}

timens_t *
timens_pos(timens_t *v, const timens_t *t) {
    return (v == t) ? v : ((*v=*t), v);
}

timens_t * 
timens_abs(timens_t *v, const timens_t *t) {
    if (t->tv_sec >= INT64_C(0)) {
        *v = *t;
    }
    else if (t->tv_nsec) {
        *v = ((timens_t) {
            .tv_sec = INT64_C(0)-(t->tv_sec+INT64_C(1)),
            .tv_nsec = ONE_BILLION-t->tv_nsec,
        });
    }
    else {
        *v=*t, v->tv_sec=INT64_C(0)-v->tv_sec;
    }
    return v;
}

timens_t *
timens_neg(timens_t *v, const timens_t *t) {
    *v = timens_NEG(t);
    return v;
}

timens_t *
timens_add(timens_t *v, const timens_t *a, const timens_t *b) {
    timens_t t = {
        .tv_sec  = a->tv_sec+b->tv_sec,
        .tv_nsec = a->tv_nsec+b->tv_nsec,
    };
    if (t.tv_nsec > TIMENS_NSEC_MAX) {
        t.tv_sec += (time_t) UN_LDIVMOD(&t.tv_nsec, t.tv_nsec, ONE_BILLION);
    }
    if (!timens_OK(&t)) {
        errno = ERANGE;
        return NULL;
    }
    *v = t;
    return v;
}

timens_t *
timens_sub(timens_t *v, const timens_t *a, const timens_t *b) {
    timens_t t = {
        .tv_sec  = a->tv_sec-b->tv_sec,
        .tv_nsec = a->tv_nsec-b->tv_nsec,
    };
    if (t.tv_nsec < 0L) {
        t.tv_sec += (time_t) UN_LDIVMOD(&t.tv_nsec, t.tv_nsec, ONE_BILLION);
    }
    if (!timens_OK(&t)) {
        errno = ERANGE;
        return NULL;
    }
    return (*v=t), v;
}

timens_t *
timens_mod(timens_t *v, const timens_t *a, const timens_t *b) {
    int128_t p = (int128_t) ONE_BILLION*a->tv_sec+a->tv_nsec;
    int128_t q = (int128_t) ONE_BILLION*b->tv_sec+b->tv_nsec;
    intmax_t x;
    *v = (timens_t){
        .tv_sec= (time_t) UN_JDIVMOD(&x, (intmax_t)(p%q), ONE_BILLION),
        .tv_nsec = (long) x,
    };
    return v;
}

timens_t *
timens_mul(timens_t *v, const timens_t *a, long b) {
    imaxdiv_t x;
    time_t s;
    long   p;
    if (b == 1L) {
        return *v=*a, v;
    }
    if (b < 1L) {
        if (b == 0L) {
            return *v=(timens_t){0}, v;
        }
        if (a->tv_sec < INT64_C(0)) {
            p = (0L-b)*(ONE_BILLION-a->tv_nsec);
            x.quot = UN_JDIVMOD(&x.rem, p, ONE_BILLION);
            s = (time_t) x.quot+b*(INT64_C(1)+a->tv_sec);
            if (s < TIMENS_SEC_MIN) {
                goto overflow;
            }
        }
        else {
            x.quot = UN_JDIVMOD(&x.rem, a->tv_nsec*b, ONE_BILLION);
            s = (time_t) x.quot+b*a->tv_sec;
            if (s > TIMENS_SEC_MAX) {
                goto overflow;
            }
        }
    }
    else {
        if (a->tv_sec < INT64_C(0)) {
            p = (0L-b)*(ONE_BILLION-a->tv_nsec);
            x.quot = UN_JDIVMOD(&x.rem, p, ONE_BILLION);
            s = (time_t) x.quot+b*(INT64_C(1)+a->tv_sec);
            if (s < TIMENS_SEC_MIN) {
                goto overflow;
            }
        }
        else {
            x.quot = UN_JDIVMOD(&x.rem, a->tv_nsec*b, ONE_BILLION);
            s = (time_t) x.quot+a->tv_sec*b;
            if (s > TIMENS_SEC_MAX) {
                goto overflow;
            }
        }
    }
    *v = (timens_t){
        .tv_sec=(time_t) s, 
        (long) x.rem,
    };
    return v;
    overflow: {
        errno = ERANGE;
        return NULL;
    }
}

long      
timens_div(timens_t *v, const timens_t *a, const timens_t *b) {
    int128_t n_ns = a->tv_nsec+(int128_t) ONE_BILLION*a->tv_sec;
    int128_t d_ns = b->tv_nsec+(int128_t) ONE_BILLION*b->tv_sec;
    intmax_t x_ns = (intmax_t) (n_ns%d_ns);
    intmax_t r_ns;
    long quotient = (long) (n_ns/d_ns);
    timens_t t = {
        .tv_sec = (time_t) UN_JDIVMOD(&r_ns, x_ns, ONE_BILLION),
    };
    t.tv_nsec = (long) r_ns;
    return (*v=t), quotient;
}

timens_t *
timens_ldiv(timens_t v[2], const timens_t *a, long b) {
    int128_t t = a->tv_nsec+(int128_t) ONE_BILLION*a->tv_sec;
    intmax_t q_s;
    intmax_t x_s;
    intmax_t q_ns = UN_JDIVMOD(&q_s, (intmax_t)(t/b), ONE_BILLION);
    intmax_t x_ns = UN_JDIVMOD(&q_s, (intmax_t)(t%b), ONE_BILLION);
    if (b < 0) {
        q_ns -= 1;
        x_ns += b;
    }
    v[0] = (timens_t){
        .tv_sec=(time_t) q_s,
        .tv_nsec=(long) q_ns,
    };
    v[1] = (timens_t){
        .tv_sec=(time_t) x_s,
        .tv_nsec=(time_t) x_ns,
    };
    return v;
}

ldouble_t 
timens_fdiv(const timens_t *a, const timens_t *b) {
    ldouble_t x = 1E+9L*a->tv_sec+a->tv_nsec;
    ldouble_t y = 1E+9L*b->tv_sec+b->tv_nsec;
    return x/y;
}

ptrdiff_t
timens_str(const timens_t *restrict t, char dst[restrict]) {
    char str[512];
    char tmp[16];
    timens_t tv;
    imaxdiv_t x;
    ptrdiff_t i = PTRDIFF_C(0);
    div_t p, q, r;
    int j;
    str[i++] = 'T';
    if (t->tv_sec > INT64_C(0)) {
        tv = *t;
        str[i++] = '+';
    }
    else {
        if (t->tv_sec) {
            str[i++] = '-';
            tv = t->tv_nsec 
                ? timens_NEG_TO_POS_1(t)
                : timens_NEG_TO_POS_0(t);
        }
        else {
            str[i++] = '+';
            str[i++] = '0';
            if (t->tv_nsec) {
                tv.tv_nsec = t->tv_nsec;
                goto the_dot;
            }
            str[i++] = 's';
            str[i] = 0;
            goto the_end;
        }
    }
    if (tv.tv_sec < timens.t_minute.tv_sec) {
        x.rem = tv.tv_sec;
        goto the_subminute;
    }
    if (tv.tv_sec >= timens.t_week.tv_sec) {
        x = imaxdiv(tv.tv_sec, timens.t_week.tv_sec);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdw", x.quot);
        if (j < 0) {
            return j;
        };
        i += j;
    }
    else {
        x.rem = tv.tv_sec;
    }
    if (x.rem >= timens.t_day.tv_sec) {
        x = imaxdiv(x.rem, timens.t_day.tv_sec);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdd", x.quot);
        if (j < 0) {
            return j;
        }
        i += j;
    }
    if (x.rem >= timens.t_hour.tv_sec) {
        x = imaxdiv(x.rem, timens.t_hour.tv_sec);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdh", x.quot);
        if (j < 0) {
            return j;
        }
        i += j;
    }
    if (x.rem >= timens.t_minute.tv_sec) {
        x = imaxdiv(x.rem, timens.t_minute.tv_sec);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdm", x.quot);
        if (j < 0) {
            return j;
        }
        i += j;
    }
    if (x.rem == INTMAX_C(0)) {
        if (tv.tv_nsec == 0L) {
            goto the_end; 
        }
        str[i++] = '0';
    }
    else {
        the_subminute: {
            (void) 0;
        }
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jd", x.rem);
        if (j < 0) {
            return j;
        }
        i += j;
        if (tv.tv_nsec == 0L) {
            str[i++] = 's';
            str[i] = 0;
            goto the_end;
        }
    }
    the_dot: {
        str[i++] = '.';
    }
    // mmm'uuu'nnn 
    // p.quot = mmm'uuu, p.rem = nnn
    // q.quot = mmm, q.rem = uuu
    p = div((int) tv.tv_nsec, 1000);
    q = div(p.quot, 1000);
    if (p.rem) {
        tmp[9] = 0;
        tmp[8] = (char) (48+(r=div(p.rem,  10)).rem);
        tmp[7] = (char) (48+(r=div(r.quot, 10)).rem);
        tmp[6] = (char) (48+r.quot);
        tmp[5] = (char) (48+(r=div(q.rem,  10)).rem);
        tmp[4] = (char) (48+(r=div(r.quot, 10)).rem);
        tmp[3] = (char) (48+r.quot);
        tmp[2] = (char) (48+(r=div(q.quot, 10)).rem);
        tmp[1] = (char) (48+(r=div(r.quot, 10)).rem);
        tmp[0] = (char) (48+r.quot);
    }
    else {
        if (!q.rem) {
            tmp[3] = 0;
        }
        else {
            tmp[6] = 0;
            tmp[5] = (char) (48+(r=div(q.rem,  10)).rem);
            tmp[4] = (char) (48+(r=div(r.quot, 10)).rem);
            tmp[3] = (char) (48+r.quot);
        }
        tmp[2] = (char) (48+(r=div(q.quot, 10)).rem);
        tmp[1] = (char) (48+(r=div(r.quot, 10)).rem);
        tmp[0] = (char) (48+r.quot);
    }
    j = snprintf(str+i, (sizeof str)-(size_t) i, "%ss", tmp);
    if (j < 0) {
        return j;
    }
    i += j;
    the_end: {
        if (!memcpy(dst, str, (size_t) (i+1))) {
            unthrow(EINVAL, "memcpy returned NULL???");
        }
        return i;
    }
}


timens_t *
timens_xmul(timens_t *v, timens_t *a, timens_t *b) {
#ifdef __SIZEOF_INT128__
    __int128_t s;
    timens_t p;
    timens_t q;
    timens_t t;
    bool neg;
    if (a->tv_sec < 0) {
        p=timens_NEG(a), a=&p;
        if (b->tv_sec < 0) {
            neg=false, q=timens_NEG(b), b=&q;
        }
        else {
            neg=true;
        }
    }
    else {
        if (b->tv_sec < 0) {
            neg=true, q=timens_NEG(b), b=&q;
        }
        else {
            neg=false;
        }
    }
    if (a->tv_sec > TIMENS_SEC_MAX) {
        bad_flojo: {
            errno = ERANGE;
            return NULL;
        }
    }
    if (b->tv_sec > TIMENS_SEC_MAX) {
            goto bad_flojo;
    }
    s = (__int128_t) a->tv_nsec*b->tv_nsec;
    t.tv_nsec = (long) (s%ONE_BILLION);
    s /= ONE_BILLION;
    s += (__int128_t) a->tv_sec*b->tv_sec;
    if (s > TIMENS_SEC_MAX) {
        goto bad_flojo;
    }
    t.tv_sec = (time_t) s;
#endif
    *v = neg ? timens_NEG(&t) : t;
    return v;
}

struct timens_op {
    timens_t *lhs;
    timens_t *rhs;
};

typedef struct {
    uint64_t hi;
    uint64_t lo;
}   unuint128_t;

uint64_t // mod
divnsec(uint64_t n[restrict], uint64_t d[restrict], uint64_t *restrict q) {
    unsigned char nbit;
    unsigned char dbit;
    unsigned char diff;
    uint64_t quot;
    if (d[0]) {
        if (d[0] > n[0]) {
            the_flow: {
                return errno=ERANGE, *q=UINT64_C(0);
            }
        }
        nbit = BITLEN64(n[0])+64;
        dbit = BITLEN64(d[0])+64;
    }
    else {
        dbit = BITLEN64(d[0]);
        if (n[0]) {
            nbit = BITLEN64(n[0])+64;
        }
        else {
            return *q=n[1]/d[1], n[1]%d[1];
        }
    }
    diff = dbit-nbit;
    if (diff > 64) {
        goto the_flow;
    }
    /*
    
    n[50] = 994003027198430, 526765080
    d[25] =        31556952, 900050000
    
    q = 31498701
    r = {3328672, 691715080}
    
    
             994003027198430526765080
    n[80] = {222786591337936920, 53885}
    d[55] = { 31556952900050000,     0}
    
    1<<55 =   36028797018963968 too big 
    1<<54 =   18014398509481984
    
    12345-((67<<7)+(67<<5)+(67<<4))
    
    
    n.tv_sec/d.tv_sec = 31498702 % 122126
    
    n[50] = 994003027198430, 526765080
    d[25] =        31556952, 900050000
    n.tv_sec/d.tv_sec = 31498702 % 122126
    31498702*d.tv_nsec = 28350406735100000
    28350406735100000/BIL = (28350406, 735100000)
    

         _____
    (344)30111 = 87, 183 
         
    
    (344)30111
         10    30÷10 
         
    
    
    30011.11/344.94 = 87%183 
    
    30000/300 = 100 
    
    
    r = 122126 
    31'498'702 
    
    
    num[50] = 994003027198430, 526765080
    den[25] =        31556952, 900000000
    
    
    */
    }
            
        }
    }
    if ()
    }
    if (n[0] == 0) {
        return *q=n[1]/d, n[1]%d;
    }
    /*
        TIMENS_SEC_MAX = 2**60-1 (1152921504606846975)
        1152921504606846975000000000 
        
        
    */
}
uint8_t
uint16_div8(uint8_t n[restrict 2], uint8_t d, uint8_t *q) {
    }
    uint8_t quot;
    uint8_t nbit = BITLENB(n[0])+8;
    uint8_t dbit = BITLENB(b);
    uint8_t dist = nbit-dbit;
    if (dist > 8) {
        return errno=ERANGE, *q=0, UINT8_MAX;
    }
    quot = 1<<dist;
    if (quot > )
    /*
    
    n = 
        (n=1026)÷(d=63) 
        qbit = 0
        dbit = 6        (L(d) == L(63))
        --------
        nbit = 11       (L(n) == L(1026))
        dist = 5        (nbit-dbit)
        quot = 2016     (d<<dist)
        2016 > 1026 
        ?   dist = 4    (dist--) == (5-1)
            quot = 1008 (d<<dist) == (0+(63<<4))
            xrem = 18   () == (1026-1008)
            18 < 63
            ?   
        
        12345÷67 = 184%17 
        12345 > 255 
        nb = 
        D(12345, 67) = 7 
        12345-(67*(128)) = 3769 
        D(3769, 67) = 5 
        12345-(67*(128+32)) = 1625 
        D(1625, 67) = 4 
        12345-(67*(128+32+16)) = 553 
        D(553, 67) = 3 
        12345-(67*(128+32+16+8)) = 17
        12345-((67<<7)+(67<<5)+(67<<4))
        
        
        ?
            nbit=14, dbit=7
            dist = 7 (14-7)
            quot = 128 (1<<7) 
            jump*=d = 8576 (128*67)
            d -= jump (3769)
            3769 > 255 
            ?
                nbit = 12 
                dist = 5 (12-7)
                jump = 32 (1<<5)
                32 > 255 
                ? 
                    ...
                :
                    32 > 67
                    ?   ...
                    
                    
            
        12345-8576=3769 
        3769 
    */
    
    
        }
            return q[0]=0, q[1]=1, 0; // 3/3
        }
        return q[0]=0, q[1]=1, d; // 1/3
    }
    if 
}
uint64_t
_udiv128(unuint128_t *n, uint64_t d, uint64_t *mod) {
    char nbit;
    char dbit;
    char dist;
    if (n->hi) {
        nbit = BITLEN64(n->hi)+64;
    }
    else {
        if (n->lo > d) {
            return *mod=n->lo%d, n->lo/d;
        }
        if (n->lo < d) {
            return *mod=d, UINT64_C(0);
        }
        return *mod=UINT64_C(0), UINT64_C(1);
    }
    dist = nbit-1-dbit;
    }
    else {
        //
    }
}

#ifdef _MSC_VER
#if defined(_M_X64)
#include <immintrin.h>
#if defined(_M_ARM)
#if defined(_M_AMD64)
_M_IX86
int64_t 
_div128(unuint128_t a, uint64_t b, uint64_t *rem) {
    
}
   __int64 divisor,
   __int64 *remainder
);
int main(void) {
    errno = 0;
    timens_t self;
     
    char res[512] = {0};
    char lhs[512] = {0};
    char rhs[512] = {0};
    // printf("micro = %d\n", (int) timens.t_list[t_microseconds].tv_nsec);
    if (0) {
        (void) printf("%d\n", snprintf(res, sizeof res, ""));
        return 0;
    }
    if (0) {
        memset(lhs, 0xff, 8);
        memset(lhs+8, 00, (sizeof lhs)-8);
        snprintf(lhs, 8, "%s", "abc");
        printf(
            "%d, %d, %d, %d, %d, %d, %d, %d\n",
            lhs[0],
            lhs[1],
            lhs[2],
            lhs[3],
            lhs[4],
            lhs[5],
            lhs[6],
            lhs[7]);
        if (1) {
            return 0;
        }
    }
    if (0) {
        timens_t pos_v = {.tv_sec=1};
        timens_t neg_v;
        timens_neg(&neg_v, &pos_v);
        timens_str(&pos_v, lhs);
        timens_str(&neg_v, rhs);
        return printf("%s && %s\n", lhs, rhs);
    }
    
    timens_t all[] = {
        [ 0]={.tv_sec=0, .tv_nsec=1},
        [ 1]={.tv_sec=0, .tv_nsec=12},
        [ 2]={.tv_sec=0, .tv_nsec=123},
        [ 3]={.tv_sec=0, .tv_nsec=1234},
        [ 4]={.tv_sec=0, .tv_nsec=12345},
        [ 5]={.tv_sec=0, .tv_nsec=123456},
        [ 6]={.tv_sec=0, .tv_nsec=1234567},
        [ 7]={.tv_sec=0, .tv_nsec=12345678},
        [ 8]={.tv_sec=0, .tv_nsec=100000000},
        [ 9]={.tv_sec=0, .tv_nsec=120000000},
        [10]={.tv_sec=0, .tv_nsec=123000000},
        [11]={.tv_sec=0, .tv_nsec=123400000},
        [12]={.tv_sec=0, .tv_nsec=123450000},
        [13]={.tv_sec=0, .tv_nsec=123456000},
        [14]={.tv_sec=0, .tv_nsec=123456700},
        [15]={.tv_sec=0, .tv_nsec=123456780},
        [16]={.tv_sec=0, .tv_nsec=123456789},
        [17]={.tv_sec=0, .tv_nsec=TIMENS_NSEC_MAX},
        [18]={.tv_sec=1, .tv_nsec=0},
        [19]={.tv_sec=1, .tv_nsec=1},
        [20]={.tv_sec=1, .tv_nsec=12},
        [21]={.tv_sec=1, .tv_nsec=123},
        [22]={.tv_sec=1, .tv_nsec=1234},
        [23]={.tv_sec=1, .tv_nsec=12345},
        [24]={.tv_sec=1, .tv_nsec=123456},
        [25]={.tv_sec=1, .tv_nsec=1234567},
        [26]={.tv_sec=1, .tv_nsec=12345678},
        [27]={.tv_sec=1, .tv_nsec=123456789},
        [28]={.tv_sec=1, .tv_nsec=TIMENS_NSEC_MAX},
        [29]={.tv_sec=59},
        [30]={.tv_sec=59, .tv_nsec=1},
        [31]={.tv_sec=59, .tv_nsec=TIMENS_NSEC_MAX},
        [32]={.tv_sec=60, .tv_nsec=1},
        [33]={.tv_sec=61},
        [34]={.tv_sec=61, .tv_nsec=1},
        [35]={.tv_sec=61, .tv_nsec=TIMENS_NSEC_MAX},
        [36]={.tv_sec=3600},
        [37]={.tv_sec=3600, .tv_nsec=1},
        [38]={.tv_sec=3600, .tv_nsec=TIMENS_NSEC_MAX},
        [39]={.tv_sec=3601},
        [40]={.tv_sec=3601, .tv_nsec=1},
        [41]={.tv_sec=3601, .tv_nsec=TIMENS_NSEC_MAX},
        [42]={.tv_sec=7200},
        [43]={.tv_sec=7200, .tv_nsec=1},
        [44]={.tv_sec=7200, .tv_nsec=TIMENS_NSEC_MAX},
        [45]={.tv_sec=86399},
        [46]={.tv_sec=86399, .tv_nsec=1},
        [47]={.tv_sec=86399, .tv_nsec=TIMENS_NSEC_MAX},
        [48]={.tv_sec=86400},
        [49]={.tv_sec=84000, .tv_nsec=1},
        [50]={.tv_sec=86400, .tv_nsec=TIMENS_NSEC_MAX},
        /*
        */
        {.tv_nsec=-1},
    };
    ptrdiff_t i = 0;
    ptrdiff_t j = 0;
    if (0) {
        for (; all[i].tv_nsec >= 0; ++i) {
            timens_neg(&self, all+i);
            (void) timens_str(all+i, lhs);
            (void) timens_str(&self, rhs);
            printf("%3td: %s\n%3td: %s\n",  i, lhs, i, rhs);
            
        //memset(res, 0, sizeof res);
        }
    }
    if (1) {
        timens_t pos_ns     = {.tv_sec=0,       .tv_nsec=1};
        timens_t pos_us     = {.tv_sec=0,       .tv_nsec=1000};
        timens_t pos_ms     = {.tv_sec=0,       .tv_nsec=1000000};
        timens_t pos_sec    = {.tv_sec=1,       .tv_nsec=0};
        timens_t pos_min    = {.tv_sec=60,      .tv_nsec=0};
        timens_t pos_hour   = {.tv_sec=3600,    .tv_nsec=0};
        timens_t pos_day    = {.tv_sec=86400,   .tv_nsec=0};
        timens_t pos_week   = {.tv_sec=86400*7, .tv_nsec=0};
        timens_t pos_zero   = {.tv_sec=0,       .tv_nsec=0};
        timens_t neg_ns     = {.tv_sec=0-1,     .tv_nsec=999999999};
        timens_t neg_us     = {.tv_sec=0-1,     .tv_nsec=999999000};
        timens_t neg_ms     = {.tv_sec=0-1,     .tv_nsec=999000000};
        timens_t neg_sec    = {.tv_sec=0-1,     .tv_nsec=0};
        timens_t neg_min    = {.tv_sec=0-60,    .tv_nsec=0};
        timens_t neg_hour   = {.tv_sec=0-60,    .tv_nsec=0};
        timens_t neg_day    = {.tv_sec=0-86400, .tv_nsec=0};
        timens_t neg_week   = {.tv_sec=0-604800,.tv_nsec=0};
        timens_t sum;
        struct timens_op oparg[] = {
            &pos_hour,  &pos_min,
            &neg_day,   &neg_hour,
            &pos_min,   &neg_min,
            &pos_hour,  &neg_hour,
            &neg_day,   &neg_day,
            &neg_week,  &neg_week,
            {0},
        };
        if (1) {
            i = 1;
            timens_t tval;
            timens_add(&tval, oparg[i].lhs, &timens.t_millisecond);
            for (long rhl=-4; rhl < 4; rhl++) {
                if (timens_str(&tval, lhs) < 0) {
                    unthrow(0, "lhs");
                }
                if (timens_mul(&sum, &tval, rhl)) {
                    if (timens_str(&sum, res) < 0) {
                        unthrow(0, "res");
                    }   
                    printf("<%s> * %ld = <%s>\n", lhs, rhl, res);
                }
                else {
                    unthrow(0, "timens_mul(&sum, tval, %ld)", rhl);
                }
            }
        }
        if (0) {
            for (i=0; oparg[i].lhs; i++) {
                if (timens_str(oparg[i].lhs, lhs) < 0) {
                    unthrow(0, "lhs");
                }
                if (timens_str(oparg[i].rhs, rhs) < 0) {
                    unthrow(0, "rhs");
                }
                if (timens_add(&sum, oparg[i].lhs, oparg[i].rhs)) {
                    if (timens_str(&sum, res) < 0) {
                        unthrow(0, "res");
                    }   
                    printf(
                        "<%s> + <%s> = <%s>\n",   
                        lhs, rhs, res);
                }
                else {
                    unthrow(0, "timens_add(&sum, lhs, rhs)");
                }
            }
        }
        
    }
    /*
    for (timens_t *t; t->tv_nsec < 0; t++) {
        if (timens_str(t, res) < 0) {
            unthrow(0,"timens_str({%ld, %ld})",(long) t->tv_sec, t->tv_nsec);
        }
        (void) printf("%03d: %s\n", i++, res);
    }
    */
    return 0;
/*
    if (!timens_fromkw(
        &a,
        (kw_t){t_neg,           false},
        (kw_t){t_milliseconds,  501},
        (kw_t){t_seconds,       51})) 
    {
        unthrow(0, "timens_fromkw(&a, T+51.501s)\n");
    }
    union timens_tm argv = {
        {
            [t_microseconds]    = 123,
            [t_weeks]           = 4,
            [t_neg]             = false,
        }
    };
    if (!timens_fromtm(&b, &argv)) {
        unthrow(0, "timens_fromtm(&b, us=123, weeks=4, neg=1)\n");
    }
    timens_t x = {
        .tv_sec=51+51+1, 
        .tv_nsec=ONE_MILLION,
    };
    if (!timens_add(&c, &a, &b)) {
        unthrow(0, "timens_add(&c, &a, &b\n)");
    }
    (void) timens_str(&a, buf);
    printf("T+51.501s+T+51.501s = %s", buf);
    
    
    return printf("\n");
    */
}
