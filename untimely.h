
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳   

*/
#pragma once

#include <assert.h>
#include <time.h>

static_assert(
    offsetof(struct timespec, tv_sec) 
<   offsetof(struct timespec, tv_nsec),
    "layout of platform's struct timespec is incompatible");

#include <errno.h>
#include <inttypes.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <wchar.h>

#include "unopcode.h"
#include "unint.h"

#define TIMENS_SEC_MAX      INT64_C(1009822464000000000)
#define TIMENS_SEC_MIN      (INT64_C(0)-TIMENS_SEC_MAX)
#define TIMENS_NSEC_MAX     (BILLION-1)
#define TIMENS_NSEC_MIN     (ZERO)
#define TIMENS_FSEC_MIN     ((double) TIMENS_SEC_MIN)
#define TIMENS_FSEC_MAX     ((double) TIMENS_SEC_MAX)
/* Q = quaque (latin) */
#define MINUTES_QH      (60)
#define HOURS_QD        (24)
#define DAYS_QW         (7)
#define DAYS_PER_WEEK   (7)

#define SECONDS_QM      (60)
#define SECONDS_QH      (SECONDS_QM*MINUTES_QH)
#define SECONDS_QD      (SECONDS_QH*HOURS_QD)
#define SECONDS_QW      (SECONDS_QD*DAYS_QW)
#define SECONDS_QA      (31556952)

#define YEAR_MAX (INT64_C(32)*BILLION)
#define YEAR_MIN (INT64_C(0)-YEAR_MAX)

typedef time_t year_t;

typedef enum {
    JAN=1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC,
} month_t;

typedef enum {
    SUN=1,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
} weekday_t;

enum TIME_UNIT {
    SECONDS,        /*  SI base unit of time */
/*  YOCTOSECONDS,   <UNUSED> 1E-24 seconds */
/*  ZEPTOSECONDS,   <UNUSED> 1E-21 seconds */ 
    ATTOSECONDS,    /*  (1÷1'000'000'000'000'000'000) */
    FEMTOSECONDS,   /*  (1÷1'000'000'000'000'000) */
    PICOSECONDS,    /*  (1÷1'000'000'000'000) */
    NANOSECONDS,    /*  (1÷1'000'000'000) */
    MICROSECONDS,   /*  (1÷1'000'000) */
    MILLISECONDS,   /*  (1÷1'000) */
    CENTISECONDS,   /*  (1÷100) */
    DECISECONDS,    /*  (1÷10) */
    DECASECONDS,    /*  (1×10) */
    HECTOSECONDS,   /*  (1×100) */
    KILOSECONDS,    /*  (1×1'000) */
    MEGASECONDS,    /*  (1×1'000'000 */
    GIGASECONDS,    /*  (1×1'000'000'000 */
    TERASECONDS,    /*  (1×1'000'000'000'000 */
    PETASECONDS,    /*  (1×1'000'000'000'000'000 */
    EXASECONDS,     /*  (1×1'000'000'000'000'000'000 */
/*  ZETTASECONDS,   <UNUSED> 1E+21 seconds */
/*  YOTTASECONDS,   <UNUSED> 1E+24 seconds */
    MINUTES,        /*  (1×60) */
    HOURS,          /*  (1×3'600 */
    DAYS,           /*  (1×86'000 */
    WEEKS,          /*  (1×604'800) */
    YEARS,          /*  (1×31'556'952) */
    TIME_UNIT_NIL,  /*  (1×0) */
    TIME_UNIT_MINMAX,
    TIME_UNIT_MAX,
};

struct untm {
/*  Compact struct tm alternative */
    year_t
        tm_year;        /*  [-32'000'000'000..+32'000'000'000] (±32 Gy)*/
    unsigned            /*              (0/32)      */
        tm_mon:     4,  /*  [1..12]     (4/32)      */
        tm_mday:    5,  /*  [1..31]     (9/32)      */
        tm_wday:    3,  /*  [1..7]      (12/32)     */
        tm_yday:    9,  /*  [1..365]    (21/32)     */
        tm_ywk:     6,  /*  [1..52]     (27/32)     */
        tm_hour:    5,  /*  [0..24]     (32/32)     */
        tm_min:     6,  /*  [0..59]     (6/32)      */
        tm_sec:     6,  /*  [0..60]     (12/32)     */
        tm_isdst:   1,  /*  [0..1]      (13/32)     */
        :           0;
    unsigned 
        tm_nsec;
};

typedef struct timespec timens_t;

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

timens_t *
timens_clr(timens_t *tv);
/*  Zero initialize fields of target */

timens_t *
timens_init(timens_t *tv, time_t tv_sec, long tv_nsec);
/* Initialize fields of target */


timens_t *
timens_fromtime(timens_t *tv, time_t t, enum TIME_UNIT unit);
/*  Initialize target from duration specified as an integer 
    multiple of time base unit unit. The following example 
    initializes v to negative 500 μs:

        `timens_fromtime(&v, 0-500, MICROSECONDS);`
*/

timens_t *
timens_fromftime(timens_t *tv, double t);
/*  Initialize target from duration specified as a double.

    Durations between [-8'388'608..+8'388'608] seconds 
    can be converted to and from double/struct timespec 
    without precision loss.
*/

timens_t *
timens_ineg(timens_t *v, const timens_t *t);
/*  Store a "negated" copy of target at t at address v.
    Returns v.
*/

timens_t *
timens_iabs(timens_t *restrict v, const timens_t *t);
/* Store |t| in v   */

timens_t 
timens_abs(const timens_t *t);
/* Compute |t|      */

timens_t 
timens_pos(const timens_t *t);
/* Compute +t       */

timens_t 
timens_neg(const timens_t *t);
/* Compute -t       */

timens_t 
timens_floor(const timens_t *t);
/* Round t toward negative infinity */

timens_t 
timens_trunc(const timens_t *t);
/* Round t towards zero */

timens_t 
timens_near(const timens_t *t);
/* Round t towards the nearest number of seconds */

timens_t 
timens_ceil(const timens_t *t);
/* Round t towards positive infinity */

timens_t 
timens_round(const timens_t *t, ROUND_T mode);
/* Round t using the specified rounding mode */


bool 
timens_lt(const timens_t *a, const timens_t *b);
/* Compute a < b */

bool 
timens_le(const timens_t *a, const timens_t *b);
/* Compute a ≤ b */

bool 
timens_eq(const timens_t *a, const timens_t *b);
/* Compute a = b */

bool 
timens_ne(const timens_t *a, const timens_t *b);
/* Compute a ≠ b */

bool 
timens_gt(const timens_t *a, const timens_t *b);
/* Compute a > b*/

bool 
timens_ge(const timens_t *a, const timens_t *b);
/* Compute a ≥ b */

bool 
timens_not(const timens_t *t);
/* Compute !t */

bool 
timens_as_bool(const timens_t *t);
/* Compute (bool) t */

int 
timens_cmp(const timens_t *a, const timens_t *b);
/* Returns -1 if a < b, 0 if a = b, or +1 if a > b */

ptrdiff_t 
timens_str(const timens_t *restrict t, char s[restrict]);
/*  Store the ISO-8601-ish representation of t in s
*/

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
    union unop      round_ops[ROUND_T_MAX];
    _Bool           LEAP_TABLE[400]; /* Gregorian leap year chart */
    short           YDAY_TABLE[13]; /* day of year on first of each month */
    char            MLEN_TABLE[13]; /* days per month */
};
  
static
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
            .r={
                .n=ONE, 
                .d=BILLION,
            },
        },
        [FEMTOSECONDS] = {
            "FEMTOSECONDS", u8"fs", 
            .n=ONE,
            .d=QUADRILLION,
            .limit=INT64_MAX,
            .r={
                .n=ONE, 
                .d=MILLION,
            },
        },
        [PICOSECONDS] = {
            "PICOOSECONDS", u8"ps", 
            .n=ONE,
            .d=TRILLION,
            .limit=INT64_MAX,
            .r={
                .n=ONE, 
                .d=THOUSAND,
            },
        },
        [NANOSECONDS] = {
            "NANOOSECONDS", u8"ns", 
            .n=ONE,
            .d=BILLION,
            .limit=INT64_MAX,
            .r={
                .n=ONE, 
                .d=ONE, 
                .zero=true,
            },
        },
        [MICROSECONDS] = {
            "MICROSECONDS", u8"μs", 
            .n=ONE,
            .d=MILLION,
            .limit=INT64_MAX,
            .r={.n=THOUSAND, .d=ONE},
        },

        [MILLISECONDS] = {
            "MILLISECONDS", u8"ms", 
            .n=ONE,
            .d=THOUSAND, 
            .limit=INT64_MAX,
            .r={.n=MILLION, .d=ONE},
        },
        [CENTISECONDS] = {
            "CENTISECONDS", u8"cs",
            .n=ONE,
            .d=HUNDRED,
            .limit=INT64_MAX,
            .r={.n=TEN*MILLION, .d=ONE},
        },
        [DECISECONDS] = {
            "DECISECONDS", u8"ds",
            .n=ONE,
            .d=TEN,
            .limit=INT64_MAX,
            .r={.n=HUNDRED*MILLION, .d=ONE},
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
    
    .LEAP_TABLE = {
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
        1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,
    },

    .YDAY_TABLE = {
        000, 000,  31,  59,  90, 120, 151, 181, 212, 243, 273, 304, 334,
    },
    /*  [0], ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, ___, */
    /*  [0], JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, */
    .MLEN_TABLE = {
        0,    31,  28,  31,  30,  31,  30,  31,  31,  30,  31,  30,  31,
    },
};

static inline _Bool
year_CHECK(year_t y) {
    return (YEAR_MIN <= y) && (y <= YEAR_MAX);
}

static inline _Bool
year_ISLEAP(year_t y) {
    assert(year_CHECK(y));
    return timens.LEAP_TABLE[y%400];
}

static inline short
date_YDAY(time_t y, month_t m, char d) {
    assert(year_CHECK(y));
    assert((1 <= m) && (m <= 12));
    assert((1 <= d) && (d <= 31));
    return timens.YDAY_TABLE[m]+d+year_ISLEAP(y);
}


static inline _Bool 
time_unit_CHECK(const enum TIME_UNIT id) {
    return (0 <= id) && (id <= TIME_UNIT_MAX);
}

static inline const char *
time_unit_GET_NAME(enum TIME_UNIT id) {
    return timens.units[id].name;
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
