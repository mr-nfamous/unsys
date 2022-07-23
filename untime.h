
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */


/*
timens_t is used to store a duration of time between 
TIMENS_SEC_MIN (INT64_C(-1152921504606846975)) and
TIMENS_SEC_MAX (INT64_C(+1152921504606846975)) 
seconds at nanosecond precision. For example, the
maximum valid value is:
    (timens_t){
        .tv_sec=TIMENS_SEC_MAX,
        .tv_nsec=999'999'999,
    }
which, if used as the number of seconds since the 
epoch, represents a date in the year 36'534'628'078 
of the Gregorian calendar.

The following symbolic constants are defined:
    TIMENS_NEG          {-1, 999'999'999}
    TIMENS_NIL          {+0, 0}
    TIMENS_NANOSECOND   {+0, 1}
    TIMENS_MICROSECOND  {+0, 1'000}
    TIMENS_MILLISECOND  {+0, 1'000'000}
    TIMENS_SECOND       {+1, 0}
    TIMENS_MINUTE       {+60, 0}
    TIMENS_HOUR         {+3600, 0}
    TIMENS_DAY          {+86400, 0}
    TIMENS_WEEK         {+604800, 0}
    TIMENS_MIN          {TIMENS_NSEC_MIN, 0}
    TIMENS_MAX          {TIMENS_NSEC_MAX, 999'999'999}
   
The following standard operations are supported:
    lt(a, b):   a < b 
    le(a, b):   a <= b 
    eq(a, b):   a == b
    ne(a, b):   a != b
    gt(a, b):   a > b
    ge(a, b):   a >= b

    not(*v) => bool:
        Return true if a duration is zero

    is(*v) => bool:  
        Return true if a duration is nonzero 

    ok(*v) => bool:
        Return true if a duration has a valid memory
        representation
        
    cmp(a, b)
    pos(v, t):      v = +t
    neg(v, t):      v = -t
    abs(v, t):      v = t < 0 ? -t : +t
    inc(t):         ++t->tv_nsec
    dec(t):         --t->tv_nsec
    add(v, a, b):   v = a+b
    sub(v, a, b):   v = a-b
    mul(v, a, b):   v = a*b
    mod(v, a, b):   v = a%b
    lmod(v, a, b):  v = fromnsec(ldiv(T(a), b).rem)
    div(v, a, b):   v = a/b
    ldiv(v[2], *a, b):
        v[0] = a/b 
        v[1] = a%b

    fdiv(a, b):     a/b

The following constructors are provided:

    fromargs(*v, name, ...):
        Initialize v to a duration computed as in the
        following example:
            timens_fromargs(
                &v,
                hours,          5,
                milliseconds,   999,
                seconds,        59)
        Optional parameters are: weeks, days, hours,
        minutes, milliseconds, microseconds, and 
        nanoseconds, all of which are interpreted as 
        unsigned int.
        The "seconds" parameter, which is interpreted as 
        a signed int, is not optional. The sign of seconds
        is the sign of the result
        
        and must be specified last
            weeks, 
                
        s is an int representing the number of seconds
        int s seconds and you modify
        this
        duration obtained by 
        computing the sum of a variable number of
        
        Initialize duration v with the number of 
        seconds specified in the int s 
        from an int representing the 
        number of seconds in the dur plus the sum of durations 
        specified in the variable arguments list
        in the form exe
    fromsec(*v, t) => v:
        Initialize v from t, a number of seconds.

    frommsec(*v, t) => v:
        Initialize v from t, a number of milliseconds.

    fromusec(*v, t) => v:
        Initialize v from t, a number of microseconds.

    fromnsec(*v, t) => v:
        Initialize v from t, a number of nanoseconds 

    fromfsec(*v, t) => v:
        Initialize v from t, a number of seconds

    fromtm(*v, t) => v:
        Initialize v from t, a struct tm.

*/

#pragma once

#include <math.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <time.h>

#include "unstddef.h"
#include "unint.h"
#include "unerror.h"
#include "unopcode.h"


typedef struct timespec timens_t;
typedef struct timeval  timeus_t;

typedef long double ftime_t;

#define TIMENS_NSEC_MIN     (000000000L)
#define TIMENS_NSEC_MAX     (999999999L)
#define TIMENS_NSEC_UNDERFLOW (TIMENS_NSEC_MIN-1)
#define TIMENS_NSEC_OVERFLOW (TIMENS_NSEC_MIN-2)

#define TIMENS_SEC_MIN (INT64_C(0)-INT64_C(1152921504606846975))
#define TIMENS_SEC_MAX INT64_C(1152921504606846975)
#define TIMENS_SEC_UNDERFLOW (TIMENS_NSEC_MIN-1)
#define TIMENS_SEC_OVERFLOW (TIMENS_SEC_MIN-2)

/* 
timens_fromfsec is constrained to the range of
inputs i for which (j=i+1, j-i==1) is true. This
is still wide enough to represent ±280My on the
Gregorian calendar...
*/
#define TIMENS_FSEC_MIN     (0.0-(1LL<<53))
#define TIMENS_FSEC_MAX     (0.0-(1LL<<53))

#define TIMENS_NANOSECOND   (&timens.t_nanosecond)
#define TIMENS_MICROSECOND  (&timens.t_microsecond)
#define TIMENS_MILLISECOND  (&timens.t_millisecond)
#define TIMENS_SECOND       (&timens.t_second)
#define TIMENS_MINUTE       (&timens.t_minute)
#define TIMENS_HOUR         (&timens.t_hour)
#define TIMENS_DAY          (&timens.t_day)
#define TIMENS_WEEK         (&timens.t_week)
#define TIMENS_FORTNIGHT    (&timens.t_fortnight)
#define TIMENS_MIN          (&timens.t_min)
#define TIMENS_MAX          (&timens.t_max)
#define TIMENS_NIL          (&timens.t_nil)
#define TIMENS_NEG          (&timens.t_neg)

bool timens_lt(const timens_t *, const timens_t *);
bool timens_le(const timens_t *, const timens_t *);
bool timens_eq(const timens_t *, const timens_t *);
bool timens_ne(const timens_t *, const timens_t *);
bool timens_gt(const timens_t *, const timens_t *);
bool timens_ge(const timens_t *, const timens_t *);
bool timens_is(const timens_t *);
bool timens_ok(const timens_t *);
bool timens_ae(const timens_t *, const timens_t *);
bool timens_not(const timens_t *);

int timens_repr(const timens_t *, FILE *, const char *);
int timens_cmp(const timens_t *, const timens_t *);
int timens_sgn(timens_t *, const timens_t *);

timens_t *timens_pos(timens_t *, const timens_t *);
timens_t *timens_neg(timens_t *, const timens_t *);
timens_t *timens_abs(timens_t *, const timens_t *);

timens_t *timens_add(timens_t *, const timens_t *, const timens_t *);
timens_t *timens_sub(timens_t *, const timens_t *, const timens_t *);
timens_t *timens_mul(timens_t *, const timens_t *, long);
timens_t *timens_mod(timens_t *, const timens_t *, const timens_t *);
timens_t *timens_lmod(timens_t *, const timens_t *, long);
long      timens_div(timens_t *, const timens_t *, const timens_t *);
ldouble_t timens_fdiv(const timens_t *, const timens_t *);
timens_t *timens_ldiv(timens_t[2], const timens_t *, long);

timens_t *timens_inc(timens_t *);
timens_t *timens_dec(timens_t *);
timens_t *timens_init(timens_t *, time_t, long);
timens_t *timens_fromkw(timens_t *, ...);
timens_t *timens_fromsec (timens_t *, time_t);
timens_t *timens_frommsec(timens_t *, time_t);
timens_t *timens_fromusec(timens_t *, time_t);
timens_t *timens_fromnsec(timens_t *, time_t);
timens_t *timens_fromfsec(timens_t *, ftime_t);

static inline bool
timens_OK(const timens_t *const t) {
    return (TIMENS_NSEC_MIN <= t->tv_nsec)
        && (TIMENS_NSEC_MAX >= t->tv_nsec)
        && (TIMENS_SEC_MIN <= t->tv_sec)
        && (TIMENS_SEC_MAX >= t->tv_sec);
}

static inline bool
timens_IS(const timens_t *const t) {
    return t->tv_sec || t->tv_nsec;
}

static inline timens_t
timens_FROMFSEC(ftime_t s) {
    ftime_t  ns;
    timens_t t;
    if (s < 0.0L) {
        ns = modfl(0.L-s, &s);
        t.tv_nsec = ns ? ((long) (TIMENS_SEC_MAX*(1.L-ns))) : 0L;
    }
    else {
        ns = modfl(s, &s);
        t.tv_nsec = ns ? ((long) (TIMENS_SEC_MIN*ns)) : 0L;
    }
    t.tv_sec = (time_t) s;
    return t;
}

static inline timens_t
timens_NEG_TO_POS_1(const timens_t *restrict const t) {
    return (timens_t){
        .tv_sec=INT64_C(0)-(t->tv_sec+INT64_C(1)),
        .tv_nsec=1000000000L-t->tv_nsec,
    };
}

static inline timens_t
timens_NEG_TO_POS_0(const timens_t *restrict const t) {
    return (timens_t){
        .tv_sec=INT64_C(0)-t->tv_sec,
        .tv_nsec=0L,
    };
}

static inline timens_t
timens_POS_TO_NEG_1(const timens_t *restrict const t) {
    return (timens_t){
        .tv_sec=(INT64_C(0)-INT64_C(1))-t->tv_sec,
        .tv_nsec=1000000000L-t->tv_nsec,
    };
}

static inline timens_t
timens_POS_TO_NEG_0(const timens_t *restrict const t) {
    return (timens_t){
        .tv_sec=(INT64_C(0)-INT64_C(1))-t->tv_sec,
        .tv_nsec=0L,
    };
}

static inline timens_t
timens_NEG_NSEC_1(const timens_t *t) {
    return (timens_t){
        .tv_sec=(INT64_C(0)-INT64_C(1))-t->tv_sec,
        .tv_nsec=(TIMENS_NSEC_MAX+1L)-t->tv_nsec,
    };
}

static inline timens_t
timens_NEG_NSEC_0(const timens_t *t) {
    return (timens_t){
        .tv_sec=INT64_C(0)-t->tv_sec,
        .tv_nsec=0L,
    };
}

static inline timens_t
timens_NEG(const timens_t *const t) {
    return ((t->tv_nsec)
        ?   timens_NEG_NSEC_1 
        :   timens_NEG_NSEC_0)(t);
}


static inline timens_t *
timens_FRAC_INIT(timens_t *v, time_t t, time_t d, long m) {
    imaxdiv_t x;
    if (t < 0) {
        x = imaxdiv(INTMAX_C(0)-t, d);
        if (x.rem) {
            if (x.quot-- > TIMENS_SEC_MAX) {
                goto fail;
            }
            *v = (timens_t){
                .tv_sec=(time_t) 0-x.quot,
                .tv_nsec=(long) ((TIMENS_NSEC_MAX+1)-x.rem)*m,
            };
        }
        else {
            if (x.quot > TIMENS_SEC_MAX) {
                goto fail;
            }
            *v = (timens_t){
                .tv_sec=(time_t) 0-x.quot,
                .tv_nsec=0L,
            };
        }
    }
    else {
        x = imaxdiv(t, d);
        if (x.quot > TIMENS_SEC_MAX) {
            goto fail;
        }
        *v = (timens_t){
            .tv_sec=(time_t) x.quot,
            .tv_nsec=(long) x.rem*m,
        };
    }
    return v;
    fail: {
        errno = ERANGE;
        return NULL;
    }
}

union timens_tm {
    int t_list[9];
    struct {
        int t_seconds;      // 0
        int t_nanoseconds;  // 1
        int t_microseconds; // 2
        int t_milliseconds; // 3

        int t_minutes;      // 4
        int t_hours;        // 5
        int t_days;         // 6
        int t_weeks;        // 7

        int t_neg;          // 8
    };
};

enum {
    t_seconds,
    t_nanoseconds,
    t_microseconds,
    t_milliseconds,
    t_minutes,
    t_hours,
    t_days,
    t_weeks,
    t_neg,
    t_nil,
    t_min,
    t_max,
};

struct timens {
    union {
        struct {
            timens_t t_second;      // 1
            timens_t t_nanosecond;  // 2
            timens_t t_microsecond; // 3
            timens_t t_millisecond; // 4
            timens_t t_minute;      // 5
            timens_t t_hour;        // 6
            timens_t t_day;         // 7
            timens_t t_week;        // 8
            timens_t t_fortnight;   // 9
            timens_t t_nil;         // 10
            timens_t t_min;         // 11
            timens_t t_max;         // 12
            timens_t t_neg;         // 13
        };
        timens_t t_list[13];
    };
    union {
        void       *ops[sizeof(oplist_t)/sizeof(void *)];
        oplist_t    op;
    };
    /*
    bool
        (*lt)   (const timens_t *, const timens_t *),
        (*le)   (const timens_t *, const timens_t *),
        (*eq)   (const timens_t *, const timens_t *),
        (*ne)   (const timens_t *, const timens_t *),
        (*gt)   (const timens_t *, const timens_t *),
        (*ge)   (const timens_t *, const timens_t *),
        (*bint) (const timens_t *);
    int
        (*cmp)  (const timens_t *, const timens_t *),
        (*sgn)  (timens_t *, const timens_t *);
    timens_t *
        (*abs)      (timens_t *, const timens_t *),
        (*pos)      (timens_t *, const timens_t *),
        (*neg)      (timens_t *, const timens_t *),
        (*add)      (timens_t *, const timens_t *, const timens_t *),
        (*sub)      (timens_t *, const timens_t *, const timens_t *),
        (*mod)      (timens_t *, const timens_t *, const timens_t *),
        (*mul)      (timens_t *, const timens_t *, long),
        (*fromsec)  (timens_t *, time_t),
        (*fromnsec) (timens_t *, time_t),
        (*fromusec) (timens_t *, time_t),
        (*frommsec) (timens_t *, time_t),
        (*fromfsec) (timens_t *, ldouble_t);
    long
        (*div)(timens_t *, const timens_t *, const timens_t *);
    long double 
        (*fdiv)(const timens_t *, const timens_t *);
*/
};
/*
timens_t *
timens_lmul(timens_t *v, const timens_t *a, long b) {
    int128_t i  = (int128_t) a->tv_nsec+ONE_BILLION*a->tv_sec;
    i *= b;
    v->tv_nsec  = (long) (i%ONE_BILLION);
    v->tv_sec   = (time_t) (i/ONE_BILLION);
    return v;
}

timens_t *
timens_fmul(timens_t *v, const timens_t *a, double b) {
    long double i = 1e+9L*a->tv_sec+a->tv_nsec;
    i *= b;
    return v;
}
*/