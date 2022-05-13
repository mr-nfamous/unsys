#pragma once

int include_langinfo_h(Lib *self, FILE *file) {

    __basedef(langinfo_h, "<langinfo.h>")

    __dentr(enums, Enum[])
        __predef("")
        // type nl_item
            // LC_CTYPE
            EREF(CODESET)
            
            // LC_TIME
            EREF(D_T_FMT) 
            EREF(D_FMT)
            EREF(T_FMT)
            EREF(T_FMT_AMPM)
            EREF(AM_STR)
            EREF(PM_STR)
            EREF(DAY_1)
            EREF(DAY_2)
            EREF(DAY_3)
            EREF(DAY_4)
            EREF(DAY_5)
            EREF(DAY_6)
            EREF(DAY_7)
            EREF(ABDAY_1)
            EREF(ABDAY_2)
            EREF(ABDAY_3)
            EREF(ABDAY_4)
            EREF(ABDAY_5)
            EREF(ABDAY_6)
            EREF(ABDAY_7)
            EREF(MON_1)
            EREF(MON_2)
            EREF(MON_3)
            EREF(MON_4)
            EREF(MON_5)
            EREF(MON_6)
            EREF(MON_7)
            EREF(MON_8)
            EREF(MON_9)
            EREF(MON_10)
            EREF(MON_11)
            EREF(MON_12)
            EREF(ABMON_1)
            EREF(ABMON_2)
            EREF(ABMON_3)
            EREF(ABMON_4)
            EREF(ABMON_5)
            EREF(ABMON_6)
            EREF(ABMON_7)
            EREF(ABMON_8)
            EREF(ABMON_9)
            EREF(ABMON_10)
            EREF(ABMON_11)
            EREF(ABMON_12)
            EREF(ERA)
            EREF(ERA_D_FMT)
            EREF(ERA_D_T_FMT)
            EREF(ERA_T_FMT)
            
            // LC_NUMERIC
            EREF(ALT_DIGITS) 
            EREF(RADIXCHAR)
            EREF(THOUSEP)

            // LC_MESSAGES
            EREF(YESEXPR) 
            EREF(NOEXPR)

            // LC_MONEYTARY
            EREF(CRNCYSTR) 
            EREF(INT_CURRENCY_SYMBOL)
            
        __preend("")
    __dexit(enums)

    __dentr(structs, Struct[])
    __dexit(structs)
    __baseret(langinfo_h)
}

int test_langinfo_h(Lib *self, FILE *file) {
#   ifndef BLTN_NL_LANGINFO
#   define BLTN_NL_LANGINFO nl_langinfo
#   endif
#   ifndef BLTN_NL_LANGINFO_L
#   define BLTN_NL_LANGINFO_L nl_langinfo_l
#   endif
    self->nl_langinfo=BLTN_NL_LANGINFO;
    self->nl_langinfo_l=BLTN_NL_LANGINFO_L;
    return 0;
}