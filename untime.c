
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 



*/

#include <semaphore.h>
#include <pthread.h>

#include "unstddef.h"
#include "untimely.h"
#include "ununicode.h"

#define unthrow(err, ret) return errno=err, ret

static pthread_spinlock_t Dict_api_lock;

_Thread_local
struct timens_locals {
    struct {
        char s[128];
    } dtostr;
    struct tm localtime;
    
} locals;


timens_t *
timens_init(timens_t *v, time_t tv_sec, long tv_nsec) {
    if (!timens_SEC_OK(tv_sec) || !timens_NSEC_OK(tv_nsec)) {
        unthrow(ERANGE, NULL);
    }
    return timens_INIT(v, tv_sec, tv_nsec);
}

timens_t *
timens_fromtime(timens_t *restrict v, time_t n, enum TIME_UNIT id) {
    timens_t    t;
    const struct time_unit *unit;
    if (!n) {
        return timens_CLR(v);
    }
    if (id == SECONDS) {
        return timens_init(v, n, 0);
    }
    bool sign = n < 0;
    if (sign) {
        if (n == INT64_MIN) {
            unthrow(ERANGE, NULL);
        }
        n = INT64_NEG(n);
    }
    if (id == NANOSECONDS) {
        t.tv_nsec = (long) (n%BILLION);
        if (t.tv_nsec) {
            if (sign) {
                t.tv_sec = ((time_t) 0-1)-(n/BILLION);
                t.tv_nsec = BILLION-t.tv_nsec;
            }
            else {
                t.tv_sec = n/BILLION;
            }
        }
        else {
            t.tv_sec = n/BILLION;
            if (sign) {
                t.tv_sec = 0-n/BILLION;
            }
        }
    }
    if (timens_units_INIT(&unit, id) == NULL) {
        unthrow(EINVAL, NULL);
    }

#   if defined(__SIZEOF_INT128__)

    __int128 s;
    __int128 x;
    if (unit->n == ONE) {
        x = (s=(__int128) n);
        s /=   (__int128) unit->d;
        x %=   (__int128) unit->d;
        if (x) {
            if (unit->r.n != ONE) {
                x *= (__int128) unit->r.n;
            }
            if (unit->r.d != ONE) {
                x /= (__int128) unit->r.d;
            }
            if (sign) {
                t.tv_sec = (0-((time_t) s))-1;
                t.tv_nsec = (long) BILLION-(long) x;
            }
            else {
                t.tv_sec = (time_t) s;
                t.tv_nsec = (long) x;
            }
        }
        else {
            t.tv_sec = (0-sign)-((time_t) s);
            t.tv_nsec = 0L;
        }
    }
    else {
        s = (n*unit->n)/unit->d;
        if (s > TIMENS_SEC_MAX) {
            unthrow(ERANGE, NULL);
        } 
        t.tv_sec = sign ? 0-(time_t) s : (time_t) s;
        t.tv_nsec = 0L;
    }
    return memcpy(v, &t, sizeof t);
#else
#error "smfd"
#endif
}

struct timens_to_time {
    time_t s_mul;
    time_t s_div;
    time_t ns_mul;
    time_t ns_div;
};

static const struct timens_to_time timens_time_table[] = {
    [SECONDS]      = {ONE,         0, 0,        0},
    [ATTOSECONDS]  = {QUINTILLION, 0, BILLION,  0},
    [FEMTOSECONDS] = {QUADRILLION, 0, MILLION,  0},
    [PICOSECONDS]  = {TRILLION,    0, THOUSAND, 0},
    [NANOSECONDS]  = {BILLION,     0, ONE,      0},
    [MICROSECONDS] = {MILLION,     0, 0,        THOUSAND},
    [MILLISECONDS] = {THOUSAND,    0, 0,        MILLION},
    [CENTISECONDS] = {HUNDRED,     0, 0,        MILLION*10},
    [DECISECONDS]  = {TEN,         0, 0,        MILLION*100},
    [DECASECONDS]  = {0,         TEN, 0,        0},
    [KILOSECONDS]  = {0,    THOUSAND, 0,          0},
    [MEGASECONDS]  = {0,     MILLION, 0,          0},
    [GIGASECONDS]  = {0,     BILLION, 0,          0},
    [TERASECONDS]  = {0,    TRILLION, 0,          0},
    [PETASECONDS]  = {0, QUADRILLION, 0,          0},
    [EXASECONDS]   = {0, QUINTILLION, 0,          0},
    [MINUTES]      = {0,  SECONDS_QM, 0,          0},
    [HOURS]        = {0,  SECONDS_QH, 0,          0},
    [DAYS]         = {0,  SECONDS_QD, 0,          0},
    [WEEKS]        = {0,  SECONDS_QW, 0,          0},
    [YEARS]        = {0,  SECONDS_QA, 0,          0},
};


#ifdef __SIZEOF_INT128__
static const __int128 QUINTILLION128 = (__int128) QUINTILLION;
static const __int128 QUADRILLION128 = (__int128) QUADRILLION;
static const __int128    TRILLION128 = (__int128) TRILLION;
static const __int128     BILLION128 = (__int128) BILLION;
static const __int128     TENMILLION128 = (__int128) (MILLION*10);
static const __int128 HUNDREDMILLION128 = (__int128) (MILLION*100);
static const __int128     MILLION128 = (__int128) MILLION;
static const __int128    THOUSAND128 = (__int128) THOUSAND;
static const __int128     HUNDRED128 = (__int128) HUNDRED;
//static const __int128         TEN128 = (__int128) TEN;
static const __int128   INT64_MAX128  = (__int128) INT64_MAX;
//static const __int128   INT64_MIN128  = (__int128) INT64_MIN;
//static const __int128  NIL128 = 0;
//static const __int128  NEG128 = NIL128-1;
#endif

static time_t timens_to_attoseconds(const timens_t *restrict v) {
#   ifdef __SIZEOF_INT128__
    __int128 t = (
        (__int128) v->tv_sec*QUINTILLION128
    +   (__int128) v->tv_nsec*MILLION128);
    if (t > INT64_MAX128) {
        unthrow(ERANGE, 0);
    }
    return (time_t) t;
#   endif
}

static time_t timens_to_femtoseconds(const timens_t *restrict v) {
#   ifdef __SIZEOF_INT128__
    __int128 t = (
        (__int128) v->tv_sec*QUADRILLION128
    +   (__int128) v->tv_nsec*MILLION128);
    if (t > INT64_MAX128) {
        unthrow(ERANGE, 0);
    }
    return (time_t) t;
#   endif
}

static time_t timens_to_picoseconds(const timens_t *restrict v) {
#   ifdef __SIZEOF_INT128__
    __int128 t = (
        (__int128) v->tv_sec*TRILLION128
    +   (__int128) v->tv_nsec*THOUSAND128);
    if (t > INT64_MAX128) {
        unthrow(ERANGE, 0);
    }
    return (time_t) t;
#   endif
}

static time_t timens_to_nanoseconds(const timens_t *restrict v) {
#   ifdef __SIZEOF_INT128__
    __int128 t = (
        (__int128) v->tv_sec*BILLION128
    +   (__int128) v->tv_nsec);
    if (t > INT64_MAX128) {
        unthrow(ERANGE, 0);
    }
    return (time_t) t;
#   endif
}

static time_t timens_to_microseconds(const timens_t *restrict v) {
#   ifdef __SIZEOF_INT128__
    __int128 t = (
        (__int128) v->tv_sec*MILLION128
    +   (__int128) v->tv_nsec/THOUSAND128);
    if (t > INT64_MAX128) {
        unthrow(ERANGE, 0);
    }
    return (time_t) t;
#   endif
}

static time_t timens_to_milliseconds(const timens_t *restrict v) {
#   ifdef __SIZEOF_INT128__
    __int128 t = (
        (__int128) v->tv_sec*THOUSAND128
    +   (__int128) v->tv_nsec/MILLION128);
    if (t > INT64_MAX128) {
        unthrow(ERANGE, 0);
    }
    return (time_t) t;
#   endif
}

static time_t timens_to_centiseconds(const timens_t *restrict v) {
#   ifdef __SIZEOF_INT128__
    __int128 t = (
        (__int128) v->tv_sec*HUNDRED128
    +   (__int128) v->tv_nsec/TENMILLION128);
    if (t > INT64_MAX128) {
        unthrow(ERANGE, 0);
    }
    return (time_t) t;
#   endif
}

static time_t timens_to_deciseconds(const timens_t *restrict v) {
#   ifdef __SIZEOF_INT128__
    __int128 t = (
        (__int128) v->tv_sec*HUNDRED128
    +   (__int128) v->tv_nsec/HUNDREDMILLION128);
    if (t > INT64_MAX128) {
        unthrow(ERANGE, 0);
    }
    return (time_t) t;
#   endif
}

static time_t timens_to_decaseconds(const timens_t *restrict v) {
    return v->tv_sec/10;
}

static time_t timens_to_hectoseconds(const timens_t *restrict v) {
    return v->tv_sec/100;
}

static time_t timens_to_kiloseconds(const timens_t *restrict v) {
    return v->tv_sec/THOUSAND;
}

static time_t timens_to_megaseconds(const timens_t *restrict v) {
    return v->tv_sec/MILLION;
}

static time_t timens_to_gigaseconds(const timens_t *restrict v) {
    return v->tv_sec/BILLION;
}

static time_t timens_to_teraseconds(const timens_t *restrict v) {
    return v->tv_sec/TRILLION;
}

static time_t timens_to_petaseconds(const timens_t *restrict v) {
    return v->tv_sec/QUADRILLION;
}

static time_t timens_to_exaseconds(const timens_t *restrict v) {
    return v->tv_sec/QUINTILLION;
}

static time_t timens_to_seconds(const timens_t *restrict v) {
    return v->tv_sec;
}

static time_t timens_to_minutes(const timens_t *restrict v) {
    return v->tv_sec/SECONDS_QM;
}

static time_t timens_to_hours(const timens_t *restrict v) {
    return v->tv_sec/SECONDS_QH;
}

static time_t timens_to_days(const timens_t *restrict v) {
    return v->tv_sec/SECONDS_QD;
    
}

static time_t timens_to_weeks(const timens_t *restrict v) {
    return v->tv_sec/SECONDS_QW;
}

static time_t timens_to_years(const timens_t *restrict v) {
    return v->tv_sec/SECONDS_QA;
}

static time_t
(*timens_to_times[])(const timens_t *) = {
    [FEMTOSECONDS] = timens_to_femtoseconds,
    [ATTOSECONDS]  = timens_to_attoseconds,
    [PICOSECONDS]  = timens_to_picoseconds,
    [NANOSECONDS]  = timens_to_nanoseconds,
    [MICROSECONDS] = timens_to_microseconds,
    [MILLISECONDS] = timens_to_milliseconds,
    [CENTISECONDS] = timens_to_centiseconds,
    [DECISECONDS]  = timens_to_deciseconds,
    [DECASECONDS]  = timens_to_decaseconds,
    [HECTOSECONDS] = timens_to_hectoseconds,
    [KILOSECONDS]  = timens_to_kiloseconds,
    [MEGASECONDS]  = timens_to_megaseconds,
    [GIGASECONDS]  = timens_to_gigaseconds,
    [TERASECONDS]  = timens_to_teraseconds,
    [PETASECONDS]  = timens_to_petaseconds,
    [EXASECONDS]   = timens_to_exaseconds,
    [SECONDS]      = timens_to_seconds,
    [MINUTES]      = timens_to_minutes,
    [HOURS]        = timens_to_hours,
    [DAYS]         = timens_to_days,
    [WEEKS]        = timens_to_weeks,
    [YEARS]        = timens_to_years,
};

time_t
timens_time(const timens_t *t, enum TIME_UNIT id) {
    timens_t v;
    if (!time_unit_CHECK(id)) {
        unthrow(EINVAL, 0);
    }
    if (id == SECONDS) {
        return t->tv_sec;
    }
    int sign = timens_SGN(&v, t);
    if (sign == 0) {
        unthrow(ERANGE, 0);
    }
    if (!v.tv_sec) {
        if (!v.tv_nsec) {
            return v.tv_sec;
        }
        if (id > DECISECONDS) {
            return v.tv_sec;
        }
        const struct timens_to_time *u = timens_time_table+id;
        if (u->ns_mul) {
            return sign*(v.tv_nsec*u->ns_mul);
        }
        else {
            return sign*(v.tv_nsec/u->ns_div);
        }
    }
    return sign*timens_to_times[id](&v);
}

timens_t *
timens_clr(timens_t *v) {
    return timens_CLR(v);
}

timens_t
timens_pos(const timens_t *v) {
    return *v;
}

timens_t *
timens_ipos(timens_t *v, const timens_t *t) {
    if (t == NULL) {
        if (v == NULL) {
            unthrow(EFAULT, NULL);
        }
        t = v;
    }
    if (!(timens_SEC_OK(t->tv_sec) && timens_NSEC_OK(t->tv_nsec))) {
        unthrow(ERANGE, NULL);
    }
    return memmove(v, t, sizeof *v);
}

timens_t *
timens_ineg(timens_t *v, const timens_t *t) {
    // *v = timens_NEG(t);
    // return v;
    
    timens_t x;
    if (t == NULL) {
        if (v == NULL) {
            unthrow(EFAULT, NULL);
        }
        x = *v;
    }
    else {
        x = *t;
    }
    if (x.tv_nsec == 0L) {
        if (!timens_SEC_OK(x.tv_sec)) {
            unthrow(ERANGE, NULL);
        }
        x.tv_sec = 0-x.tv_sec;
    }
    else {
        if (!timens_SEC_OK(x.tv_sec)) {
            unthrow(ERANGE, NULL);
        }
        x.tv_sec = (0-1)-x.tv_sec;
        x.tv_nsec = BILLION-x.tv_nsec;
    }
    return memcpy(v, &x, sizeof x);
    
}

timens_t
timens_neg(const timens_t *t) {
    return timens_NEG(t);
}

timens_t
timens_abs(const timens_t *t) {
    return (t->tv_sec < 0) ? timens_NEG(t): *t;
}

timens_t *
timens_iabs(timens_t *v, const timens_t *t) {
    if (t == NULL) {
        if (v == NULL) {
            unthrow(EFAULT, NULL);
        }
        t = v;
    }
    if (t->tv_nsec == 0L) {
        if (t->tv_sec < 0) {
            return timens_INIT(v, 0-t->tv_sec, 0L);
        }
        return timens_INIT(v, t->tv_sec, 0L);
    }
    if (!timens_NSEC_OK(t->tv_nsec)) {
        unthrow(ERANGE, NULL);
    }
    if (t->tv_sec < 0) {
        if (t->tv_sec < TIMENS_SEC_MIN) {
            unthrow(ERANGE, NULL);
        }
        return timens_INIT(v, (0-1)-t->tv_sec, BILLION-t->tv_nsec);
    }
    if (t->tv_nsec > TIMENS_SEC_MAX) {
        unthrow(ERANGE, NULL);
    }
    return memmove(v, t, sizeof *v);
}

ptrdiff_t
timens_str(const timens_t *restrict t, char dst[restrict]) {
    char str[512];  // for the actual string (vastly oversized)
    char tmp[16];   // for the sub second part 
    timens_t tv;
    imaxdiv_t x;
    ptrdiff_t i = PTRDIFF_C(0);
    div_t p;
    div_t q;
    div_t r;
    int j;
    str[i++] = 'T';
    if (t->tv_sec > INT64_C(0)) {
        tv = *t;
        str[i++] = '+';
    }
    else {
        if (t->tv_sec) {
            str[i++] = '-';
            tv = (t->tv_nsec 
                ?   timens_NEG_WITH_NSEC
                :   timens_NEG_ONLY_SECS
                )(t);
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
    if (tv.tv_sec < timens.units[MINUTES].n) {
        x.rem = tv.tv_sec;
        goto the_subminute;
    }
    if (tv.tv_sec >= timens.units[WEEKS].n) {
        x = imaxdiv(tv.tv_sec, timens.units[WEEKS].n);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdw", x.quot);
        if (j < 0) {
            return j;
        };
        i += j;
    }
    else {
        x.rem = tv.tv_sec;
    }
    if (x.rem >= timens.units[DAYS].n) {
        x = imaxdiv(x.rem, timens.units[DAYS].n);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdd", x.quot);
        if (j < 0) {
            return j;
        }
        i += j;
    }
    if (x.rem >= timens.units[HOURS].n) {
        x = imaxdiv(x.rem, timens.units[HOURS].n);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdh", x.quot);
        if (j < 0) {
            return j;
        }
        i += j;
    }
    if (x.rem >= timens.units[MINUTES].n) {
        x = imaxdiv(x.rem, timens.units[MINUTES].n);
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
            j = snprintf(str+i, (sizeof str)-(size_t) i, "%jd", x.rem);
        }
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
            unthrow(EINVAL, 0-1);
        }
    }
    return i;
}

int 
timens_cmp(const timens_t *a, const timens_t *b) {
    return  (a == b) ? 0
        :   (a->tv_sec  >  b->tv_sec)   ? 0+1
        :   (a->tv_sec  <  b->tv_sec)   ? 0-1
        :   (a->tv_nsec == b->tv_nsec)  ? 0+0
        :   (a->tv_nsec <  b->tv_nsec)  ? 0-1
        :   1;
}

bool
timens_bool(const timens_t *t) {
    return t->tv_sec || t->tv_nsec;
}

bool
timens_not(const timens_t *t) {
    return !(t->tv_sec || t->tv_nsec);
}

bool
timens_lt(const timens_t *a, const timens_t *b) {
    return  (a == b) ? false 
        :   (a->tv_sec  <  b->tv_sec) ? true
        :   (a->tv_sec  >  b->tv_sec) ? false 
        :   (a->tv_nsec <  b->tv_nsec);
}

bool 
timens_le(const timens_t *a, const timens_t *b) {
    return  (a == b) ? true
        :   (a->tv_sec  <  b->tv_sec) ? true 
        :   (a->tv_sec  >  b->tv_sec) ? false 
        :   (a->tv_nsec <= b->tv_nsec);
}

bool 
timens_eq(const timens_t *a, const timens_t *b) {
    return  (a == b) ? true 
        :   (a->tv_sec != b->tv_sec) ? false
        :   (a->tv_nsec == b->tv_nsec);
}

bool 
timens_ne(const timens_t *a, const timens_t *b) {
    return  (a == b) ? false 
        :   (a->tv_sec  != b->tv_sec) ? true
        :   (a->tv_nsec != b->tv_nsec);
}

bool 
timens_gt(const timens_t *a, const timens_t *b) {
    return  (a == b) ? false
        :   (a->tv_sec > b->tv_sec) ? true
        :   (a->tv_sec < b->tv_sec) ? false 
        :   (a->tv_nsec> b->tv_nsec);
}

bool 
timens_ge(const timens_t *a, const timens_t *b) {
    return  (a == b) ? true
        :   (a->tv_sec  >  b->tv_sec) ? true 
        :   (a->tv_sec  <  b->tv_sec) ? false
        :   (a->tv_nsec >= b->tv_nsec);
}

timens_t
timens_trunc(const timens_t *t) {
    return (timens_t){
        .tv_sec=(
            t->tv_sec < 0 
        ?   t->tv_nsec ? (t->tv_sec+1) :t->tv_sec
        :   t->tv_sec),
    };
}

timens_t
timens_ceil(const timens_t *t) {
    return (timens_t){
        .tv_sec = (
            !t->tv_nsec 
            ?   t->tv_sec 
            :   t->tv_sec+1)
    };
}

timens_t
timens_floor(const timens_t *t) {
    return (timens_t){t->tv_sec};
}

timens_t
timens_near(const timens_t *t) {
    if (!t->tv_nsec) {
        return *t;
    }
    return (timens_t) {
        (t->tv_sec < 0)
        ?   (t->tv_nsec <= (BILLION/2))
            ?   (t->tv_sec)
            :   (t->tv_sec+1)
        :   (t->tv_nsec < (BILLION/2))
            ?   (t->tv_sec)
            :   (t->tv_sec+1)
    };
}

timens_t
timens_round(const timens_t *t, ROUND_T mode) {
    return timens.round_ops[mode].timeround_mode(t);
}

timens_t
timens_add(const timens_t *a, const timens_t *b) {
    timens_t t = {
        .tv_sec  = a->tv_sec +b->tv_sec,
        .tv_nsec = a->tv_nsec+b->tv_nsec,
    };
    if (t.tv_nsec > TIMENS_NSEC_MAX) {
        t.tv_sec += (time_t) long_DIVMOD(&t.tv_nsec, t.tv_nsec, BILLION);
    }
    return t;
}

timens_t 
timens_sub(const timens_t *a, const timens_t *b) {
    timens_t t = {
        .tv_sec  = a->tv_sec-b->tv_sec,
        .tv_nsec = a->tv_nsec-b->tv_nsec,
    };
    if (t.tv_nsec < 0L) {
        t.tv_sec += (time_t) long_DIVMOD(&t.tv_nsec, t.tv_nsec, BILLION);
    }
    return t;
}

timens_t *
timens_iadd(timens_t *v, const timens_t *a, const timens_t *b) {
    timens_t t = timens_add(a, b);
    if (!timens_SEC_OK(t.tv_sec)) {
        unthrow(ERANGE, NULL);
    }
    return memcpy(v, &t, sizeof t);
}

timens_t *
timens_isub(timens_t *v, const timens_t *a, const timens_t *b) {
    timens_t t = timens_sub(a, b);
    if (!timens_SEC_OK(t.tv_sec)) {
        unthrow(ERANGE, NULL);
    }
    return memcpy(v, &t, sizeof t);
}

timens_t *
timens_imul(timens_t *restrict v, const timens_t *a, int b) {
    imaxdiv_t p;
    intmax_t m;
    timens_t t;
    bool sign;
    /* intmax_t targ = __LINE__; */ 
    if (!a->tv_nsec) {
        if (!a->tv_sec) {
            return memset(v, 0, sizeof t);
        }
        if (a->tv_sec < 0) {
            if (a->tv_sec < TIMENS_SEC_MIN) {
                range_error: {
                    /* 
                    char buf[256]; 
                    assert(timens_str(a, buf));
                    printf("[targ=%ji] <%s> × %d\n",targ, buf, b);
                    */ 
                    unthrow(ERANGE, NULL);
                }
            }
            if (b < 2) {
                switch (b) {
                    case (0+1): return memcpy(v, a, sizeof t);
                    case (0*0): return memset(v, 0, sizeof t);
                    case (0-1): {
                        t.tv_sec = 0-a->tv_sec;
                        t.tv_nsec = 0L;
                        return memcpy(v, &t, sizeof t);
                    }
                }
                t = timens_NEG(a);
                b = 0-b;
                if (t.tv_sec > TIMENS_SEC_MAX/b) {
                    /* targ = __LINE__; */
                    goto range_error;
                }
                t.tv_sec *= b;
            }
            else {
                t = timens_NEG(a);
                if (t.tv_sec > TIMENS_SEC_MAX/b) {
                    /* targ = __LINE__; */
                    goto range_error;
                }
                t.tv_sec = 0-(t.tv_sec*b);
            }
        }
        else {
            if (a->tv_sec > TIMENS_SEC_MAX) {
                /* targ = __LINE__; */
                goto range_error;
            }
            if (b < 2) {
                switch (b) {
                    case (0*0): return memset(v, 0, sizeof t);
                    case (0+1): return memcpy(v, a, sizeof t);
                    case (0-1): {
                        t.tv_sec = 0-a->tv_sec;
                        t.tv_nsec = 0L;
                        return memcpy(v, &t, sizeof t);
                    }
                }
                t.tv_sec = a->tv_sec;
                if ((t.tv_sec+1) > TIMENS_SEC_MAX/(0-b)) {
                    /* targ = __LINE__; */
                    goto range_error;
                }
                t.tv_sec = t.tv_sec*b-1;
            }
            else {
                if (a->tv_sec > TIMENS_SEC_MAX/b) {
                    /* targ = __LINE__; */
                    goto range_error;
                }
                t.tv_sec = a->tv_sec*b;
            }
            t.tv_nsec = 0L;
        }
        return memcpy(v, &t, sizeof t);
    }
    if (!timens_NSEC_OK(a->tv_nsec)) {
        /* targ=__LINE__; */
        goto range_error;
    }
    if (a->tv_sec < 0) {
        if (a->tv_sec < TIMENS_SEC_MIN) {
            /* targ = __LINE__; */
            goto range_error;
        }
        switch (b) {
            case 0+1: return memcpy(v, a, sizeof t);
            case 0*0: return memset(v, 0, sizeof t);
            case 0-1: {
                t = timens_NEG(a);
                return memcpy(v, &t, sizeof t);
            }
        }
        t = timens_NEG(a);
        if (b < 0) {
            m = 0-(intmax_t) b;
            sign = false;
        }
        else {
            m = (intmax_t) b;
            sign = true;
        }
    }
    else {
        if (a->tv_sec > TIMENS_SEC_MAX) {
            /* targ = __LINE__; */ 
            goto range_error;
        }
        switch (b) {
            case 0+1: return memcpy(v, a, sizeof t);
            case 0*0: return memset(v, 0, sizeof t);
            case 0-1: {
                t = timens_NEG(a);
                return memcpy(v, &t, sizeof t);
            }
        }
        t.tv_sec = a->tv_sec;
        t.tv_nsec = a->tv_nsec;
        if (b < 0) {
            m = 0-(intmax_t) b;
            sign = true;
        }
        else {
            m = b;
            sign = false;
        }
    }
    if (t.tv_sec > TIMENS_SEC_MAX/m) {
        /*targ = __LINE__; */
        goto range_error;
    }
    t.tv_sec = (time_t) (m*t.tv_sec);
    p = imaxdiv(m*t.tv_nsec, BILLION);
    t.tv_sec += (time_t) p.quot;
    t.tv_nsec = (long) p.rem;
    if (sign) {
        t = timens_NEG(&t);
    }
    if (!timens_SEC_OK(t.tv_sec)) {
        /* targ = __LINE__; */
        goto range_error;
    }
    return memcpy(v, &t, sizeof t);
}

timens_t *
timens_fmul(timens_t *restrict v, const timens_t *a, double b) {
    long double x;
    long double p;
    long double q;
    timens_t t;
    bool sign;
    if (!isfinite(b)) {
        range_error: {
            unthrow(ERANGE, NULL);
        }
    }
    if (b < 0) {
        if (a->tv_sec < 0) {
            if (a->tv_sec < TIMENS_SEC_MIN) {
                goto range_error;
            }
            t = timens_NEG(a);
            sign = false;
        }
        else {
            if (a->tv_sec > TIMENS_SEC_MAX) {
                goto range_error;
            }
            sign = true;
            t = *a;
        }
        x = 0.L-b;
    }
    else {
        if (a->tv_sec < 0) {
            if (a->tv_sec < TIMENS_SEC_MIN) {
                goto range_error;
            }
            t = timens_NEG(a);
            sign = true;
        }
        else {
            if (a->tv_sec > TIMENS_SEC_MAX) {
                goto range_error;
            }
            sign = false;
            t = *a;
        }
        x = b;
    }
    p = x*t.tv_sec;
    q = x*t.tv_nsec;
    p+= q/BILLION;
    t.tv_nsec = (long) fmodl(q, BILLION);
    if (p > TIMENS_SEC_MAX) {
        goto range_error;
    }
    t.tv_sec = (time_t) p;
    if (sign) {
        t = timens_NEG(&t);
    }
    return memcpy(v, &t, sizeof t);
    /*
    x = 2.5
    t = {24, 567'890'000}
    p = 2.5*24 
    q = 2.5*567'890'000 = 1'419'725'000.0
    
    
    timens_t m = {
        
    }
    if ()
    if (a->tv_nsec == 0) {
        if (a->tv_sec == 0) {
            return memset(v, 0, sizeof *v);
        }
        
    }
    if (a->tv_sec < 0) {
        p = timens_NEG(a);
        s = 1;
    }
    else {
        s = 0;
    }
    t = p.tv_sec*t;
    if (timens_fromftime(&p, (double) t) == NULL) {
        return NULL;
    }
    t = p.tv_nsec*(long double) b;
    if (timens_fromftime(&q, (double) (t/BILLION)) == NULL) {
        return NULL;
    }
    if (timens_add(&p, &p, &q) == NULL) {
        return NULL;
    }
    if (s) {
        *v = b < 0 ? p : timens_NEG(&p);
    }
    else {
        *v = p;
    }
    return v;
    */
}

time_t
timens_div(timens_t *restrict mod, const timens_t *a, const timens_t *b) {
    if ((a->tv_sec < 0) || (b->tv_sec < 0)) {
        unthrow(EINVAL, 0);
    }
    if (a->tv_sec < b->tv_sec) {
        tiny_dividend: {
            (void) memcpy(mod, a, sizeof *mod);
            return 0;
        }
    }
    if (a->tv_sec == b->tv_sec) {
        if (a->tv_nsec <= b->tv_nsec) {
            if (a->tv_nsec < b->tv_nsec) {
                goto tiny_dividend;
            }
            (void) memset(mod, 0, sizeof *mod);
            return 1;
        }
    }
    int128_t n = BILLION*(int128_t) a->tv_sec+a->tv_nsec;
    int128_t d = BILLION*(int128_t) b->tv_sec+b->tv_nsec;
    int128_t q = n/d;
    if (q > TIMENS_SEC_MAX) {
        unthrow(ERANGE, 0);
    }
    int128_t r = n%d;
    (void) memcpy(
        mod,
        &(timens_t){
            .tv_sec = (time_t) (r/BILLION),
            .tv_nsec = (long) (r%BILLION),
        },
        sizeof *mod);
    return (time_t) q;
}

timens_t *
timens_fromftime(timens_t *restrict v, double sec) {
    double i;
    timens_t t;
    if (sec < 0.0) {
        double p = modf(0.0-sec, &i);
        if (i > TIMENS_FSEC_MAX) {
            unthrow(ERANGE, NULL);
        }
        t.tv_sec = 0-(1-((time_t) i));
        t.tv_nsec = p ? (BILLION-(long) (p*BILLION)) : 0L;
    }
    else {
        t.tv_nsec = (long) (BILLION*modf(sec, &i));
        if (i > TIMENS_FSEC_MAX) {
            unthrow(ERANGE, NULL);
        }
        t.tv_sec = (time_t) i;
    }
    return memcpy(v, &t, sizeof t);
}

double
timens_ftime(const timens_t *restrict t) {
    double z;
    timens_t r;
    if (t->tv_sec < 0) {
        if (t->tv_sec < TIMENS_SEC_MIN) {
            the_flowjob: {
                unthrow(ERANGE, 0-1);
            }
        }
        r = timens_NEG(t);
        t = &r;
    }
    else {
        if (t->tv_sec > TIMENS_SEC_MAX) {
            goto the_flowjob;
        }
    }
    if (!t->tv_nsec) {
        the_integer: {
            z = (double) ((t == &r) ? (0-t->tv_sec) : t->tv_sec);
        }
        goto the_end;
    }
    if (!timens_NSEC_OK(t->tv_nsec)) {
        goto the_flowjob;
    }
    const unsigned char b = BITLEN64((uint64_t) t->tv_sec);
    const double        x = timens.FTIMES[b];
    if (b < 24) {
        z = (BILLION*t->tv_sec+t->tv_nsec)/1e9;
        if (t == &r) {
            z = 0.0-z;
        }
    }
    else {
        if (b > 49) {
            goto the_integer;
        }
        z = (x*t->tv_sec+t->tv_nsec/timens.FTIMENS[b])/x;
        if (t == &r) {
            z = 0.0-z;
        }
    }
    the_end: {
        return z;
    }
}

timens_t
timens_now(void) {
    timens_t t;
#   if _POSIX_TIMERS
    if (clock_gettime(CLOCK_REALTIME, &t)) {
        abort();
    }
#   endif
    return t;
}

struct tm *
timens_localtime(timens_t *t) {
    time_t i = t == NULL ? time(0) : t->tv_sec;
    return memcpy(
        &locals.localtime, 
        localtime(&i), 
        sizeof locals.localtime);
}

timens_t
timens_mktime(struct untm *t) {
    return (timens_t){
        .tv_sec = mktime(&(struct tm){
            .tm_year = t->tm_year,
            .tm_yday = t->tm_yday,
            .tm_mon  = t->tm_mon,
            .tm_mday = t->tm_mday,
            .tm_hour = t->tm_hour,
            .tm_min  = t->tm_min,
            .tm_sec  = t->tm_sec,
            .tm_isdst= t->tm_isdst,
        }),
        .tv_nsec = t->tm_nsec,
    };
}

time_t
unmktime(struct tm *t) {
    return (time_t) (
        (t->tm_sec)
    +   (t->tm_hour*3600)
    +   (t->tm_yday*86400)
    +   (t->tm_year-70)*31536000
    +   ((t->tm_year-69)/4)*86400
    -   ((t->tm_year-1)/100)*86400
    +   ((t->tm_year+299)/400)*86400);
}

ptrdiff_t
unstrrepr(const char *restrict src, FILE *restrict dst) {
    if (dst == NULL) {
        dst = stdout;
    }
    ptrdiff_t len = 1;
    int n = 0;
    if (fputc('"', dst) < 0) {
        return -1;
    }
    while (*src) {
        return 0;
    }
}

#define DICT_OP_SUCCESS ((hash_t) 0)
#define DICT_OP_FAILURE ((hash_t) 0-1)

hash_t 
unstrhash(const char *restrict);

struct unitem;

typedef struct unitem {
    const char     *k;
    const void     *v;
    hash_t          i;
    struct unitem  *next;
} unitem;

typedef struct {
    uint8_t     bits;
    hash_t      used;
    hash_t      size;
    unitem    **staq;
    unitem     *imap[1];
} undict;

typedef union ptrview {
    void        *addr;
    uintptr_t   uint;
    char        *c;
    wchar_t     *w;
    uint8_t     *u8;
    uint16_t    *u16;
    uint32_t    *u32;
    uint64_t    *u64;
    uintmax_t   *umax;
    size_t      *usz;
    int8_t      *s8;
    int16_t     *s16;
    int32_t     *s32;
    int64_t     *s64;
    intmax_t    *smax;
    ssize_t     *ssz;
    float       *flt;
    double      *dbl;
} ptrview_t;

typedef struct dict_item {
    const char *key;
    void       *val;
    struct dict_item *next;
} DictItem;

typedef struct {
    size_t              size;
    timens_t            vers;
    hash_t              nkey;
    hash_t              used;
    int                 type;
    uint8_t             lsh;
    uint8_t             rsh;
    pthread_rwlock_t    lock;
    DictItem **         map;
    DictItem  *         data;
} Dict;

Dict *  Dict_new    (hash_t, int);
void    Dict_destroy(Dict *restrict);
void *  Dict_get    (Dict *restrict, const char *);
hash_t  Dict_put    (Dict *restrict, const char *, void *);
void *  Dict_hget   (Dict *restrict, const char *, hash_t);
hash_t  Dict_hput   (Dict *restrict, const char *, void *, hash_t);

void Dict_api_init(void) {
    if (pthread_spin_init(&Dict_api_lock, PTHREAD_PROCESS_PRIVATE)) {
        perror(__func__), exit(EXIT_FAILURE);
    }
}

static  
uint8_t NBIT[256] = {
    0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
    8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
};

hash_t
unstrhash(const char *restrict str) {
    size_t i = 0;
    union {
        uint64_t v;
        struct {
            uint16_t a;
            uint32_t b;
        };
    } hash = {.a=1, .b=0};
    for (; str[i]; i++) {
        hash.a += str[i];
        hash.b += hash.a;
    }
    if (!hash.v) {
        return 0;
    }
    hash.v ^= hash.v>>12;
    hash.v ^= hash.v<<25;
    hash.v ^= hash.v>>27;
    return    hash.v>>33;
}

static inline uint8_t
hashbits(hash_t i) {
    if (i <  0x00000004) return 003;
    if (i <= 0x000000FF) return 001+NBIT[i];
    if (i <= 0x0000FFFF) return 011+NBIT[i>>010];
    if (i <= 0x00FFFFFF) return 021+NBIT[i>>020];
    else                 return 031+NBIT[i>>030];
}

Dict *
Dict_new(hash_t nkey, int type) {
    Dict dict = {
        .nkey=nkey, 
        .type=type,
        .lsh=hashbits(nkey),
    };
    dict.rsh            = 31-dict.lsh;
    dict.size           = 1<<dict.lsh;
    const size_t ptrs   = sizeof(DictItem*)*dict.size;
    const size_t data   = sizeof(DictItem)*nkey;
    const size_t xtra   = data+ptrs;
    const size_t need   = sizeof(Dict)+xtra;
    ptrview_t buf       = {malloc(need)};
    Dict *self          = buf.addr;
    if (!self) {
        return NULL;
    }
    if (pthread_rwlock_init(&self->lock, NULL)) {
        free(self);
        return NULL;
    }
    if (memcpy(self, &dict, sizeof *self) == NULL) {
        fail: {
            Dict_destroy(self);
            return NULL;
        }
    }
    if (memset(buf.addr=self+1, 0, xtra) == NULL) {
        goto fail;
    }
    self->map   = buf.addr;
    self->data  = (void *)(buf.c+ptrs);
    return self;
}

void 
Dict_destroy(Dict *d) {
    (void) pthread_rwlock_destroy(&d->lock);
    (void) memset(d, 0, sizeof *d);
    free(d);
}

void *
Dict_hget(Dict *restrict d, const char *k, hash_t hash) {
    assert(errno == 0);
    if (hash == DICT_OP_FAILURE) {
        return NULL;
    }
    if (pthread_rwlock_rdlock(&d->lock)) {
        switch (errno) {
            case EDEADLK:   return NULL;
            case EAGAIN:    return NULL;
            default:        abort();
        }
    }
    void *v = NULL;
    DictItem *i = d->map[hash>>d->rsh];
    for (; i; i=i->next) {
        printf("i->key = \"%s\"
        if (!strcmp(k, i->key)) {
            v = i->val;
            break;
        }
    }
    if (pthread_rwlock_unlock(&d->lock)) {
        return NULL;
    }
    return v;
}

void *
Dict_get(Dict *restrict d, const char *k) {
    return Dict_hget(d, k, unstrhash(k));
}

static inline bool
Dict_FULL(Dict *d) {
    return d->used >= d->size;
}

hash_t
Dict_hput(Dict *restrict d, const char *k , void *v, hash_t hash) {
    if (pthread_rwlock_wrlock(&d->lock)) {
        return DICT_OP_FAILURE;
    }
    hash_t slot = hash>>d->rsh;
    DictItem *i = d->map[slot];
    for (; i; i=i->next) {
        if (!strcmp(i->key, k)) {
            goto insertion_success;
        }
    }
    if (Dict_FULL(d)) {
        slot = DICT_OP_FAILURE;
    }
    else {
        i = (d->used++)+d->data;
        i->next = NULL;
        i->key  = k;
        insertion_success: {
            i->val = v;
        }
    }
    if (pthread_rwlock_unlock(&d->lock)) {
        return DICT_OP_FAILURE;
    }
    return slot;
}

hash_t
Dict_put(Dict *restrict d, const char *k, void *v) {
    return Dict_hput(d, k, v, unstrhash(k));
}


/*
    tm_sec 
+   tm_min*60
+ tm_hour*3600
+ tm_yday*86400
+ (tm_year-70)
*   31536000 
+ ((tm_year-69)/4)*86400
- ((tm_year-1)/100)*86400
+ ((tm_year+299)/400)*86400 

static char *
dtostr(double n) {
    double i;
    (void) modf(n, &i);
    const unsigned char b = BITLEN64((uint64_t) i);
    const int d = timens.FTIME_NDIGIT[b];
    locals.dtostr.s[0] = 0;
    if (snprintf(locals.dtostr.s, sizeof locals.dtostr.s, "%.*f", d, n) < 0) {
        return NULL;
    }
    return locals.dtostr.s;
}
*/
const char *bool_repr(bool v) {
    return v ? "true" : "false";
}

#include <sys/mman.h>
#include <fcntl.h>
#include <dirent.h>

void unopened(DIR *it, const char *why) {
    if (it != NULL) {
        closedir(it);
    }
    perror(why);
    exit(EXIT_FAILURE);
}

_Thread_local char joined_path[FILENAME_MAX];

const char *
path_join(const char *restrict path, const char *restrict name) {
    if (0 > snprintf(joined_path, FILENAME_MAX, "%s/%s", path, name)) {
        return NULL;
    }
    return joined_path;
}

void showdir(const char *path) {
    assert(errno == 0);
    DIR *it = opendir(path);
    if (it != NULL) {
        goto pass;
    }
    fail: {
        switch (errno) {
            case EACCES: unopened(it, "permission denied");
            case EBADF:   unopened(it, "bad fd");
            case EMFILE:  unopened(it, "proc open FD limit exceeded");
            case ENFILE:  unopened(it, "system open FD limit exceeded");
            case ENOENT:  unopened(it, "dir doesn't exist");
            case ENOTDIR: unopened(it, "not a directory path");
            case ENOMEM:  unopened(it, "out of memory");
        }
    }
    pass: {}
    /*
    DT_BLK      This is a block device. 
    DT_CHR      This is a character device.
    DT_DIR      This is a directory. 
    DT_FIFO     This is a named pipe (FIFO). 
    DT_LNK      This is a symbolic link. 
    DT_REG      This is a regular file.
    DT_SOCK     This is a UNIX domain socket. 
    DT_UNKNOWN  The file
    */
    int i = 0;
    for (struct dirent *e=NULL; ; i++) {
        assert(i < 1000);
        e = readdir(it);
        if (e == NULL) {
            if (errno != 0) {
                goto fail;
            }
            break;
        }
        const char *p = path_join(path, e->d_name);
        const char *t;
        switch (e->d_type) {
            case DT_CHR:
            case DT_BLK: {
                t = "[c]";
                break;
            }
            case DT_SOCK: {
                t = "[s]";
                break;
            }
            case DT_FIFO: {
                t = "[p]";
                break;
            }
            case DT_LNK: {
                t = " # ";
                break;
            }
            case DT_DIR: {
                t = "[+]";
                break;
            }
            case DT_REG: {
                t = "   ";
                break;
            }
            default: {
                t = "[?]";
            }
        }

        printf("%s \"%s\"\n",t,p);
        
    }
    closedir(it);
    
}

int main(void) {
    char str[512] = {0};
    errno = 0;
    const char *dir = "/sdcard/.dewclaw";
    if (0) showdir(dir);
    if (1) Dict_api_init();

    Dict *dick = Dict_new(15, 0);
    int vals[] = {
        1, 22, 333, 4444, 55555, 666666, 7777777
    };
    assert(Dict_put(dick, "mon", vals+0) != DICT_OP_FAILURE);
    int *val = Dict_get(dick, "mon");
    printf(
        "errno = %d\n"
        "val = %p\n",
        errno, val
        );
    /*
    const char *keys[] = {
        "mon",
        "tue",
        "wed",
        "thu",
        "fri",
        "sat",
        "sun",
        0,
    };
    int vals[] = {1, 22, 333, 4444, 55555, 666666, 7777777};
    for (int i=0; i < 7; i++) {
        assert(Dict_put(dick, keys[i], &vals[i]) != DICT_OP_FAILURE);
    }
    for (int i=0; i < 7; ++i) {
        int   *v = Dict_get(dick, keys[i]);
        assert(v);
        printf("dick[\"%s\"] => %i\n", keys[i], *v);
    }
    Dict_destroy(dick);
    */
    timens_t now = timens_now();
    //printf("_POSIX_TIMERS = %s\n", bool_repr(_POSIX_TIMERS));
//    printf("_POSIX_C_SOURCE = %ld\n", _POSIX_C_SOURCE);
    //printf("now = %jd.%ld\n", (intmax_t) now.tv_sec, now.tv_nsec);
    struct tm *c = timens_localtime(&now);
    printf("mktime(...) => %jd\n", (intmax_t) unmktime(c));
    printf(
        "yday[2011-11-29] => %i\n"
        "yday[1988-07-17] => %i\n",
        date_YDAY(2011, 11, 29),
        date_YDAY(1988, 7,  17));
    printf(
        "(struct tm){"
        ".tm_yday=%i, .tm_year=%i, .tm_mon=%i, "
        ".tm_mday=%i, .tm_hour=%i, .tm_min=%i, .tm_sec=%i, "
        ".tm_wday=%i, .tm_isdst=%i}\n",
        c->tm_yday, c->tm_year, c->tm_mon,
        c->tm_mday, c->tm_hour, c->tm_min, c->tm_sec,
        c->tm_wday, c->tm_isdst);

}
#if 0
#include <semaphore.h>
#include <pthread.h>

sem_t loque;
int tasks_completed = 0;
int task_ids[] = {69, 777};

static void untoss_impl(const char *f, intmax_t lineno) {
    char buf[512] = {0};
    (void) snprintf(
        buf,
        sizeof buf,
        "In func \"%s\" in line %ji\n",
        f,
        lineno);
    perror(buf);
    exit(EXIT_FAILURE);
}

#define untoss() untoss_impl(__func__, __LINE__)
/*
int 
pthread_create(
    pthread_t *restrict thread, 
    const pthread_attr_t *restrict attr, 
    void *(*start_routine)(void *),
    void *restrict arg);
*/

void *
task(void *arg) {
    timens_t timeout;
    bool destroy_after;
    if(!timens_fromtime(&timeout, 750, MILLISECONDS)) {
        untoss();
    }
    if (sem_timedwait(&loque, &timeout)) {
        untoss();
    }
    int *task_id = arg;
    printf("done with task # %d\n", *task_id);
    destroy_after = ++tasks_completed >= 2;
    if (sem_post(&loque)) {
        untoss();
    }
    if (destroy_after) {
        if (sem_destroy(&loque)) {
            untoss();
        }
    }
    return NULL;
}

void prog(void) {
    if (sem_init(&loque, 0, 1)) {
        untoss();
    }
    pthread_t task_a;
    pthread_t task_b;

    if (pthread_create(&task_a, 0, task, task_ids+0)) {
        untoss();
    }
    if (pthread_create(&task_b, 0, task, task_ids+1)) {
        untoss();
    }
}

#include "test/untime.h"


int main(void) {
    errno = 0;
    printf("FLT_MANT_DIG = %d\n", FLT_MANT_DIG);
    prog();
    timens_t req, rem = {0};
    if (!timens_fromftime(&req, 1.5)){
        untoss();
    }
    nanosleep(&req, &rem);
    char rhs[512] = {0};
    if (timens_str(&rem, rhs) < 0) {
        untoss();
    }
    printf("rem = <%s>\n", rhs);
    
    /*
    (void) 0 ? printf(
        "fmod(1419725000.0, %'d) => %f\n",
        BILLION,
        fmod(1419725000.0, BILLION)):0;
        
    */
    char lhs[512] = {0};
    double fuq = timens_ftime(&timens.nanosecond.neg);
    if (0) {printf(
        "errno = %d\n"
        "fuq   = %.9f\n"
        "timens.nanosecond.pos = {%jd, %ld}\n",
        errno, fuq, 
        timens.nanosecond.neg.tv_sec,
        timens.nanosecond.neg.tv_nsec
        );}
    if (0) {
        timens_t yo;
        assert(timens_fromftime(&yo, -0.000123));
        assert(timens_str(&yo, lhs));
            printf("__STDC_VERSION__ = %ld\n", __STDC_VERSION__);
            return printf(
            "yo=%s {%jd, %ld}\n", 
            lhs, 
            (intmax_t) yo.tv_sec,
            yo.tv_nsec);
    }
    
    
    //true && 1 < 60 || 1 > 60 ? false : 0 < 0
    /*
    volatile int a = 1;
    volatile int b = 60;
    volatile _Bool t = 1;
    volatile _Bool f = 0;
    */
    div_t CTR = {0};
    if (1) {
        timens_ARITHMETIC(0, &CTR);
    }
    if (1) {
        timens_TEST_MUL(0, &CTR);
    }
    if (1) {
        timens_TEST_DIV(0, &CTR);
    }
    if (1) {
        timens_TEST_TIME(0, &CTR);
    }
    if (1) {
        timens_TEST_SIGNEDNESS(0, &CTR);
    }
    if (1) {
        timens_TEST_TIMEROUND(0, &CTR);
    }
    if (1) {
        timens_TEST_FTIMES(0, &CTR);
    }
    if (1) {
        timens_TEST_CMP(0, &CTR);
    }
    printf("passed %d/%d tests\n", CTR.quot, CTR.rem);

    /*
    if (!timens_fromtime(&t, 0-7777, MILLISECONDS)) {
        (void)printf("fail\n");
    }
    timens_t self;
    time_t sec_min = TIMENS_SEC_MIN;
    time_t sec_neg = 0-1;
    time_t sec_nil = 0;
    time_t sec_pos = 1;
    time_t sec_max = TIMENS_SEC_MAX;
    long nsec_min = TIMENS_NSEC_MIN;
    long nsec_one = 1l;
    long nsec_max = TIMENS_NSEC_MAX;

    int pos=1, nil=0, neg=0-1, max=999999999;
    timens_TEST_CMP(&(timens_t){nil, nil}, &(timens_t){nil,nil}, 0);
    timens_TEST_CMP(&(timens_t){nil, one}, &(timens_t){ni
    timens_TEST_CMP(tvs+0, tvs+2, one); // 
    timens_TEST_CMP(tvs+1, tvs+0, one); //
    timens_TEST_CMP(tvs+1, tvs+0, ); 
    timens_TEST_CMP(tvs+1, tvs+0, ); 

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
        {.tv_nsec=0-1},
    };
    ptrdiff_t i = 0;
    ptrdiff_t j = 0;
    if (0) {
        for (; all[i].tv_nsec >= 0; ++i) {
            timens_neg(&self, all+i);
            (void) timens_str(all+i, lhs);
            (void) timens_str(&self, rhs);
            printf("%3td: %s\n%3td: %s\n",  i, lhs, i, rhs);
        }
    }
    
    return printf(
        "(timens_r){.tv_sec=%jd, .tv_nsec=%jd}\n",
        (intmax_t) t.tv_sec,
        (intmax_t) t.tv_nsec);
    */
    return 123456789;
}
/*

os.system("clang kelvin.c -o untest -lm -I /sdcard/Python/unsys")
os.system(
    "clang "
    "/sdcard/Python/unsys/untime.c -o untest "
    "-lm "
    "-I /sdcard/Python/unsys"
    "--shared"
    )
2,0,5
9

0
2,2
  0
  2,2
os.system(
  "clang "
"/sdcard/Python/unsys/untime.c "
"-shared "
"-lpython3.10 "
"-lm "
"-I ../usr/include/python3.10 "
"-I /sdcard/Python/unsys "
"-o ../usr/lib/python3.10/site-packages/unsys.cpython-310.so"
)
*/
#endif
