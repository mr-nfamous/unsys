

#if     !(defined(UN_T))
#   error missing UN_T definition
#elif   !(defined(UN_DIV_T) && defined(UN_DIV_F))
#   error missing UN_DIV_T  &| UN_DIV_F definitions 
#elif   !(defined(UN_VMIN)  && defined(UN_VMAX))
#   error missing UN_VMIN   &| UN_VMAX definitions 
#elif   !(defined(UN_EOVER) && defined(UN_EUNDR))
#   error missing UN_EOVER  &| UN_EUNDR definitions 
#elif !defined(UN_INTFMT)
#   error missing UN_INTFMT def 
#endif

#ifndef    UN_INTIMPL_H
#   define UN_STRINGY(...) #__VA_ARGS__
#   define UN_JONCAT(_L_, _R_, ...) _L_##__VA_ARGS__##_R_
#   define UN_OVERFLOW (errno=UN_EOVER)
#   define UN_UNDERFLOW (errno=UN_EUNDR)
#   define UN_FUNC(...) UN_T##_##__VA_ARGS__ 
#   define UN_DECL(...) UN_T##_##__VA_ARGS__

#endif

static inline int
UN_DECL(INC)(UN_T *const v) {
    return (*v==UN_VMAX) ? UN_OVERFLOW: ((*v=*v-1), 0); 
}
#ifndef UN_INTIMPL_H
#define UN_INTIMPL_H

static void 
UN_RUN_UNINT_TESTS(FILE *f) {
    errno = 0;
    int narg = 1;
    const char *opname = UN_STRINGY(UN_T) "_INC";
    struct {
        int x;
        UN_T a, b, c, v;
        int r;
        int next;
    } inc_args[]= {
        {.x=0, .a=UN_VMIN+0, .v=UN_VMIN+1, .next=1},
        {.x=0, .a=UN_VMAX-1, .v=UN_VMAX+0, .next=1},
        {.x=1, .a=UN_VMAX+0, .v=0},
        {.next=0},
    }, *tc;
    for (; tc->next; ++tc) {
        if ((tc->r=long_INC(&tc->v))) {
            if (tc->x)  errno = 0;
            else goto expected_success;
        }
        else {
            if (tc->x) goto expected_failure;
        }
    }
    goto the_end;
    
    expected_failure:
    switch (narg) {
        case 1: return (void) fprintf(
            f,
            "expected %s(" UN_INTFMT ") to fai\nl",
            opname, tc->a);
        case 2: return (void) fprintf(
            f,
            "expected %s(" UN_INTFMT ", " UN_INTFMT ") to fail\n",
            opname, tc->a, tc->b);
    }
    exit(EXIT_FAILURE);
    
    expected_success:
    switch (narg) {
        case 1: return (void) fprintf(
            f,
            "expected %s(" UN_INTFMT ") to succeed\n",
            opname, tc->a);
        case 2: return (void) fprintf(
            f,
            "expected %s(" UN_INTFMT ", " UN_INTFMT ") to succeed\n",
            opname, tc->a, tc->b);
    }
    exit(EXIT_FAILURE);
    the_end: {
        return (void) fprintf(f, "done!\n");
    }
}

#endif
/*
UN_RX(pd,DEC)(pd*const v){return*v>MIN?((*v=*v-1),0):UN_EXC;}\
UN_RX(pd,CLR)(pd*const v){return(*v=0);}\
UN_RX(pd,POS)(pd i,pd*const v){return(*v=i),0;}\
UN_RX(pd,NEG)(pd i,pd*const v){return(i==MIN)?UN_EXC:((*v=0-i),0);}\
UN_RX(pd,SGN)(pd a,pd*const v){\
    return(a==MIN)?UN_EXC:(a<0)?((*v=0-a),0-1:((*v=a),1))}\
UN_RX(pd,ADD)(pd a, pd b,pd*const v){\
    if(a<0){if((0>b)&&(b<(MIN-a))){return UN_EXC;}}\
    else{if((0<b)&&(b>(MAX-a))){return UN_EXC;}}\
    return(*v=a+b),0;}\
UN_RX(pd,SUB)(pd a,pd b,pd*const v) {\
    if(a<0){if((0<b)&&(b>(MAX+a+1))){return UN_EXC;}}\
    else{if((0>b)&&(b<(0-(MIN-a)))){return UN_EXC;}}\
    return (*v=a-b),0;}\
UN_RX(pd,MUL)(pd a,pd b,pd*const v) {\
    dtp x;\
    if (!a||!b){return(*v=0),0;}\
    if (a>0){\
        if(b<0){\
            x = dfn(MIN,a);\
            if(b<(x.quot+(x.rem!=0)))return UN_EXC;}\
        else{if(b>(MAX/a))return UN_EXC;}}\
    else {if (b<0) {\
            x=dfn(MIN,a);\
            if(b<(0-(x.quot-(!x.rem))))return UN_EXC;}\
        else{if(b>(MIN/a))return UN_EXC;}}\
    return (*v=a*b), 0;}
*/

#undef UN_T
#undef UN_VMAX
#undef UN_VMIN
#undef UN_DIV_T
#undef UN_DIV_F
#undef UN_INTFMT

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳   

Bounds checked signed int arithmetic. Most return
0 on success or (errno=ERANGE) if the operation
would result in signed (over/under)flow, storing
the result in the last argument. 

    v++:    t_INC(&v);
    v--:    t_DEC(&v);
    v=0:    t_CLR(&v);
            t_SGN(n, &v);
    v=a:    t_POS(n, &v)
    v=0-n:  t_NEG(n, &v) 
            t_ABS(n, &v)
    v=a+b:  t_ADD(a, b, &v)
    v=a-b:  t_SUB(a, b, &v)
    v=a*b:  t_MUL(a, b, &v)
    
SGN computes abs (if possible) and returns the 
sign (as ±1) on success or 0 on error.

CLR sets the argument to its nul representation.

*/

#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#define UN_RX(tp, op) static inline int tp##op
#define UN_EXC (errno=ERANGE)
#define UN_INTOPS(T, div_T, div_F, MIN, MAX) 

static inline
UN_RX(T, INC)(T *const v){return (*v==MAX)?UN_EXC:((*v=*v+1),0);}
    
UN_INTOPS(long, ldiv_t, ldiv, LONG_MIN, LONG_MAX)

void UN_TEST_OPS(void) {
    long a=0, b, c;
    if(long_INC(&a)) {
        exit(EXIT_FAILURE);
    };
}


/*
#define UN_INTOPS(pd, dtp, dfn, MIN, MAX) \


static void
UN_TEST_OPS(FILE *f) {
    errno = 0;
#define UN_T long
#define UN_T_PF "ld"
#define UN_T_MIN LONG_MIN
#define UN_T_MAX LONG_MAX
#define UN_T_NAME(...) #UN_T #__VA_ARGS__
#define UN_T_J(a, b) a##b
#define UN_SUB(...) UN_T_J(UN_T, _SUB)(__VA_ARGS__)
#define UN_ADD(...) UN_T_J(UN_T, _ADD)(__VA_ARGS__)
#define UN_MUL(...) UN_T_J(UN_T, _MUL)(__VA_ARGS__)
    if (f == NULL) {
        f = stdout;
    }
    UN_T min = UN_T_MIN;
    UN_T max = UN_T_MAX;
    UN_T nil = 0;
    UN_T one = 1;
    UN_T two = 2;
    UN_T neg = min+one; // -127
    UN_T inv = nil-one; // -1
    UN_T pos = max-one; // 126
    UN_T c, o, v, *arg;

    UN_T *(args[]);

    const char *op[] = {
        ['+'] = UN_T_NAME(_ADD),
        ['-'] = UN_T_NAME(_SUB),
        ['*'] = UN_T_NAME(_MUL),
    };
    
    _tcase ops[] = {
        {'+', nil, min, min+0}, //   +0 + -128 = -128
        {'+', nil, max, max+0}, //   +0 + +127 = +127
        {'+', nil, two, nil+2}, //   +0 +   +2 = +2
        {'+', one, min, min+1}, //   +1 + -128 = -127
        {'+', max, nil, max-0}, // +127 +   +0 = +127
        {'+', max, inv, max-1}, // +127 +   -1 = +126
        {'+', max, neg, nil+0}, // +127 + -127 = +0
        {'+', max, min, nil-1}, // +127 + -128 = -1
        {'+', pos, one, max-0}, // +126 +   +1 = +127
        {'+', pos, nil, max-1}, // +126 +   +0 = +126
        {'+', pos, inv, max-2}, // +126 +   -1 = +126
        {'+', pos, min, nil-2}, // +126 + -128 = -2
        {'+', min, nil, neg-1}, // -128 +   +0 = -128 
        {'+', min, one, neg-0}, // -128 +   +1 = -127 
        {'+', min, max, nil-1}, // -128 + +127 = -1 
        {'-', min, nil, min+0}, // -128 -   +0 = -128
        {'-', min, inv, min+1}, // -128 -   -1 = -127
        {'-', min, min, nil+0}, // -128 - -128 = +0
        {'-', nil, max, min+1}, //   +0 - +127 = -127
        {'-', nil, one, inv+0}, //   +0 -   +1 = -1
        {'-', nil, nil, nil+0}, //   +0 -   +0 = +0
        {'-', inv, max, min+0}, //   -1 - +127 = -128
        {'-', inv, min, max+0}, //   -1 - -128 = +127
        {'-', inv, one, inv-1}, //   -1 -   +1 = -2 
        {'-', inv, inv, nil+0}, //   -1 -   -1 = +0
        {'*', max/2, 2, 2*(max/2)},
        {'*', (min+1),inv,max},
        {'*', min/2, 2, min},
        {0}
    };
    args = ops;
    for (arg=*args; (o=*arg); arg=*args++) {
        switch (o) {
            case '*': {
                if (UN_T_MUL(arg[1], arg[2], &v)) goto fail_ret;
                break;
            }
            case '-': {
                if (UN_T_SUB(arg[1], arg[2], &v)) goto fail_ret;
                break;
            }
            case '+': {
                if (UN_T_ADD(arg[1], arg[2], &v)) goto fail_ret;
                break;
            }
            default: {
                (void) fprintf(f, "wtf is %d?\n", o);
                exit(EXIT_FAILURE);
            }
        }
        if (v != arg[3]) {
            (void) fprintf(
                f,
                "expected v = (%d) after %s(%d, %d)\n"
                "actually v = (%d)\n",
                arg[3], 
                op[o],
                arg[1], 
                arg[2],
                v);
            exit(EXIT_FAILURE);
        }
    }

    return (void) fprintf(f, "all tests passed\n");
    fail_ret: {
        (void) fprintf(
            f,
            "%s(" 
            UN_T_PF 
            ", " 
            UN_T_PF 
            ")returned error;\n"
            "expected v=("
            UN_T_PF
            ")\n",
            op[o],
            arg[1],
            arg[2],
            arg[3]);
        exit(EXIT_FAILURE);
    }
}
*/
