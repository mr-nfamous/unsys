
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

struct timens_op {
    timens_t *lhs;
    timens_t *rhs;
};

#define timens_PASSED() \
fprintf(dst == NULL ? stdout : dst,"%s: pass\n", __func__)

static void
timens_cmp_test(FILE *dst) {
    char lhs[256], rhs[256];
    static const char *sep[] = {
        [CMP_LT]="< ",
        [CMP_LE]="<=",
        [CMP_EQ]="==",
        [CMP_NE]="!=",
        [CMP_GT]="> ",
        [CMP_GE]=">=",
    };
    timens_t xxx = {0};
    timens_t yyy = {1};
    
    assert(timens_lt(&xxx, &yyy) );
    struct {
        int f;
        bool x;
        timens_t v[2];
    } c[] = {
        {CMP_EQ, 1, {{+1, 0}, {+1, 0}}},
        {CMP_EQ, 1, {{+0, 0}, {+0, 0}}},
        {CMP_EQ, 1, {{-1, 0}, {-1, 0}}},
        {CMP_EQ, 0, {{-1, 0}, {-2, 0}}},
        {CMP_EQ, 0, {{+1, 0}, {+2, 0}}},
        {CMP_NE, 1, {{+1, 0}, {+2, 0}}},
        {CMP_NE, 0, {{+1, 0}, {+1, 0}}},
        {CMP_LT, 1, {{+0, 0}, {+1, 0}}},
        {CMP_LT, 1, {{-1, 0}, {+0, 0}}},
        {CMP_LT, 1, {{-1, 0}, {-1, 1}}},
        {CMP_LT, 0, {{-1, 1}, {-1, 0}}},
        {CMP_LT, 0, {{+1, 0}, {+0, 1}}},
        {CMP_LT, 0, {{+0, 0}, {+0, 0}}},
        {CMP_LE, 1, {{+1, 0}, {+1, 0}}},
        {CMP_LE, 1, {{+0, 0}, {+1, 0}}},
        {CMP_LE, 1, {{+0, 0}, {+0, 1}}},
        {CMP_LE, 1, {{-1, 0}, {+0, 0}}},
        {CMP_LE, 0, {{+1, 0}, {+0, 1}}},
        {CMP_LE, 0, {{+1, 1}, {+1, 0}}},
        {CMP_LE, 0, {{-1, 1}, {-1, 0}}},
        {CMP_GT, 1, {{+1, 1}, {+1, 0}}},
        {CMP_GT, 1, {{+0, 1}, {+0, 0}}},
        {CMP_GT, 1, {{+0, 0}, {-1, 999999999}}},
        {CMP_GT, 1, {{-1, 1}, {-1, 0}}},
        {CMP_GT, 0, {{+1, 1}, {+1, 2}}},
        {CMP_GT, 0, {{+0, 1}, {+1, 0}}},
        {CMP_GT, 0, {{-1, 0}, {-1, 1}}},
        {CMP_GE, 1, {{+1, 1}, {+1, 1}}},
        {CMP_GE, 1, {{+1, 1}, {+0, 0}}},
        {CMP_GE, 1, {{+0, 0}, {+0, 0}}},
        {CMP_GE, 1, {{-1, 0}, {-1, 0}}},
        {CMP_GE, 0, {{-1, 0}, {-1, 1}}},
        {CMP_GE, 0, {{+0, 0}, {+0, 1}}},
        {CMP_GE, 0, {{+0, 1}, {+1, 0}}},
        {0-1},
    };
    for (int i=0; c[i].f >= 0; ++i) {
        assert(i < 100);
        union {
            void *addr;
            bool (*call)(const timens_t*, const timens_t *);
        } func = {.addr=timens.ops.cmp.list[c[i].f]};
        assert(timens_str(c[i].v+0, lhs) > 0);
        assert(timens_str(c[i].v+1, rhs) > 0);
        if (func.call(c[i].v+0, c[i].v+1) != c[i].x) {
            printf(
                "fail on (%s) %s (%s) == %d\n",
                lhs, sep[c[i].f], rhs, c[i].x);
                
        }
        if (dst != NULL) {
            (void) fprintf(
                dst, 
                "(%s) %s (%s) == %d\n", 
                lhs, sep[c[i].f], rhs, c[i].x);
        }
    }
    timens_PASSED();
}


static void 
timens_ops_test(FILE *dst) {
    assert((void *)timens.ops.un_clr == (void *)timens_clr);
    assert((void *)timens.ops.un_pos == (void *)timens_pos);
    assert((void *)timens.ops.un_neg == (void *)timens_neg);
    assert((void *)timens.ops.un_inc == (void *)timens_inc);
    assert((void *)timens.ops.un_dec == (void *)timens_dec);
    assert((void *)timens.ops.bi_add == (void *)timens_add);
    assert((void *)timens.ops.bi_fadd == (void *)timens_fadd);
    assert((void *)timens.ops.bi_sub == (void *)timens_sub);
    assert((void *)timens.ops.bi_fsub == (void *)timens_fsub);
    assert((void *)timens.ops.cmp.lt == (void *)timens_lt);
    assert((void *)timens.ops.cmp.le == (void *)timens_le);
    assert((void *)timens.ops.cmp.eq == (void *)timens_eq);
    assert((void *)timens.ops.cmp.ne == (void *)timens_ne);
    assert((void *)timens.ops.cmp.gt == (void *)timens_gt);
    assert((void *)timens.ops.cmp.ge == (void *)timens_ge);
    timens_PASSED();
}

static void
timens_init_test(FILE *dst) {
    char str[256];
    timens_t arg[] = {
        {+0,            1}, {-1, TIMENS_NSEC_MAX},
        {+0,     THOUSAND}, {-1, TIMENS_NSEC_MAX-THOUSAND},
        {+0,      MILLION}, {-1, TIMENS_NSEC_MAX-MILLION},
        {+1,    BILLION-1}, {-1, 0},
        {+1,            1}, {-2, TIMENS_NSEC_MAX},
        {+60,           0}, {-60, TIMENS_NSEC_MAX},
        {+60,           1}, {-60, TIMENS_NSEC_MAX-1},
        {+61,           0}, {-61, TIMENS_NSEC_MAX},
        {+3599, BILLION-1}, {-3600, 0},
        {.tv_nsec=-1},
    };
    for (int i=0; arg[i].tv_nsec >= 0; ++i) {
        timens_t a = arg[i];
        timens_t b = {0};
        assert(i < 100);
        assert(timens_init(&b, a.tv_sec, a.tv_nsec) != NULL);
        assert(timens_eq(&a, &b));
    }
    timens_PASSED();
}

static void
timens_OK_test(FILE *dst) {
    timens_t t;
    assert(timens_OK(TIMENS_NANOSECOND));
    assert(timens_OK(TIMENS_MICROSECOND));
    assert(timens_OK(TIMENS_MILLISECOND));
    assert(timens_OK(TIMENS_SECOND));
    assert(timens_OK(TIMENS_MINUTE));
    assert(timens_OK(TIMENS_HOUR));
    assert(timens_OK(TIMENS_DAY));
    assert(timens_OK(TIMENS_WEEK));
    assert(timens_OK(timens_neg(&t, TIMENS_NANOSECOND)));
    assert(timens_OK(timens_neg(&t, TIMENS_MICROSECOND)));
    assert(timens_OK(timens_neg(&t, TIMENS_MILLISECOND)));
    assert(timens_OK(timens_neg(&t, TIMENS_SECOND)));
    assert(timens_OK(timens_neg(&t, TIMENS_MINUTE)));
    assert(timens_OK(timens_neg(&t, TIMENS_HOUR)));
    assert(timens_OK(timens_neg(&t, TIMENS_DAY)));
    assert(timens_OK(timens_neg(&t, TIMENS_WEEK))); 
    assert(!timens_OK(timens_INIT(&t, (INT64_C(1)<<60), 0)));
    
    timens_PASSED();
   
}

static void 
timens_neg_test(FILE *dst) {
    char lhs[256];
    char rhs[256];
    /*
    struct {
        timens_t pos;
        timens_t neg;
    } seq[] = {
        {timens.t_microsecond,  timens_NEG(&timens.t_microsecond)},
        {timens.t_millisecond,  timens_NEG(&timens.t_millisecond)},
        {timens.t_nanosecond,   timens_NEG(&timens.t_nanosecond)},
        {timens.t_second,       timens_NEG(&timens.t_second)},
        {timens.t_minute,       timens_NEG(&TIMENS_MINUTE)},
        {timens.t_hour,         timens_NEG(&TIMENS_HOUR)},
        {timens.t_day,          timens_NEG(&TIMENS_DAY)},
        {timens.t_week,         timens_NEG(&TIMENS_WEEK)},
        {{.tv_nsec=-1}},
    };
    int fail = 0;
    for (int i=0; seq[i].tv_nsec >= 0; i++) {
        assert(i < 100);
        timens_t *pos = &seq[i].pos;
        timens_t *neg = &seq[i].neg;
        if (!timens_ne(pos, neg)) {
            fail++;
            assert(timens_str(pos, lhs) > 0);
            assert(timens_str(neg, rhs) > 0);
            fprintf(
                dst,
                "timens_NEG(%s) => (%s)\n",
                lhs, rhs);
        }
        else {
            if (!timens_eq(pos, timens_ineg(neg))) {
                
            }
        }
    }
    assert(timens_str(t, arg) > 0);
    assert(timens_neg(&v, t) != NULL);
    assert(timens_str(&v, res) > 0);
    timens_PASSED();
    */
}

static void 
timens_div_test(const timens_t *a, const timens_t *b) {
    char lhs[256];
    char rhs[256];
    char mod[256];
    timens_t m;
    long q = timens_div(&m, a, b);
    if (timens_str(a, lhs) < 0) {
        unthrow(0, "str(lhs)");
    }
    if (timens_str(b, rhs) < 0) {
        unthrow(0, "str(rhs)");
    }
    if (timens_str(&m, mod) < 0) {
        unthrow(0, "str(mod)");
    }
    //printf("m.tv_sec=%jd\nm.tv_nsec = %ld\n", m.tv_sec,m.tv_nsec);
   
    (void) printf("%s ÷ %s = %+ld(%s)\n", lhs, rhs, q, mod);
}

static void
timens_mul_test(const timens_t *a, long b) {
    char lhs[256];
    char res[256];
    timens_t p;
    (void) timens_mul(&p, a, b);
    if (timens_str(a, lhs) < 0) {
        unthrow(0, "str(lhs)");
    }
    if (timens_str(&p, res) < 0) {
        unthrow(0, "str(product)");
    }
    //printf("m.tv_sec=%jd\nm.tv_nsec = %ld\n", m.tv_sec,m.tv_nsec);
   
    (void) printf("%s × %+ld = %s\n", lhs, b, res);
}

static void 
timens_sub_test(const timens_t *a, const timens_t *b) {
    char lhs[256];
    char rhs[256];
    char dif[256];
    timens_t v;
    (void) timens_sub(&v, a, b);
    (void) timens_str(&v, dif);
    (void) timens_str(a, lhs);
    (void) timens_str(b, rhs);
    (void) printf("%s - %s = %s\n", lhs, rhs, dif);
    
}

static void 
timens_add_test(const timens_t *a, const timens_t *b) {
    char lhs[256];
    char rhs[256];
    char sum[256];
    timens_t v;
    (void) timens_str(a, lhs);
    (void) timens_str(b, rhs);
    (void) timens_add(&v, a, b);
    (void) timens_str(&v, sum);
    (void) printf("%s + %s = %s\n", lhs, rhs, sum);
}
    
static void
timens_ftime_test(const timens_t *t) {
    char str[256];
    double v;
    assert(timens_str(t, str) > 0);
    assert(timens_ftime(&v, t) != (0.0-1) || !errno);
    int nbit = BITLENJ((uintmax_t)fabs(v));
    int ndig = TIMENS_FTIME_NDIGIT[nbit];
    printf("(double) (%s) => %+.*f\n", str, ndig, v);
}
    
static void
timens_fromftime_test(timens_t *t, double s) {
    char str[256];
    assert(timens_fromfsec(t, s) != NULL);
    assert(timens_str(t, str) > 0);
    printf("timens_fromfsec(%f) => %s\n", s, str);
}
