#pragma once

int include_locale_h(Lib *self, FILE *file) {

    __basedef(locale_h, "<locale.h>")

    __dentr(enums, Enum[])
        __predef("LC")
            EDEF_(LC,ALL)
            EDEF_(LC,COLLATE)
            EDEF_(LC,CTYPE)
            EDEF_(LC,MESSAGES)
            EDEF_(LC,MONETARY)
            EDEF_(LC,NUMERIC)
            EDEF_(LC,TIME)
        __preend("LC")
        __predef("LC")
            EDEF_(LC,ALL_MASK)
            EDEF_(LC,COLLATE_MASK)
            EDEF_(LC,CTYPE_MASK)
            EDEF_(LC,MESSAGES_MASK)
            EDEF_(LC,MONETARY_MASK)
            EDEF_(LC,NUMERIC_MASK)
            EDEF_(LC,TIME_MASK)
        __preend("LC", .fmt="x")
         
    __dexit(enums)

    __dentr(structs, Struct[])
        __memdef(lconv_s)
        __member(lconv_s, decimal_point, "chars")
        __member(lconv_s, thousands_sep, "chars")
        __member(lconv_s, grouping, "chars")
        __member(lconv_s, int_curr_symbol, "chars")
        __member(lconv_s, currency_symbol, "chars")
        __member(lconv_s, mon_decimal_point, "chars")
        __member(lconv_s, mon_thousands_sep, "chars")
        __member(lconv_s, mon_grouping, "chars")
        __member(lconv_s, positive_sign, "chars")
        __member(lconv_s, negative_sign, "chars")
        __member(lconv_s, int_frac_digits, "char")
        __member(lconv_s, frac_digits, "char")
        __member(lconv_s, p_cs_precedes, "char")
        __member(lconv_s, p_sep_by_space, "char")
        __member(lconv_s, n_cs_precedes, "char")
        __member(lconv_s, n_sep_by_space, "char")
        __member(lconv_s, p_sign_posn, "char")
        __member(lconv_s, n_sign_posn, "char")
        __member(lconv_s, int_p_cs_precedes, "char")
        __member(lconv_s, int_p_sep_by_space, "char")
        __member(lconv_s, int_n_cs_precedes, "char")
        __member(lconv_s, int_n_sep_by_space, "char")
        __member(lconv_s, int_p_sign_posn, "char")
        __member(lconv_s, int_n_sign_posn, "char")
        __enddef(lconv_s)
    __dexit(structs)
    __baseret(locale_h)
}

int test_locale_h(Lib *self, FILE *file) {
#   ifndef BLTN_DUPLOCALE
#   define BLTN_DUPLOCALE duplocale
#   endif
#   ifndef BLTN_USELOCALE
#   define BLTN_USELOCALE uselocale
#   endif
#   ifndef BLTN_NEWLOCALE
#   define BLTN_NEWLOCALE newlocale
#   endif
#   ifndef BLTN_FREELOCALE
#   define BLTN_FREELOCALE freelocale
#   endif
#   ifndef BLTN_LOCALECONV
#   define BLTN_LOCALECONV localeconv
#   endif
#   ifndef BLTN_SETLOCALE
#   define BLTN_SETLOCALE setlocale
#   endif
    self->duplocale=BLTN_DUPLOCALE;
    self->uselocale=BLTN_USELOCALE;
    self->newlocale=BLTN_NEWLOCALE;
    self->freelocale=BLTN_FREELOCALE;
    self->localeconv=BLTN_LOCALECONV;
    self->setlocale=BLTN_SETLOCALE;
    return 0;
}