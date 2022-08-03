
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once

#include <time.h>
#include <assert.h>
#include <stddef.h>

static_assert(
    offsetof(struct timespec, tv_sec) 
<   offsetof(struct timespec, tv_nsec),
    "layout of platform's struct timespec is incompatible");
    
#include "unint.h"

#define TIMENS_SEC_MAX      INT64_C(1009822464000000000)
#define TIMENS_SEC_MIN      (INT64_C(0)-TIMENS_SEC_MAX)
#define TIMENS_NSEC_MAX     (BILLION-1)
#define TIMENS_NSEC_MIN     (ZERO)
#define TIMENS_FSEC_MIN     ((double) TIMENS_SEC_MIN)
#define TIMENS_FSEC_MAX     ((double) TIMENS_SEC_MAX)
#define MINUTES_QH      (60)
#define HOURS_QD        (24)
#define DAYS_QW         (7)
#define DAYS_PER_WEEK   (7)
#define SECONDS_QM      (60)
#define SECONDS_QH      (SECONDS_QM*MINUTES_QH)
#define SECONDS_QD      (SECONDS_QH*HOURS_QD)
#define SECONDS_QW      (SECONDS_QD*DAYS_QW)
#define SECONDS_QA      (31556952)

enum TIME_UNIT {
    SECONDS,
    ATTOSECONDS,
    FEMTOSECONDS,
    PICOSECONDS,
    NANOSECONDS,
    MICROSECONDS,
    MILLISECONDS,
    CENTISECONDS,
    DECISECONDS,
    DECASECONDS,
    HECTOSECONDS,
    KILOSECONDS,
    MEGASECONDS,
    GIGASECONDS,
    TERASECONDS,
    PETASECONDS,
    EXASECONDS,
    MINUTES,
    HOURS,
    DAYS,
    WEEKS,
    YEARS,
    TIME_UNIT_NIL,
    TIME_UNIT_MINMAX,
    TIME_UNIT_MAX,
};

typedef struct {
    union {
        struct {
            time_t n;
            time_t d;
        };
        struct {
            time_t quot;
            time_t rem;
        };
    };
    bool zero;
}   timefrac_t;

typedef struct timespec timens_t;

struct timens_const {
    timens_t pos;
    timens_t neg;
};

struct time_unit {
    const char *name;   //
    const char *symbol; // SI symbol
    int         fmt;
    time_t      n;      // numerator 
    time_t      d;      // denominator 
    time_t      limit;  // limit of timens_fromtime arg
    timefrac_t  r;      // ns recipr
};

typedef struct {
    timens_t it_interval;
    timens_t it_value;
} itimerns_t;

timens_t *timens_clr(timens_t *);
timens_t *timens_init(timens_t *, time_t, long);
timens_t *timens_fromtime(timens_t *restrict, time_t, enum TIME_UNIT);

timens_t *timens_fromftime(timens_t *restrict, double);

timens_t *timens_ineg(timens_t *restrict, const timens_t *);
timens_t *timens_iabs(timens_t *restrict, const timens_t *);

timens_t timens_abs(const timens_t *);
timens_t timens_pos(const timens_t *);
timens_t timens_neg(const timens_t *);

timens_t timens_floor(const timens_t *);
timens_t timens_trunc(const timens_t *);
timens_t timens_near(const timens_t *);
timens_t timens_ceil(const timens_t *);

timens_t timens_round(const timens_t *, ROUND_T);

bool timens_lt(const timens_t *, const timens_t *);
bool timens_le(const timens_t *, const timens_t *);
bool timens_eq(const timens_t *, const timens_t *);
bool timens_ne(const timens_t *, const timens_t *);
bool timens_gt(const timens_t *, const timens_t *);
bool timens_ge(const timens_t *, const timens_t *);
bool timens_not(const timens_t *);
bool timens_as_bool(const timens_t *);
int timens_cmp(const timens_t *, const timens_t *);

ptrdiff_t timens_str(const timens_t *restrict, char[restrict]);

struct timens {
    union {
        struct {
            struct timens_const second;
            struct timens_const attosecond;
            struct timens_const femtosecond;
            struct timens_const picosecond;
            struct timens_const nanosecond;
            struct timens_const microsecond;
            struct timens_const millisecond;
            struct timens_const centisecond;
            struct timens_const decisecond;
            struct timens_const decasecond;
            struct timens_const hectosecond;
            struct timens_const kilosecond;
            struct timens_const megasecond;
            struct timens_const gigasecond;
            struct timens_const terasecond;
            struct timens_const petasecond;
            struct timens_const exasecond;
            struct timens_const minute;
            struct timens_const hour;
            struct timens_const day;
            struct timens_const week;
            struct timens_const year;
            struct timens_const nil;
            struct timens_const minmax;
        };
        struct timens_const consts[TIME_UNIT_MAX];
    };
    struct time_unit units[TIME_UNIT_MAX];
    void *ml;
    double          FTIMES[65];
    int             FTIMENS[65];
    unsigned char   FTIME_NDIGIT[65];
    union unop round_ops[ROUND_T_MAX];
};
  

const struct timens timens = {

    .consts = {
        [SECONDS]       = {{0+1, 0L}, {0-1, 0L}},
        [ATTOSECONDS]   = {
            {0+0, 0L},
            {0+0, 0L},
        },
        [FEMTOSECONDS]  = {
            {0+0, 0L},
            {0+0, 0L},
        },
        [NANOSECONDS]   = {
            {0-0, (ONE)},
            {0-1, (BILLION-ONE)},
        },
        [MICROSECONDS]  = {
            {0-0, (THOUSAND)},
            {0-1, (BILLION-THOUSAND)},
        },
        [MILLISECONDS]  = {
            {0+0, (MILLION)},
            {0-1, (BILLION-MILLION)},
        },
        [CENTISECONDS]  = {
            {0+0, (MILLION*TEN) },
            {0-1, (BILLION-TEN*MILLION)},
        },
        [DECISECONDS]    = {
            {0+0, (MILLION*HUNDRED)}, 
            {0-1, (BILLION-HUNDRED*MILLION)},
        },
        [DECASECONDS]   = {{TEN},           {TEN*(0-1)}},
        [HECTOSECONDS]  = {{HUNDRED},       {HUNDRED*(0-1)}},
        [KILOSECONDS]   = {{THOUSAND},      {THOUSAND*(0-1)}},
        [MEGASECONDS]   = {{MILLION},       {MILLION*(0-1)}},
        [GIGASECONDS]   = {{BILLION},       {BILLION*(0-1)}},
        [TERASECONDS]   = {{TRILLION},      {TRILLION*(0-1)},},
        [PETASECONDS]   = {{QUADRILLION},   {QUADRILLION*(0-1)},},
        [EXASECONDS]    = {{QUINTILLION},   {QUINTILLION*(0-1)}, },
        [MINUTES]       = {{SECONDS_QM},    {SECONDS_QM*(0-1)},},
        [HOURS]         = {{SECONDS_QH},    {SECONDS_QH*(0-1)}},
        [DAYS]          = {{SECONDS_QD},    {SECONDS_QD*(0-1)}},
        [WEEKS]         = {{SECONDS_QW},    {SECONDS_QW*(0-1)}},
        [YEARS]         = {{SECONDS_QA},    {SECONDS_QA*(0-1)}},
        [TIME_UNIT_NIL] = {{0}},
        [TIME_UNIT_MINMAX] = {
            {TIMENS_SEC_MAX, TIMENS_NSEC_MAX},
            {TIMENS_SEC_MIN, TIMENS_NSEC_MIN},
        },
    },

    .units = {

        [ATTOSECONDS] = {
            "ATTOSECONDS", u8"as", 
            .n=ONE,
            .d=QUINTILLION,
            .limit=INT64_MAX,
            .r={ONE, BILLION},
        },
        [FEMTOSECONDS] = {
            "FEMTOSECONDS", u8"fs", 
            .n=ONE,
            .d=QUADRILLION,
            .limit=INT64_MAX,
            .r={ONE, MILLION},
        },
        [PICOSECONDS] = {
            "PICOOSECONDS", u8"ps", 
            .n=ONE,
            .d=TRILLION,
            .limit=INT64_MAX,
            .r={ONE, THOUSAND},
        },
        [NANOSECONDS] = {
            "NANOOSECONDS", u8"ns", 
            .n=ONE,
            .d=BILLION,
            .limit=INT64_MAX,
            .r={ONE, ONE, true},
        },
        [MICROSECONDS] = {
            "MICROSECONDS", u8"μs", 
            .n=ONE,
            .d=MILLION,
            .limit=INT64_MAX,
            .r={THOUSAND, ONE},
        },

        [MILLISECONDS] = {
            "MILLISECONDS", u8"ms", 
            .n=ONE,
            .d=THOUSAND, 
            .limit=INT64_MAX,
            .r={MILLION, ONE},
        },
        [CENTISECONDS] = {
            "CENTISECONDS", u8"cs",
            .n=ONE,
            .d=HUNDRED,
            .limit=INT64_MAX,
            .r={TEN*MILLION, ONE},
        },
        [DECISECONDS] = {
            "DECISECONDS", u8"ds",
            .n=ONE,
            .d=TEN,
            .limit=INT64_MAX,
            .r={HUNDRED*MILLION, ONE},
        },
        [SECONDS] = { 
            "SECONDS",      u8"s", 
            'S',
            .n=ONE,
            .d=ONE,
            .limit=TIMENS_SEC_MAX,
            .r={.zero=true},
        },
        [DECASECONDS] = {
            "DECASECONDS",  u8"das",
            .n=TEN,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/TEN,
            .r={.zero=true},
        },
        [HECTOSECONDS] = {
            "HECTOSECONDS",    u8"hs",
            .n=HUNDRED,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/HUNDRED,
            .r={.zero=true},
        },
        [KILOSECONDS] = {
            "KILOSECONDS",    u8"hs",
            .n=THOUSAND,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/THOUSAND,
            .r={.zero=true},
        },
        [MEGASECONDS] = {
            "MEGASECONDS", u8"Ms",
            .n=MILLION,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/MILLION,
            .r={.zero=true},
        },
        [GIGASECONDS] = {
            "GIGASECONDS", u8"Gs",
            .n=BILLION,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/BILLION,
            .r={.zero=true},
        },
        [TERASECONDS] = {
            "TERASECONDS", u8"Ts",
            .n=TRILLION,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/TRILLION,
            .r={.zero=true},
        },
        [PETASECONDS] = {
            "PETASECONDS", u8"Ps",
            .n=QUADRILLION,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/QUADRILLION,
            .r={.zero=true},
        },
        [EXASECONDS] = {
            "EXASECONDS",   u8"Ps",
            .n=QUINTILLION,
            .d=ONE,
            .limit=ONE,
            .r={.zero=true},
        },
        [MINUTES] = {
            "MINUTES",      u8"m",
            'M',
            .n=SECONDS_QM,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/SECONDS_QM,
            .r={.zero=true},
        },
        [HOURS] = {
            "HOURS",        u8"h",
            'H',
            .n=SECONDS_QH,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/SECONDS_QH,
            .r={.zero=true},
        },
        [DAYS] = {
            "DAYS",         u8"d",
            'd',
            .n=SECONDS_QD,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/SECONDS_QD,
            .r={.zero=true},
        },
        [WEEKS] = {
            "WEEKS",        u8"w",
            'w',
            .n=SECONDS_QW,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/SECONDS_QW,
            .r={.zero=true},
        },
        [YEARS] = {
            "YEARS",        u8"y",
            'y',
            .n=SECONDS_QA,
            .d=ONE,
            .limit=TIMENS_SEC_MAX/SECONDS_QA,
            .r={.zero=true},
        },
    },

    .FTIMES = {
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
    },

    .FTIMENS = {
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
    },

    .FTIME_NDIGIT = {
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
    },

    .round_ops = {
        [ROUND_NEAR] = {timens_near},
        [ROUND_ZERO] = {timens_trunc},
        [ROUND_CEIL] = {timens_ceil},
        [ROUND_DOWN] = {timens_floor},
    },
};


static inline _Bool 
time_unit_CHECK(const enum TIME_UNIT id) {
    return 0 <= id && id <= TIME_UNIT_MAX;
}

static inline const char *
time_unit_GET_NAME(enum TIME_UNIT id) {
    return timens.units[id].name;
}

static ptrdiff_t
time_unit_REPR(const struct time_unit *unit, FILE *dst, const char *fmt) {
    if (dst == NULL) {
        dst = stdout;
    }
    int w = 0;
    int x = fprintf(dst, "(struct time_unit){\n");
    if (x < 0) goto fail;
    else w += x;
    if ((x=fprintf(dst, "    .nname\"%s\",\n", unit->name)) < 0) {
        fail: {
            exit(EXIT_FAILURE);
        }
    }
    w += x;
    if ((x=fprintf(dst, "    .symbol=u8\"%s\",\n", unit->symbol)) < 0) {
        goto fail;
    }
    w += x;
    if ((x=fprintf(dst, "    .n=%jd,\n", unit->n)) < 0) {
        goto fail;
    }
    w += x;
    if ((x=fprintf(dst, "    .d=%jd,\n", unit->d)) < 0) {
        goto fail;
    }
    w += x;
    if ((x=fprintf(dst, "    .r={\n")) < 0) {
        goto fail;
    }
    w += x;
    if ((x=fprintf(dst, "        .n=%jd,\n", unit->r.n)) < 0) {
        goto fail;
    }
    w += x;
    if ((x=fprintf(dst, "        .d=%jd,\n", unit->r.d)) < 0) {
        goto fail;
    }
    w += x;
    return w+fprintf(dst, "    }\n}\n");
}

static inline void
timens_units_LOAD(const struct time_unit **v, enum TIME_UNIT i) {
    *v = timens.units+i;
}

static inline const struct time_unit *
timens_units_INIT(const struct time_unit **v, enum TIME_UNIT i) {
    if (!time_unit_CHECK(i)) {
        *v = NULL;
        return NULL;
    }
    return (*v=timens.units+i);
}

static inline timens_t *
timens_INIT(timens_t *restrict v, time_t tv_sec, long tv_nsec) {
    *v = (timens_t){
        .tv_sec=tv_sec,
        .tv_nsec=tv_nsec,
    };
    return v;
}

static inline _Bool
timens_SEC_OK(time_t n) {
    return (TIMENS_SEC_MIN <= n) && (n <= TIMENS_SEC_MAX);
}

static inline _Bool
timens_NSEC_OK(long n) {
    return (TIMENS_NSEC_MIN <= n) && (n <= TIMENS_NSEC_MAX);
}

static inline int
timens_OK(const timens_t *restrict t) {
    if (t->tv_nsec < TIMENS_NSEC_MIN || t->tv_nsec > TIMENS_NSEC_MAX) {
        return 0;
    }
    if (t->tv_sec < 0) {
        return 0-(t->tv_sec >= TIMENS_SEC_MIN);
    }
    else {
        return   (t->tv_sec <= TIMENS_SEC_MAX);
    }
}

static inline void *
timens_CLR(timens_t *restrict v) {
    return memset(v, 0, sizeof *v);
}

static inline timens_t
timens_NEG_ONLY_SECS(const timens_t *t) {
    return (timens_t){
        .tv_sec=0-t->tv_sec,
        .tv_nsec=0L,
    };
}

static inline timens_t
timens_NEG_WITH_NSEC(const timens_t *t) {
    return (timens_t){
        (0-1)-t->tv_sec,
        (long) BILLION-t->tv_nsec,
    };
}

static inline timens_t
timens_NEG(const timens_t *restrict t) {
    timens_t v;
    if (t->tv_nsec) {
        v.tv_sec = (0-t->tv_sec)-INT64_C(1);
        v.tv_nsec = BILLION-t->tv_nsec;
    }
    else {
        v.tv_sec = 0-t->tv_sec;
        v.tv_nsec = 0;
    }
    return v;
}

static inline int
timens_SGN(timens_t *restrict v, const timens_t *restrict t) {
    const int ok = timens_OK(t);
    if (ok) {
        *v = ok < 0 ? timens_NEG(t): *t;
    }
    return ok;
}

static inline bool
timens_NOT(const timens_t *t) {
    return !(t->tv_sec || t->tv_nsec);
}
