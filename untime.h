
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳   

The timens_t type uses the same layout as the timespec 
struct to represent any specific nanosecond over any 
±36 billion year interval.

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
   
   
    T_SECOND
    T_MINUTE
    T_HOUR
    T_DAY
    T_WEEK
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

 -{+0,   1} => {-1, 999}
 -{+0, 999} => {-1,   1}
 -{+1,   0} => {-1,   0}

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

typedef struct timeval  timeus_t;
typedef struct timespec timens_t;


#define TIMENS_NSEC_MIN         (000000000L)
#define TIMENS_NSEC_MAX         (999999999L)
#define TIMENS_NSEC_UNDERFLOW   (TIMENS_NSEC_MIN-1)
#define TIMENS_NSEC_OVERFLOW    (TIMENS_NSEC_MIN-2)

#define TIMENS_SEC_MAX    INT64_C(1152921504606846975)
#define TIMENS_SEC_MIN (0-INT64_C(1152921504606846976))

#define TIMENS_SEC_UNDERFLOW (TIMENS_NSEC_MIN-1)
#define TIMENS_SEC_OVERFLOW  (TIMENS_SEC_MIN-2)

#define TIMENS_NANOSECOND   (&timens.t_nanosecond)
#define TIMENS_MICROSECOND  (&timens.t_microsecond)
#define TIMENS_MILLISECOND  (&timens.t_millisecond)
#define TIMENS_SECOND       (&timens.t_second)
#define TIMENS_MINUTE       (&timens.t_minute)
#define TIMENS_HOUR         (&timens.t_hour)
#define TIMENS_DAY          (&timens.t_day)
#define TIMENS_WEEK         (&timens.t_week)
#define TIMENS_MINIMUM      (&timens.t_minumum)
#define TIMENS_MAXIMUM      (&timens.t_maximum)
#define TIMENS_NIL          (&timens.t_nil)
#define TIMENS_NEG          (&timens.t_neg)

static const double TIMENS_FTIMES[] = {
/* 
    timens_fromftime initializes the timens object with 
    the integer part of a IEEE 754-2008 binary64 format
    C double as the tv_sec field and the fraction part 
    as the tv_nsec field. Durations between ±8388607s 
    can be represented with full precision. This is
    just shy of 97 days, far longer than needed for many
    uses of high resolution time measurements.

    Therefore, the recommended way to initialize timeouts 
    on the scale of 1 nanosecond to one day is to use 
    timens_fromftime (or timens_FROMFTIME) with a double
    literal like 0.001 for 1 millisecond. These are 
    particularly handy for negative durations, which are
    annoying to mentally compute.
    
    The following tables are used by the aforementioned 
    routines to guarantee that precision is maintained
    without sacrificing speed.
*/

    [ 0]=1e9, [ 1]=1e9, [ 2]=1e9, [ 3]=1e9, [ 4]=1e9,
    [ 5]=1e9, [ 6]=1e9, [ 7]=1e9, [ 8]=1e9, [ 9]=1e9,
    [10]=1e9, [11]=1e9, [12]=1e9, [13]=1e9, [14]=1e9,
    [15]=1e9, [16]=1e9, [17]=1e9, [18]=1e9, [19]=1e9,
    [20]=1e9, [21]=1e9, [22]=1e9, [23]=1e9, [24]=1e8,
    [25]=1e8, [26]=1e8, [27]=1e7, [28]=1e7, [29]=1e7,
    [30]=1e6, [31]=1e6, [32]=1e6, [33]=1e6, [34]=1e5,
    [35]=1e5, [36]=1e5, [37]=1e4, [38]=1e4, [39]=1e4,
    [40]=1e3, [41]=1e3, [42]=1e3, [43]=1e3, [44]=1e2,
    [45]=1e2, [46]=1e2, [47]=1e1, [48]=1e1, [49]=1e1,
    [50]=1.0, [51]=1.0, [52]=1.0, [53]=1.0, [54]=0.5,
    [55]=0.5, [56]=0.5, [57]=0.5, [58]=0.5, [59]=0.5,
    [60]=0.5, [61]=0.5, [62]=0.5, [63]=0.5, [64]=0.5,
#   define TIMENS_FSEC_MIN     ((double) TIMENS_SEC_MIN)
#   define TIMENS_FSEC_MAX     ((double) TIMENS_SEC_MAX)
};

static const int TIMENS_FTIMENS[] = {
    [ 0]=1,   [ 1]=1,   [ 2]=1,   [ 3]=1,   [ 4]=1,
    [ 5]=1,   [ 6]=1,   [ 7]=1,   [ 8]=1,   [ 9]=1,
    [10]=1,   [11]=1,   [12]=1,   [13]=1,   [14]=1,
    [15]=1,   [16]=1,   [17]=1,   [18]=1,   [19]=1,
    [20]=1,   [21]=1,   [22]=1,   [23]=1,   [24]=1e1,
    [25]=1e1, [26]=1e1, [27]=1e2, [28]=1e2, [29]=1e2,
    [30]=1e3, [31]=1e3, [32]=1e3, [33]=1e3, [34]=1e4,
    [35]=1e4, [36]=1e4, [37]=1e5, [38]=1e5, [39]=1e5,
    [40]=1e6, [41]=1e6, [42]=1e6, [43]=1e6, [44]=1e7,
    [45]=1e7, [46]=1e7, [47]=1e8, [48]=1e8, [49]=1e8,
};

static const unsigned char TIMENS_FTIME_NDIGIT[]={
    [ 0]=9, [ 1]=9, [ 2]=9, [ 3]=9, [ 4]=9,
    [ 5]=9, [ 6]=9, [ 7]=9, [ 8]=9, [ 9]=9,
    [10]=9, [11]=9, [12]=9, [13]=9, [14]=9,
    [15]=9, [16]=9, [17]=9, [18]=9, [19]=9,
    [20]=9, [21]=9, [22]=9, [23]=9, [24]=8,
    [25]=8, [26]=8, [27]=7, [28]=7, [29]=7,
    [30]=6, [31]=6, [32]=6, [33]=6, [34]=5,
    [35]=5, [36]=5, [37]=4, [38]=4, [39]=4,
    [40]=3, [41]=3, [42]=3, [43]=3, [44]=2,
    [45]=2, [46]=2, [47]=1, [48]=1, [49]=1,
    [64]=0,
};

/* Zero (re)initialize obj.tv_sec && obj.tv_nsec */
timens_t *
timens_clr(timens_t *restrict obj);

/* Store absolute value of obj at dst */
timens_t *
timens_abs (timens_t *restrict dst, const timens_t *obj);

/* Store copy of obj at dst then increment dst.tv_sec */
timens_t *
timens_inc (timens_t *restrict dst, const timens_t *obj);

/* Store copy of obj at dst then decrement dst.tv_sec */
timens_t *
timens_dec (timens_t *restrict dst, const timens_t *obj);

/* Implement ++obj (which increments obj.tv_sec) */
timens_t *
timens_iinc(timens_t *restrict obj);

/* Implement --obj (which decrements obj.tv_sec) */
timens_t *
timens_idec(timens_t *restrict obj);

/* Implement iabs(obj) */
timens_t *
timens_iabs(timens_t *restrict obj);

/* Implement ineg(obj) */ 
timens_t *
timens_ineg(timens_t *restrict obj);

/* Implement dst = -obj */
timens_t *
timens_neg(timens_t *restrict dst, const timens_t *obj);

/* Implement dst = +obj */
timens_t *
timens_pos(timens_t *restrict dst, const timens_t *obj);

/* (re)initialize obj */
timens_t *
timens_init(timens_t *restrict, time_t, long);

/* Initialize obj with the normalized duration obtained
by multiplying the 64 bit signed integer n by the 
multiplier associated with the unit specified as base. 

E.g. the following initializes var to T+0.000000150s
    fromtime(&var, 150, T_NANOSECOND) 

while this initializes var to T-13m
    fromtime(&var, 0-13, T_MINUTE)*/
timens_t *
timens_fromtime(timens_t *restrict obj, time_t n, int b);

/* Total ordering */
timens_t *
timens_fromftime(timens_t *restrict, double);

/* Implement a < b */
bool 
timens_lt(const timens_t *, const timens_t *);

/* Implement a ≤ b */
bool 
timens_le(const timens_t *, const timens_t *);

/* Implement a = b */
bool 
timens_eq(const timens_t *, const timens_t *);

/* Implement a ≠ b */
bool 
timens_ne(const timens_t *, const timens_t *);

/* Implement a > b */
bool 
timens_gt(const timens_t *, const timens_t *);

/* Implement a ≥ b */
bool 
timens_ge(const timens_t *, const timens_t *);

/* Implement a ≈ b */
bool 
timens_ae(const timens_t *, const timens_t *);

/* Implement the "ok" protocol
    If 0 <= obj && obj <= type(obj).MAX, return +1 
    If 0 >  obj && obj >  type(obj).MIN, return -1 
    Otherwise, if 0 is returned obj is invalid. 
*/
int  timens_ok(const timens_t *);

/* Implement !obj */
bool timens_not(const timens_t *);

/* "print" the ISO-8859-1 representation of obj to dst */
int timens_repr(const timens_t *, FILE *, const char *);

/* Implements the cmp protocol */
int timens_cmp(const timens_t *, const timens_t *);

/* Implements the sgn protocol */
int timens_sgn(timens_t *, const timens_t *);

/* Convert obj to a ISO-8601 duration string */
ptrdiff_t 
timens_str(const timens_t *restrict, char[restrict]);

/* Implement the ceil rounding protocol*/
timens_t *
timens_ceil (timens_t *, const timens_t *);

/* Implement the nextafter rounding protocol */
timens_t *
timens_next (timens_t *, const timens_t *);

/* Implement the nearby rounding protocol */
timens_t *
timens_near (timens_t *, const timens_t *);

/* Implement the floor rounding protocol */ 
timens_t *
timens_floor(timens_t *, const timens_t *);

/* Implement the trunc rounding protocol */
timens_t *
timens_trunc(timens_t *, const timens_t *);

timens_t *
timens_round(timens_t *, const timens_t *, ROUND_TO_T);

/* Convert obj to time_t */
time_t timens_time(const timens_t *);

/* Convert obj to a double */
double timens_ftime(const timens_t *);

/* Implement Duration<timens_t> + Duration<timens_t> */
timens_t *
timens_add(timens_t *restrict, const timens_t *, const timens_t *);

/* Implement Duration<timens_t> + Duration<double> */
timens_t *
timens_fadd(timens_t *restrict, const timens_t *, double);

/* Implement Duration<timens_t> + Duration<long> */
timens_t *
timens_ladd(timens_t *restrict, const timens_t *, long);

/* Implement Duration<timens_t> += Duration<timens_t> */
timens_t *
timens_iadd (timens_t *restrict, const timens_t *);

/* Implement Duration<timens_t> += Duration<double> */
timens_t *
timens_ifadd(timens_t *restrict, double);

/* Implement Duration<timens_t> += Duration<long> */
timens_t *
timens_iladd(timens_t *restrict, long);

/* Duration subtraction */
timens_t *
timens_sub  (timens_t *restrict, const timens_t *, const timens_t *);

timens_t *
timens_fsub (timens_t *restrict, const timens_t *, double);

timens_t *
timens_lsub (timens_t *restrict, const timens_t *, long);

timens_t *
timens_isub (timens_t *restrict, const timens_t *);

timens_t *
timens_ifsub(timens_t *restrict, double);

timens_t *
timens_ilsub(timens_t *restrict, long);

/* Duration multiplication */
timens_t *
timens_mul (timens_t *restrict, const timens_t *, long);

timens_t *
timens_imul(timens_t *restrict, long);

timens_t *
timens_fmul(timens_t *restrict, const timens_t *, double);

timens_t *
timens_ifmul(timens_t *, double);

/* Duration division 
    (T+1m) ÷ +7     == (+7) × (T+8s) % (T+4s) 
    (T+1m) ÷ (T+8s) == (+7) × (T+8s) % (T+4s)
    
*/
timens_t *
timens_mod(timens_t *restrict, const timens_t *, const timens_t *);

timens_t *
timens_lmod(timens_t *restrict, const timens_t *, long);

long      
timens_div (timens_t *restrict, const timens_t *, const timens_t *);

timens_t *
timens_fdiv(timens_t[restrict], const timens_t *, double);

timens_t *
timens_ldiv(timens_t[restrict], const timens_t *, long);

long
timens_idiv(timens_t *, const timens_t *);

timens_t *
timens_ifdiv(timens_t *, double);


static inline bool
timens_SEC_OK(time_t t) {
    return (TIMENS_SEC_MIN <= t) && (t <= TIMENS_SEC_MAX);
}

static inline bool
timens_NSEC_OK(long t) {
    return (TIMENS_NSEC_MIN <= t) && (t <= TIMENS_NSEC_MAX);
}

static inline int
timens_OK(const timens_t *const t) {
    if ((t->tv_nsec < TIMENS_NSEC_MIN) || (t->tv_nsec > TIMENS_NSEC_MAX)) {
        return 0;
    }
    if (t->tv_sec < 0) {
        return t->tv_sec < TIMENS_SEC_MIN ? 0 : 0-1;
    }
    else {
        return t->tv_sec > TIMENS_SEC_MAX ? 0 : 0+1;
    }
}

static inline bool
timens_IS(const timens_t *const t) {
    return t->tv_sec || t->tv_nsec;
}

/*
static inline timens_t
timens_FROMFSEC(double s) {
    double  ns;
    timens_t t;
    if (s < 0.0) {
        ns = modf(0.0-s, &s);
        if (ns) {
            t.tv_nsec = (long) ((TIMENS_NSEC_MAX+1)*(1.0-ns));
        }
        else {
            t.tv_nsec = 0L;
        }
    }
    else {
        ns = modf(s, &s);
        if (ns) {
            t.tv_nsec = (long) ((TIMENS_NSEC_MAX+1)*ns);
        }
        else {
            t.tv_nsec = 0L;
        }
    }
    return t.tv_sec=(time_t) s, t;
}
*/

static inline timens_t *
timens_INIT(timens_t *t, time_t tv_sec, long tv_nsec) {
    *t = (timens_t){
        .tv_sec=tv_sec,
        .tv_nsec_tv_nsec,
    };
    return t;
}

static inline timens_t 
timens_FROMUTIME(time_t tv_usec) {
    imaxdiv_t p;
    if (tv_usec < 0) {
        p = imaxdiv(INTMAX_C(0)-tv_usec, INTMAX_C(1000000));
        if (p.rem) {
            return (timens_t){
                .tv_sec = (time_t)((0-1)-p.quot),
                .tv_nsec = (long) ((1000000-p.rem)*1000),
            };
        }
        return (timens_t){
            .tv_sec = (time_t) (0-p.quot),
        };
    }
    p = imaxdiv(tv_usec, INTMAX_C(1000000));
    return (timens_t){
        .tv_sec=(time_t) p.quot,
        .tv_nsec=(long) (p.rem*1000)
    };
}

static inline timens_t
timens_FROMFTIME(double s) {
    double i;
    timens_t t;
    if (s < 0.0) {
        double p = modf(0.0-s, &i);
        t.tv_sec = 0-((time_t) i);
        t.tv_nsec = p ? BILLION-(long) (p*BILLION) : 0L;
    }
    else {
        t.tv_nsec = (long) (BILLION*modf(s, &i));
        t.tv_sec = (time_t) i;
    }
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

static inline int
timens_SGN(timens_t *v, const timens_t *t) {
    const int ok = timens_OK(t);
    if (ok) {
        *v = ok < 0 ? timens_NEG(t): *t;
    }
    return ok;
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

static inline timens_t
timens_INC(const timens_t *t) {
    timens_t r = *t;
    if (r.tv_sec == INT64_C(0)-1) {
        if (r.tv_nsec) {
            r.tv_nsec = (TIMENS_NSEC_MAX+1)-r.tv_nsec;
        }
        r.tv_sec = INT64_C(0);
    }
    else {
        r.tv_sec--; 
    }
    return r;
}

static inline timens_t
timens_DEC(const timens_t *t) {
    timens_t v = *t;
    if (v.tv_sec == INT64_C(0)) {
        v.tv_sec =  INT64_C(0)-1;
        if (v.tv_nsec) {
            v.tv_nsec = (TIMENS_NSEC_MAX+1)-v.tv_nsec;
        }
    }
    else {
        v.tv_sec--;
    }
    return v;
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
    t_minima,
    t_maxima,
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
            timens_t t_neg;         // 9
            timens_t t_nil;         // 9
            timens_t t_minimum;     // 10
            timens_t t_maximum;     // 11
        };
        timens_t t_list[13];
    };
    opmap_t ops;
      
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
/*
enum {
    //          unit            scale 
    SECOND      = BASE_UNIT,
    YOCTOSECOND = YOCTO_UNIT+SECOND,      // ys 1e-24
    ZEPTOSECOND = ZEPTO_UNIT+SECOND,      // zs 1e-21
    ATTOSECOND  = ATTO_UNIT+SECOND,       // as 1e-18
    FEMTOSECOND = FEMTO_UNIT+SECOND,      // fs 1e-15
    PICOSECOND  = PICO_UNIT+SECOND,       // ps 1e-12 
    NANOSECOND  = NANO_UNIT+SECOND,       // ns 1e-9
    MICROSECOND = MICRO_UNIT+SECOND,      // µs 1e-6
    MILLISECOND = MILLI_UNIT+SECOND,      // ms 1e-3
    CENTISECOND = CENTI_UNIT+SECOND,      // cs 1e-2
    DECISECOND  = DECI_UNIT+SECOND,       // ds 1e-1 
    DECASECOND  = DECA_UNIT+SECOND,       // das 1e+1 
    HECTOSECOND = HECTO_UNIT+SECOND,      // hs 1e+02
    KILOSECOND  = KILO_UNIT+SECOND,       // ks 1e+03
    MEGASECOND  = MEGA_UNIT+SECOND,       // Ms 1e+06 11d13h 
    GIGASECOND  = GIGA_UNIT+SECOND,       // Gs 1e+09 31y287d
    TERASECOND  = TERA_UNIT+SECOND,       // Ts 1e+12 31'688y
    PETASECOND  = PETA_UNIT+SECOND,       // Ps 1e+15 31'688 My
    EXASECOND   = EXA_UNIT+SECOND,        // Es 1e+18
    ZETTASECOND = ZETTA_UNIT+SECOND,      // Zs 1e+21
    YOTTASECOND = YOTTA_UNIT+SECOND,      // Ys 1e+24
    
};

#define ITIMER_REAL 0
#define ITIMER_VIRTUAL 1
#define ITIMER_PROF 2
#define CLOCK_REALTIME 0
#define CLOCK_MONOTONIC 1
#define CLOCK_PROCESS_CPUTIME_ID 2
#define CLOCK_THREAD_CPUTIME_ID 3
#define CLOCK_MONOTONIC_RAW 4
#define CLOCK_REALTIME_COARSE 5
#define CLOCK_MONOTONIC_COARSE 6
#define CLOCK_BOOTTIME 7
#define CLOCK_REALTIME_ALARM 8
#define CLOCK_BOOTTIME_ALARM 9
#define CLOCK_SGI_CYCLE 10
#define CLOCK_TAI 11
#define MAX_CLOCKS 16
#define CLOCKS_MASK (CLOCK_REALTIME | CLOCK_MONOTONIC)
#define CLOCKS_MONO CLOCK_MONOTONIC
#define TIMER_ABSTIME 0x01
#endif

CLOCK_BOOTTIME == ULONGLONG GetTickCount64();
CLOCK_PROCESS_CPUTIME_ID BOOL GetProcessTimes(
  [in]  HANDLE     hProcess,
  [out] LPFILETIME lpCreationTime,
  [out] LPFILETIME lpExitTime,
  [out] LPFILETIME lpKernelTime,
  [out] LPFILETIME lpUserTime
);
CLOCK_THREAD_CPUTIME_ID BOOL GetThreadTimes(
  [in]  HANDLE     hThread,
  [out] LPFILETIME lpCreationTime,
  [out] LPFILETIME lpExitTime,
  [out] LPFILETIME lpKernelTime,
  [out] LPFILETIME lpUserTime
);
*/
