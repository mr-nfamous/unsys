
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

timens: Temporal computations at nanosecond resolution

    aio_suspend
    utimensat
    futimens 
    sched_rr_get_interval
    mq_timedreceive
    mq_timedsend 
    pselect 
    clock_getres 
    clock_setres 
    clock_gettime 
    clock_settime 
    clock_nanosleep 
    nanosleep
    sem_timedwait 
    sigtimedwait 
    pthread_cond_timedwait
    pthread_mutex_timedlock
    pthread_rwlock_timedrdlock
    pthread_rwlock_timedwrlock

*/

#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <math.h>

#include "unopcode.h"
//#include "unint.h"
#include "untimely.h"


#define arraylen(a) ((sizeof a)/(sizeof *(a)))

typedef unsigned char   char8_t;
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;

struct bival {
    int     k;
    void   *v;
};

struct bimap {
    size_t len;
    const struct bival *map;
};

static inline const struct bival *
bimap_GET(const struct bimap *restrict const d, const int k) {
    for (size_t lo=0, hi=d->len; lo < hi;) {
        const size_t i = (lo+hi)>>1;
        if (d->map[i].k == k) {
            return d->map+i;
        }
        if (d->map[i].k > k) {
            lo = i;
        }
        else {
            hi = i+1;
        }
        
    }
    return NULL;
}

/*
*/

#define unthrow(err, ret) return errno=err, ret


/*
union timens_methods {
    bool        (*lt)   (const timens_t *, const timens_t *);
    bool        (*le)   (const timens_t *, const timens_t *);
    bool        (*eq)   (const timens_t *, const timens_t *);
    bool        (*ne)   (const timens_t *, const timens_t *);
    bool        (*gt)   (const timens_t *, const timens_t *);
    bool        (*ge)   (const timens_t *, const timens_t *);
    bool        (*ae)   (const timens_t *, const timens_t *);
    int         (*cmp)  (const timens_t *, const timens_t *);
    ptrdiff_t   (*str)  (const timens_t *, char *);
    ptrdiff_t   (*repr) (const timens_t *, FILE *);
    timens_t *  (*abs)  (timens_t *, const timens_t *);
    timens_t *  (*iabs) (timens_t *);
    timens_t *  (*neg)  (timens_t *, const timens_t *);
    timens_t *  (*ineg) (timens_t *);
    timens_t *  (*pos)  (timens_t *, const timens_t *);
    timens_t *  (*ipos) (timens_t *);
    timens_t *  (*clr)  (timens_t *);
    timens_t *  (*add)  (timens_t *, const timens_t *, const timens_t *);
    timens_t *  (*fadd) (timens_t *, const timens_t *, double);
    timens_t *  (*ladd) (timens_t *, const timens_t *, long);
    timens_t *  (*iadd) (timens_t *, const timens_t *);
    timens_t *  (*ifadd)(timens_t *, double);
    timens_t *  (*iladd)(timens_t *, long);
    timens_t *  (*sub)  (timens_t *, const timens_t *, const timens_t *);
    timens_t *  (*fsub) (timens_t *, const timens_t *, double);
    timens_t *  (*lsub) (timens_t *, const timens_t *, long);
    timens_t *  (*isub) (timens_t *, const timens_t *);
    timens_t *  (*ifsub)(timens_t *, double);
    timens_t *  (*ilsub)(timens_t *, long);
    timens_t *  (*fmul) (timens_t *, const timens_t *, double);
    timens_t *  (*lmul) (timens_t *, const timens_t *, long);
    timens_t *  (*ifmul)(timens_t *, double);
    timens_t *  (*ilmul)(timens_t *, long);
    undiv_t  *  (*div)  (undiv_t *, const timens_t *, const timens_t *);
    unldiv_t *  (*ldiv) (unldiv_t *, const timens_t *, long);
    unfdiv_t *  (*fdiv) (unfdiv_t *, const timens_t *, double);
    */  
    
/*
    
    struct {
        time_t  (*itime);
        double  (*ftime);
        bool    (*boolean);
    }   as

    (i)add:     <T+60s> + <T+1s>    = <T+61s>
    (i)ladd:    <T+60s> + 1L        = <T+61s>
    (i)fadd:    <T+60s> + 1.5       = <T+61.5s>
    
    (i)sub:     <T+60s> - <T+1s>    = <T+59s>
    (i)lsub:    <T+60s> - 80L       = <T-20s>
    (i)fsub:    <T+60s> - 1.5       = <T+58.5s>
    
    (i)lmul:    <T+4s> × 3L     = <T+12s>
    (i)fmul:    <T+2d> × 0.25   = <T+12h>

    (i)div:    <T+1h> ÷ <T+7m> = (undiv_t){
        .quot   = (intmax_t) 8, 
        .rem    = <T+4m>,
    }
    (i)ldiv:     <T+1h> ÷ 7     = (unldiv_t){
        .quot   = <T+8m34s>, 
        .rem    = <T+0.000002s>
    }
    (i)fdiv:    <T+1h> ÷ 2.1    = {unldiv_t){
        .quot   = <T+28m34.285714s>,
        .rem    = <T+0.000001s>,
    }
        28, 34, 285714
        
    }
    <T+60m> - <T+1m> = <T+59>
    
};
*/



timens_t *
timens_init(timens_t *restrict v, time_t tv_sec, long tv_nsec) {
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
    time_t s_mul, s_div;
    time_t ns_mul, ns_div;
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
static const __int128         TEN128 = (__int128) TEN;
static const __int128   INT64_MAX128  = (__int128) INT64_MAX;
static const __int128   INT64_MIN128  = (__int128) INT64_MIN;
static const __int128  NIL128 = 0;
static const __int128  NEG128 = NIL128-1;
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

time_t
(*timens_to_times[])(const timens_t *) = {

    [FEMTOSECONDS] = timens_to_femtoseconds,
    [ATTOSECONDS]  = timens_to_attoseconds,
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
timens_time(const timens_t *restrict t, enum TIME_UNIT id) {
    if (!time_unit_CHECK(id)) {
        unthrow(EINVAL, 0);
    }
    if (id == SECONDS) {
        return t->tv_sec;
    }
    timens_t v;
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

timens_t
timens_pos(const timens_t *v) {
    return *v;
}

timens_t *
timens_ineg(timens_t *restrict v, const timens_t *t) {
    *v = timens_NEG(t);
    return v;
}

timens_t
timens_neg(const timens_t *t) {
    return timens_NEG(t);
}

timens_t
timens_abs(const timens_t *t) {
    return (t->tv_sec < 0) ? timens_NEG(t): *t;
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

timens_t *
timens_add(timens_t *restrict v, const timens_t *a, const timens_t *b) {
    timens_t t = {
        .tv_sec  = a->tv_sec +b->tv_sec,
        .tv_nsec = a->tv_nsec+b->tv_nsec,
    };
    if (t.tv_nsec > TIMENS_NSEC_MAX) {
        t.tv_sec += (time_t) long_DIVMOD(&t.tv_nsec, t.tv_nsec, BILLION);
    }
    if (!timens_SEC_OK(t.tv_sec)) {
        unthrow(ERANGE, NULL);
    }
    return memcpy(v, &t, sizeof t);
}

timens_t *
timens_sub(timens_t *restrict v, const timens_t *a, const timens_t *b) {
    timens_t t = {
        .tv_sec  = a->tv_sec-b->tv_sec,
        .tv_nsec = a->tv_nsec-b->tv_nsec,
    };
    if (t.tv_nsec < 0L) {
        t.tv_sec += (time_t) long_DIVMOD(&t.tv_nsec, t.tv_nsec, BILLION);
    }
    if (!timens_SEC_OK(t.tv_sec)) {
        unthrow(ERANGE, NULL);
    }
    return memcpy(v, &t, sizeof t);
}

static inline bool
timens_MUL_TINY(timens_t *restrict v, const timens_t *restrict a, int b) {
    switch (b) {
        case (0+1): return memcpy(v, a, sizeof *v);
        case (0*0): return memset(v, 0, sizeof *v);
        case (0-1): return *v=timens_NEG(a), v;
    }
    return false;
}

timens_t *
timens_mul(timens_t *restrict v, const timens_t *a, int b) {
    imaxdiv_t p;
    intmax_t m;
    timens_t t;
    bool sign;
    intmax_t targ = __LINE__;
    if (!a->tv_nsec) {
        if (!a->tv_sec) {
            return memset(v, 0, sizeof t);
        }
        if (a->tv_sec < 0) {
            if (a->tv_sec < TIMENS_SEC_MIN) {
                range_error: {
                    char buf[256];
                    assert(timens_str(a, buf));
                    printf("[targ=%ji] <%s> × %d\n",targ, buf, b);
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
                b = 0-b;
                t.tv_sec = 0-a->tv_sec;
                if (t.tv_sec > TIMENS_SEC_MAX/b) {
                    targ = __LINE__; goto range_error;
                }
                t.tv_sec *= b;
            }
            else {
                t.tv_sec = 0-a->tv_nsec;
                if (t.tv_sec > TIMENS_SEC_MAX/b) {
                    targ = __LINE__; goto range_error;
                }
                t.tv_sec *= 0-b;
            }
        }
        else {
            if (a->tv_sec > TIMENS_SEC_MAX) {
                targ = __LINE__; goto range_error;
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
                    targ = __LINE__; goto range_error;
                }
                t.tv_sec = t.tv_sec*b-1;
            }
            else {
                if (a->tv_sec > TIMENS_SEC_MAX/b) {
                    targ = __LINE__; goto range_error;
                }
                t.tv_sec = a->tv_sec*b;
            }
        }
        t.tv_nsec = 0L;
        return memcpy(v, &t, sizeof t);
    }
    if (!timens_NSEC_OK(a->tv_nsec)) {
        targ=__LINE__; goto range_error;
    }
    if (a->tv_sec < 0) {
        if (a->tv_sec < TIMENS_SEC_MIN) {
            targ = __LINE__;
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
        t.tv_sec = 0-a->tv_sec;
        t.tv_nsec = BILLION-a->tv_nsec;
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
            targ=__LINE__; goto range_error;
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
        targ = __LINE__; goto range_error;
    }
    t.tv_sec = (time_t) (m*t.tv_sec);
    p = imaxdiv(m*t.tv_nsec, BILLION);
    t.tv_sec += (time_t) p.quot;
    t.tv_nsec = (long) p.rem;
    if (sign) {
        t = timens_NEG(&t);
    }
    if (!timens_SEC_OK(t.tv_sec)) {
        targ = __LINE__; goto range_error;
    }
    return memcpy(v, &t, sizeof t);
}

timens_t *
timens_fmul(timens_t *restrict v, const timens_t *a, double b) {
    timens_t p;
    timens_t q;
    long double t = b;
    int s;
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
}

long
timens_div(timens_t *restrict mod, const timens_t *a, const timens_t *b) {
    timens_t m;
    timens_t o[2];
    /*
    (+)÷(+) = (+)%(+) +5/+2 = +2 % +1
    
    
    */
#if defined(__SIZEOF_INT128__)

    if (a->tv_sec < 0) {
        o[0] = timens_NEG(a);
        a = o;
        if (b->tv_sec < 0) {
            o[1] = timens_NEG(b);   // (-)÷(-) = (+)%(-) -5/-2 = +2 % -1
            b = o+1;                // (-)÷(+) = (-)%(+) -5/+2 = -3 % +1 
        }
    }
    else {
        if (b->tv_sec < 0) {
            o[1] = timens_NEG(b);
            b = o+1;                //(+)÷(-) = (-)%(-) +5/-2 = -3 % -1 
        }
    }
    int128_t n = (int128_t) a->tv_sec*BILLION+a->tv_nsec;
    int128_t d = (int128_t) b->tv_sec*BILLION+b->tv_nsec;
    int128_t r = n%d;
    union {
        int128_t x;
        long l;
    } q = {.x=n/d};
    m.tv_sec    = (time_t) (r/BILLION);
    m.tv_nsec   = (long)   (r%BILLION);
    if (a == o+0) {
        if (b == o+1) {
            if (q.x > LONG_MAX) {
                the_flowjob: {
                    unthrow(ERANGE, 0L);
                }
            }
            *mod = timens_NEG(&m);
            return (long) q.x;
        }
        negative_quotient: {
            if (q.x > LONG_MAX) {
                goto the_flowjob;
            }
        }
        *mod = m;
        return 0L-(long) q.x;
    }
    if (b == o+1) {
        *mod = timens_neg(&m);
        goto negative_quotient;
    }
    if (q.x > LONG_MAX) {
        goto the_flowjob;
    }
    return *mod=m, (long) q.x;
#endif
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

struct timens_locals {
    struct {
        char s[128];
    } dtostr;
};

_Thread_local struct timens_locals locals;

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

typedef struct {
    const timens_t *a;
    const timens_t *b;
    ROUND_T mode;
} round_test;

typedef struct {
    timens_t a;
    timens_t b;
    timens_t x;
    timens_t v;
} math_test;

typedef struct {
    timens_t a;
    int b;
    timens_t x;
} mul_test;

static const char *round_names[] = {
    [ROUND_CEIL] = "timens_ceil",
    [ROUND_DOWN] = "timens_floor",
    [ROUND_NEAR] = "timens_near",
    [ROUND_ZERO] = "timens_trunc",
};

static void 
timens_TEST_MUL(FILE *dst, div_t *CTR) {
    if (dst == NULL) {
        dst = stdout;
    }
    char lhs[256], res[256], req[256];

    timens_t v;
    int p_1 = 1;
    int p_2 = 2;
    int n_1 = 0-p_1;
    int n_2 = 0-p_2;
    int b_1 = BILLION-1;
    int b_2 = BILLION-2;
    mul_test *test, tests[] = {
        [0x00]={{0, 0}, 000, {000,  000}},
        [0x01]={{0, 0}, 001, {000,  000}},
        [0x02]={{0, 0}, 002, {000,  000}},
        [0x03]={{0, 0}, 0-1, {000,  000}},
        [0x04]={{0, 0}, 0-2, {000,  000}},
        [0x05]={{0, 1}, 000, {000,  000}},
        [0x06]={{0, 1}, 001, {000,  001}},
        [0x07]={{0, 1}, 002, {000,  002}},
        [0x08]={{0, 1}, 0-1, {0-1,  b_1}},
        [0x09]={{0, 1}, 0-2, {0-1,  b_2}},
        [0x0a]={{1, 0}, 000, {000,  000}},
        [0x0b]={{1, 0}, 001, {001,  000}},
        [0x0c]={{1, 0}, 002, {002,  000}},
        [0x0d]={{1, 0}, 0-1, {0-1,  000}},
        [0x0e]={{1, 0}, 0-2, {0-3,  000}},
        [0x0f]={{1, 1}, 000, {000,  000}},
        [0x10]={{1, 1}, 0+1, {0+1,  001}},
        [0x11]={{1, 1}, 0+2, {0+2,  002}},
        [0x12]={{1, 1}, 0-1, {0-2,  b_1}},
        [0x13]={{1, 1}, 0-2, {0-3,  b_2}},
    };
    for (int i=0; i < arraylen(tests); i++) {
        test = tests+i;
        assert(timens_mul(&v, &test->a, test->b));
        if (timens_eq(&v, &test->x)) {
            CTR->quot++;
        }
        else {
            assert(0 < timens_str(&test->a, lhs));
            assert(0 < timens_str(&test->x, req));
            assert(0 < timens_str(&v, res));
            fprintf(
                dst,
                "[0x%02x]<%s>×%d => <%s> (expected <%s>)\n",
                i, lhs, test->b, res, req);
        }
        CTR->rem++;
    }
}

static bool 
timens_MATH_TEST(bool k, int i, math_test *test, FILE *f, const char *s) {
    if (!k) {
        char lhs[256], rhs[256], ans[256], req[256];
        assert(0 < timens_str(&test->a, lhs));
        assert(0 < timens_str(&test->b, rhs));
        assert(0 < timens_str(&test->v, ans));
        assert(0 < timens_str(&test->x, req));
        assert(0 < fprintf(f, s, i, lhs, rhs, ans, req));
    }
    return k;
}

static void
timens_ARITHMETIC(FILE *dst, div_t *CTR) {
    if (dst == NULL) {
        dst = stdout;
    }
    const long Z = TIMENS_NSEC_MAX;
    time_t pos = 1;
    time_t neg = 0-pos;
    bool k;

    math_test 
        *test, 
        add_tests[] = {
            [0x00]={ {0*pos,0}, {0*pos,0}, {0, 0}},
            [0x01]={ {0*pos,1}, {0*pos,0}, {0, 1}},
            [0x02]={ {1*pos,0}, {0*pos,0}, {1, 0}},
            [0x03]={ {1*pos,1}, {0*pos,0}, {1, 1}},
            [0x04]={ {0*pos,0}, {0*pos,1}, {0, 1}},
            [0x05]={ {0*pos,0}, {1*pos,0}, {1, 0}},
            [0x06]={ {0*pos,0}, {1*pos,1}, {1, 1}},
            [0x07]={ {0*pos,1}, {0*pos,1}, {0, 2}},
            [0x08]={ {0*pos,1}, {0*pos,Z}, {1, 0}},
            [0x09]={ {1*pos,Z}, {0*pos,Z}, {2, Z-1}},
            [0x0a]={ {1*neg,Z}, {0*pos,1}, {0, 0}},
            [0x0b]={ {1*neg,0}, {1*pos,0}, {0, 0}},
            [0x0c]={ {1*pos,1}, {1*pos,Z}, {3, 0}},
            [0x0d]={ {1*neg,1}, {0*pos,Z}, {0, 0}},
        },
        sub_tests[] = {
            [0x00]={{0*pos,0}, {0*pos,0}, {0, 0}},
            [0x01]={{1*pos,0}, {0*pos,0}, {1, 0}},
        };
    for (int i=0; i < arraylen(add_tests); i++) {
        test = add_tests+i;
        assert(timens_add(&test->v, &test->a, &test->b));
        CTR->rem++;
        CTR->quot+=timens_MATH_TEST(
            k=timens_eq(&test->v, &test->x),
            i, test, dst,
            "[0x%02x] <%s>+<%s> => <%s> (expected <%s>)\n");
    }
    for (int i=0; i < arraylen(sub_tests); i++) {
        test = sub_tests+i;
        assert(timens_sub(&test->v, &test->a, &test->b));
        CTR->rem++;
        CTR->quot += timens_MATH_TEST(
            timens_eq(&test->v, &test->x),
            i, test, dst,
            "[0x%02x] <%s>-<%s> => <%s> (expected <%s>)\n");
    }
}

static bool
timens_round_test(FILE *out, round_test *test) {
    static char a_str[512], b_str[512], v_str[512];
    *a_str=0, *b_str=0, *v_str=0;
    timens_t v = timens_round(test->a, test->mode);
    if (timens_ne(test->b, &v)) {
        assert(timens_str(test->a, a_str) > 0);
        assert(timens_str(test->b, b_str) > 0);
        assert(timens_str(&v, v_str) > 0);
        assert(0<fprintf(out, "%s", round_names[test->mode]));
        assert(0<fprintf(out, "(<%.*s>)", (int)sizeof a_str, a_str));
        assert(0<fprintf(out, " => <%.*s>", (int) sizeof v_str, v_str));
        assert(0<fprintf(
            out, 
            " (expected <%.*s>)\n",
            (int) sizeof b_str, b_str));
        return false;
    }
    else {
        return true;
    }
}

static void 
timens_TEST_TIMEROUND(FILE *out, div_t *CTR) {
    if (out == NULL) {
        out = stdout;
    }
    timens_t a;
    timens_t b;
    timens_t x;
    char buf[512] = {0};
    const long 
        t_00=0L,
        t_01=1L,
        t_25=BILLION/4,
        t_50=t_25*2,
        t_49=t_50-1,
        t_51=t_50+1,
        t_75=t_25*3,
        t_99=BILLION-1;
    const timens_t 
        p_10_00={0+10, t_00},
        p_10_01={0+10, t_01},
        p_10_49={0+10, t_49},
        p_10_50={0+10, t_50},
        p_10_51={0+10, t_51+1},
        p_10_99={0+10, t_99},
        p_11_00={0+11, t_00},
        
        n_11_00={0-11, t_00},
        n_10_99={0-11, t_01},
        n_10_51={0-11, t_49},
        n_10_50={0-11, t_50},
        n_10_49={0-11, t_51},
        n_10_01={0-11, t_99},
        n_10_00={0-10, t_00};
    
    round_test s[] = {
        {&p_10_00, &p_10_00, ROUND_ZERO},
        {&p_10_01, &p_10_00, ROUND_ZERO},
        {&p_10_49, &p_10_00, ROUND_ZERO},
        {&p_10_50, &p_10_00, ROUND_ZERO},
        {&p_10_51, &p_10_00, ROUND_ZERO},
        {&p_10_99, &p_10_00, ROUND_ZERO},
        {&p_11_00, &p_11_00, ROUND_ZERO},
        
        {&p_10_00, &p_10_00, ROUND_NEAR},
        {&p_10_01, &p_10_00, ROUND_NEAR},
        {&p_10_49, &p_10_00, ROUND_NEAR},
        {&p_10_50, &p_11_00, ROUND_NEAR},
        {&p_10_51, &p_11_00, ROUND_NEAR},
        {&p_10_99, &p_11_00, ROUND_NEAR},
        {&p_11_00, &p_11_00, ROUND_NEAR},
        
        {&p_10_00, &p_10_00, ROUND_DOWN},
        {&p_10_01, &p_10_00, ROUND_DOWN},
        {&p_10_49, &p_10_00, ROUND_DOWN},
        {&p_10_50, &p_10_00, ROUND_DOWN},
        {&p_10_51, &p_10_00, ROUND_DOWN},
        {&p_10_99, &p_10_00, ROUND_DOWN},
        {&p_11_00, &p_11_00, ROUND_DOWN},
        
        {&p_10_00, &p_10_00, ROUND_CEIL},
        {&p_10_01, &p_11_00, ROUND_CEIL},
        {&p_10_49, &p_11_00, ROUND_CEIL},
        {&p_10_50, &p_11_00, ROUND_CEIL},
        {&p_10_51, &p_11_00, ROUND_CEIL},
        {&p_10_99, &p_11_00, ROUND_CEIL},
        {&p_11_00, &p_11_00, ROUND_CEIL},

        {&n_10_00, &n_10_00, ROUND_ZERO},
        {&n_10_01, &n_10_00, ROUND_ZERO},
        {&n_10_49, &n_10_00, ROUND_ZERO},
        {&n_10_50, &n_10_00, ROUND_ZERO},
        {&n_10_51, &n_10_00, ROUND_ZERO},
        {&n_10_99, &n_10_00, ROUND_ZERO},
        {&n_11_00, &n_11_00, ROUND_ZERO},

        {&n_10_00, &n_10_00, ROUND_DOWN},
        {&n_10_01, &n_11_00, ROUND_DOWN},
        {&n_10_49, &n_11_00, ROUND_DOWN},
        {&n_10_50, &n_11_00, ROUND_DOWN},
        {&n_10_51, &n_11_00, ROUND_DOWN},
        {&n_10_99, &n_11_00, ROUND_DOWN},
        {&n_11_00, &n_11_00, ROUND_DOWN},

        {&n_10_00, &n_10_00, ROUND_CEIL},
        {&n_10_01, &n_10_00, ROUND_CEIL},
        {&n_10_49, &n_10_00, ROUND_CEIL},
        {&n_10_50, &n_10_00, ROUND_CEIL},
        {&n_10_51, &n_10_00, ROUND_CEIL},
        {&n_10_99, &n_10_00, ROUND_CEIL},
        {&n_11_00, &n_11_00, ROUND_CEIL},

        {&n_10_00, &n_10_00, ROUND_NEAR},
        {&n_10_01, &n_10_00, ROUND_NEAR},
        {&n_10_49, &n_10_00, ROUND_NEAR},
        {&n_10_50, &n_11_00, ROUND_NEAR},
        {&n_10_51, &n_11_00, ROUND_NEAR},
        {&n_10_99, &n_11_00, ROUND_NEAR},
        {&n_11_00, &n_11_00, ROUND_NEAR},
    };
    for (int i=0; i < arraylen(s); i++) {
        CTR->quot += timens_round_test(out, s+i);
        CTR->rem++;
    }
}

static void
timens_TEST_TIME(FILE *dst, div_t *CTR) {
    if (dst == NULL) {
        dst = stdout;
    }
    assert(!errno);
    const int 
        p=1, 
        n=0-p,
        t0=0, 
        t1=1,
        t9=BILLION-1;
    
    struct time_test {
        timens_t a;
        enum TIME_UNIT t;
        time_t x;
    } 
    tests[] = {
        [0x00]={{p*59, t0}, MINUTES, 0},
        [0x01]={{p*59, t9}, MINUTES, 0},
        [0x02]={{p*60, t1}, MINUTES, 1},
        [0x03]={{p*3600}, MINUTES, 60},
        [0x04]={{p*86400}, MINUTES, 24*60},
        [0x05]={{p*86400}, HOURS, 24},
        [0x06]={{p*86400*7}, DAYS, 7},
        [0x07]={{p*86400*6, t9}, DAYS, 6},
        [0x08]={{1,15}, NANOSECONDS, BILLION+15},
        [0x09]={{0, 9}, PICOSECONDS, 9000},
        [0x0a]={timens_NEG(&(timens_t){0,9}), PICOSECONDS, 0-9000},
        [0x0b]={{0, 0000}, MICROSECONDS, MILLION*0+0},
        [0x0c]={{0, 1000}, MICROSECONDS, MILLION*0+1},
        [0x0d]={{1, 0000}, MICROSECONDS, MILLION*1+0},
        [0x0e]={{1, 2000}, MICROSECONDS, MILLION*1+2},
    };
    for (int i=0; i < arraylen(tests); i++) {
        struct time_test *test = tests+i;
        time_t v = timens_time(&test->a, test->t);
        assert(!errno);
        if (v == test->x) {
            CTR->quot++;
        }
        else {
            char str[256];
            assert(timens_str(&test->a, str)>0);
            assert(0<fprintf(
                dst,
                "[%x] timens_time(<%s>, %s) => "
                "%ji (expected %ji)\n",
                i, str, time_unit_GET_NAME(test->t),
                (intmax_t) v, (intmax_t)test->x));
        }
        CTR->rem++;
    }
}

static void 
timens_TEST_FTIMES(FILE * out, div_t *CTR) {
    assert(!errno);
    if (out == NULL) {
        out = stdout;
    }
    size_t len;
    char buf[512] = {0};
    char tmp[512];
    struct {
        const char *repr;
        bool (*call)(const timens_t *, const timens_t *);
    }   
    ml[] = {
        [CMP_LT]={u8"<", timens_lt},
        [CMP_LE]={u8"≤", timens_le},
        [CMP_EQ]={u8"=", timens_eq},
        [CMP_NE]={u8"≠", timens_ne},
        [CMP_GT]={u8">", timens_gt},
        [CMP_GE]={u8"≥", timens_ge},
    };
    
    const struct {
        int         test;
        int         unit;
        time_t      time;
        timens_t    x;
    }   
    testq[] = {
        // test          unit   time                     x
        {CMP_EQ, PICOSECONDS,   INT64_C(1000000001000), {1, 1}},
        {CMP_EQ, NANOSECONDS,   INT64_C(1000000001),    {1, 1}},
        {CMP_EQ, MICROSECONDS,  INT64_C(1000001),       {1, 1000}},
        {CMP_EQ, MILLISECONDS,  INT64_C(1001),          {1, MILLION}},
        {CMP_EQ, CENTISECONDS,  INT64_C(101),           {1, TEN*MILLION}},
        {CMP_EQ, DECISECONDS,   INT64_C(11),            {1, HUNDRED*MILLION}},
        {CMP_EQ, DECASECONDS,   INT64_C(1),             {TEN}},
        {CMP_EQ, HECTOSECONDS,  INT64_C(1),             {HUNDRED}},
        {CMP_EQ, KILOSECONDS,   INT64_C(1),             {THOUSAND}},
        {CMP_EQ, MINUTES,       INT64_C(1),             {60}},
        {CMP_EQ, HOURS,         INT64_C(1),             {3600}},
        {CMP_EQ, DAYS,          INT64_C(1),             {86400}},
        {CMP_EQ, YEARS,         INT64_C(2), {63113904}},
        {CMP_EQ, SECONDS, 0-INT64_C(2000), {0-2000}}
        
    };

    len = arraylen(testq);
    for (size_t i=0; i < len; i++) {
        CTR->rem++;
        timens_t j = {0};
        const struct time_unit *unit;
        assert(timens_units_INIT(&unit, testq[i].unit) != NULL);
        assert(timens_fromtime(  &j,    testq[i].time, testq[i].unit));
        if (ml[testq[i].test].call(&j, &testq[i].x)) {
            CTR->quot++;
            continue;
        }
        assert(timens_str(&j, buf) > 0);
        assert(timens_str(&testq[i].x, tmp) > 0);
        fprintf(
            out,
            "[0x%zx]: timens_fromtime(&j, %jd, %s) => %s\n"
            "    (expected %s)\n",
            i, 
            (intmax_t) testq[i].time, 
            unit->name,
            buf,
            tmp);
        exit(EXIT_FAILURE);
    }
    const struct ftimes_test {
        int         g;
        double      d;
        timens_t    x;
    } 
    tests[] = {
        {9, 0+0.000000000, {0}},
        {9, 0+0.000000001, timens.nanosecond.pos},
        {9, 0-0.000000001, timens.nanosecond.neg},
        {9, 0+0.000000012, {0-0,        12}},
        {9, 0+0.000000123, {0+0,       123}},
        {9, 0+0.000123000, {0-0,    123000}},
        {9, 0+0.123000000, {0+0, 123000000}},
        {9, 0-0.000000001, {0-1, BILLION-1}},
        {9, 0-0.000000012, {0-1, BILLION-12}},
        {9, 0-0.000000123, {0-1, BILLION-123}},
        {9, 0-0.000123000, {0-1, BILLION-123000}},
        {9, 0-0.123000000, {0-1, BILLION-123000000}},
        {9, 8388607.999999999, {8388607, 999999999}},
        {9, 8388607.999999998, {8388607, 999999998}},
        {9, 8388607.999999997, {8388607, 999999997}},
    };
    len = sizeof tests/sizeof *tests;
    for (size_t i=0; i < len; i++) {
        CTR->rem++;
        timens_t old_t = tests[i].x;
        double   old_d = tests[i].d;
        assert(timens_str(&old_t, buf) > 0);
        double   new_d = timens_ftime(&old_t);
        timens_t new_t = {0};
        if (errno) {
            fprintf(
                out,
                "test[%zu]:\n"
                "    timens_ftime(<%s>) threw %i\n",
                i, buf, errno), exit(EXIT_FAILURE);
        } 
        if (new_d != old_d) {
            fprintf(
                out,
                "test[%zu]:\n"
                "   expected %.9f from timens_ftime(%s)\n"
                "   not %.9f",
                i, old_d, buf, new_d), exit(EXIT_FAILURE);
        }
        assert(timens_fromftime(&new_t, new_d) != NULL);
        if (timens_eq(&new_t, &old_t)) {
            CTR->quot++;
            continue;
        }
        (void) timens_str(&new_t, tmp);
        fprintf(
            out,
            "test[%zu]:\n"
            "   btimens_fromftime(&new_t, %.9f) => <%s>\n"
            "   expected <%s>\n",
            i,  new_d, tmp, buf);
        exit(EXIT_FAILURE);
    }
}
 
static void
timens_TEST_CMP(FILE *dst, div_t *CTR) {
    char lhs[512]={0}, rhs[512]={0};
    if (dst == NULL) {
        dst = stdout;
    }
    const int X = CMP_NE;
    const timens_t 
        *pos_s = &timens.second.pos,
        *neg_s = &timens.second.neg,
        *pos_m = &timens.minute.pos,
        *neg_m = &timens.minute.neg,
        *pos_0 = &(timens_t){0},
        *uno_s = &(timens_t){1}
        ;
    struct {
        const char *op;
        bool (*call)(const timens_t *, const timens_t *);
    } 
    ml[] = {
        [CMP_LT]={u8"<", timens_lt},
        [CMP_LE]={u8"≤", timens_le},
        [CMP_EQ]={u8"=", timens_eq},
        [CMP_NE]={u8"≠", timens_ne},
        [CMP_GT]={u8">", timens_gt},
        [CMP_GE]={u8"≥", timens_ge},
    };
    
    struct {
        const timens_t *a;
        int f;
        const timens_t *b;
        bool x;
    } 
    ops[] = {
        [0x00] = {neg_s, CMP_LT, pos_s, 1},
        [0x01] = {neg_s, CMP_LE, pos_s, 1},
        [0x02] = {neg_s, CMP_EQ, pos_s, 0},
        [0x03] = {neg_s, CMP_NE, pos_s, 1},
        [0x04] = {neg_s, CMP_GT, pos_s, 0},
        [0x05] = {neg_s, CMP_GE, pos_s, 0},
     
        [0x06] = {neg_s, CMP_LT, neg_s, 0},
        [0x07] = {neg_s, CMP_LE, neg_s, 1},
        [0x08] = {neg_s, CMP_EQ, neg_s, 1},
        [0x09] = {neg_s, CMP_NE, neg_s, 0},
        [0x0a] = {neg_s, CMP_GT, neg_s, 0},
        [0x0b] = {neg_s, CMP_GE, neg_s, 1},
        
        [0x0c] = {pos_s, CMP_LT, pos_s, 0},
        [0x0d] = {pos_s, CMP_LE, pos_s, 1},
        [0x0e] = {pos_s, CMP_EQ, pos_s, 1},
        [0x0f] = {pos_s, CMP_NE, pos_s, 0},
        [0x10] = {pos_s,  CMP_GT, pos_s, 0},
        [0x11] = {pos_s,  CMP_GE, pos_s, 1},
        
        [0x12] = {pos_s,  CMP_LT, pos_m, 1},
        [0x13] = {pos_s,  CMP_LE, pos_m, 1},
        [0x14] = {pos_s,  CMP_EQ, pos_m, 0},
        [0x15] = {pos_s,  CMP_NE, pos_m, 1},
        [0x16] = {pos_s,  CMP_GT, pos_m, 0},
        [0x17] = {pos_s,  CMP_GE, pos_m, 0},
        
        [0x18] = {pos_s,  CMP_LT, uno_s, 0},
        [0x19] = {pos_s,  CMP_LE, uno_s, 1},
        [0x1a] = {pos_s,  CMP_EQ, uno_s, 1},
        [0x1b] = {pos_s,  CMP_NE, uno_s, 0},
        [0x1c] = {pos_s,  CMP_GT, uno_s, 0},
        [0x1d] = {pos_s,  CMP_GE, uno_s, 1},

        [0x1e] = {&timens.nanosecond.pos, X,&(timens_t){0-0,ONE}},
        [0x1f] = {&timens.nanosecond.neg, X,&(timens_t){0-1,BILLION-ONE}},

        [0x20] = {&timens.microsecond.pos,X,&(timens_t){0-0,THOUSAND}},
        [0x21] = {&timens.microsecond.neg,X,&(timens_t){0-1,BILLION-THOUSAND}},
    
        [0x22] = {&timens.millisecond.pos,X,&(timens_t){0-0,MILLION}},
        [0x23] = {&timens.millisecond.neg,X,&(timens_t){0-1,BILLION-MILLION}},

        [0x24] = {&timens.centisecond.pos,X,&(timens_t){0-0,10000000}},
        [0x25] = {&timens.centisecond.neg,X,&(timens_t){0-1,990000000}},

        [0x26] = {&timens.decisecond.pos, X,&(timens_t){0-0,100000000}},
        [0x27] = {&timens.decisecond.neg, X,&(timens_t){0-1,900000000}},

        [0x28] = {&timens.decasecond.pos, X,&(timens_t){TEN}},
        [0x29] = {&timens.decasecond.neg, X,&(timens_t){0-TEN}},

        [0x2a] = {&timens.hectosecond.pos,X,&(timens_t){HUNDRED}},
        [0x2b] = {&timens.hectosecond.neg,X,&(timens_t){0-HUNDRED}},

        [0x2c] = {&timens.kilosecond.pos, X,&(timens_t){THOUSAND}},
        [0x2d] = {&timens.kilosecond.neg, X,&(timens_t){0-THOUSAND}},

        [0x2e] = {&timens.megasecond.pos, X,&(timens_t){MILLION}},
        [0x2f] = {&timens.megasecond.neg, X,&(timens_t){0-MILLION}},

        [0x30] = {&timens.gigasecond.pos, X,&(timens_t){BILLION}},
        [0x31] = {&timens.gigasecond.neg, X,&(timens_t){0-BILLION}},

        [0x32] = {&timens.petasecond.pos, X,&(timens_t){QUADRILLION}},
        [0x33] = {&timens.petasecond.neg, X,&(timens_t){0-QUADRILLION}},

        [0x34] = {&timens.terasecond.pos, X,&(timens_t){TRILLION}},
        [0x35] = {&timens.terasecond.neg, X,&(timens_t){0-TRILLION}},

        [0x36] = {&timens.exasecond.pos,  X,&(timens_t){QUINTILLION}},
        [0x37] = {&timens.exasecond.neg,  X,&(timens_t){0-QUINTILLION}},

        {0},
    };

    for (int i=0; i < (sizeof ops/sizeof *ops) ; i++) {
        const timens_t *a = ops[i].a;
        const timens_t *b = ops[i].b;
        int op = ops[i].f;
        bool r = ml[op].call(a, b);
        if (r == ops[i].x) {
            CTR->quot++;
        }
        else {
            (void) timens_str(a, lhs);
            (void) timens_str(b, rhs);
            (void) assert(0 < fprintf(
                dst,
                "test[0x%x]:\n"
                "    {%s} %s {%s>} => %d\n"
                "    (expected %d)\n",
                i,
                lhs, ml[op].op, rhs, r, 
                ops[i].x));
        }
        CTR->rem++;
    }
}

static void
timens_TEST_SIGNEDNESS(FILE *dst, div_t *CTR) {
    if (dst == NULL) {
        dst = stdout;
    }
    char a_str[256]={0}, b_str[256], v_str[256];
    const long 
        l_000=0,
        l_001=1,
        l_999=BILLION-1;
    const time_t 
        p_000=0,
        p_001=1,
        n_001=0-1,
        n_002=0-2;
    struct negatest {
        timens_t a;
        timens_t b;
    } tests[] = {
        [0]={{p_000, l_000}, {p_000, l_000}},
        [1]={{p_000, l_001}, {n_001, l_999}},
        [2]={{p_001, l_000}, {n_001, l_000}},
        [3]={{p_001, l_001}, {n_002, l_999}},
        [4]={{n_001, l_999}, {p_000, l_001}},
        [5]={{n_001, l_000}, {p_001, l_000}},
        [6]={{n_002, l_999}, {p_001, l_001}},
    };
    for (int i=0; i < arraylen(tests); i++) {
        struct negatest *test = tests+i;
        timens_t v;
        assert(timens_ineg(&v, &test->a) == &v);
        if (timens_ne(&v, &test->b)) {
            assert(timens_str(&test->a, a_str) > 0);
            assert(timens_str(&test->b, b_str) > 0);
            assert(timens_str(      &v, v_str) > 0);
            assert(fprintf(
                dst,
                "[%i] timens_ineg(&v, &<%s>) => <%s>, not <%s>\n",
                i,
                a_str, b_str, v_str) > 0);
        }
        else {
            timens_t j = timens_neg(&v);
            assert(timens_eq(&j, &test->a));
            CTR->quot++;
        }
        CTR->rem++;
    }
}

int main(void) {
    errno = 0;
    
    char lhs[512] = {0};
    char rhs[512] = {0};
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
    volatile int a = 1;
    volatile int b = 60;
    volatile _Bool t = 1;
    volatile _Bool f = 0;
    div_t CTR = {0};
    if (1) {
        timens_ARITHMETIC(0, &CTR);
    }
    if (1) {
        timens_TEST_MUL(0, &CTR);
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

2,0,5
9

0
2,2
  0
  2,2
  
*/
