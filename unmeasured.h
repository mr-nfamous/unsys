
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once 
#include "unint.h"


#define ZERO        0
#define ONE         1 
#define TWO         2
#define THREE       3
#define FOUR        4
#define FIVE        5
#define SIX         6
#define SEVEN       7
#define EIGHT       8
#define NINE        9
#define TEN         10
#define ELEVEN      11
#define TWELVE      12 
#define THIRTEEN    13
#define FOURTEEN    14 
#define FIFTEEN     15 
#define SIXTEEN     16 
#define SEVENTEEN   17
#define EIGHTEEN    18 
#define NINETEEN    19
#define TWENTY      20
#define THIRTY      30 
#define FOURTY      40
#define FIFTY       50 
#define SIXTY       60 
#define SEVENTY     70 
#define EIGHTY      80 
#define NINETY      90 
#define HUNDRED     100
#define THOUSAND    1000
#define MILLION     INT32_C(1000000)
#define BILLION     INT32_C(1000000000)
#define TRILLION    INT64_C(1000000000000)
#define QUADRILLION INT64_C(1000000000000000)
#define QUINTILLION INT64_C(1000000000000000000)

#define HALF_BILLION    (FIVE_HUNDRED*MILLION)
/*
#define BASE_UNIDS (BASE_UNID_MAX)
#define TIME_UNIDS (TIME_UNID_MAX-BASE_UNIDS)
#define DATA_UNIDS (DATA_UNID_MAX-BASE_UNIDS)
#define MASS_UNIDS (MASS_UNID_MAX-BASE_UNIDS)
#define DIST_UNIDS (DIST_UNID_MAX-BASE_UNIDS)
#define CRNT_UNIDS (CRNT_UNID_MAX-BASE_UNIDS)
#define TEMP_UNIDS (TEMP_UNID_MAX-BASE_UNIDS)
#define LUMI_UNIDS (TEMP_UNID_MAX-BASE_UNIDS)

#define BASE_UNID_OFFSET 0
#define TIME_UNID_OFFSET (BASE_UNIDS)
#define DATA_UNID_OFFSET (BASE_UNIDS+TIME_UNID_MAX) 
#define MASS_UNID_OFFSET (BASE_UNIDS+DATA_UNID_MAX)
#define DIST_UNID_OFFSET (BASE_UNIDS+MASS_UNID_MAX)
#define CRNT_UNID_OFFSET (BASE_UNIDS+DIST_UNID_MAX)
#define TEMP_UNID_OFFSET (BASE_UNIDS+CRNT_UNID_MAX)
#define LUMI_UNID_OFFSET (BASE_UNIDS+TEMP_UNID_MAX)


*/

#define BASE_UNIDS (BASE_UNID_MAX)
#define TIME_UNIDS (TIME_UNID_MAX-TIME_UNID_MIN)
#define DATA_UNIDS (DATA_UNID_MAX-DATA_UNID_MIN)
#define MASS_UNIDS (MASS_UNID_MAX-MASS_UNID_MIN)
#define DIST_UNIDS (DIST_UNID_MAX-DIST_UNID_MIN)
#define CRNT_UNIDS (CRNT_UNID_MAX-CRNT_UNID_MIN)
#define TEMP_UNIDS (TEMP_UNID_MAX-TEMP_UNID_MIN)
#define LUMI_UNIDS (LUMI_UNID_MAX-LUMI_UNID_MIN)

#define BASE_BASE_UNID BASEUNIT
#define TIME_BASE_UNID SECOND 
#define DATA_BASE_UNID BYTE 
#define MASS_BASE_UNID GRAM 
#define DIST_BASE_UNID METER 
#define CRNT_BASE_UNID AMPERE 
#define TEMP_BASE_UNID KELVIN
#define LUMI_BASE_UNID CANDELA 


#define UNIT_UNIDS (\
    TIME_UNIDS\
+   DATA_UNIDS\
+   MASS_UNIDS\
+   DIST_UNIDS\
+   CRNT_UNIDS\
+   TEMP_UNIDS\
+   LUMI_UNIDS)

enum BASE_UNID {
    BASEUNIT,
    YOCTOUNIT,      // y  1e-24
    ZEPTOUNIT,      // z  1e-21
    ATTOUNIT,       // a  1e-18
    FEMTOUNIT,      // f  1e-15
    PICOUNIT,       // p  1e-12 
    NANOUNIT,       // n  1e-9
    MICROUNIT,      // µ  1e-6
    MILLIUNIT,      // m  1e-3
    CENTIUNIT,      // c  1e-2
    DECIUNIT,       // d  1e-1
    DECAUNIT,       // da 1e+1
    HECTOUNIT,      // h  1e+2
    KILOUNIT,       // k  1e+3
    MEGAUNIT,       // M  1e+6
    GIGAUNIT,       // G  1e+9
    TERAUNIT,       // T  1e+12
    PETAUNIT,       // P  1e+15
    EXAUNIT,        // E  1e+18
    ZETTAUNIT,      // Z  1e+21
    YOTTAUNIT,      // Y  1e+24
    // Binary based (used for data only, e.g. MiB => mebibyte)
    KIBIUNIT,       // ki (1<<10)
    MEBIUNIT,       // Mi (1<<20)
    GIBIUNIT,       // Gi (1<<30)
    TEBIUNIT,       // Ti (1<<40)
    PEBIUNIT,       // Pi (1<<50)
    EXBIUNIT,       // Ei (1<<60)
    ZEBIUNIT,       // Zi (1<<70)
    YOBIUNIT,       // Yi (1<<80)
    BASE_UNID_MAX,
    #define TIME_UNID_MIN   BASE_UNID_MAX
};

enum TIME_UNID {
    SECOND      = TIME_UNID_MIN,
    YOCTOSECOND = SECOND+YOCTOUNIT,
    ZEPTOSECOND = SECOND+ZEPTOUNIT,
    ATTOSECOND  = SECOND+ATTOUNIT,
    FEMTOSECOND = SECOND+FEMTOUNIT,
    PICOSECOND  = SECOND+PICOUNIT,
    NANOSECOND  = SECOND+NANOUNIT,
    MICROSECOND = SECOND+MICROUNIT,
    MILLISECOND = SECOND+MILLIUNIT,
    CENTISECOND = SECOND+CENTIUNIT,
    DECISECOND  = SECOND+DECIUNIT,
    DECASECOND  = SECOND+DECAUNIT,
    HECTOSECOND = SECOND+HECTOUNIT,
    KILOSECOND  = SECOND+KILOUNIT,
    MEGASECOND  = SECOND+MEGAUNIT,
    GIGASECOND  = SECOND+GIGAUNIT,
    TERASECOND  = SECOND+TERAUNIT,
    PETASECOND  = SECOND+PETAUNIT,
    EXASECOND   = SECOND+EXAUNIT,
    ZETTASECOND = SECOND+ZETTAUNIT,
    YOTTASECOND = SECOND+YOTTAUNIT,
    GREGORIAN_MINUTE,
    GREGORIAN_HOUR, 
    GREGORIAN_DAY,
    GREGORIAN_WEEK,
    GREGORIAN_CYCLE,        // 146'097 days
    GREGORIAN_MILLENNIUM,   // 1000y
    GREGORIAN_CENTURY,      // 100y 
    GREGORIAN_DECADE,       // 10y
    GREGORIAN_MONTH,        // 1/4800 of a Gregorian calendar cycle
    GREGORIAN_YEAR,         // 365.2425d (1/400 cycle)
    MARTIAN_SOL,
    JIFFY,                  // 1/<PAL=50, NTSC=60>
    SHAKE,                  // 10ns
    TIME_UNID_MAX,
#   define DATA_UNID_MIN    TIME_UNID_MAX
};

enum UNID_MULTI {
    
}

enum DATA_UNID {

    BYTE      = DATA_UNID_MIN,

    KILOBYTE  = BYTE+KILOUNIT,
    MEGABYTE  = BYTE+MEGAUNIT,
    GIGABYTE  = BYTE+GIGAUNIT,
    TERABYTE  = BYTE+TERAUNIT,
    PETABYTE  = BYTE+PETAUNIT,
    EXABYTE   = BYTE+EXAUNIT,
    ZETTABYTE = BYTE+ZETTAUNIT,
    YOTTABYTE = BYTE+YOTTAUNIT,

    KIBIBYTE  = BYTE+KIBIUNIT,
    MEBIBYTE  = BYTE+MEGAUNIT, 
    GIBIBYTE  = BYTE+GIGAUNIT, 
    TEBIBYTE  = BYTE+TEBIUNIT, 
    PEBIBYTE  = BYTE+PEBIUNIT, 
    EXBIBYTE  = BYTE+EXBIUNIT,
    ZEBIBYTE  = BYTE+ZEBIUNIT, 
    YOBIBYTE  = BYTE+YOBIUNIT,

    BIT,

    KILOBIT  = BIT+KILOUNIT,
    MEGABIT  = BIT+MEGAUNIT,
    GIGABIT  = BIT+GIBIUNIT,
    TERABIT  = BIT+TERAUNIT,
    PETABIT  = BIT+PETAUNIT,
    EXABIT   = BIT+EXAUNIT,
    ZETTABIT = BIT+ZETTAUNIT,
    YOTTABIT = BIT+YOTTAUNIT,

    KIBIBIT  = BIT+KIBIUNIT,
    MEBIBIT  = BIT+MEBIUNIT,
    GIBIBIT  = BIT+GIBIUNIT,
    TEBIBIT  = BIT+TEBIUNIT,
    PEBIBIT  = BIT+PEBIUNIT,
    EXBIBIT  = BIT+EXBIUNIT,
    ZEBIBIT  = BIT+ZEBIUNIT,
    YOBIBIT  = BIT+YOBIUNIT,

    NIBBLE, // 4 bit

    DATA_UNID_MAX,
#   define MASS_UNID_MIN DATA_UNID_MAX
};

enum MASS_UNID {

    GRAM      = MASS_UNID_MIN,
    
    YOCTOGRAM = GRAM+YOCTOUNIT,
    ZEPTOGRAM = GRAM+ZEPTOUNIT,
    ATTOGRAM  = GRAM+ATTOUNIT,
    FEMTOGRAM = GRAM+FEMTOUNIT,
    PICOGRAM  = GRAM+PICOUNIT,
    NANOGRAM  = GRAM+NANOUNIT,
    MICROGRAM = GRAM+MICROUNIT,
    MILLIGRAM = GRAM+MILLIUNIT,
    CENTIGRAM = GRAM+CENTIUNIT,
    DECIGRAM  = GRAM+DECIUNIT,
    DECAGRAM  = GRAM+DECAUNIT,
    HECTOGRAM = GRAM+HECTOUNIT,
    KILOGRAM  = GRAM+KILOUNIT,
    MEGAGRAM  = GRAM+MEGAUNIT,
    GIGAGRAM  = GRAM+GIGAUNIT,
    TERAGRAM  = GRAM+TERAUNIT,
    PETAGRAM  = GRAM+PETAUNIT,
    EXAGRAM   = GRAM+EXAUNIT,
    ZETTAGRAM = GRAM+ZETTAUNIT,
    YOTTOGRAM = GRAM+YOCTOUNIT,

    POUND,  // = 453.59237g

    TON,
    TONNE,
    STONE,
    GRAIN,          // "gr"             64.79891    mg 
    EARTH_MASS,     // "M\U0001F728"    5.9722e+27  g 
    LUNAR_MASS,     // "M\U0000263E"    0.0123000371 × earth
    SOLAR_MASS,     // "M\U0000260a"    332946 × earth
    MERCURIAN_MASS, // "M\U0000263f"    0.0553 × earth
    VENUSIAN_MASS,  // "M\U00002640"    0.815
    MARTIAN_MASS,   // "M\U00002642"    0.107
    JOVIAN_MASS,    // "Mj"             317.8
    SATURNIAN_MASS, // "M\U00002644"    95.2
    URANIAN_MASS,   // "M\U00002645"    14.5
    NEPTUNE_MASS,   // "M\U00002646"    17.1
    
    MASS_UNID_MAX,
#   define DIST_UNID_MIN MASS_UNID_MAX
};

enum DIST_UNID {

    METER       = DIST_UNID_MIN,

    YOCTOMETER = METER+YOCTOUNIT,
    ZEPTOMETER = METER+ZEPTOUNIT,
    ATTOMETER  = METER+ATTOUNIT,
    FEMTOMETER = METER+FEMTOUNIT,
    PICOMETER  = METER+PICOUNIT,
    NANOMETER  = METER+NANOUNIT,
    MICROMETER = METER+MICROUNIT,
    MILLIMETER = METER+MILLIUNIT,
    CENTIMETER = METER+CENTIUNIT,
    DECIMETER  = METER+DECIUNIT,
    DECAMETER  = METER+DECAUNIT,
    HECTOMETER = METER+HECTOUNIT,
    KILOMETER  = METER+KILOUNIT,
    MEGAMETER  = METER+MEGAUNIT,
    GIGAMETER  = METER+GIGAUNIT,
    TERAMETER  = METER+TERAUNIT,
    PETAMETER  = METER+PETAUNIT,
    EXAMETER   = METER+EXAUNIT,
    ZETTAMETER = METER+ZETTAUNIT,
    YOTTAMETER = METER+YOTTAUNIT,

    INCH,                   // 25.4 mm

    FOOT,                   // ft   12 in
    MILE,                   // mi   5280.0 ft
    YARD,                   // yd   3.0 ft
    ROD,                    //      5.5 yd
    CHAIN,                  //      4 rod
    MIL,                    //      0.001 in
    PARSEC,                 //      30856775814671900 m
    LIGHT_YEAR,             //      9460730472580800 m
    ASTRONOMICAL_UNIT,      //      149597870700 m
    FATHOM,                 //      1.8288 m
    NAUTICAL_MILE,          //      1852 m
    ANGSTROM,               // Å    100pm
    
    DIST_UNID_MAX,
#   define CRNT_UNID_MIN DIST_UNID_MAX
};

enum CRNT_UNID {

    AMPERE = CRNT_UNID_MIN,

    YOCTOAMPERE = AMPERE+YOCTOUNIT,
    ZEPTOAMPERE = AMPERE+ZEPTOUNIT,
    FEMTOAMPERE = AMPERE+FEMTOUNIT,
    ATTOAMPERE  = AMPERE+ATTOUNIT,
    PICOAMPERE  = AMPERE+PICOUNIT,
    NANOAMPERE  = AMPERE+NANOUNIT,
    MICROAMPERE = AMPERE+MICROUNIT,
    MILLIAMPERE = AMPERE+MILLIUNIT,
    CENTIAMPERE = AMPERE+CENTIUNIT,
    DECIAMPERE  = AMPERE+DECIUNIT,
    DECAAMPERE  = AMPERE+DECAUNIT,
    HECTOAMPERE = AMPERE+HECTOUNIT,
    KILOAMPERE  = AMPERE+KILOUNIT,
    MEGAAMPERE  = AMPERE+MEGAUNIT,
    GIGAAMPERE  = AMPERE+GIGAUNIT,
    TERAAMPERE  = AMPERE+TERAUNIT,
    PETAAMPERE  = AMPERE+PETAUNIT,
    EXAAMPERE   = AMPERE+EXAUNIT,
    ZETTAAMPERE = AMPERE+ZETTAUNIT,
    YOTTAAMPERE = AMPERE+YOCTOUNIT,

    CRNT_UNID_MAX,
#   define TEMP_UNID_MIN CRNT_UNID_MAX
};

enum TEMP_UNID {

    KELVIN = TEMP_UNID_MIN,
    
    YOCTOKELVIN = KELVIN+YOCTOUNIT,
    ZEPTOKELVIN = KELVIN+ZEPTOUNIT,
    FEMTOKELVIN = KELVIN+FEMTOUNIT,
    ATTOKELVIN  = KELVIN+ATTOUNIT,
    PICOKELVIN  = KELVIN+PICOUNIT,
    NANOKELVIN  = KELVIN+NANOUNIT,
    MICROKELVIN = KELVIN+MICROUNIT,
    MILLIKELVIN = KELVIN+MILLIUNIT,
    CENTIKELVIN = KELVIN+CENTIUNIT,
    DECIKELVIN  = KELVIN+DECIUNIT,
    DECAKELVIN  = KELVIN+DECAUNIT,
    HECTOKELVIN = KELVIN+HECTOUNIT,
    KILOKELVIN  = KELVIN+KILOUNIT,
    MEGAKELVIN  = KELVIN+MEGAUNIT,
    GIGAKELVIN  = KELVIN+GIGAUNIT,
    TERAKELVIN  = KELVIN+TERAUNIT,
    PETAKELVIN  = KELVIN+PETAUNIT,
    EXAKELVIN   = KELVIN+EXAUNIT,
    ZETTAKELVIN = KELVIN+ZETTAUNIT,
    YOTTAKELVIN = KELVIN+YOCTOUNIT,

    CELSIUS,

    FAHRENHEIT,

    TEMP_UNID_MAX,
#   define LUMI_UNID_MIN TEMP_UNID_MAX
};

enum LUMI_UNID {

    CANDELA = LUMI_UNID_MIN,

    YOCTOCANDELA = CANDELA+YOCTOUNIT,
    ZEPTOCANDELA = CANDELA+ZEPTOUNIT,
    FEMTOCANDELA = CANDELA+FEMTOUNIT,
    ATTOCANDELA  = CANDELA+ATTOUNIT,
    PICOCANDELA  = CANDELA+PICOUNIT,
    NANOCANDELA  = CANDELA+NANOUNIT,
    MICROCANDELA = CANDELA+MICROUNIT,
    MILLICANDELA = CANDELA+MILLIUNIT,
    CENTICANDELA = CANDELA+CENTIUNIT,
    DECICANDELA  = CANDELA+DECIUNIT,
    DECACANDELA  = CANDELA+DECAUNIT,
    HECTOCANDELA = CANDELA+HECTOUNIT,
    KILOCANDELA  = CANDELA+KILOUNIT,
    MEGACANDELA  = CANDELA+MEGAUNIT,
    GIGACANDELA  = CANDELA+GIGAUNIT,
    TERACANDELA  = CANDELA+TERAUNIT,
    PETACANDELA  = CANDELA+PETAUNIT,
    EXACANDELA   = CANDELA+EXAUNIT,
    ZETTACANDELA = CANDELA+ZETTAUNIT,
    YOTTACANDELA = CANDELA+YOTTAUNIT,

    LUMI_UNID_MAX,

};

#define UNID_CHECK(kind) static inline _Bool kind##_UNID_CHECK(int i) {\
    return kind##_UNID_MIN <= i && i < kind##_UNID_MAX;}

UNID_CHECK(TIME)
UNID_CHECK(DATA)
UNID_CHECK(MASS)
UNID_CHECK(DIST)
UNID_CHECK(CRNT)
UNID_CHECK(TEMP)
UNID_CHECK(LUMI)


static const char *UNDT_MON_FULL[] = {
    [1]
struct unid_month {
    
}
struct unid_calendar {
    const char *week_names;
    const char *month_names;
    const char *
    unsigned hour;
    unsigned second;
    unsigned day;
    unsigned week;
    unsigned month;
    unsigned fortnight;
    unsigned year;
    unsigned decade;
    unsigned century;
    unsigned millennium;
    unsigned epoch;
    unsigned cycle;
};


typedef void (*unit_multiproc) (void *, void *);


struct unit_multiplier {
    union {
        unsigned long long  i;
        long double         f;
        unsigned long long  q[2];
    } nu, de;
    const char *symbol;
    unit_multiproc fn;
};

static const
union unit_multipliers {
    struct     unit_multiplier list[UNIT_UNIDS];
    struct {
        struct unit_multiplier base[BASE_UNIDS];
        struct unit_multiplier time[TIME_UNIDS];
        struct unit_multiplier data[DATA_UNIDS];
        struct unit_multiplier mass[MASS_UNIDS];
        struct unit_multiplier dist[DIST_UNIDS];
        struct unit_multiplier crnt[CRNT_UNIDS];
        struct unit_multiplier temp[TEMP_UNIDS];
        struct unit_multiplier lumi[LUMI_UNIDS];
    };

} unit = {
    /*
    unit
    */
    .list={
        [BASEUNIT]  = {{1}, {ONE}},
        [ATTOUNIT]  = {{1}, {QUINTILLION}, u8"a"},
        [FEMTOUNIT] = {{1}, {QUADRILLION}, u8"f"},
        [PICOUNIT]  = {{1}, {TRILLION}, u8"p"},
        [NANOUNIT]  = {{1}, {BILLION}, u8"n"},
        [MICROUNIT] = {{1}, {MILLION}, u8"µ"},
        [MILLIUNIT] = {{1}, {THOUSAND}, u8"m"},
        [CENTIUNIT] = {{1}, {HUNDRED}, u8"c"},
        [DECIUNIT]  = {{1}, {ONE}, u8"d"},
        [DECAUNIT]  = {{TEN},            {1}, u8"da"},
        [HECTOUNIT] = {{HUNDRED},        {1}, u8"h"},
        [KILOUNIT]  = {{THOUSAND},    {1}, u8"k"},
        [MEGAUNIT]  = {{MILLION},     {1}, u8"M"},
        [GIGAUNIT]  = {{BILLION},     {1}, u8"G"},
        [TERAUNIT]  = {{TRILLION},    {1}, u8"T"},
        [PETAUNIT]  = {{QUADRILLION}, {1}, u8"P"},
        [EXAUNIT]   = {{QUINTILLION}, {1}, u8"E"},
        [MILLISECOND] = {{1}, {THOUSAND}, u8"ms"},
        [MICROSECOND] = {{1}, {MILLION},  u8"μs"},
        [NANOSECOND]  = {{1}, {BILLION},  u8"ns"},
        
        [SECOND]    = {{1}, {1}, u8"s"},
        [MINUTE]    = {{60},             {1}, u8"min"},
        [HOUR]      = {{60*60},          {1}, u8"h"},

        [EARTH_DAY] = {{60*60*24},       {1}, u8"d"},
        [MARTIAN_SOL] = {{24*60*60+39*60+25}, {1}, u8"sol"}, 

        [GREGORIAN_WEEK]       = {{60*60*24*7},     {1}, u8"w"},
        [GREGORIAN_FORTNIGHT]  = {{1209600},           {1}, u8"ftn"},
        [GREGORIAN_MONTH]      = {{2629746},           {1}, u8"m"},
        [GREGORIAN_YEAR]       = {{31556952},          {1}, u8"y"},
        [GREGORIAN_DECADE]     = {{31556952000ULL},    {1}, u8""},
        [GREGORIAN_MILLENNIUM] = {{31556952000000ULL}, {1}}, u8""},

#   if THIS_IS_PLANET_EARTH
#   define WEEK         GREGORIAN_WEEK 
#   define MONTH        GREGORIAN_MONTH 
#   define YEAR         GREGORIAN_YEAR 
#   define DECADE       GREGORIAN_DECADE 
#   define CENTURY      GREGORIAN_CENTURY 
#   define MILLENNIUM   GREGORIAN_MILLENNIUM 

        [INCH]  = {{254},       {1000}, u8"in"},
        [FOOT]  = {{254*12},    {1000}, u8"ft"},
        [YARD]  = {{254*36},    {1000}, u8"yd"},
        [MILE]  = {{16093440},  {1000}, u8"mi"},
        [METER] = {{1},         {1},    u8"m"},
        
        [BIT]    = {ONE, 8, u8"b"},
        [NIBBLE] = {ONE, 4, u8""},

        [KIBIBIT] = {{1ULL<<10}, {8}, u8"kib"},
        [MEBIBIT] = {{1ULL<<20}, {8}, u8"Mib"},
        [GIBIBIT] = {{1ULL<<30}, {8}, u8"Gib"},
        [TEBIBIT] = {{1ULL<<40}, {8}, u8"Tib"},
        [PEBIBIT] = {{1ULL<<50}, {8}, u8"Pib"},
        [EXBIBIT] = {{1ULL<<60}, {8}, u8"Eib"},

        [KILOBIT] = {{THOUSAND},    {8}, u8"kb"},
        [MEGABIT] = {{MILLION},     {8}, u8"Mb"},
        [GIGABIT] = {{BILLION},     {8}, u8"Gb"},
        [TERABIT] = {{TRILLION},    {8}, u8"Tb"},
        [PETABIT] = {{QUADRILLION}, {8}, u8"Pb"},
        [EXABIT]  = {{QUINTILLION}, {8}, u8"Eb"},
        
        [KILOBYTE] = {{THOUSAND},    {1}, u8"kB"},
        [MEGABYTE] = {{MILLION},     {1}, u8"MB"},
        [GIGABYTE] = {{BILLION},     {1}, u8"GB"},
        [TERABYTE] = {{TRILLION},    {1}, u8"TB"},
        [PETABYTE] = {{QUADRILLION}, {1}, u8"PB"},
        [EXABYTE]  = {{QUINTILLION}, {1}, u8"EB"},
    },
};

#include <stdio.h>

void test(void) {
    const wchar_t *p = 0;
}