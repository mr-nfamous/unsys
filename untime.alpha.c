
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#include "untime.h"

static const struct timens timens = {
    .t_nanosecond   = {.tv_nsec=1L},
    .t_microsecond  = {.tv_nsec=1L*THOUSAND},
    .t_millisecond  = {.tv_nsec=MILLION*1L},
    .t_second       = {.tv_sec =INT64_C(1)},
    .t_minute       = {.tv_sec =INT64_C(60)},
    .t_hour         = {.tv_sec =INT64_C(3600)},
    .t_day          = {.tv_sec =INT64_C(86400)},
    .t_week         = {.tv_sec =INT64_C(86400)*7},
    .t_nil          = {0},
    .t_minimum      = {
        .tv_sec=TIMENS_SEC_MIN,
        .tv_nsec=TIMENS_NSEC_MIN,
    },
    .t_maximum      = {
        .tv_sec=TIMENS_SEC_MAX,
        .tv_nsec=TIMENS_NSEC_MAX,
    },
    .ops = {
        .list={
            /*
            [OP_UN_IINC]    = timens_iinc,
            [OP_UN_IDEC]    = timens_idec,
            */
            [OP_UN_CLR]     = timens_clr,
            [OP_UN_IABS]    = timens_iabs,
            [OP_UN_INEG]    = timens_ineg,
            [OP_UN_IINV]    = NULL,
            [OP_UN_INC]     = timens_inc,
            [OP_UN_DEC]     = timens_dec,
            [OP_UN_ABS]     = timens_abs,
            [OP_UN_NEG]     = timens_neg,
            [OP_UN_POS]     = timens_pos,
            [OP_UN_OK]      = timens_ok,
            [OP_UN_ROUND]   = timens_round,
            [OP_UN_TRUNC]   = timens_trunc,
            [OP_UN_CEIL]    = timens_ceil,
            [OP_UN_NEAR]    = timens_near,
            [OP_UN_NEXT]    = timens_next,
            [OP_UN_FLOOR]   = timens_floor,
            [OP_UN_NOT]     = timens_not,
            
            [OP_BI_ADD]     = timens_add,
            [OP_BI_IADD]    = timens_iadd,
            [OP_BI_IFADD]   = timens_iadd,
            [OP_BI_ILADD]   = timens_iadd,
            [OP_BI_FADD]    = timens_fadd,
            [OP_BI_LADD]    = timens_ladd,
            [OP_BI_SUB]     = timens_sub,
            [OP_BI_FSUB]    = timens_fsub,
            [OP_BI_MUL]     = timens_mul,
            [OP_BI_FMUL]    = timens_fmul,
            [OP_BI_MOD]     = timens_mod,
            [OP_BI_DIV]     = timens_div,

            [OP_BI_CMP]     = timens_cmp,

            [OP_CMP_LT]     = timens_lt,
            [OP_CMP_LE]     = timens_le,
            [OP_CMP_EQ]     = timens_eq,
            [OP_CMP_NE]     = timens_ne,
            [OP_CMP_GT]     = timens_gt,
            [OP_CMP_GE]     = timens_ge,
        },
    }
};

timens_t *
timens_fromtm(timens_t *restrict v, const union timens_tm *restrict argv) { 
    timens_t t = {
        .tv_sec  = argv->t_seconds,
        .tv_nsec = argv->t_nanoseconds,
    };
    if ((t.tv_sec < INT64_C(0)) || (t.tv_nsec < 0L) ) {
        the_flowjob: {
            return unexc_ERANGE(0);
        }
    }
    intmax_t arg;
    int i;
    for (i=t_microseconds; i < t_minutes; ++i) {
        if (argv->t_list[i] < 0) {
            goto the_flowjob;
        }
        arg = timens.t_list[i].tv_nsec;
        arg *= argv->t_list[i];
        arg += t.tv_nsec;
        if (arg > TIMENS_NSEC_MAX) {
            imaxdiv_t x = imaxdiv(arg, BILLION);
            t.tv_sec += (time_t) x.quot;
            t.tv_nsec = (long) x.rem;
        }
        else {
            t.tv_nsec = (long) arg;
        }
    }
    for ( ; i <= t_weeks; ++i) {
        if (argv->t_list[i] < 0) {
            goto the_flowjob;
        }
        arg = timens.t_list[i].tv_sec;
        arg *= argv->t_list[i];
        arg += t.tv_sec;
        if (arg > TIMENS_SEC_MAX) {
            goto the_flowjob;
        }
        t.tv_sec = (time_t) arg;
    }
    if (argv->t_neg) {
        *v = (t.tv_nsec ? timens_POS_TO_NEG_1 : timens_POS_TO_NEG_0)(&t);
    }
    else {
        *v = t;
    }
    return v;
}

timens_t *
timens_fromkw(timens_t *v, ...) {
    intmax_t sec  = INTMAX_C(0);
    intmax_t nsec = INTMAX_C(0);
    intmax_t lim  = TIMENS_SEC_MAX;
    va_list  va;
    va_start(va, v);
    int s = 0;
    for (kw_t arg; ; ) {
        arg = va_arg(va, kw_t);
        intmax_t val = arg.u;
        if (arg.k < t_minutes) {
            if (arg.k == t_seconds) {
                if (val > lim) {
                    the_flowjob: {
                        va_end(va);
                        return unexc_ERANGE(0);
                    }
                }
                sec += val;
                break;
            }
            val *= (intmax_t) timens.t_list[arg.k].tv_nsec;
            val += nsec;
            if (val >= BILLION) {
                imaxdiv_t x = imaxdiv(val, BILLION);
                if (x.quot > lim) {
                    goto the_flowjob;
                }
                sec += x.quot;
                lim = TIMENS_SEC_MAX-sec;
                nsec = x.rem;
            }
            else {
                nsec = val;
            }
        }
        else {
            if (arg.k == t_neg) {
                s = 1;
                continue;
            }
            val *= (intmax_t) timens.t_list[arg.k].tv_sec;
            if (val > lim) {
                goto the_flowjob;
            }
            lim -= val;
            sec += val;
        }
    }
    if (s) {
        if (nsec) {
            *v = (timens_t) {
                .tv_sec  = (time_t) (INTMAX_C(0)-sec-INTMAX_C(1)),
                .tv_nsec = BILLION-(long) nsec,
            };
        }
        else {
            *v = (timens_t) {
                .tv_sec = (time_t) INTMAX_C(0)-sec,
                .tv_nsec = 0L,
            };
        }
    }
    else {
        *v = (timens_t) {
            .tv_sec =(time_t) sec,
            .tv_nsec=(long)  nsec,
        };
    }
    va_end(va);
    return v;
}

int 
timens_repr(const timens_t *t, FILE *f, const char *fmt) {
    char buf[128];
    if (f == NULL) {
        f = stdout;
    }
    if (fmt != NULL) {
        if (fprintf(f, "%s", fmt) < 0) {
            unthrow(0, "printf");
        }
    }
    return fprintf(
        f, 
        "{.tv_sec=%+jd, .tv_nsec=%jd}",
        (intmax_t) t->tv_sec,
        (intmax_t) t->tv_nsec);
}

int 
timens_cmp(const timens_t *a, const timens_t *b) {
    return       (a == b)           ? 0 :
        (a->tv_sec  >  b->tv_sec)   ? 1 : 
        (a->tv_sec  <  b->tv_sec)   ? 0-1:
        (a->tv_nsec == b->tv_nsec)  ? 0 :
        (a->tv_nsec <  b->tv_nsec)  ? 0-1: 1;
}

int
timens_ok(const timens_t *t) {
    return timens_OK(t);
}

bool 
timens_is(const timens_t *t) {
    return timens_IS(t);
}

bool 
timens_not(const timens_t *t) {
    return !timens_IS(t);
}

bool 
timens_lt(const timens_t *a, const timens_t *b) {
    return      a == b         ? false 
    :   a->tv_sec  < b->tv_sec ? true 
    :   a->tv_sec  > b->tv_sec ? false 
    :   a->tv_nsec < b->tv_nsec;
}

bool 
timens_le(const timens_t *a, const timens_t *b) {
    return       a == b         ? true 
    :   a->tv_sec   > b->tv_sec ? false 
    :   a->tv_sec   < b->tv_sec ? true 
    :   a->tv_nsec <= b->tv_nsec;
}

bool 
timens_eq(const timens_t *a, const timens_t *b) {
    return a->tv_sec == b->tv_sec && a->tv_nsec == b->tv_nsec;
}

bool 
timens_ne(const timens_t *a, const timens_t *b) {
    return a->tv_sec != b->tv_sec || a->tv_nsec != b->tv_nsec;
}

bool 
timens_gt(const timens_t *a, const timens_t *b) {
    return      a == b          ? false 
    :   a->tv_sec  > b->tv_sec  ? true
    :   a->tv_sec  < b->tv_sec  ? false 
    :   a->tv_nsec > b->tv_nsec;
}

bool 
timens_ge(const timens_t *a, const timens_t *b) {
    return       a == b         ? true
    :   a->tv_sec  <  b->tv_sec ? false
    :   a->tv_sec  >  b->tv_sec ? true
    :   a->tv_nsec >= b->tv_nsec;
}

timens_t *
timens_ceil(timens_t *v, const timens_t *t) {
    timens_t r = *t;
    if (!++r.tv_sec) {
        if (r.tv_nsec) {
            if (!timens_NSEC_OK(r.tv_nsec)) {
                return errno=ERANGE, NULL;
            }
            r.tv_nsec = BILLION-r.tv_nsec;
        }
    }
    else {
        if (!timens_SEC_OK(r.tv_sec)) {
            return errno=ERANGE, NULL;
        }
    }
    return *v=r, v;
}

timens_t *
timens_floor(timens_t *v, const timens_t *t) {
    timens_t r = *t;
    if (!r.tv_sec--) {
        if (r.tv_nsec) {
            if (!timens_NSEC_OK(r.tv_nsec)) {
                return errno=ERANGE, NULL;
            }
            r.tv_nsec = BILLION-r.tv_nsec;
        }
    }
    else {
        if (!timens_SEC_OK(r.tv_sec)) {
            return errno=ERANGE, NULL;
        }
    }
    return *v=r, v;
}

timens_t *
timens_trunc(timens_t *v, const timens_t *t) {
    timens_t r = {.tv_sec=t->tv_sec};
    if (!timens_SEC_OK(r.tv_sec)) {
        return errno=ERANGE, NULL;
    }
    return *v=r, v;
}

timens_t *
timens_near(timens_t *v, const timens_t *t) {
    timens_t r;
    if (t->tv_nsec == 0L) {
        if (!timens_SEC_OK(t->tv_sec)) {
            the_flowjob: {
                return errno=ERANGE, NULL;
            }
        }
        return *v=*t, v;
    }
    if (!timens_NSEC_OK(t->tv_nsec)) {
        goto the_flowjob;
    }
    if (t->tv_sec < 0) {
        if (t->tv_nsec < ((TIMENS_NSEC_MAX+1)/2)) {
            r.tv_sec = t->tv_sec;
        }
        else {
            r.tv_sec = t->tv_sec+1;
        }
        if (r.tv_sec < TIMENS_SEC_MIN) {
            goto the_flowjob;
        }
    }
    else {
        if (t->tv_nsec < ((TIMENS_NSEC_MAX+1)/2)) {
            r.tv_sec = t->tv_sec;
        }
        else {
            r.tv_sec = t->tv_sec+1;
        }
        if (r.tv_sec > TIMENS_SEC_MAX) {
            goto the_flowjob;
        }
    }
    r.tv_nsec = 0L;
    return *v=r, v;
}

timens_t *
timens_next(timens_t *v, const timens_t *t) {
    timens_t r;
    if (t->tv_nsec) {
        if (t->tv_sec) {
            if (t->tv_sec < 0) {
                r.tv_sec = t->tv_sec-1;
                if (r.tv_sec < TIMENS_SEC_MIN) {
                    return errno=ERANGE, NULL;
                }
            }
            else {
                r.tv_sec = t->tv_sec+1;
                if (r.tv_sec > TIMENS_SEC_MAX) {
                    return errno=ERANGE, NULL;
                }
            }
        }
        r.tv_nsec = 0;
    }
    else {
        if (timens_SEC_OK(t->tv_sec)) {
            return *v=*t, v;
        }
        else {
            return errno=ERANGE, NULL;
        }
    }
    return *v=r, v;
}

timens_t *
timens_round(timens_t *v, const timens_t *t, ROUND_TO_T mode) {
    timens_t r;
    if (mode > ROUND_TO_FUNC && mode < ROUND_TO_T_MAX) {
        timens_t *(*f)(timens_t *, const timens_t *);
        f = timens.ops.un_round.list[mode];
        if (f(&r, t) != NULL) {
            return *v=r, v;
        }
    }
    return errno=EINVAL, NULL;
}

timens_t *
timens_clr(timens_t *restrict t) {
    return memset(t, 0, sizeof(timens_t));
}

time_t
timens_time(const timens_t *restrict t) {
    return t->tv_sec;
}

timens_t
timens_timespec(const timens_t *restrict t) {
    return *t;
}

timeus_t
timens_timeval(const timens_t *restrict t) {
    
    return (struct timeval){
        .tv_sec=t->tv_sec,
        .tv_usec=t->tv_nsec/1000,
    };
}

double
timens_ftime(const timens_t *restrict t) {
    double z;
    timens_t r;
    if (t->tv_sec < 0) {
        if (t->tv_sec < TIMENS_SEC_MIN) {
            the_flowjob: {
                return errno=ERANGE, 0-1;
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
    if (timens_NSEC_OK(t->tv_nsec)) {
        goto the_flowjob;
    }
    const unsigned char b = BITLEN64((uint64_t) t->tv_sec);
    const double        x = TIMENS_FTIMES[b];
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
        z = (x*t->tv_sec+t->tv_nsec/TIMENS_FTIMENS[b])/x;
        if (t == &r) {
            z = 0.0-z;
        }
    }
    the_end: {
        return z;
    }
}

int 
timens_sgn(timens_t *restrict v, const timens_t *t) {
    const int ok = timens_SGN(v, t);
    if (ok == false) {
        return errno=ERANGE, 0;
    }
    return ok;
}

timens_t * 
timens_init(timens_t *restrict t, time_t s, long ns) {
    timens_t v = {
        .tv_sec = s,
        .tv_nsec  = ns,
    };
    if (!timens_OK(&v)) {
        return errno=ERANGE, NULL;
    }
    return *t=v, t;
}

timens_t *
timens_fromftime(timens_t *restrict v, double s) {
    double i;
    timens_t t;
    if (s < 0.0) {
        double p = modf(0.0-s, &i);
        if (i > TIMENS_FSEC_MAX) {
            return errno=ERANGE, NULL;
        }
        t.tv_sec = 0-((time_t) i);
        if (p) {
            t.tv_nsec = BILLION-(long) (p*BILLION);
        }
        else {
            t.tv_nsec = 0L;
        }
    }
    else {
        t.tv_nsec = (long) (BILLION*modf(s, &i));
        if (i > TIMENS_FSEC_MAX) {
            return errno=ERANGE, NULL;
        }
        t.tv_sec = (time_t) i;
    }
    return *v=t, v;
}

timens_t *
timens_fromtime(timens_t *restrict v, time_t n, int b) {
    bool sign;
    if (!T_UNIT_OK(b)) {
        errno = EINVAL;
        return NULL;
    }
    if (n < 1) {
        if (!n) {
            return memset(v, 0, sizeof *v);
        }
        sign = true;
        n = INT64_C(0)-n;
    }
    else {
        sign = false;
    }
    const struct unit_multiplier *m = unit.list+base;

    return 0;
}

timens_t *
timens_frommsec(timens_t *restrict v, time_t ms) {
    return timens_FRAC_INIT(v, ms, THOUSAND, MILLION);
}

timens_t *
timens_fromusec(timens_t *v, time_t us) {
    return timens_FRAC_INIT(v, us, MILLION, 1000L);
}

timens_t *
timens_fromnsec(timens_t *v, time_t ns) {
    return timens_FRAC_INIT(v, ns, BILLION, 1L);
}

timens_t *
timens_iinc(timens_t *restrict v) {
    if (v->tv_nsec < TIMENS_NSEC_MAX) {
        v->tv_nsec++;
    }
    else {
        if (v->tv_sec >= TIMENS_SEC_MAX) {
            errno = ERANGE;
            return v;
        }
        *v = ((timens_t) {
            .tv_sec=v->tv_sec+1,
            .tv_nsec=TIMENS_NSEC_MIN,
        });
    }
    return v;
}

timens_t *
timens_idec(timens_t *restrict v) {
    if (v->tv_nsec > TIMENS_NSEC_MIN) {
        v->tv_nsec--;
    }
    else {
        if (v->tv_sec <= TIMENS_SEC_MIN) {
            errno = ERANGE;
            return NULL;
        }
        *v = ((timens_t) {
            .tv_sec=v->tv_sec-1,
            .tv_nsec=TIMENS_NSEC_MAX,
        });
    }
    return v;
}

timens_t *
timens_dec(timens_t *restrict v, const timens_t *restrict t) {
    timens_t copy = *t;
    if (!timens_idec(&copy)) {
        return NULL;
    }
    return *v=copy, v;
}

timens_t *
timens_inc(timens_t *restrict v, const timens_t *restrict t) {
    timens_t copy = *t;
    if (!timens_iinc(&copy)) {
        return NULL;
    }
    return *v=copy, v;
}

timens_t *
timens_iabs(timens_t *restrict v) {
    timens_t copy;
    if (!timens_abs(&copy, v)) {
        return NULL;
    }
    return *v=copy, v;
}

timens_t *
timens_ineg(timens_t *restrict v) {
    timens_t copy;
    if (!timens_neg(&copy, v)) {
        return NULL;
    }
    return *v=copy, v;
}

timens_t *
timens_pos(timens_t *restrict v, const timens_t *t) {
    if (!timens_OK(t)) {
        return errno=ERANGE, NULL;
    }
    if (v != t) {
        *v = *t;
    }
    return v;
}

timens_t * 
timens_abs(timens_t *restrict v, const timens_t *t) {
    if (t->tv_nsec) {
        if (!timens_NSEC_OK(t->tv_nsec)) {
            the_flowjob: {
                return errno=ERANGE, NULL;
            }
        }
        if (t->tv_sec < INT64_C(0)) {
            if (t->tv_sec < TIMENS_SEC_MIN) {
                goto the_flowjob;
            }
            *v = (timens_t){
                 .tv_sec=0-(t->tv_sec+1),
                 .tv_nsec=(BILLION-t->tv_nsec),
            };
        }
        else {
            if (t->tv_sec > TIMENS_SEC_MAX) {
                goto the_flowjob;
            }
            *v = *t;
        }
    }
    else {
        if (t->tv_sec < 0) {
            if (t->tv_sec < TIMENS_SEC_MIN) {
                goto the_flowjob;
            }
            *v = (timens_t){
                .tv_sec=0-t->tv_sec,
            };
        }
        else {
            if (t->tv_sec > TIMENS_SEC_MAX) {
                goto the_flowjob;
            }
            *v = *t;
        }
    }
    return v;
}

timens_t *
timens_neg(timens_t *restrict v, const timens_t *t) {
    if (!timens_OK(t)) {
        return errno=ERANGE, NULL;
    }
    return *v=timens_NEG(t), v;
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
        return errno=ERANGE, NULL;
    }
    return *v=t, v;
}

timens_t *
timens_fadd(timens_t *restrict v, const timens_t *a, double b) {
    timens_t t;
    return  timens_fromftime(&t, b)
        ?   timens_add(v, a, &t)
        :   NULL;
}

timens_t *
timens_iadd(timens_t *restrict a, const timens_t *b) {
    return timens_add(a, a, b);
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
        return errno=ERANGE, NULL;
    }
    return (*v=t), v;
}

timens_t *
timens_fsub(timens_t *restrict v, const timens_t *a, double b) {
    timens_t t;
    return  timens_fromftime(&t, b)
        ?   timens_sub(v, a, &t) 
        :   NULL;
}

timens_t *
timens_isub(timens_t *restrict a, const timens_t *b) {
    return timens_sub(a, a, b);
}

timens_t *
timens_mod(timens_t v[restrict], const timens_t *a, const timens_t *b) {
    if (timens_div(v, a, b) == 0L && errno != 0) {
        return NULL;
    }
    return v;
}

timens_t *
timens_mul(timens_t *restrict v, const timens_t *a, long b) {
    imaxdiv_t x;
    time_t s;
    long   p;
    if (b == 1L) {
        return *v=*a, v;
    }
    if (b < 1L) {
        if (b == 0L) {
            return *v=(timens_t){0}, v;
        }
        if (a->tv_sec < INT64_C(0)) {
            p = (0L-b)*(BILLION-a->tv_nsec);
            x.quot = intmax_DIVMOD(&x.rem, p, BILLION);
            s = (time_t) x.quot+b*(INT64_C(1)+a->tv_sec);
            if (s < TIMENS_SEC_MIN) {
                goto overflow;
            }
        }
        else {
            x.quot = intmax_DIVMOD(&x.rem, a->tv_nsec*b, BILLION);
            s = (time_t) x.quot+b*a->tv_sec;
            if (s > TIMENS_SEC_MAX) {
                goto overflow;
            }
        }
    }
    else {
        if (a->tv_sec < INT64_C(0)) {
            p = (0L-b)*(BILLION-a->tv_nsec);
            x.quot = intmax_DIVMOD(&x.rem, p, BILLION);
            s = (time_t) x.quot+b*(INT64_C(1)+a->tv_sec);
            if (s < TIMENS_SEC_MIN) {
                goto overflow;
            }
        }
        else {
            x.quot = intmax_DIVMOD(&x.rem, a->tv_nsec*b, BILLION);
            s = (time_t) x.quot+a->tv_sec*b;
            if (s > TIMENS_SEC_MAX) {
                goto overflow;
            }
        }
    }
    *v = (timens_t){
        .tv_sec=(time_t) s, 
        (long) x.rem,
    };
    return v;
    overflow: {
        return errno=ERANGE, NULL;
    }
}

timens_t *
timens_fmul(timens_t *restrict v, const timens_t *a, double b) {
    timens_t p;
    timens_t q;
    long double t=b;
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
    t = p.tv_nsec*(ldouble_t) b;
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
                    return errno=ERANGE, 0L;
                }
            }
            if (timens_neg(mod, &m) == NULL) {
                goto the_flowjob;
            }
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
        if (timens_neg(&m, &m) == NULL) {
            goto the_flowjob;
        }
        goto negative_quotient;
    }
    if (q.x > LONG_MAX) {
        goto the_flowjob;
    }
    return *mod=m, (long) q.x;
#endif
}

timens_t *
timens_ldiv(timens_t *restrict v, const timens_t *a, long b) {
    return NULL;
}

double
timens_fdiv(const timens_t * a, const timens_t *b) {
    ldouble_t x = 1E+9L*a->tv_sec+a->tv_nsec;
    ldouble_t y = 1E+9L*b->tv_sec+b->tv_nsec;
    return (double)x/y;
}

ptrdiff_t
timens_str(const timens_t *restrict t, char dst[restrict]) {
    char str[512];
    char tmp[16];
    timens_t tv;
    imaxdiv_t x;
    ptrdiff_t i = PTRDIFF_C(0);
    div_t p, q, r;
    int j;
    str[i++] = 'T';
    if (t->tv_sec > INT64_C(0)) {
        tv = *t;
        str[i++] = '+';
    }
    else {
        if (t->tv_sec) {
            str[i++] = '-';
            tv = t->tv_nsec 
                ? timens_NEG_TO_POS_1(t)
                : timens_NEG_TO_POS_0(t);
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
    if (tv.tv_sec < timens.t_minute.tv_sec) {
        x.rem = tv.tv_sec;
        goto the_subminute;
    }
    if (tv.tv_sec >= timens.t_week.tv_sec) {
        x = imaxdiv(tv.tv_sec, timens.t_week.tv_sec);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdw", x.quot);
        if (j < 0) {
            return j;
        };
        i += j;
    }
    else {
        x.rem = tv.tv_sec;
    }
    if (x.rem >= timens.t_day.tv_sec) {
        x = imaxdiv(x.rem, timens.t_day.tv_sec);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdd", x.quot);
        if (j < 0) {
            return j;
        }
        i += j;
    }
    if (x.rem >= timens.t_hour.tv_sec) {
        x = imaxdiv(x.rem, timens.t_hour.tv_sec);
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jdh", x.quot);
        if (j < 0) {
            return j;
        }
        i += j;
    }
    if (x.rem >= timens.t_minute.tv_sec) {
        x = imaxdiv(x.rem, timens.t_minute.tv_sec);
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
            (void) 0;
        }
        j = snprintf(str+i, (sizeof str)-(size_t) i, "%jd", x.rem);
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
    // mmm'uuu'nnn 
    // p.quot = mmm'uuu, p.rem = nnn
    // q.quot = mmm, q.rem = uuu
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
            unthrow(EINVAL, "memcpy returned NULL???");
        }
        return i;
    }
}


timens_t *
timens_xmul(timens_t *v, timens_t *a, timens_t *b) {
#ifdef __SIZEOF_INT128__
    __int128_t s;
    timens_t p;
    timens_t q;
    timens_t t;
    bool neg;
    if (a->tv_sec < 0) {
        p=timens_NEG(a), a=&p;
        if (b->tv_sec < 0) {
            neg=false, q=timens_NEG(b), b=&q;
        }
        else {
            neg=true;
        }
    }
    else {
        if (b->tv_sec < 0) {
            neg=true, q=timens_NEG(b), b=&q;
        }
        else {
            neg=false;
        }
    }
    if (a->tv_sec > TIMENS_SEC_MAX) {
        bad_flojo: {
            errno = ERANGE;
            return NULL;
        }
    }
    if (b->tv_sec > TIMENS_SEC_MAX) {
            goto bad_flojo;
    }
    s = (__int128_t) a->tv_nsec*b->tv_nsec;
    t.tv_nsec = (long) (s%BILLION);
    s /= BILLION;
    s += (__int128_t) a->tv_sec*b->tv_sec;
    if (s > TIMENS_SEC_MAX) {
        goto bad_flojo;
    }
    t.tv_sec = (time_t) s;
#endif
    *v = neg ? timens_NEG(&t) : t;
    return v;
}


#include "test_untime.h"

int main(void) {
    errno = 0;
    char res[512] = {0};
    /*
    timens_ops_test(stdout);
    timens_cmp_test(stdout);
    timens_t pos_zero   = {.tv_sec=0,       .tv_nsec=0};
    timens_t pos_ns     = *TIMENS_NANOSECOND;
    timens_t pos_us     = *TIMENS_MICROSECOND;
    timens_t pos_ms     = *TIMENS_MILLISECOND;
    timens_t pos_sec    = *TIMENS_SECOND;
    timens_t pos_min    = *TIMENS_MINUTE;
    timens_t pos_hour   = *TIMENS_HOUR;
    timens_t pos_day    = *TIMENS_DAY;
    timens_t pos_week   = *TIMENS_WEEK;
    timens_t pos_max    = {
        .tv_sec=TIMENS_SEC_MAX,
        .tv_nsec=TIMENS_NSEC_MAX,
    };
    timens_t neg_ns     = timens_NEG(&pos_ns);
    timens_t neg_us     = timens_NEG(&pos_us);
    timens_t neg_ms     = timens_NEG(&pos_ms);
    timens_t neg_sec    = timens_NEG(&pos_sec);
    timens_t neg_min    = timens_NEG(&pos_min);
    timens_t neg_hour   = timens_NEG(&pos_hour);
    timens_t neg_day    = timens_NEG(&pos_day);
    timens_t neg_week   = timens_NEG(&pos_week);
    timens_t neg_max    = timens_NEG(&pos_max);
    if (0) {
        printf(
        "neg_max.tv_sec=%jd\n"
        "neg_max.tv_nsec=%ld\n",
        (intmax_t) neg_max.tv_sec,
        neg_max.tv_nsec);
    }
    timens_t sum;
    if (errno) {
        printf("errno?...\n");
    }

    if (0) {
        timens_neg_test(&neg_max);
        timens_neg_test(&pos_sec);
        timens_neg_test(&pos_min);
        timens_neg_test(&pos_max);
        timens_neg_test(&neg_sec);
        timens_neg_test(&neg_min);
        printf("all timens_neg tests passed: errno=%d\n", errno);
    }
    timens_t self = {0};
    timens_str(&pos_hour, res);
    timens_ftime_test(&pos_hour);
    if (1) {
        timens_fromftime_test(&self, 99.9);
    }
    timens_t flt_pos[] = {
        {.tv_sec=999999,.tv_nsec=123456789},
        {.tv_sec=9999999,.tv_nsec=123456780},
        {.tv_sec=99999999,.tv_nsec=123456700},
        {.tv_sec=999999999,.tv_nsec=123456000},
        {.tv_sec=9999999999,.tv_nsec=123450000},
        {.tv_sec=99999999999,.tv_nsec=123400000},
        {.tv_sec=999999999999,.tv_nsec=123000000},
        {.tv_sec=9999999999999,.tv_nsec=120000000},
        {.tv_sec=99999999999999,.tv_nsec=100000000},
        {.tv_sec=999999999999999,.tv_nsec=123456789},
        {0},
    };

    if (0) {
        for (timens_t *tk=flt_pos; tk->tv_sec; tk++) {
            timens_ftime_test(tk);
        }
    }

    if (1) {
           // printf("str(pos_hour) => \"%s\"\n", res);
        
        //printf("self = %.512s\n", res);
        
        if (0)   { 
            timens_add_test(&pos_day, &pos_hour);
            timens_add_test(&pos_day, &neg_hour);
            timens_add_test(&neg_day, &pos_hour);
            timens_add_test(&neg_day, &neg_hour);
        }
        if (0) {
            timens_sub_test(&pos_day, &pos_hour);
            timens_sub_test(&pos_day, &neg_hour);
            timens_sub_test(&neg_day, &pos_hour);
            timens_sub_test(&neg_day, &neg_hour);
        }
        if (0) {
            timens_mul_test(&pos_day, 0+2L);
            timens_mul_test(&pos_day, 0-2L);
            timens_mul_test(&neg_day, 0+2L);
            timens_mul_test(&neg_day, 0-2L);
        }
        if (1) {
            timens_div_test(&pos_day, &pos_hour);
            timens_div_test(&pos_day, &neg_hour);
            timens_div_test(&neg_day, &pos_hour);
            timens_div_test(&neg_day, &neg_hour);
        }
    }
        
    char lhs[512] = {0};
    char rhs[512] = {0};
    */
    // printf("micro = %d\n", (int) timens.t_list[t_microseconds].tv_nsec);
    /*
    if (0) {
        (void) printf("%d\n", snprintf(res, sizeof res, ""));
        return 0;
    }
    if (0) {
        memset(lhs, 0xff, 8);
        memset(lhs+8, 00, (sizeof lhs)-8);
        snprintf(lhs, 8, "%s", "abc");
        printf(
            "%d, %d, %d, %d, %d, %d, %d, %d\n",
            lhs[0],
            lhs[1],
            lhs[2],
            lhs[3],
            lhs[4],
            lhs[5],
            lhs[6],
            lhs[7]);
        if (1) {
            return 0;
        }
    }
    if (0) {
        timens_t pos_v = {.tv_sec=1};
        timens_t neg_v;
        timens_neg(&neg_v, &pos_v);
        timens_str(&pos_v, lhs);
        timens_str(&neg_v, rhs);
        return printf("%s && %s\n", lhs, rhs);
    }
    
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
    };  
        {.tv_nsec=-1},
    };
    ptrdiff_t i = 0;
    ptrdiff_t j = 0;
    if (0) {
        for (; all[i].tv_nsec >= 0; ++i) {
            timens_neg(&self, all+i);
            (void) timens_str(all+i, lhs);
            (void) timens_str(&self, rhs);
            printf("%3td: %s\n%3td: %s\n",  i, lhs, i, rhs);
            
        //memset(res, 0, sizeof res);
        }
    }
    if (1) {

        struct timens_op oparg[] = {
            &pos_hour,  &pos_min,
            &neg_day,   &neg_hour,
            &pos_min,   &neg_min,
            &pos_hour,  &neg_hour,
            &neg_day,   &neg_day,
            &neg_week,  &neg_week,
            {0},
        };
        if (0) {
            i = 1;
            timens_t tval;
            timens_add(&tval, oparg[i].lhs, &timens.t_millisecond);
            for (long rhl=-4; rhl < 4; rhl++) {
                if (timens_str(&tval, lhs) < 0) {
                    unthrow(0, "lhs");
                }
                if (timens_mul(&sum, &tval, rhl)) {
                    if (timens_str(&sum, res) < 0) {
                        unthrow(0, "res");
                    }   
                    printf("<%s> * %ld = <%s>\n", lhs, rhl, res);
                }
                else {
                    unthrow(0, "timens_mul(&sum, tval, %ld)", rhl);
                }
            }
        }
        if (0) {
            for (i=0; oparg[i].lhs; i++) {
                if (timens_str(oparg[i].lhs, lhs) < 0) {
                    unthrow(0, "lhs");
                }
                if (timens_str(oparg[i].rhs, rhs) < 0) {
                    unthrow(0, "rhs");
                }
                if (timens_add(&sum, oparg[i].lhs, oparg[i].rhs)) {
                    if (timens_str(&sum, res) < 0) {
                        unthrow(0, "res");
                    }   
                    printf(
                        "<%s> + <%s> = <%s>\n",   
                        lhs, rhs, res);
                }
                else {
                    unthrow(0, "timens_add(&sum, lhs, rhs)");
                }
            }
        }
        
    }
    for (timens_t *t; t->tv_nsec < 0; t++) {
        if (timens_str(t, res) < 0) {
            unthrow(0,"timens_str({%ld, %ld})",(long) t->tv_sec, t->tv_nsec);
        }
        (void) printf("%03d: %s\n", i++, res);
    }
    */
    return 0;
/*
    if (!timens_fromkw(
        &a,
        (kw_t){t_neg,           false},
        (kw_t){t_milliseconds,  501},
        (kw_t){t_seconds,       51})) 
    {
        unthrow(0, "timens_fromkw(&a, T+51.501s)\n");
    }
    union timens_tm argv = {
        {
            [t_microseconds]    = 123,
            [t_weeks]           = 4,
            [t_neg]             = false,
        }
    };
    if (!timens_fromtm(&b, &argv)) {
        unthrow(0, "timens_fromtm(&b, us=123, weeks=4, neg=1)\n");
    }
    timens_t x = {
        .tv_sec=51+51+1, 
        .tv_nsec=ONE_MILLION,
    };
    if (!timens_add(&c, &a, &b)) {
        unthrow(0, "timens_add(&c, &a, &b\n)");
    }
    (void) timens_str(&a, buf);
    printf("T+51.501s+T+51.501s = %s", buf);
    
    
    return printf("\n");
    */
}
