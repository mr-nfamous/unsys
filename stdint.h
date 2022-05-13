
#pragma once

int include_stdint_h(Lib *self, FILE *file) {

    __basedef(stdint_h, "<stdint.h>")

    __dentr(enums, Enum[])
        __predef("")
            EREF(WCHAR_MAX)
            EREF(WCHAR_MIN)
            EREF(INT8_MIN)
            EREF(INT8_MAX)
            EREF(UINT8_MAX)
            EREF(INT16_MIN)
            EREF(INT16_MAX)
            EREF(UINT16_MAX)
            EREF(INT32_MIN)
            EREF(INT32_MAX)
            EREF(UINT32_MAX)
            EREF(INT64_MIN)
            EREF(INT64_MAX)
            EREF(UINT64_MAX)
            EREF(INTMAX_MIN)
            EREF(INTMAX_MAX)
            EREF(UINTMAX_MAX)
            EREF(SIG_ATOMIC_MAX)
            EREF(SIG_ATOMIC_MIN)
            EREF(WINT_MAX)
            EREF(WINT_MIN)
            EREF(INTPTR_MIN)
            EREF(INTPTR_MAX)
            EREF(UINTPTR_MAX)
            EREF(PTRDIFF_MIN)
            EREF(PTRDIFF_MAX)
            EREF(SIZE_MAX)
        __preend("")
    __dexit(enums)

    __baseret(stdint_h)
}
