

/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳


bool gety(T s, k)
    s.Y[k]

Byte getb(T s, int k)
    s.B[k]p



    T dely(T s, int k)

        Clear (set to 0) bit k.

        Byte delyb(Byte s, int k);
        Half delyh(Half s, int k);
        Word delyw(Word s, int k);
        Dwrd delyd(Dwrd s, int k);
        Quad delyq(Quad s, int k);

        Vwb  delywb(Vwb s, int k);
        Vwh  delywh(Vwh s, int k);

        Vdb  delydb(Vdb s, int k);
        Vdh  delydh(Vdh s, int k);
        Vdw  delydw(Vdw s, int k);

        Vqb  delyqb(Vqb s, int k);
        Vqh  delyqh(Vqh s, int k);
        Vqw  delyqw(Vqw s, int k);
        Vqd  delyqd(Vqd s, int k);

        Vob  delyqb(Vqb s, int k);
        Voh  delyqh(Vqh s, int k);
        Vow  delyqw(Vqw s, int k);
        Vod  delyqd(Vqd s, int k);



    T delb(T s, k)
        s.B[k] = 0

    T delh(T s, k)
        s.H[k] = 0

    T delw(T s, k)
        s.W[k] = 0

    T deld(T s, k)
        s.D[k] = 0

    setb(s, k, t)
        s[k*8:(k+1)*8] = t[:8]

    (src, i, val)
        s[k*8:(k+1)*8] = b[:8]
        Set src[i:i+16] = val[0:16]

    setw(src, i, val)
        Set src[i:i+32] = val[0:32]

    rot[bhw](src, k)
        Rotate the representation of src by k [bhw].
        The highest [bhw] is shifted towards 0 by
        most significant byte is rotated towards the
        lowest

        If n is positive, it is the number of [bhw] to
        dextrorotate src by. If n is negative, abs(n) is the
        number of [bhw] to levorotate src by. E.g. dexbwu is
        the operation for rotating uint32_t; dexbwu(n, 1)
        returns n[24:32]|n[0:24] while dexbwu(n, -1) returns
        n[]


        the representation of src to by. E.g. rothdu(n, 1)
        returns n[48:64]+

        n[16:]+n[:sizeof(n)-8].
        If n is negative, src is rotated left by abs(n) bytes
        instead.

      0x'00'00'ff'80    => {0x80, 0xff, 0x00, 0x00}
rotbwu(0x00'00'ff'00, 1) =>{0xff, 0x00, 0x00, 0x80}

rotbwu(0x80'02'01'ff, -1) => 0x'02'01'ff'80
rotbwu(0x80'02'01'ff, +1) => 0x'ff'80'02'01

                [0]   [1]   [2]   [3]
LE: 0x800201ff {0xff, 0x01, 0x02, 0x80}

                      [3]   [0]   [1]   [2]
    -1 => 0x0201ff80 {0x80, 0xff, 0x01, 0x02}
    -1 = (x<<8)|(x>>24)
    -2 = (x<<16)|(x>>16)
    -3 = (x<<24)|(x>>8)

                      [1]   [2]   [3]   [0]
    +1 => 0xff800201 {0x01, 0x02, 0x80, 0xff}
        (x<<24)|(x>>8)

                [3]   [2]   [1]   [0]
BE: 0x800201ff {0x80, 0x02, 0x01, 0xff}

    -1 => 0x0201ff80b {



-3: 0x02, 0x03, 0x04, 0x01
-2: 0x03, 0x04, 0x01, 0x02
-1: 0x04, 0x01, 0x02, 0x03
+0: 0x01, 0x02, 0x03, 0x04
+1: 0x02, 0x03, 0x04, 0x01
+2: 0x03, 0x04, 0x01, 0x02
+3: 0x04, 0x01, 0x02, 0x03

*/

/*  Memory to register (load), register to memory (save)

    *   T load(T volatile const src[1])

        Load a value from `src`, which must be readable and
        properly aligned.

        Note that loading an 8, 16, 32, or 64 bit integer
        from a properly aligned addresses is an inherently
        atomic operation on all supported targets.


    *   T aqld(T volatile const src[1])

        Atomically acquire-then-load `src`. This operation
        is semantically identical to `atomic_load_explicit`
        with `memory_order_acquire`.


    *   T scld(T volatile const src[1])

        Sequentially consistent atomic load. Semantically
        identical to `atomic_load` from <stdatomic.h>,
        which uses `memory_order_seq_cst`.


    *   save(T volatile dst[1], regidter T src)

        Save `src` to `dst`, which must be properly aligned.
        Semantically identical to `atomic_store_explicit`
        using `memory_order_relaxed` if the target could
        correctly implement it for type T. Otherwise,
        `save(dst, src)` is semantically identical to
        `(void)(*(T volatile *) dst = src)`


    *   strl(T volatile dst[1], register T src)

        Atomically store-release src to dst. Identical to
        `atomic_store_explicit` with `memory_order_release`.


    *   scst(T volatile dst[1], register T src)

        Sequentially consistent atomic store. Identical to
        `atomic_store_explicit` with `memory_order_seq_cst`.


    *   T swap(T volatile a[1], register T b)

        Atomically exchange `b` with the value stored in
        the properly aligned `a`. Identical to
        `atomic_exchange_explicit` with
        `memory_order_relaxed`.

    *   T aqsw(T volatile a[1], register T b)

        Atomically acquire-exchange `b` with the value
        stored in the properly aligned `a`. Identical to
        `atomic_exchange_explicit` with
        `memory_order_acquire`.

    *   T swrl(T volatile a[1], register T b)

        Atomically acquire-exchange `b` with the value
        stored in the properly aligned `a`. Identical to
        `atomic_exchange_explicit` with
        `memory_order_release`.

    *   T scsw(T volatile a[1], register T b)

        Sequentially consistent atomic exchange `b` with
        the value stored in the properly aligned `a`.
        Identical to `atomic_exchange_explicit` with
        `memory_order_seq_cst`.

*/

#ifndef MY_EXTVEC_H
#define MY_EXTVEC_H

#ifndef MY_EXTNUM_H
#include  "extnum.h"
#endif


#define     V1_K0       0x0

#ifndef MY_ENDIAN
#error "MY_ENDIAN aint defined"

#elif MY_ENDIAN == ENDIAN_BIG
/*  The least significant bit of a bit of a big endian 
    vector is in the element with the highest address.

    And yes, these constants are useful and necessary even 
    for targets without native 256 or 512 bit vectors.
*/
#   define  V2_K0   (0x1)
#   define  V2_K1   (0x0

#   define  V4_K0   (0x3)
#   define  V4_K1   (0x2)
#   define  V4_K2   (0x1)
#   define  V4_K3   (0x0)

#   define  V8_K0   (0x7)
#   define  V8_K1   (0x6)
#   define  V8_K2   (0x5)
#   define  V8_K3   (0x4)
#   define  V8_K4   (0x3)
#   define  V8_K5   (0x2)
#   define  V8_K6   (0x1)
#   define  V8_K7   (0x0)

#   define  V16_K0  (0xf)
#   define  V16_K1  (0xe)
#   define  V16_K2  (0xd)
#   define  V16_K3  (0xc)
#   define  V16_K4  (0xb)
#   define  V16_K5  (0xa)
#   define  V16_K6  (0x9)
#   define  V16_K7  (0x8)
#   define  V16_K8  (0x7)
#   define  V16_K9  (0x6)
#   define  V16_K10 (0x5)
#   define  V16_K11 (0x4)
#   define  V16_K12 (0x3)
#   define  V16_K13 (0x2)
#   define  V16_K14 (0x1)
#   define  V16_K15 (0x0)

#   define  V32_K0  (0x1f)
#   define  V32_K1  (0x1e)
#   define  V32_K2  (0x1d)
#   define  V32_K3  (0x1c)
#   define  V32_K4  (0x1b)
#   define  V32_K5  (0x1a)
#   define  V32_K6  (0x19)
#   define  V32_K7  (0x18)
#   define  V32_K8  (0x17)
#   define  V32_K9  (0x16)
#   define  V32_K10 (0x15)
#   define  V32_K11 (0x14)
#   define  V32_K12 (0x13)
#   define  V32_K13 (0x12)
#   define  V32_K14 (0x11)
#   define  V32_K15 (0x10)
#   define  V32_K16 (0x0f)
#   define  V32_K17 (0x0e)
#   define  V32_K18 (0x0d)
#   define  V32_K19 (0x0c)
#   define  V32_K20 (0x0b)
#   define  V32_K21 (0x0a)
#   define  V32_K22 (0x09)
#   define  V32_K23 (0x08)
#   define  V32_K24 (0x07)
#   define  V32_K25 (0x06)
#   define  V32_K26 (0x05)
#   define  V32_K27 (0x04)
#   define  V32_K28 (0x03)
#   define  V32_K29 (0x02)
#   define  V32_K30 (0x01)
#   define  V32_K31 (0x00)

#   define  V64_K0  (0x3f)
#   define  V64_K1  (0x3e)
#   define  V64_K2  (0x3d)
#   define  V64_K3  (0x3c)
#   define  V64_K4  (0x3b)
#   define  V64_K5  (0x3a)
#   define  V64_K6  (0x39)
#   define  V64_K7  (0x38)
#   define  V64_K8  (0x37)
#   define  V64_K9  (0x36)
#   define  V64_K10 (0x35)
#   define  V64_K11 (0x34)
#   define  V64_K12 (0x33)
#   define  V64_K13 (0x32)
#   define  V64_K14 (0x31)
#   define  V64_K15 (0x30)
#   define  V64_K16 (0x2f)
#   define  V64_K17 (0x2e)
#   define  V64_K18 (0x2d)
#   define  V64_K19 (0x2c)
#   define  V64_K20 (0x2b)
#   define  V64_K21 (0x2a)
#   define  V64_K22 (0x29)
#   define  V64_K23 (0x28)
#   define  V64_K24 (0x27)
#   define  V64_K25 (0x26)
#   define  V64_K26 (0x25)
#   define  V64_K27 (0x24)
#   define  V64_K28 (0x23)
#   define  V64_K29 (0x22)
#   define  V64_K30 (0x21)
#   define  V64_K31 (0x20)
#   define  V64_K32 (0x1f)
#   define  V64_K33 (0x1e)
#   define  V64_K34 (0x1d)
#   define  V64_K35 (0x1c)
#   define  V64_K36 (0x1b)
#   define  V64_K37 (0x1a)
#   define  V64_K38 (0x19)
#   define  V64_K39 (0x18)
#   define  V64_K40 (0x17)
#   define  V64_K41 (0x16)
#   define  V64_K42 (0x15)
#   define  V64_K43 (0x14)
#   define  V64_K44 (0x13)
#   define  V64_K45 (0x12)
#   define  V64_K46 (0x11)
#   define  V64_K47 (0x10)
#   define  V64_K48 (0x0f)
#   define  V64_K49 (0x0e)
#   define  V64_K50 (0x0d)
#   define  V64_K51 (0x0c)
#   define  V64_K52 (0x0b)
#   define  V64_K53 (0x0a)
#   define  V64_K54 (0x09)
#   define  V64_K55 (0x08)
#   define  V64_K56 (0x07)
#   define  V64_K57 (0x06)
#   define  V64_K58 (0x05)
#   define  V64_K59 (0x04)
#   define  V64_K60 (0x03)
#   define  V64_K61 (0x02)
#   define  V64_K62 (0x01)
#   define  V64_K63 (0x00)

#elif MY_ENDIAN == ENDIAN_LIL

#   define  V2_K0   (0x0)
#   define  V2_K1   (0x1)

#   define  V4_K0   (0x0)
#   define  V4_K1   (0x1)
#   define  V4_K2   (0x2)
#   define  V4_K3   (0x3)

#   define  V8_K0   (0x0)
#   define  V8_K1   (0x1)
#   define  V8_K2   (0x2)
#   define  V8_K3   (0x3)
#   define  V8_K4   (0x4)
#   define  V8_K5   (0x5)
#   define  V8_K6   (0x6)
#   define  V8_K7   (0x7)

#   define  V16_K0  (0x00)
#   define  V16_K1  (0x01)
#   define  V16_K2  (0x02)
#   define  V16_K3  (0x03)
#   define  V16_K4  (0x04)
#   define  V16_K5  (0x05)
#   define  V16_K6  (0x06)
#   define  V16_K7  (0x07)
#   define  V16_K8  (0x08)
#   define  V16_K9  (0x09)
#   define  V16_K10 (0x0a)
#   define  V16_K11 (0x0b)
#   define  V16_K12 (0x0c)
#   define  V16_K13 (0x0d)
#   define  V16_K14 (0x0e)
#   define  V16_K15 (0x0f)

#   define  V32_K0  (0x00)
#   define  V32_K1  (0x01)
#   define  V32_K2  (0x02)
#   define  V32_K3  (0x03)
#   define  V32_K4  (0x04)
#   define  V32_K5  (0x05)
#   define  V32_K6  (0x06)
#   define  V32_K7  (0x07)
#   define  V32_K8  (0x08)
#   define  V32_K9  (0x09)
#   define  V32_K10 (0x0a)
#   define  V32_K11 (0x0b)
#   define  V32_K12 (0x0c)
#   define  V32_K13 (0x0d)
#   define  V32_K14 (0x0e)
#   define  V32_K15 (0x0f)
#   define  V32_K16 (0x10)
#   define  V32_K17 (0x11)
#   define  V32_K18 (0x12)
#   define  V32_K19 (0x13)
#   define  V32_K20 (0x14)
#   define  V32_K21 (0x15)
#   define  V32_K22 (0x16)
#   define  V32_K23 (0x17)
#   define  V32_K24 (0x18)
#   define  V32_K25 (0x19)
#   define  V32_K26 (0x1a)
#   define  V32_K27 (0x1b)
#   define  V32_K28 (0x1c)
#   define  V32_K29 (0x1d)
#   define  V32_K30 (0x1e)
#   define  V32_K31 (0x1f)

#   define  V64_K0  (0x00)
#   define  V64_K1  (0x01)
#   define  V64_K2  (0x02)
#   define  V64_K3  (0x03)
#   define  V64_K4  (0x04)
#   define  V64_K5  (0x05)
#   define  V64_K6  (0x06)
#   define  V64_K7  (0x07)
#   define  V64_K8  (0x08)
#   define  V64_K9  (0x09)
#   define  V64_K10 (0x0a)
#   define  V64_K11 (0x0b)
#   define  V64_K12 (0x0c)
#   define  V64_K13 (0x0d)
#   define  V64_K14 (0x0e)
#   define  V64_K15 (0x0f)
#   define  V64_K16 (0x10)
#   define  V64_K17 (0x11)
#   define  V64_K18 (0x12)
#   define  V64_K19 (0x13)
#   define  V64_K20 (0x14)
#   define  V64_K21 (0x15)
#   define  V64_K22 (0x16)
#   define  V64_K23 (0x17)
#   define  V64_K24 (0x18)
#   define  V64_K25 (0x19)
#   define  V64_K26 (0x1a)
#   define  V64_K27 (0x1b)
#   define  V64_K28 (0x1c)
#   define  V64_K29 (0x1d)
#   define  V64_K30 (0x1e)
#   define  V64_K31 (0x1f)
#   define  V64_K32 (0x20)
#   define  V64_K33 (0x21)
#   define  V64_K34 (0x22)
#   define  V64_K35 (0x23)
#   define  V64_K36 (0x24)
#   define  V64_K37 (0x25)
#   define  V64_K38 (0x26)
#   define  V64_K39 (0x27)
#   define  V64_K40 (0x28)
#   define  V64_K41 (0x29)
#   define  V64_K42 (0x2a)
#   define  V64_K43 (0x2b)
#   define  V64_K44 (0x2c)
#   define  V64_K45 (0x2d)
#   define  V64_K46 (0x2e)
#   define  V64_K47 (0x2f)
#   define  V64_K48 (0x30)
#   define  V64_K49 (0x31)
#   define  V64_K50 (0x32)
#   define  V64_K51 (0x33)
#   define  V64_K52 (0x34)
#   define  V64_K53 (0x35)
#   define  V64_K54 (0x36)
#   define  V64_K55 (0x37)
#   define  V64_K56 (0x38)
#   define  V64_K57 (0x39)
#   define  V64_K58 (0x3a)
#   define  V64_K59 (0x3b)
#   define  V64_K60 (0x3c)
#   define  V64_K61 (0x3d)
#   define  V64_K62 (0x3e)
#   define  V64_K63 (0x3f)
#else
#error "why !(MY_ENDIAN==ENDIAN_LIL || MY_ENDIAN==ENDIAN_BIG)?"
#endif

#define     VDBU_(_)    VDBU_ ## _
#define     VDBI_(_)    VDBI_ ## _

#define     VDHU_(_)    VDHU_ ## _
#define     VDHI_(_)    VDHI_ ## _
#define     VDHF_(_)    VDHF_ ## _

#define     VDWU_(_)    VDWU_ ## _
#define     VDWI_(_)    VDWI_ ## _
#define     VDWF_(_)    VDWF_ ## _

#define     VDDU_(_)    VDDU_ ## _
#define     VDDI_(_)    VDDI_ ## _
#define     VDDF_(_)    VDDF_ ## _

#define     VQBU_(_)    VQBU_ ## _
#define     VQBI_(_)    VQBI_ ## _

#define     VQHU_(_)    VQHU_ ## _
#define     VQHI_(_)    VQHI_ ## _
#define     VQHF_(_)    VQHF_ ## _

#define     VQWU_(_)    VQWU_ ## _
#define     VQWI_(_)    VQWI_ ## _
#define     VQWF_(_)    VQWF_ ## _

#define     VQDU_(_)    VQDU_ ## _
#define     VQDI_(_)    VQDI_ ## _
#define     VQDF_(_)    VQDF_ ## _

#define     VQQU_(_)    VQQU_ ## _
#define     VQQI_(_)    VQQI_ ## _
#define     VQQF_(_)    VQQF_ ## _

#define     VOBU_(_)    VOBU_ ## _
#define     VOBI_(_)    VOBI_ ## _

#define     VOHU_(_)    VOHU_ ## _
#define     VOHI_(_)    VOHI_ ## _
#define     VOHF_(_)    VOHF_ ## _

#define     VOWU_(_)    VOWU_ ## _
#define     VOWI_(_)    VOWI_ ## _
#define     VOWF_(_)    VOWF_ ## _

#define     VODU_(_)    VODU_ ## _
#define     VODI_(_)    VODI_ ## _
#define     VODF_(_)    VODF_ ## _

#define     VOQU_(_)    VOQU_ ## _
#define     VOQI_(_)    VOQI_ ## _
#define     VOQF_(_)    VOQF_ ## _

#define     VSBU_(_)    VSBU_ ## _
#define     VSBI_(_)    VSBI_ ## _

#define     VSHU_(_)    VSHU_ ## _
#define     VSHI_(_)    VSHI_ ## _
#define     VSHF_(_)    VSHF_ ## _

#define     VSWU_(_)    VSWU_ ## _
#define     VSWI_(_)    VSWI_ ## _
#define     VSWF_(_)    VSWF_ ## _

#define     VSDU_(_)    VSDU_ ## _
#define     VSDI_(_)    VSDI_ ## _
#define     VSDF_(_)    VSDF_ ## _

#define     VSQU_(_)    VSQU_ ## _
#define     VSQI_(_)    VSQI_ ## _
#define     VSQF_(_)    VSQF_ ## _

#define     VDBU_WIDTH  64
#define     VDBI_WIDTH  64

#define     VDHU_WIDTH  64
#define     VDHI_WIDTH  64
#define     VDHF_WIDTH  64

#define     VDWU_WIDTH  64
#define     VD_WI_WIDTH 64
#define     VDWF_WIDTH  64

#define     VDDU_WIDTH  64
#define     VDDI_WIDTH  64
#define     VDDF_WIDTH  64

// 128 bit "quadruple word" vectors
#define     VQBU_WIDTH  128
#define     VQBI_WIDTH  128

#define     VQHU_WIDTH  128
#define     VQHI_WIDTH  128
#define     VQHF_WIDTH  128

#define     VQWU_WIDTH  128
#define     VQWI_WIDTH  128
#define     VQWF_WIDTH  128

#define     VQDU_WIDTH  128
#define     VQDI_WIDTH  128
#define     VQDF_WIDTH  128

#define     VQQU_WIDTH  128
#define     VQQI_WIDTH  128
#define     VQQF_WIDTH  128

// 256 bit "octuple word" vectors
#define     VOBU_WIDTH  256
#define     VOBI_WIDTH  256

#define     VOHU_WIDTH  256
#define     VOHI_WIDTH  256
#define     VOHF_WIDTH  256

#define     VOWU_WIDTH  256
#define     VOWI_WIDTH  256
#define     VOWF_WIDTH  256

#define     VODU_WIDTH  256
#define     VODI_WIDTH  256
#define     VODF_WIDTH  256

#define     VOQU_WIDTH  256
#define     VOQI_WIDTH  256
#define     VOQF_WIDTH  256

// 512 bit "sexdecuple word" vectors
#define     VSBU_WIDTH  512
#define     VSBI_WIDTH  512

#define     VSHU_WIDTH  512
#define     VSHI_WIDTH  512
#define     VSHF_WIDTH  512

#define     VSWU_WIDTH  512
#define     VSWI_WIDTH  512
#define     VSWF_WIDTH  512

#define     VSDU_WIDTH  512
#define     VSDI_WIDTH  512
#define     VSDF_WIDTH  512

#define     VSQU_WIDTH  512
#define     VSQI_WIDTH  512
#define     VSQF_WIDTH  512

#define     VDBU_NEL    8
#define     VDBI_NEL    8

#define     VDHU_NEL    4
#define     VDHI_NEL    4
#define     VDHF_NEL    4

#define     VDWU_NEL    2
#define     VDWI_NEL    2
#define     VDWF_NEL    2

#define     VDDU_NEL    1
#define     VDDI_NEL    1
#define     VDDF_NEL    1

// 128 bit "quadruple word" vectors
#define     VQBU_NEL    16
#define     VQBI_NEL    16

#define     VQHU_NEL    8
#define     VQHI_NEL    8
#define     VQHF_NEL    8

#define     VQWU_NEL    4
#define     VQWI_NEL    4
#define     VQWF_NEL    4

#define     VQDU_NEL    2
#define     VQDI_NEL    2
#define     VQDF_NEL    2

#define     VQQU_NEL    1
#define     VQQI_NEL    1
#define     VQQF_NEL    1

// 256 bit "octuple word" vectors
#define     VOBU_NEL    32
#define     VOBI_NEL    32

#define     VOHU_NEL    16
#define     VOHI_NEL    16
#define     VOHF_NEL    16

#define     VOWU_NEL    8
#define     VOWI_NEL    8
#define     VOWF_NEL    8

#define     VODU_NEL  4
#define     VODI_NEL  4
#define     VODF_NEL  4

#define     VOQU_NEL  2
#define     VOQI_NEL  2
#define     VOQF_NEL  2

// 512 bit "sexdecuple word" vectors
#define     VSBU_NEL  64
#define     VSBI_NEL  64

#define     VSHU_NEL  32
#define     VSHI_NEL  32
#define     VSHF_NEL  32

#define     VSWU_NEL  16
#define     VSWI_NEL  16
#define     VSWF_NEL  16

#define     VSDU_NEL  8
#define     VSDI_NEL  8
#define     VSDF_NEL  8

#define     VSQU_NEL  4
#define     VSQI_NEL  4
#define     VSQF_NEL  4

// 64 bit "double word" vectors
#define     VDBU_SN(_)          _ ## dbu
#define     VDBI_SN(_)          _ ## dbi

#define     VDHU_SN(_)          _ ## dhu
#define     VDHI_SN(_)          _ ## dhi
#define     VDHF_SN(_)          _ ## dhf

#define     VDWU_SN(_)          _ ## dwu
#define     VDWI_SN(_)          _ ## dwi
#define     VDWF_SN(_)          _ ## dwf

#define     VDDU_SN(_)          _ ## ddu
#define     VDDI_SN(_)          _ ## ddi
#define     VDDF_SN(_)          _ ## ddf

// 128 bit "quadruple word" vectors
#define     VQBU_SN(_)          _ ## qbu
#define     VQBI_SN(_)          _ ## qbi

#define     VQHU_SN(_)          _ ## qhu
#define     VQHI_SN(_)          _ ## qhi
#define     VQHF_SN(_)          _ ## qhf

#define     VQWU_SN(_)          _ ## qwu
#define     VQWI_SN(_)          _ ## qwi
#define     VQWF_SN(_)          _ ## qwf

#define     VQDU_SN(_)          _ ## qdu
#define     VQDI_SN(_)          _ ## qdi
#define     VQDF_SN(_)          _ ## qdf

#define     VQQU_SN(_)          _ ## qqu
#define     VQQI_SN(_)          _ ## qqi
#define     VQQF_SN(_)          _ ## qqf

// 256 bit "octuple word" vectors
#define     VOBU_SN(_)          _ ## obu
#define     VOBI_SN(_)          _ ## obi

#define     VOHU_SN(_)          _ ## ohu
#define     VOHI_SN(_)          _ ## ohi
#define     VOHF_SN(_)          _ ## ohf

#define     VOWU_SN(_)          _ ## owu
#define     VOWI_SN(_)          _ ## owi
#define     VOWF_SN(_)          _ ## owf

#define     VODU_SN(_)          _ ## odu
#define     VODI_SN(_)          _ ## odi
#define     VODF_SN(_)          _ ## odf

#define     VOQU_SN(_)          _ ## oqu
#define     VOQI_SN(_)          _ ## oqi
#define     VOQF_SN(_)          _ ## oqf

// 512 bit "sexdecuple word" vectors
#define     VSBU_SN(_)          _ ## sbu
#define     VSBI_SN(_)          _ ## sbi

#define     VSHU_SN(_)          _ ## shu
#define     VSHI_SN(_)          _ ## shi
#define     VSHF_SN(_)          _ ## shf

#define     VSWU_SN(_)          _ ## swu
#define     VSWI_SN(_)          _ ## swi
#define     VSWF_SN(_)          _ ## swf

#define     VSDU_SN(_)          _ ## sdu
#define     VSDI_SN(_)          _ ## sdi
#define     VSDF_SN(_)          _ ## sdf

#define     VSQU_SN(_)          _ ## squ
#define     VSQI_SN(_)          _ ## sqi
#define     VSQF_SN(_)          _ ## sqf


/*
    The following figure shows the relationship between the
    fundamental types:

    Any:
        Scalar:
            Byte B;
                Bc  C;  // char
                Bu  U;  // uchar
                Bi  I;  // schar
            Half H;
                Hu  U;  // ushort
                Hi  I;  //  short
                Hf  F:  // ushort || _Float16
            Word W;
                Wu  U;  //  uint
                Wi  I;  //   int
                Wf  F;  // float
            Dwrd D;
                Du  U;  // ullong || ulong
                Di  I;  //  llong ||  long
                Df  F;  // double
            Quad Q;
                Qu  U;  // Xqu || unsigned __int128 || ullong
                Qi  I;  // Xqi ||   signed __int128 || ullong
                Qf  F;  // Xqf || _Float128 || long double
            Split X;
                Xh  H;  //
                    Xhu U; // Bu[2]
                    Xhi I; // Bi[2]
                    Xhf F; // Bu[2]

                Xw W;
                    Xwu U; // Hu[2]
                    Xwi I; // Hi[2]
                    Xwf F; // Hf[2]

                Xd D;
                    Xdu U; // Wu[2]
                    Xdi I; // Wi[2]
                    Xdf F; // Wu[2]

                Xq Q;
                    Xqu U; // Du[2]
                    Xqi I; // Di[2]
                    Xqf F; // Du[2]

        Vector V:

            Vb B:

                Vby:
                    Vbyb B:   bint1_t × 8
                    Vbyh H:   bint2_t × 4
                    Vbyw W:   bint4_t × 2
                    bool Y[1];
            Vh H:
                Vhy:
                    Vhyb B:  bint1_t × 16
                    Vhyh H:  bint2_t × 8
                    Vhyw W:  bint4_t × 4
                    bool Y[2];
            Vw W:
                Vwy Y:
                    Vwyb B:  bint1_t × 32
                    Vwyh H:  bint2_t × 16
                    Vwyw W:  bint4_t × 8
                    bool Y[4];

                Vwb B: // V.W.B
                    Vwbu U:  uint8_t × 4
                    Vwbi    I:   int8_t × 4

                Vwh H:
                    Vwhu U: uint16_t × 2
                    Vwhi I:  int16_t × 2
                    Vwhf F:  flt16_t × 2

            Vd:
                Vdy Y:
                    Vdyb B:  bint4_t × 64
                    Vdyh H:  bint4_t × 32
                    Vdyw W:  bint4_t × 16
                Vdb B:
                    Vdbu U:  uint8_t × 8
                    Vdbi I:   int8_t × 8
                Vdh H:
                    Vdhu : uint16_t × 4
                    Vdhi :  int16_t × 4
                    Vdhf :  flt16_t × 4
                Vdw W:
                    Vdwu : uint32_t × 2
                    Vdwi :  int32_t × 2
                    Vdwf :  flt32_t × 2

            Vq:
                Vqy:
                    Vqyb :  bint4_t × 128
                    Vqyh :  bint4_t × 64
                    Vqyw :  bint4_t × 32
                Vqb:
                    Vqbu :  uint8_t × 16
                    Vqbi :   int8_t × 16
                Vqh:
                    Vqhu : uint16_t × 8 (V.Q.H.K0..K7)
                    Vqhi :  int16_t × 8
                    Vqhf :  flt16_t × 8
                Vqw:
                    Vqwu : uint32_t × 4
                    Vqwi :  int32_t × 4
                    Vqwf :  flt32_t × 4
                Vqd:
                    Vqdu : uint64_t × 2
                    Vqdi :  int64_t × 2
                    Vqdf :  flt64_t × 2
                Vqi:
                    Vqdu : uint128_t × 1
                    Vqdi :  int128_t × 1
                    Vqdf :  flt128_t × 1

            256 bit

                Voyw :  bint4_t × 64

                Vobu :  uint8_t × 32
                Vobi :   int8_t × 32

                Vohu : uint16_t × 16
                Vohi :  int16_t × 16
                Vohf :  flt16_t × 16

                Vowu : uint32_t × 8
                Vowi :  int32_t × 8
                Vowf :  flt32_t × 8

                Vodu : uint64_t × 4
                Vodi :  int64_t × 4
                Vodf :  flt64_t × 4

                Voqu : uint128_t × 2
                Voqi :  int128_t × 2
                Voqf :  flt128_t × 2

            512 bit
                Vsbu :  uint8_t × 64
                Vsbi :   int8_t × 64

                Vshu : uint16_t × 32
                Vshi :  int16_t × 32
                Vshf :  flt16_t × 32

                Vswu : uint32_t × 16
                Vswi :  int32_t × 16
                Vswf :  flt32_t × 16

                Vsdu : uint64_t × 8
                Vsdi :  int64_t × 8
                Vsdf :  flt64_t × 8

                Vsqu : uint128_t × 4
                Vsqi :  int128_t × 4
                Vsqf :  flt128_t × 4

*/

#if defined(SPC_EMULATED_VECTOR_TYPES)

#else

#   if MY_ISA == ISA_X86

#       ifndef SPC_X86_SSE2
#       define SPC_EMULATED_VECTOR_TYPES
#       endif

#   elif MY_ISA == ISA_ARM

#       ifndef SPC_ARM_NEON
#       define SPC_EMULATED_VECTOR_TYPES
#       endif

#   endif // MY_ISA == ISA_X86

#endif // defined(SPC_EMULATED_VECTOR_TYPES)

#if defined(SPC_EMULATED_VECTOR_TYPES)

    struct Vdbu {  uint8_t MY_NV8(K,  );};
    struct Vdbi {   int8_t MY_NV8(K,  );};

    struct Vdhu { uint16_t MY_NV4(K,  );};
    struct Vdhi {  int16_t MY_NV4(K,  );};
    struct Vdhf {  flt16_t MY_NV4(K,  );};

    struct Vdwu { uint32_t MY_NV2(K,  );};
    struct Vdwi {  int32_t MY_NV2(K,  );};
    struct Vdwf {  flt32_t MY_NV2(K,  );};

    struct Vddu { uint64_t MY_NV1(K,  );};
    struct Vddi {  int64_t MY_NV1(K,  );};
    struct Vddf {  flt64_t MY_NV1(K,  );};


    struct Vqbu {  uint8_t MY_NV16(K, );};
    struct Vqbi {   int8_t MY_NV16(K, );};

    struct Vqhu { uint16_t MY_NV8(K,  );};
    struct Vqhi {  int16_t MY_NV8(K,  );};
    struct Vqhf {  flt16_t MY_NV8(K,  );};

    struct Vqwu { uint32_t MY_NV4(K,  );};
    struct Vqwi {  int32_t MY_NV4(K,  );};
    struct Vqwf {  flt32_t MY_NV4(K,  );};

    struct Vqdu { uint64_t MY_NV2(K,  );};
    struct Vqdi {  int64_t MY_NV2(K,  );};
    struct Vqdf {  flt64_t MY_NV2(K,  );};

    struct Vqqu {uint128_t MY_NV1(K,  );};
    struct Vqqi { int128_t MY_NV1(K,  );};
    struct Vqqf { flt128_t MY_NV1(K,  );};


    struct Vobu {  uint8_t MY_NV32(K, );};
    struct Vobi {   int8_t MY_NV32(K, );};

    struct Vohu { uint16_t MY_NV16(K,  );};
    struct Vohi {  int16_t MY_NV16(K,  );};
    struct Vohf {  flt16_t MY_NV16(K,  );};

    struct Vowu { uint32_t MY_NV8(K,  );};
    struct Vowi {  int32_t MY_NV8(K,  );};
    struct Vowf {  flt32_t MY_NV8(K,  );};

    struct Vodu { uint64_t MY_NV4(K,  );};
    struct Vodi {  int64_t MY_NV4(K,  );};
    struct Vodf {  flt64_t MY_NV4(K,  );};

    struct Voqu {uint128_t MY_NV2(K,  );};
    struct Voqi { int128_t MY_NV2(K,  );};
    struct Voqf { flt128_t MY_NV2(K,  );};


    struct Vsbu {  uint8_t MY_NV64(K, );};
    struct Vsbi {   int8_t MY_NV64(K, );};

    struct Vshu { uint16_t MY_NV32(K,  );};
    struct Vshi {  int16_t MY_NV32(K,  );};
    struct Vshf {  flt16_t MY_NV32(K,  );};

    struct Vswu { uint32_t MY_NV16(K,  );};
    struct Vswi {  int32_t MY_NV16(K,  );};
    struct Vswf {  flt32_t MY_NV16(K,  );};

    struct Vsdu { uint64_t MY_NV8(K,  );};
    struct Vsdi {  int64_t MY_NV8(K,  );};
    struct Vsdf {  flt64_t MY_NV8(K,  );};

    struct Vsqu {uint128_t MY_NV4(K,  );};
    struct Vsqi { int128_t MY_NV4(K,  );};
    struct Vsqf { flt128_t MY_NV4(K,  );};


#elif MY_ISA == ISA_X86

#   ifndef MY_INTRIN_H
#   define MY_INTRIN_H
#   include  <intrin.h>
#   endif

/*  For x86 targets, we use a `double` to represent a 64 bit
    vector, since all supported targets pass and return them
    in the low 64 bits of an xmm register.
    
    There's no MD[BHWD]*_TYPE object macros defined because 
    `__m64`, the closest thing x86 has to a 64 bit vector
    type, only supports a very small subset of operations,
    even on the platforms that actually bother implementing
    them.
*/

    struct Vdbu {double    MY_NV1(V,  );};
    struct Vdbi {double    MY_NV1(V,  );};

    struct Vdhu {double    MY_NV1(V,  );};
    struct Vdhi {double    MY_NV1(V,  );};
    struct Vdhf {double    MY_NV1(V,  );};

    struct Vdwu {double    MY_NV1(V,  );};
    struct Vdwi {double    MY_NV1(V,  );};
    struct Vdwf {double    MY_NV1(V,  );};

    struct Vddu {double    MY_NV1(V,  );};
    struct Vddu {double    MY_NV1(V,  );};
    struct Vddf {double    MY_NV1(V,  );};

#   define  MQB_TYPE        union Vqb
#   define  MQBU_TYPE       __m128i
#   define  MQBI_TYPE       __m128i

#   define  MQH_TYPE        union Vqh
#   define  MQHU_TYPE       __m128i
#   define  MQHI_TYPE       __m128i

#   define  MQW_TYPE        union Vqw
#   define  MQWU_TYPE       __m128i
#   define  MQWI_TYPE       __m128i
#   define  MQWF_TYPE       __m128

#   define  MQD_TYPE        union Vqd
#   define  MQDU_TYPE       __m128i
#   define  MQDI_TYPE       __m128i
#   define  MQDF_TYPE       __m128d

#   define  MQQ_TYPE        union Vqq
#   define  MQQU_TYPE       __m128i
#   define  MQQI_TYPE       __m128i
#   define  MQQF_TYPE       __m128d

    struct Vqbu {__m128i MY_NV1(V,  );};
    struct Vqbi {__m128i MY_NV1(V,  );};

    struct Vqhu {__m128i MY_NV1(V,  );};
    struct Vqhi {__m128i MY_NV1(V,  );};

    struct Vqwu {__m128i MY_NV1(V,  );};
    struct Vqwi {__m128i MY_NV1(V,  );};
    struct Vqwi {__m128  MY_NV1(V,  );};

    struct Vqdu {__m128i MY_NV1(V,  );};
    struct Vqdi {__m128i MY_NV1(V,  );};
    struct Vqdi {__m128d MY_NV1(V,  );};

    struct Vqdu {__m128i MY_NV1(V,  );};
    struct Vqdi {__m128i MY_NV1(V,  );};
    struct Vqdi {__m128d MY_NV1(V,  );};

#   if defined(SPC_X86_AVX512FP16)
#       define MQHF_TYPE    __m128h
#       define MOHF_TYPE    __m256h
#       define MSHF_TYPE    __m512h
        struct Vqhf {__m128h MY_NV1(V,  );};
        struct Vohf {__m256h MY_NV1(V,  );};
        struct Vshf {__m512h MY_NV1(V,  );};
#   else
#       define MQHU_TYPE    __m128i
#       define MOHU_TYPE    __m256i
#       define MSHU_TYPE    __m512i
        struct Vqhf {__m128i MY_NV1(V,  );};
        struct Vohf {__m256i MY_NV1(V,  );};
        struct Vshf {__m512i MY_NV1(V,  );};
#   endif

#   if defined(SPC_X86_AVX)

#       define MOB_TYPE     union Vob
#       define MOBU_TYPE    __m256i
#       define MOBU_TYPE    __m256i
#       define MOBI_TYPE    __m256i

#       define MOH_TYPE     union Voh
#       define MOHU_TYPE    __m256i
#       define MOHI_TYPE    __m256i

#       define MOW_TYPE     union Vow
#       define MOWU_TYPE    __m256i
#       define MOWI_TYPE    __m256i
#       define MOWF_TYPE    __m256

#       define MOD_TYPE     union Vod
#       define MODU_TYPE    __m256i
#       define MODI_TYPE    __m256i
#       define MODF_TYPE    __m256d

        struct Vobu {__m256i  MY_NV1(V, );};
        struct Vobi {__m256i  MY_NV1(V, );};
    
        struct Vohu {__m256i  MY_NV1(V, );};
        struct Vohi {__m256i  MY_NV1(V, );};
    
        struct Vowu {__m256i  MY_NV1(V, );};
        struct Vowi {__m256i  MY_NV1(V, );};
        struct Vowf {__m256   MY_NV1(V, );};
    
        struct Vodu {__m256i  MY_NV1(V, );};
        struct Vodi {__m256i  MY_NV1(V, );};
        struct Vodf {__m256d  MY_NV1(V, );};
    
        struct Voqu {__m256i  MY_NV1(V, );};
        struct Voqi {__m256i  MY_NV1(V, );};
        struct Voqf {__m256d  MY_NV1(V, );};
#else
        struct Vobu {__m128i MY_NV2(V, );};
        struct Vobi {__m128i MY_NV2(V, );};
    
        struct Vohu {__m128i MY_NV2(V, );};
        struct Vohi {__m128i MY_NV2(V, );};
    
        struct Vowu {__m128i MY_NV2(V, );};
        struct Vowi {__m128i MY_NV2(V, );};
        struct Vowf {__m128  MY_NV2(V, );};
    
        struct Vodu {__m128i MY_NV2(V, );};
        struct Vodi {__m128i MY_NV2(V, );};
        struct Vodf {__m128d MY_NV2(V, );};
    
        struct Voqu {__m128i MY_NV2(V, );};
        struct Voqi {__m128i MY_NV2(V, );};
        struct Voqf {__m128d MY_NV2(V, );};
#   endif // defined(SPC_X86_AVX)

#   if defined(SPC_X86_AVX512F)
#       define MSB_TYPE     union Vob
#       define MSBU_TYPE    __m512i
#       define MSBI_TYPE    __m512i

#       define MSH_TYPE     union Voh
#       define MSHU_TYPE    __m512i
#       define MSHI_TYPE    __m512i

#       define MSW_TYPE     union Vow
#       define MSWU_TYPE    __m512i
#       define MSWI_TYPE    __m512i
#       define MSWF_TYPE    __m512

#       define MSD_TYPE     union Vod
#       define MSDU_TYPE    __m512i
#       define MSDI_TYPE    __m512i
#       define MSDF_TYPE    __m512d

        struct Vsbu {__m512i  MY_NV1(V, );};
        struct Vsbi {__m512i  MY_NV1(V, );};
    
        struct Vshu {__m512i  MY_NV1(V, );};
        struct Vshi {__m512i  MY_NV1(V, );};
    
        struct Vswu {__m512i  MY_NV1(V, );};
        struct Vswi {__m512i  MY_NV1(V, );};
        struct Vswf {__m512   MY_NV1(V, );};
    
        struct Vsdu {__m512i  MY_NV1(V, );};
        struct Vsdi {__m512i  MY_NV1(V, );};
        struct Vsdf {__m512d  MY_NV1(V, );};
    
        struct Vsqu {__m512i  MY_NV1(V, );};
        struct Vsqi {__m512i  MY_NV1(V, );};
        struct Vsqf {__m512d  MY_NV1(V, );};
#   else
/*  We're not going to make the x86 codebase 33% larger 
    just to accommodate the couple of years between AVX2 
    and AVX512.
*/
        struct Vsbu {__m128i  MY_NV4(V, );};
        struct Vsbi {__m128i  MY_NV4(V, );};
    
        struct Vshu {__m128i  MY_NV4(V, );};
        struct Vshi {__m128i  MY_NV4(V, );};
    
        struct Vswu {__m128i  MY_NV4(V, );};
        struct Vswi {__m128i  MY_NV4(V, );};
        struct Vswf {__m128   MY_NV4(V, );};
    
        struct Vsdu {__m128i  MY_NV4(V, );};
        struct Vsdi {__m128i  MY_NV4(V, );};
        struct Vsdf {__m128d  MY_NV4(V, );};
    
        struct Vsqu {__m128i  MY_NV4(V, );};
        struct Vsqi {__m128i  MY_NV4(V, );};
        struct Vsqf {__m128d  MY_NV4(V, );};
#   endif // defined(SPC_X86_AVX512F)


#elif MY_ISA == ISA_ARM

#   define  MHF_TYPE    __fp16

#   if  defined(_MSC_VER)
#       error "MSVC support is currently restricted to x86"
#   endif

#   ifndef MY_ARM_NEON_H
#   include  <arm_neon.h>
#   endif

#   ifndef MY_ARM_ACLE_H
#   include  <arm_acle.h>
#   endif

/*  The convoluted definitions of Vqqu, Vqqi, and Vqqf
    are needed to guarantee values are passed and returned
    in vector registers.
*/

#   define MDB_TYPE     union Vdb
#   define MDH_TYPE     union Vdh
#   define MDW_TYPE     union Vdw
#   define MDD_TYPE     union Vdd

#   define MQB_TYPE     union Vqb
#   define MQH_TYPE     union Vqh
#   define MQW_TYPE     union Vqw
#   define MQD_TYPE     union Vqd
#   define MQQ_TYPE     union Vqq

#   define MDBU_TYPE   uint8x8_t
#   define MDBI_TYPE    int8x8_t

#   define MDHU_TYPE   uint16x4_t
#   define MDHI_TYPE    int16x4_t

#   define MDWU_TYPE   uint32x2_t
#   define MDHF_TYPE  float16x4_t
#   define MDWI_TYPE    int32x2_t
#   define MDWF_TYPE  float32x2_t

#   define MDDU_TYPE   uint64x1_t
#   define MDDI_TYPE    int64x1_t
#   define MDDF_TYPE  float64x1_t


#   define MQBU_TYPE   uint8x16_t
#   define MQBI_TYPE    int8x16_t

#   define MQHU_TYPE   uint16x8_t
#   define MQHI_TYPE    int16x8_t
#   define MQHF_TYPE  float16x8_t

#   define MQWU_TYPE   uint32x4_t
#   define MQWI_TYPE    int32x4_t
#   define MQWF_TYPE  float32x4_t

#   define MQDU_TYPE   uint64x2_t
#   define MQDI_TYPE    int64x2_t
#   define MQDF_TYPE  float64x2_t

#   define MQQU_TYPE    poly128_t


#   define VDBU_TYPE   uint8x8_t
#   define VDBI_TYPE    int8x8_t

#   define VDHU_TYPE   uint16x4_t
#   define VDHI_TYPE    int16x4_t
#   define VDHF_TYPE  float16x4_t

#   define VDWU_TYPE   uint32x2_t
#   define VDWI_TYPE    int32x2_t
#   define VDWF_TYPE  float32x2_t

#   define VDDU_TYPE   uint64x1_t
#   define VDDI_TYPE    int64x1_t
#   define VDDF_TYPE  float64x1_t



#   define VQBU_TYPE   uint8x16_t
#   define VQBI_TYPE    int8x16_t

#   define VQHU_TYPE   uint16x8_t
#   define VQHI_TYPE    int16x8_t
#   define VQHF_TYPE  float16x8_t

#   define VQWU_TYPE   uint32x4_t
#   define VQWI_TYPE    int32x4_t
#   define VQWF_TYPE  float32x4_t

#   define VQDU_TYPE   uint64x2_t
#   define VQDI_TYPE    int64x2_t
#   define VQDF_TYPE  float64x2_t

    struct Vqqu { uint64x2_t MY_NV1(V,  );};

    struct Vqqi {  int64x2_t MY_NV1(V,  );};

    struct Vqqf {float64x2_t MY_NV1(V,  );};

#   define VQQU_TYPE struct Vqqu
#   define VQQI_TYPE struct Vqqi
#   define VQQF_TYPE struct Vqqf


#   define MOBU_TYPE  uint8x16x2_t
#   define MOBI_TYPE   int8x16x2_t

#   define MOHU_TYPE  uint16x8x2_t
#   define MOHI_TYPE   int16x8x2_t
#   define MOHF_TYPE float16x8x2_t
#   define MOWU_TYPE uint32x4x2_t
#   define MOWI_TYPE   int32x4x2_t
#   define MOWF_TYPE float32x4x2_t

#   define MODU_TYPE  uint64x2x2_t
#   define MODI_TYPE   int64x2x2_t
#   define MODF_TYPE float64x2x2_t

#   define MSBU_TYPE  uint8x16x4_t
#   define MSBI_TYPE   int8x16x4_t

#   define MSHU_TYPE  uint16x8x4_t
#   define MSHI_TYPE   int16x8x4_t
#   define MSHF_TYPE float16x8x4_t

#   define MSWU_TYPE  uint32x4x4_t
#   define MSWI_TYPE   int32x4x4_t
#   define MSWF_TYPE float32x4x4_t

#   define MSDU_TYPE  uint64x2x4_t
#   define MSDI_TYPE   int64x2x4_t
#   define MSDF_TYPE float64x2x4_t

/*
    If there's a target on which these aren't classified
    by the ABI as homogeneous short vector aggregates,
    tough titties.
*/
    struct Voqu { 
        union {
            struct {  MODU_TYPE M;};
            struct { uint64x2_t MY_NV2(V,  );};
        };
    };

    struct Voqi { 
        union {
            struct {  MODI_TYPE M;};
            struct {  int64x2_t MY_NV2(V,  );};
        };
    };

    struct Voqf { 
        union {
            struct {  MODF_TYPE M;};
            struct {float64x2_t MY_NV2(V,  );};
        };
    };



    struct Vsqu { 
        union {
            struct {  MSDU_TYPE M;};
            struct { uint64x2_t MY_NV4(V,  );};
        };
    };

    struct Vsqi { 
        union {
            struct {  MSDI_TYPE M;};
            struct {  int64x2_t MY_NV4(V,  );};
        };
    };

    struct Vsqf { 
        union {
            struct {  MSDF_TYPE M;};
            struct {float64x2_t MY_NV4(V,  );};
        };
    };

#   define VOQU_TYPE struct Voqu
#   define VOQI_TYPE struct Voqi
#   define VOQF_TYPE struct Voqf

#   define VSQU_TYPE struct Vsqu
#   define VSQI_TYPE struct Vsqi
#   define VSQF_TYPE struct Vsqf

#   if 0
{
    struct Vobu {
        union {    
            struct { MOBU_TYPE  M;};
            struct {uint8x16_t  MY_NV2(V, );};
        };
    };

    struct Vobi {
        union {
            struct { MOBI_TYPE  M;};
            struct { int8x16_t  MY_NV2(V, );};
        };
    };


    struct Vohu {
        union {
            struct {  MOHU_TYPE M;};
            struct { uint16x8_t MY_NV2(V, );};
        };
    };

    struct Vohi {
        union {
            struct {  MOHI_TYPE M;};
            struct {  int16x8_t MY_NV2(V, );};
        };
    };

    struct Vohf {
        union {
            struct {  MOHF_TYPE M;};
            struct {float16x8_t MY_NV2(V, );};
        };
    };


    struct Vowu {
        union {
            struct {MOWU_TYPE   M;};
            struct { uint32x4_t MY_NV2(V, );};
        };
    };

    struct Vowi {
        union {
            struct {MOWI_TYPE   M;};
            struct {int32x4_t MY_NV2(V, );};
        };
    };

    struct Vowf {
        union {
            struct {MOWF_TYPE   M;};
            struct {float32x4_t MY_NV2(V, );};
        };
    };


    struct Vodu {
        union {
            struct {MODU_TYPE   M;};
            struct {uint64x2_t  MY_NV2(V, );};
        };
    };

    struct Vodi {
        union {
            struct {MODI_TYPE   M;};
            struct {int64x2_t   MY_NV2(V, );};
        };
    };

    struct Vodf {
        union {
            struct {MODF_TYPE   M;};
            struct {float64x2_t MY_NV2(V, );};
        };
    };



    struct Vsbu {
        union {    
            struct { MSBU_TYPE  M;};
            struct {uint8x16_t  MY_NV4(V, );};
        };
    };

    struct Vsbi {
        union {
            struct { MSBI_TYPE  M;};
            struct { int8x16_t  MY_NV4(V, );};
        };
    };


    struct Vshu {
        union {
            struct {  MSHU_TYPE M;};
            struct { uint16x8_t MY_NV4(V, );};
        };
    };

    struct Vshi {
        union {
            struct {  MSHI_TYPE M;};
            struct {  int16x8_t MY_NV4(V, );};
        };
    };

    struct Vshf {
        union {
            struct {  MSHF_TYPE M;};
            struct {float16x8_t MY_NV4(V, );};
        };
    };


    struct Vswu {
        union {
            struct {MSWU_TYPE   M;};
            struct { uint32x4_t MY_NV4(V, );};
        };
    };

    struct Vswi {
        union {
            struct {MSWI_TYPE   M;};
            struct {int32x4_t MY_NV4(V, );};
        };
    };

    struct Vswf {
        union {
            struct {MSWF_TYPE   M;};
            struct {float32x4_t MY_NV4(V, );};
        };
    };


    struct Vsdu {
        union {
            struct {  MSDU_TYPE M;};
            struct { uint64x2_t MY_NV4(V, );};
        };
    };

    struct Vsdi {
        union {
            struct {  MSDI_TYPE M;};
            struct {  int64x2_t MY_NV4(V, );};
        };
    };

    struct Vsdf {
        union {
            struct {  MSDF_TYPE M;};
            struct {float64x2_t MY_NV4(V, );};
        };
    };
}
#   endif // if 0

#elif MY_ISA == ISA_PPC

#   ifndef MY_ALTIVEC_H
#   include  <altivec.h>
#   endif
/*  Eventually, someone else can properly design a proper
    ppc implementation.
*/
#   define MQBU_TYPE vector unsigned char
#   define MQBI_TYPE vector signed char

#   define MQHU_TYPE vector unsigned short 
#   define MQHI_TYPE vector short
#   define MQHF_TYPE vector unsigned short 

#   define MQWU_TYPE vector unsigned int
#   define MQWI_TYPE vector int
#   define MQWF_TYPE vector float

#   if QUAD_NLONG == 2
#       define MQDU_TYPE vector unsigned long
#       define MQDI_TYPE vector long
#   else
#       define MQDU_TYPE vector unsigned long long
#       define MQDI_TYPE vector long long
#   endif

#   define MQDF_TYPE vector double

#   if defined(__INT128_SIZEOF__)
#       define MQQU_TYPE vector unsigned __int128
#       define MQQI_TYPE vector __int128
#       define MQQF_TYPE vector unsigned __int128
#   else
#       define MQQU_TYPE vector unsigned long long
#       define MQQI_TYPE vector long long
#       define MQQF_TYPE vector unsigned long long
#   endif

#elif MY_ISA == ISA_RV


#endif // defined(EMULATE_VECTOR_TYPES)

#undef B
#undef H
#undef W
#undef D
#undef Q
#undef O
#undef S


#if defined(MQBU_TYPE) && !defined(VOBU_TYPE)
struct Vobu {
    union {
#   if defined(MOBU_TYPE)
        MOBU_TYPE   M;
#   endif
        struct {MQBU_TYPE   MY_NV2(V,  );};
    };
};
#endif

#if defined(MQBI_TYPE) && !defined(VOBI_TYPE)
struct Vobi {
    union {
#   if defined(MOBI_TYPE)
        MOBI_TYPE   M;
#   endif
        struct {MQBI_TYPE   MY_NV2(V,  );};
    };
};
#endif


#if defined(MQHU_TYPE) && !defined(VOHU_TYPE)
struct Vohu {
    union {
#   if defined(MOHU_TYPE)
        MOHU_TYPE   M;
#   endif
        struct {MQHU_TYPE   MY_NV2(V,  );};
    };
};
#endif

#if defined(MQHI_TYPE) && !defined(VOHI_TYPE)
struct Vohi {
    union {
#   if defined(MOHI_TYPE)
        MOHI_TYPE   M;
#   endif
        struct { MQHI_TYPE   MY_NV2(V,  );};
    };
};
#endif

#if defined(MQHF_TYPE) && !defined(VOHF_TYPE)
struct Vohf {
    union {
#   if defined(MOHF_TYPE)
        MOHF_TYPE   M;
#   endif
        struct { MQHF_TYPE   MY_NV2(V,  ); };
    };
};
#endif


#if defined(MQWU_TYPE) && !defined(VOWU_TYPE)
struct Vowu {
    union {
#   if defined(MOWU_TYPE)
        MOWU_TYPE   M;
#   endif
        struct {MQWU_TYPE   MY_NV2(V,  );};
    };
};
#endif

#if defined(MQWI_TYPE) && !defined(VOWI_TYPE)
struct Vowi {
    union {
#   if defined(MOWI_TYPE)
        MOWI_TYPE   M;
#   endif
        struct {MQWI_TYPE   MY_NV2(V,  );};
    };
};
#endif

#if defined(MQWF_TYPE) && !defined(VOWF_TYPE)
struct Vowf {
    union {
#   if defined(MOWF_TYPE)
        MOWF_TYPE   M;
#   endif
        struct {MQWF_TYPE   MY_NV2(V,  );};
    };
};
#endif


#if defined(MQDU_TYPE) && !defined(VODU_TYPE)
struct Vodu {
    union {
#   if defined(MODU_TYPE)
        MODU_TYPE   M;
#   endif
        struct {MQDU_TYPE   MY_NV2(V,  );};
    };
};
#endif

#if defined(MQDI_TYPE) && !defined(VODI_TYPE)
struct Vodi {
    union {
#   if defined(MODI_TYPE)
        MODI_TYPE   M;
#   endif
        struct {MQDI_TYPE   MY_NV2(V,  );};
    };
};
#endif

#if defined(MQDF_TYPE) && !defined(VODF_TYPE)
struct Vodf {
    union {
#   if defined(MODF_TYPE)
        MODF_TYPE   M;
#   endif
        struct {MQDF_TYPE   MY_NV2(V,  );};
    };
};
#endif



#if defined(MQQU_TYPE) && !defined(VOQU_TYPE)
struct Voqu {
    union {
#   if defined(MOQU_TYPE)
        MOQU_TYPE   M;
#   endif
        struct {MQQU_TYPE   MY_NV2(V,  );};
    };
};
#endif

#if defined(MQQI_TYPE) && !defined(VOQI_TYPE)
struct Voqi {
    union {
#   if defined(MOQI_TYPE)
        MOQI_TYPE   M;
#   endif
        struct {MQQI_TYPE   MY_NV2(V,  );};
    };
};
#endif

#if defined(MQQF_TYPE) && !defined(VOQF_TYPE)
struct Voqf {
    union {
#   if defined(MOQF_TYPE)
        MOQF_TYPE   M;
#   endif
        struct {MQQF_TYPE   MY_NV2(V,  );};
    };
};
#endif


#if defined(MQBU_TYPE) && !defined(VSBU_TYPE)
struct Vsbu {
    union {
#   if defined(MSBU_TYPE)
        MSBU_TYPE   M;
#   endif
        struct {MQBU_TYPE   MY_NV4(V,  );};
    };
};
#endif

#if defined(MQBI_TYPE) && !defined(VSBI_TYPE)
struct Vsbi {
    union {
#   if defined(MSBI_TYPE)
        MSBI_TYPE   M;
#   endif
        struct {MQBI_TYPE   MY_NV4(V,  );};
    };
};
#endif


#if defined(MQHU_TYPE) && !defined(VSHU_TYPE)
struct Vshu {
    union {
#   if defined(MSHU_TYPE)
        MSHU_TYPE   M;
#   endif
        struct {MQHU_TYPE   MY_NV4(V,  );};
    };
};
#endif

#if defined(MQHI_TYPE) && !defined(VSHI_TYPE)
struct Vshi {
    union {
#   if defined(MSHI_TYPE)
        MSHI_TYPE   M;
#   endif
        struct { MQHI_TYPE   MY_NV4(V,  );};
    };
};
#endif

#if defined(MQHF_TYPE) && !defined(VSHF_TYPE)
struct Vshf {
    union {
#   if defined(MSHF_TYPE)
        MSHF_TYPE   M;
#   endif
        struct { MQHF_TYPE   MY_NV4(V,  ); };
    };
};
#endif


#if defined(MQWU_TYPE) && !defined(VSWU_TYPE)
struct Vswu {
    union {
#   if defined(MSWU_TYPE)
        MSWU_TYPE   M;
#   endif
        struct {MQWU_TYPE   MY_NV4(V,  );};
    };
};
#endif

#if defined(MQWI_TYPE) && !defined(VSWI_TYPE)
struct Vswi {
    union {
#   if defined(MSWI_TYPE)
        MSWI_TYPE   M;
#   endif
        struct {MQWI_TYPE   MY_NV4(V,  );};
    };
};
#endif

#if defined(MQWF_TYPE) && !defined(VSWF_TYPE)
struct Vswf {
    union {
#   if defined(MSWF_TYPE)
        MSWF_TYPE   M;
#   endif
        struct {MQWF_TYPE   MY_NV4(V,  );};
    };
};
#endif


#if defined(MQDU_TYPE) && !defined(VSDU_TYPE)
struct Vsdu {
    union {
#   if defined(MSDU_TYPE)
        MSDU_TYPE   M;
#   endif
        struct {MQDU_TYPE   MY_NV4(V,  );};
    };
};
#endif

#if defined(MQDI_TYPE) && !defined(VSDI_TYPE)
struct Vsdi {
    union {
#   if defined(MSDI_TYPE)
        MSDI_TYPE   M;
#   endif
        struct {MQDI_TYPE   MY_NV4(V,  );};
    };
};
#endif

#if defined(MQDF_TYPE) && !defined(VSDF_TYPE)
struct Vsdf {
    union {
#   if defined(MSDF_TYPE)
        MSDF_TYPE   M;
#   endif
        struct {MQDF_TYPE   MY_NV4(V,  );};
    };
};
#endif



#if defined(MQQU_TYPE) && !defined(VSQU_TYPE)
struct Vsqu {
    union {
#   if defined(MSQU_TYPE)
        MSQU_TYPE   M;
#   endif
        struct {MQQU_TYPE   MY_NV4(V,  );};
    };
};
#endif

#if defined(MQQI_TYPE) && !defined(VSQI_TYPE)
struct Vsqi {
    union {
#   if defined(MSQI_TYPE)
        MSQI_TYPE   M;
#   endif
        struct {MQQI_TYPE   MY_NV4(V,  );};
    };
};
#endif

#if defined(MQQF_TYPE) && !defined(VSQF_TYPE)
struct Vsqf {
    union {
#   if defined(MSQF_TYPE)
        MSQF_TYPE   M;
#   endif
        struct {MQQF_TYPE   MY_NV4(V,  );};
    };
};
#endif




#ifndef VDBU_TYPE
#define VDBU_TYPE        struct Vdbu
#endif

#ifndef VDBI_TYPE
#define VDBI_TYPE        struct Vdbi
#endif


#ifndef VDHU_TYPE
#define VDHU_TYPE        struct Vdhu
#endif

#ifndef VDHI_TYPE
#define VDHI_TYPE        struct Vdhi
#endif

#ifndef VDHF_TYPE
#define VDHF_TYPE        struct Vdhf
#endif


#ifndef VDWU_TYPE
#define VDWU_TYPE        struct Vdwu
#endif

#ifndef VDWI_TYPE
#define VDWI_TYPE        struct Vdwi
#endif

#ifndef VDWF_TYPE
#define VDWF_TYPE        struct Vdwf
#endif


#ifndef VDDU_TYPE
#define VDDU_TYPE        struct Vddu
#endif

#ifndef VDDI_TYPE
#define VDDI_TYPE        struct Vddi
#endif

#ifndef VDDF_TYPE
#define VDDF_TYPE        struct Vddf
#endif



#ifndef VQBU_TYPE
#define VQBU_TYPE        struct Vqbu
#endif

#ifndef VQBI_TYPE
#define VQBI_TYPE        struct Vqbi
#endif


#ifndef VQHU_TYPE
#define VQHU_TYPE        struct Vqhu
#endif

#ifndef VQHI_TYPE
#define VQHI_TYPE        struct Vqhi
#endif

#ifndef VQHF_TYPE
#define VQHF_TYPE        struct Vqhf
#endif


#ifndef VQWU_TYPE
#define VQWU_TYPE        struct Vqwu
#endif

#ifndef VQWI_TYPE
#define VQWI_TYPE        struct Vqwi
#endif

#ifndef VQWF_TYPE
#define VQWF_TYPE        struct Vqwf
#endif


#ifndef VQDU_TYPE
#define VQDU_TYPE        struct Vqdu
#endif

#ifndef VQDI_TYPE
#define VQDI_TYPE        struct Vqdi
#endif

#ifndef VQDF_TYPE
#define VQDF_TYPE        struct Vqdf
#endif


#ifndef VQQU_TYPE
#define VQQU_TYPE        struct Vqqu
#endif

#ifndef VQQI_TYPE
#define VQQI_TYPE        struct Vqqi
#endif

#ifndef VQQF_TYPE
#define VQQF_TYPE        struct Vqqf
#endif



#ifndef VOBU_TYPE
#define VOBU_TYPE        struct Vobu
#endif

#ifndef VOBI_TYPE
#define VOBI_TYPE        struct Vobi
#endif

#ifndef VOHU_TYPE
#define VOHU_TYPE        struct Vohu
#endif

#ifndef VOHI_TYPE
#define VOHI_TYPE        struct Vohi
#endif

#ifndef VOHF_TYPE
#define VOHF_TYPE        struct Vohf
#endif


#ifndef VOWU_TYPE
#define VOWU_TYPE        struct Vowu
#endif

#ifndef VOWI_TYPE
#define VOWI_TYPE        struct Vowi
#endif

#ifndef VOWF_TYPE
#define VOWF_TYPE        struct Vowf
#endif


#ifndef VODU_TYPE
#define VODU_TYPE        struct Vodu
#endif

#ifndef VODI_TYPE
#define VODI_TYPE        struct Vodi
#endif

#ifndef VODF_TYPE
#define VODF_TYPE        struct Vodf
#endif


#ifndef VOQU_TYPE
#define VOQU_TYPE        struct Voqu
#endif

#ifndef VOQI_TYPE
#define VOQI_TYPE        struct Voqi
#endif

#ifndef VOQF_TYPE
#define VOQF_TYPE        struct Voqf
#endif


#ifndef VSBU_TYPE
#define VSBU_TYPE        struct Vsbu
#endif

#ifndef VSBI 
#define VSBI_TYPE        struct Vsbi
#endif


#ifndef VSHU_TYPE
#define VSHU_TYPE        struct Vshu
#endif

#ifndef VSHI_TYPE
#define VSHI_TYPE        struct Vshi
#endif

#ifndef VSHF_TYPE
#define VSHF_TYPE        struct Vshf
#endif


#ifndef VSWU_TYPE
#define VSWU_TYPE        struct Vswu
#endif

#ifndef VSWI_TYPE
#define VSWI_TYPE        struct Vswi
#endif

#ifndef VSWF_TYPE
#define VSWF_TYPE        struct Vswf
#endif


#ifndef VSDU_TYPE
#define VSDU_TYPE        struct Vsdu
#endif

#ifndef VSDI_TYPE
#define VSDI_TYPE        struct Vsdi
#endif

#ifndef VSDF_TYPE
#define VSDF_TYPE        struct Vsdf
#endif


#ifndef VSQU_TYPE
#define VSQU_TYPE        struct Vsqu
#endif

#ifndef VSQI_TYPE
#define VSQI_TYPE        struct Vsqi
#endif

#ifndef VSQF_TYPE
#define VSQF_TYPE        struct Vsqf
#endif


typedef VDBU_TYPE   Vdbu;
typedef VDBI_TYPE   Vdbi;

typedef VDHU_TYPE   Vdhu;
typedef VDHI_TYPE   Vdhi;
typedef VDHF_TYPE   Vdhf;

typedef VDWU_TYPE   Vdwu;
typedef VDWI_TYPE   Vdwi;
typedef VDWF_TYPE   Vdwf;

typedef VDDU_TYPE   Vddu;
typedef VDDI_TYPE   Vddi;
typedef VDDF_TYPE   Vddf;


typedef VQBU_TYPE   Vqbu;
typedef VQBI_TYPE   Vqbi;

typedef VQHU_TYPE   Vqhu;
typedef VQHI_TYPE   Vqhi;
typedef VQHF_TYPE   Vqhf;

typedef VQWU_TYPE   Vqwu;
typedef VQWI_TYPE   Vqwi;
typedef VQWF_TYPE   Vqwf;

typedef VQDU_TYPE   Vqdu;
typedef VQDI_TYPE   Vqdi;
typedef VQDF_TYPE   Vqdf;

typedef VQQU_TYPE   Vqqu;
typedef VQQI_TYPE   Vqqi;
typedef VQQF_TYPE   Vqqf;


typedef VOBU_TYPE   Vobu;
typedef VOBI_TYPE   Vobi;

typedef VOHU_TYPE   Vohu;
typedef VOHI_TYPE   Vohi;
typedef VOHF_TYPE   Vohf;

typedef VOWU_TYPE   Vowu;
typedef VOWI_TYPE   Vowi;
typedef VOWF_TYPE   Vowf;

typedef VODU_TYPE   Vodu;
typedef VODI_TYPE   Vodi;
typedef VODF_TYPE   Vodf;

typedef VOQU_TYPE   Voqu;
typedef VOQI_TYPE   Voqi;
typedef VOQF_TYPE   Voqf;


typedef VSBU_TYPE   Vsbu;
typedef VSBI_TYPE   Vsbi;

typedef VSHU_TYPE   Vshu;
typedef VSHI_TYPE   Vshi;
typedef VSHF_TYPE   Vshf;

typedef VSWU_TYPE   Vswu;
typedef VSWI_TYPE   Vswi;
typedef VSWF_TYPE   Vswf;

typedef VSDU_TYPE   Vsdu, vec512du_t;
typedef VSDI_TYPE   Vsdi, vec512di_t;
typedef VSDF_TYPE   Vsdf, vec512df_t;

typedef VSQU_TYPE   Vsqu, vec512qu_t;
typedef VSQI_TYPE   Vsqi, vec512qi_t;
typedef VSQF_TYPE   Vsqf, vec512qf_t;

#ifndef VDB_TYPE
#define VDB_TYPE    union Vdb
#endif

#ifndef VDH_TYPE
#define VDH_TYPE    union Vdh
#endif

#ifndef VDW_TYPE
#define VDW_TYPE    union Vdw
#endif

#ifndef VDD_TYPE
#define VDD_TYPE    union Vdd
#endif


#ifndef VQB_TYPE
#define VQB_TYPE    union Vqb
#endif

#ifndef VQH_TYPE
#define VQH_TYPE    union Vqh
#endif

#ifndef VQW_TYPE
#define VQW_TYPE    union Vqw
#endif

#ifndef VQD_TYPE
#define VQD_TYPE    union Vqd
#endif

#ifndef VQQ_TYPE
#define VQQ_TYPE    union Vqq
#endif


#ifndef VOB_TYPE
#define VOB_TYPE    union Vob
#endif

#ifndef VOH_TYPE
#define VOH_TYPE    union Voh
#endif

#ifndef VOW_TYPE
#define VOW_TYPE    union Vow
#endif

#ifndef VOD_TYPE
#define VOD_TYPE    union Vod
#endif

#ifndef VOQ_TYPE
#define VOQ_TYPE    union Voq
#endif


#ifndef VSB_TYPE
#define VSB_TYPE    union Vsb
#endif

#ifndef VSH_TYPE
#define VSH_TYPE    union Vsh
#endif

#ifndef VSW_TYPE
#define VSW_TYPE    union Vsw
#endif

#ifndef VSD_TYPE
#define VSD_TYPE    union Vsd
#endif

#ifndef VSQ_TYPE
#define VSQ_TYPE    union Vsq
#endif

union Vdb {
    struct {char            MY_NV8(C,  );};
    struct {BYTE_TYPE       MY_NV8(K,  );};
    struct {BYTE_U(TYPE)    MY_NV8(U,  );};
    struct {BYTE_I(TYPE)    MY_NV8(I,  );};
    VDBU_TYPE U; 
    VDBI_TYPE I;
};

union Vdh {
    struct {char            MY_NV8(C,  );};
    struct {HALF_TYPE       MY_NV4(K,  );};
    struct {HALF_U(TYPE)    MY_NV4(U,  );};
    struct {HALF_I(TYPE)    MY_NV4(I,  );};
    struct {HALF_F(TYPE)    MY_NV4(F,  );};
    VDHU_TYPE   U;
    VDHI_TYPE   I;
    VDHF_TYPE   F;
};

union Vdw {
    struct {char            MY_NV8(C,  );};
    struct {WORD_TYPE       MY_NV2(K,  );};
    struct {WORD_U(TYPE)    MY_NV2(U,  );};
    struct {WORD_I(TYPE)    MY_NV2(I,  );};
    struct {WORD_F(TYPE)    MY_NV2(F,  );};
    VDWU_TYPE   U;
    VDWI_TYPE   I;
    VDWF_TYPE   F;
};

union Vdd {
    struct {char            MY_NV8(C,  );};
    struct {DWRD_TYPE       MY_NV1(K,  );};
    struct {DWRD_U(TYPE)    MY_NV1(U,  );};
    struct {DWRD_I(TYPE)    MY_NV1(I,  );};
    struct {DWRD_F(TYPE)    MY_NV1(F,  );};
    VDDU_TYPE   U;
    VDDI_TYPE   I;
    VDDF_TYPE   F;
};


union Vqb {
    struct {char            MY_NV16(C,  );};
    struct {BYTE_TYPE       MY_NV16(K,  );};
    struct {BYTE_U(TYPE)    MY_NV16(U,  );};
    struct {BYTE_I(TYPE)    MY_NV16(I,  );};
    struct {VDB_TYPE        MY_PAIR(Lo,Hi,); };
    VQBU_TYPE   U;
    VQBI_TYPE   I;
};

union Vqh {
    struct {char            MY_NV16(C,  );};
    struct {VDH_TYPE        MY_PAIR(Lo, Hi,  );     };
    struct {HALF_TYPE       MY_NV8(K,  );};
    struct {HALF_U(TYPE)    MY_NV8(U,  );};
    struct {HALF_I(TYPE)    MY_NV8(I,  );};
    struct {HALF_F(TYPE)    MY_NV8(F,  );};
    VQHU_TYPE   U;
    VQHI_TYPE   I;
    VQHF_TYPE   F;
};

union Vqw {
    struct {char            MY_NV16(C,  );};
    struct {VDW_TYPE        MY_PAIR(Lo, Hi,  );};
    struct {WORD_TYPE       MY_NV4(K,  );};
    struct {WORD_U(TYPE)    MY_NV4(U,  );};
    struct {WORD_I(TYPE)    MY_NV4(I,  );};
    struct {WORD_F(TYPE)    MY_NV4(F,  );};
    VQWU_TYPE   U;
    VQWI_TYPE   I;
    VQWF_TYPE   F;
};

union Vqd {
    struct {char            MY_NV16(C,  );};
    struct {VDD_TYPE        MY_PAIR(Lo, Hi,  );};
    struct {DWRD_TYPE       MY_NV2(K,  );};
    struct {DWRD_U(TYPE)    MY_NV2(U,  );};
    struct {DWRD_I(TYPE)    MY_NV2(I,  );};
    struct {DWRD_F(TYPE)    MY_NV2(F,  );};
    VQDU_TYPE   U;
    VQDI_TYPE   I;
    VQDF_TYPE   F;
};

union Vqq {
    struct {char            MY_NV16(C,  );};
    struct {QUAD_TYPE       MY_NV1(K,  );};
    struct {QUAD_U(TYPE)    MY_NV1(U,  );};
    struct {QUAD_I(TYPE)    MY_NV1(I,  );};
    struct {QUAD_F(TYPE)    MY_NV1(F,  );};
    VQQU_TYPE   U;
    VQQI_TYPE   I;
    VQQF_TYPE   F;
#   if defined(MQQ_TYPE)
    union {
#       if defined(MQQU_TYPE)
        MQQU_TYPE U;
#       endif

#       if defined(MQQI_TYPE)
        MQQI_TYPE I;
#       endif

#       if defined(MQQF_TYPE)
        MQQI_TYPE F;
#       endif

    } M;
#   endif
};


union Vob {
    struct {char            MY_NV32(C,  );};
    struct {BYTE_TYPE       MY_NV32(K,  );};
    struct {BYTE_U(TYPE)    MY_NV32(U,  );};
    struct {BYTE_I(TYPE)    MY_NV32(I,  );};
    struct {VQB_TYPE        MY_PAIR(Lo, Hi,  );      };
    VOBU_TYPE   U;
    VOBI_TYPE   I;
};

union Voh {
    struct {char            MY_NV32(C,  );};
    struct {VQH_TYPE        MY_PAIR(Lo, Hi,  );     };
    struct {HALF_TYPE       MY_NV16(K,  );};
    struct {HALF_U(TYPE)    MY_NV16(U,  );};
    struct {HALF_I(TYPE)    MY_NV16(I,  );};
    struct {HALF_F(TYPE)    MY_NV16(F,  );};
    VOHU_TYPE   U;
    VOHI_TYPE   I;
    VOHF_TYPE   F;
};

union Vow {
    struct {char            MY_NV32(C,  );};
    struct {VQW_TYPE        MY_PAIR(Lo, Hi,  );};
    struct {WORD_TYPE       MY_NV8(K,  );};
    struct {WORD_U(TYPE)    MY_NV8(U,  );};
    struct {WORD_I(TYPE)    MY_NV8(I,  );};
    struct {WORD_F(TYPE)    MY_NV8(F,  );};
    VOWU_TYPE   U;
    VOWI_TYPE   I;
    VOWF_TYPE   F;
#   if defined(VOWM_TYPE)
    VOWM_TYPE   M;
#   endif
};

union Vod {
    struct {char            MY_NV32(C,  );};
    struct {VQD_TYPE        MY_PAIR(Lo, Hi,  );};
    struct {DWRD_TYPE       MY_NV4(K,  );};
    struct {DWRD_U(TYPE)    MY_NV4(U,  );};
    struct {DWRD_I(TYPE)    MY_NV4(I,  );};
    struct {DWRD_F(TYPE)    MY_NV4(F,  );};
    VODU_TYPE   U;
    VODI_TYPE   I;
    VODF_TYPE   F;
};

union Voq {
    struct {char            MY_NV32(C,  );};
    struct {VQQ_TYPE        MY_PAIR(Lo, Hi,  );};
    struct {QUAD_TYPE       MY_NV2(K,  );};
    struct {QUAD_U(TYPE)    MY_NV2(U,  );};
    struct {QUAD_I(TYPE)    MY_NV2(I,  );};
    struct {QUAD_F(TYPE)    MY_NV2(F,  );};
    VOQU_TYPE   U;
    VOQI_TYPE   I;
    VOQF_TYPE   F;
};


union Vsb {
    struct {char            MY_NV64(C,  );};
    struct {BYTE_TYPE       MY_NV64(K,  );};
    struct {BYTE_U(TYPE)    MY_NV64(U,  );};
    struct {BYTE_I(TYPE)    MY_NV64(I,  );};
    struct {VOB_TYPE        MY_PAIR(Lo, Hi,  );      };
    VSBU_TYPE   U;
    VSBI_TYPE   I;
};

union Vsh {
    struct {char            MY_NV64(C,  );};
    struct {HALF_TYPE       MY_NV32(K,  );};
    struct {HALF_U(TYPE)    MY_NV32(U,  );};
    struct {HALF_I(TYPE)    MY_NV32(I,  );};
    struct {HALF_F(TYPE)    MY_NV32(F,  );};
    struct {VOH_TYPE        MY_PAIR(Lo, Hi,  );     };
    VSHU_TYPE   U;
    VSHI_TYPE   I;
    VSHF_TYPE   F;
};

union Vsw {
    struct {char            MY_NV64(C,  );};
    struct {WORD_TYPE       MY_NV16(K,  );};
    struct {WORD_U(TYPE)    MY_NV16(U,  );};
    struct {WORD_I(TYPE)    MY_NV16(I,  );};
    struct {WORD_F(TYPE)    MY_NV16(F,  );};
    struct {VOW_TYPE        MY_PAIR(Lo, Hi,  );};
    VSWU_TYPE   U;
    VSWI_TYPE   I;
    VSWF_TYPE   F;
};

union Vsd {
    struct {char            MY_NV64(C,  );};
    struct {VOD_TYPE        MY_PAIR(Lo, Hi,  );};
    struct {DWRD_TYPE       MY_NV8(K,  );};
    struct {DWRD_U(TYPE)    MY_NV8(U,  );};
    struct {DWRD_I(TYPE)    MY_NV8(I,  );};
    struct {DWRD_F(TYPE)    MY_NV8(F,  );};
    VSDU_TYPE   U;
    VSDI_TYPE   I;
    VSDF_TYPE   F;
};

union Vsq {
    struct {char            MY_NV64(C,  );};
    struct {VOQ_TYPE        MY_PAIR(Lo, Hi,  );};
    struct {QUAD_TYPE       MY_NV4(K,  );};
    struct {QUAD_U(TYPE)    MY_NV4(U,  );};
    struct {QUAD_I(TYPE)    MY_NV4(I,  );};
    struct {QUAD_F(TYPE)    MY_NV4(F,  );};
    VSQU_TYPE   U;
    VSQI_TYPE   I;
    VSQF_TYPE   F;
};


typedef VDB_TYPE Vdb;
typedef VDH_TYPE Vdh;
typedef VDW_TYPE Vdw;
typedef VDD_TYPE Vdd;

typedef VQB_TYPE Vqb;
typedef VQH_TYPE Vqh;
typedef VQW_TYPE Vqw;
typedef VQD_TYPE Vqd;
typedef VQQ_TYPE Vqq;

typedef VOB_TYPE Vob;
typedef VOH_TYPE Voh;
typedef VOW_TYPE Vow;
typedef VOD_TYPE Vod;
typedef VOQ_TYPE Voq;

typedef VSB_TYPE Vsb;
typedef VSH_TYPE Vsh;
typedef VSW_TYPE Vsw;
typedef VSD_TYPE Vsd;
typedef VSQ_TYPE Vsq;

#ifndef     DWRD_VTYPE
#define     DWRD_VTYPE  union Vd
#endif

#ifndef     QUAD_VTYPE
#define     QUAD_VTYPE  union Vq
#endif

#ifndef     OCTA_VTYPE
#define     OCTA_VTYPE  union Vo
#endif

#ifndef     SEXD_VTYPE
#define     SEXD_VTYPE  union Vs
#endif

union Vd {
    Vdb B; 
    Vdh H; 
    Vdw W; 
    Vdd D;
};

typedef DWRD_VTYPE      Vd, vec64_t;

union Vq {
    Vqb     B; 
    Vqh     H; 
    Vqw     W; 
    Vqd     D; 
    Vqq     Q;
    struct {Vd  MY_PAIR(Lo, Hi,  );};
};
typedef QUAD_VTYPE      Vq, vec128_t;

union Vo {
    Vob     B; 
    Voh     H;
    Vow     W; 
    Vod     D; 
    Voq     Q;
    struct {Vq  MY_PAIR(Lo, Hi,  );};
};
typedef OCTA_VTYPE      Vo, vec256_t;

union Vs {
    Vsb     B;
    Vsh     H;
    Vsw     W;
    Vsd     D;
    Vsq     Q;
    struct {Vo  MY_PAIR(Lo, Hi,  );};
};
typedef SEXD_VTYPE      Vs, vec512_t;

typedef union Vector {
    Vd  D;
    Vq  Q;
    Vo  O;
    Vs  S;
    union {
        union {
            union {Bu U[1]; Bi I[1]; Bc C[1];  } B;
        } B;
        union {
            union {Bu U[ 2]; Bi I[ 2]; Bc C[ 2];  } B;
            union {Hu U[ 1]; Hi I[ 1]; Hf F[ 1];  } H;
        } H;
        union {
            union { Bu U[ 4]; Bi I[ 4]; Bc C[ 4]; } B;
            union { Hu U[ 2]; Hi I[ 2]; Hf F[ 1]; } H;
            union { Wu U[ 1]; Wi I[ 1]; Wf F[ 1]; } W;
        } W;
        union {
            union { Bu U[ 4]; Bi I[ 4]; Bc C[ 4]; } B;
            union { Hu U[ 2]; Hi I[ 2]; Hf F[ 2]; } H;
            union { Wu U[ 2]; Wi I[ 2]; Wf F[ 2]; } W;
            union { Du U[ 1]; Di I[ 1]; Df F[ 1]; } D;
        } D;
        union {
            union { Bu U[16]; Bi I[16]; Bc C[16]; } B;
            union { Hu U[ 8]; Hi I[ 8]; Hf F[ 8]; } H;
            union { Wu U[ 4]; Wi I[ 4]; Wf F[ 4]; } W;
            union { Du U[ 2]; Di I[ 2]; Df F[ 2]; } D;
            union { Qu U[ 1]; Qi I[ 1]; Qf F[ 1]; } Q;
        } Q;
        union {
            union { Bu U[32]; Bi I[32]; Bc C[32]; } B;
            union { Hu U[16]; Hi I[16]; Hf F[16]; } H;
            union { Wu U[ 8]; Wi I[ 8]; Wf F[ 8]; } W;
            union { Du U[ 4]; Di I[ 4]; Df F[ 4]; } D;
            union { Qu U[ 2]; Qi I[ 2]; Qf F[ 2]; } Q;
        } O;
        union {
            union { Bu U[64]; Bi I[64]; Bc C[64]; } B;
            union { Hu U[32]; Hi I[32]; Hf F[32]; } H;
            union { Wu U[16]; Wi I[16]; Wf F[16]; } W;
            union { Du U[ 8]; Di I[ 8]; Df F[ 8]; } D;
            union { Qu U[ 4]; Qi I[ 4]; Qf F[ 4]; } Q;
        } S;
    } A;
} Vector;


#define     TGD_BI(_)   Vdbi: VDBI_SN(_),
#define     TGD_BU(_)   Vdbu: VDBU_SN(_),
#define     TGD_BF(_)   

#define     TGD_HI(_)   Vdhi: VDHI_SN(_),
#define     TGD_HU(_)   Vdhu: VDHU_SN(_),
#if 1
#   define  TGD_HF(_)   
#else
#   define  TGD_HF(_)   Vdhf: VDHF_SN(_),
#endif

#define     TGD_WI(_)   Vdwi: VDWI_SN(_),
#define     TGD_WU(_)   Vdwu: VDWU_SN(_),
#define     TGD_WF(_)   Vdwf: VDWF_SN(_),

#define     TGD_DI(_)   Vddi: VDDI_SN(_),
#define     TGD_DU(_)   Vddu: VDDU_SN(_),
#define     TGD_DF(_)   Vddf: VDDF_SN(_),

#define     TGD_BZ(_)               TGD_BU(_)   TGD_BI(_) 
#define     TGD_BS(_)   TGD_BF(_)               TGD_BI(_)
#define     TGD_BN(_)   TGD_BF(_)   TGD_BU(_)
#define     TGD_BR(_)   TGD_BF(_)   TGD_BU(_)   TGD_BI(_)

#define     TGD_HZ(_)               TGD_HU(_)   TGD_HI(_)
#define     TGD_HS(_)   TGD_HF(_)               TGD_HI(_)
#define     TGD_HN(_)   TGD_HF(_)   TGD_HU(_)
#define     TGD_HR(_)   TGD_HF(_)   TGD_HU(_)   TGD_HI(_)

#define     TGD_WZ(_)               TGD_WU(_)   TGD_WI(_)
#define     TGD_WS(_)   TGD_WF(_)               TGD_WI(_)
#define     TGD_WN(_)   TGD_WF(_)   TGD_WU(_)
#define     TGD_WR(_)   TGD_WF(_)   TGD_WU(_)   TGD_WI(_)

#define     TGD_DZ(_)               TGD_DU(_)   TGD_DI(_)
#define     TGD_DS(_)   TGD_DF(_)               TGD_DI(_)
#define     TGD_DN(_)   TGD_DF(_)   TGD_DU(_)
#define     TGD_DR(_)   TGD_DF(_)   TGD_DU(_)   TGD_DI(_)

#define     TGD_B_HI(_) TGD_BI(_) TGD_HI(_)
#define     TGD_H_WI(_)           TGD_HI(_) TGD_WI(_) 
#define     TGD_W_DI(_)                     TGD_WI(_) TGD_DI(_)
#define     TGD_D_QI(_)                               TGD_DI(_)          
#define     TGD_B_WI(_) TGD_BI(_) TGD_HI(_) TGD_WI(_) 
#define     TGD_H_DI(_)           TGD_HI(_) TGD_WI(_) TGD_DI(_) 
#define     TGD_W_QI(_)                     TGD_WI(_) TGD_DI(_)          
#define     TGD_B_DI(_) TGD_BI(_) TGD_HI(_) TGD_WI(_) TGD_DI(_)
#define     TGD_H_QI(_)           TGD_HI(_) TGD_WI(_) TGD_DI(_)          

#define     TGD_B_HU(_) TGD_BU(_) TGD_HU(_)
#define     TGD_H_WU(_)           TGD_HU(_) TGD_WU(_) 
#define     TGD_W_DU(_)                     TGD_WU(_) TGD_DU(_)
#define     TGD_D_QU(_)                               TGD_DU(_)          
#define     TGD_B_WU(_) TGD_BU(_) TGD_HU(_) TGD_WU(_) 
#define     TGD_H_DU(_)           TGD_HU(_) TGD_WU(_) TGD_DU(_) 
#define     TGD_W_QU(_)                     TGD_WU(_) TGD_DU(_)          
#define     TGD_B_DU(_) TGD_BU(_) TGD_HU(_) TGD_WU(_) TGD_DU(_)
#define     TGD_H_QU(_)           TGD_HU(_) TGD_WU(_) TGD_DU(_)          

#define     TGD_B_HF(_) TGD_BF(_) TGD_HF(_)
#define     TGD_H_WF(_)           TGD_HF(_) TGD_WF(_) 
#define     TGD_W_DF(_)                     TGD_WF(_) TGD_DF(_)
#define     TGD_D_QF(_)                               TGD_DF(_)          
#define     TGD_B_WF(_) TGD_BF(_) TGD_HF(_) TGD_WF(_) 
#define     TGD_H_DF(_)           TGD_HF(_) TGD_WF(_) TGD_DF(_) 
#define     TGD_W_QF(_)                     TGD_WF(_) TGD_DF(_)          
#define     TGD_B_DF(_) TGD_BF(_) TGD_HF(_) TGD_WF(_) TGD_DF(_)
#define     TGD_H_QF(_)           TGD_HF(_) TGD_WF(_) TGD_DF(_)

#define     TGD_B_HZ(_) TGD_BZ(_) TGD_HZ(_)
#define     TGD_H_WZ(_)           TGD_HZ(_) TGD_WZ(_) 
#define     TGD_W_DZ(_)                     TGD_WZ(_) TGD_DZ(_)
#define     TGD_D_QZ(_)                               TGD_DZ(_)
#define     TGD_B_WZ(_) TGD_BZ(_) TGD_HZ(_) TGD_WZ(_) 
#define     TGD_H_DZ(_)           TGD_HZ(_) TGD_WZ(_) TGD_DZ(_) 
#define     TGD_W_QZ(_)                     TGD_WZ(_) TGD_DZ(_)          
#define     TGD_B_DZ(_) TGD_BZ(_) TGD_HZ(_) TGD_WZ(_) TGD_DZ(_)
#define     TGD_H_QZ(_)           TGD_HZ(_) TGD_WZ(_) TGD_DZ(_)          

#define     TGD_B_HS(_) TGD_BS(_) TGD_HS(_)
#define     TGD_H_WS(_)           TGD_HS(_) TGD_WS(_) 
#define     TGD_W_DS(_)                     TGD_WS(_) TGD_DS(_)
#define     TGD_D_QS(_)                               TGD_DS(_)          
#define     TGD_B_WS(_) TGD_BS(_) TGD_HS(_) TGD_WS(_) 
#define     TGD_H_DS(_)           TGD_HS(_) TGD_WS(_) TGD_DS(_) 
#define     TGD_W_QS(_)                     TGD_WS(_) TGD_DS(_)          
#define     TGD_B_DS(_) TGD_BS(_) TGD_HS(_) TGD_WS(_) TGD_DS(_)
#define     TGD_H_QS(_)           TGD_HS(_) TGD_WS(_) TGD_DS(_)          

#define     TGD_B_HN(_) TGD_BN(_) TGD_HN(_)
#define     TGD_H_WN(_)           TGD_HN(_) TGD_WN(_) 
#define     TGD_W_DN(_)                     TGD_WN(_) TGD_DN(_)
#define     TGD_D_QN(_)                               TGD_DN(_)          
#define     TGD_B_WN(_) TGD_BN(_) TGD_HN(_) TGD_WN(_) 
#define     TGD_H_DN(_)           TGD_HN(_) TGD_WN(_) TGD_DN(_) 
#define     TGD_W_QN(_)                     TGD_WN(_) TGD_DN(_)          
#define     TGD_B_DN(_) TGD_BN(_) TGD_HN(_) TGD_WN(_) TGD_DN(_)
#define     TGD_H_QN(_)           TGD_HN(_) TGD_WN(_) TGD_DN(_)          

#define     TGD_B_HR(_) TGD_BR(_) TGD_HR(_)
#define     TGD_H_WR(_)           TGD_HR(_) TGD_WR(_) 
#define     TGD_W_DR(_)                     TGD_WR(_) TGD_DR(_)
#define     TGD_D_QR(_)                               TGD_DR(_)          
#define     TGD_B_WR(_) TGD_BR(_) TGD_HR(_) TGD_WR(_) 
#define     TGD_H_DR(_)           TGD_HR(_) TGD_WR(_) TGD_DR(_) 
#define     TGD_W_QR(_)                     TGD_WR(_) TGD_DR(_)          
#define     TGD_B_DR(_) TGD_BR(_) TGD_HR(_) TGD_WR(_) TGD_DR(_)
#define     TGD_H_QR(_)           TGD_HR(_) TGD_WR(_) TGD_DR(_)          


#define     TGQ_BI(_)   Vqbi: VQBI_SN(_),
#define     TGQ_BU(_)   Vqbu: VQBU_SN(_),
#define     TGQ_BF(_) 

#define     TGQ_HI(_)   Vqhi: VQHI_SN(_),
#define     TGQ_HU(_)   Vqhu: VQHU_SN(_),
#if 1
#   define  TGQ_HF(_)
#else
#   define  TGQ_HF(_)   Vqhf: VQHF_SN(_),
#endif

#define     TGQ_WI(_)   Vqwi: VQWI_SN(_),
#define     TGQ_WU(_)   Vqwu: VQWU_SN(_),
#define     TGQ_WF(_)   Vqwf: VQWF_SN(_),

#define     TGQ_DI(_)   Vqdi: VQDI_SN(_),
#define     TGQ_DU(_)   Vqdu: VQDU_SN(_),
#define     TGQ_DF(_)   Vqdf: VQDF_SN(_),

#define     TGQ_QI(_)   Vqqi: VQQI_SN(_),
#define     TGQ_QU(_)   Vqqu: VQQU_SN(_),
#define     TGQ_QF(_)   Vqqf: VQQF_SN(_),

#define     TGQ_BZ(_)               TGQ_BU(_)   TGQ_BI(_) 
#define     TGQ_BS(_)   TGQ_BF(_)               TGQ_BI(_)
#define     TGQ_BN(_)   TGQ_BF(_)   TGQ_BU(_)
#define     TGQ_BR(_)   TGQ_BF(_)   TGQ_BU(_)   TGQ_BI(_)

#define     TGQ_HZ(_)               TGQ_HU(_)   TGQ_HI(_)
#define     TGQ_HS(_)   TGQ_HF(_)               TGQ_HI(_)
#define     TGQ_HN(_)   TGQ_HF(_)   TGQ_HU(_)
#define     TGQ_HR(_)   TGQ_HF(_)   TGQ_HU(_)   TGQ_HI(_)

#define     TGQ_WZ(_)               TGQ_WU(_)   TGQ_WI(_)
#define     TGQ_WS(_)   TGQ_WF(_)               TGQ_WI(_)
#define     TGQ_WN(_)   TGQ_WF(_)   TGQ_WU(_)
#define     TGQ_WR(_)   TGQ_WF(_)   TGQ_WU(_)   TGQ_WI(_)

#define     TGQ_DZ(_)               TGQ_DU(_)   TGQ_DI(_)
#define     TGQ_DS(_)   TGQ_DF(_)               TGQ_DI(_)
#define     TGQ_DN(_)   TGQ_DF(_)   TGQ_DU(_)
#define     TGQ_DR(_)   TGQ_DF(_)   TGQ_DU(_)   TGQ_DI(_)

#define     TGQ_QZ(_)               TGQ_QU(_)   TGQ_QI(_)
#define     TGQ_QS(_)   TGQ_QF(_)               TGQ_QI(_)
#define     TGQ_QN(_)   TGQ_QF(_)   TGQ_QU(_)
#define     TGQ_QR(_)   TGQ_QF(_)   TGQ_QU(_)   TGQ_QI(_)

#define     TGQ_B_HI(_) TGQ_BI(_) TGQ_HI(_)
#define     TGQ_H_WI(_)           TGQ_HI(_) TGQ_WI(_) 
#define     TGQ_W_DI(_)                     TGQ_WI(_) TGQ_DI(_)
#define     TGQ_D_QI(_)                               TGQ_DI(_) TGQ_QI(_)
#define     TGQ_B_WI(_) TGQ_BI(_) TGQ_HI(_) TGQ_WI(_) 
#define     TGQ_H_DI(_)           TGQ_HI(_) TGQ_WI(_) TGQ_DI(_) 
#define     TGQ_W_QI(_)                     TGQ_WI(_) TGQ_DI(_) TGQ_QI(_)
#define     TGQ_B_DI(_) TGQ_BI(_) TGQ_HI(_) TGQ_WI(_) TGQ_DI(_)
#define     TGQ_H_QI(_)           TGQ_HI(_) TGQ_WI(_) TGQ_DI(_) TGQ_QI(_)
#define     TGQ_B_QI(_) TGQ_BI(_) TGQ_HI(_) TGQ_WI(_) TGQ_DI(_) TGQ_QI(_)

#define     TGQ_B_HU(_) TGQ_BU(_) TGQ_HU(_)
#define     TGQ_H_WU(_)           TGQ_HU(_) TGQ_WU(_) 
#define     TGQ_W_DU(_)                     TGQ_WU(_) TGQ_DU(_)
#define     TGQ_D_QU(_)                               TGQ_DU(_) TGQ_QU(_)
#define     TGQ_B_WU(_) TGQ_BU(_) TGQ_HU(_) TGQ_WU(_) 
#define     TGQ_H_DU(_)           TGQ_HU(_) TGQ_WU(_) TGQ_DU(_) 
#define     TGQ_W_QU(_)                     TGQ_WU(_) TGQ_DU(_) TGQ_QU(_)
#define     TGQ_B_DU(_) TGQ_BU(_) TGQ_HU(_) TGQ_WU(_) TGQ_DU(_)
#define     TGQ_H_QU(_)           TGQ_HU(_) TGQ_WU(_) TGQ_DU(_) TGQ_QU(_)
#define     TGQ_B_QU(_) TGQ_BU(_) TGQ_HU(_) TGQ_WU(_) TGQ_DU(_) TGQ_QU(_)


#define     TGQ_B_HF(_) TGQ_BF(_) TGQ_HF(_)
#define     TGQ_H_WF(_)           TGQ_HF(_) TGQ_WF(_) 
#define     TGQ_W_DF(_)                     TGQ_WF(_) TGQ_DF(_)
#define     TGQ_D_QF(_)                               TGQ_DF(_) TGQ_QF(_)
#define     TGQ_B_WF(_) TGQ_BF(_) TGQ_HF(_) TGQ_WF(_) 
#define     TGQ_H_DF(_)           TGQ_HF(_) TGQ_WF(_) TGQ_DF(_) 
#define     TGQ_W_QF(_)                     TGQ_WF(_) TGQ_DF(_) TGQ_QF(_)
#define     TGQ_B_DF(_) TGQ_BF(_) TGQ_HF(_) TGQ_WF(_) TGQ_DF(_)
#define     TGQ_H_QF(_)           TGQ_HF(_) TGQ_WF(_) TGQ_DF(_) TGQ_QF(_)
#define     TGQ_B_QF(_) TGQ_BF(_) TGQ_HF(_) TGQ_WF(_) TGQ_DF(_) TGQ_QF(_)

#define     TGQ_B_HZ(_) TGQ_BZ(_) TGQ_HZ(_)
#define     TGQ_H_WZ(_)           TGQ_HZ(_) TGQ_WZ(_) 
#define     TGQ_W_DZ(_)                     TGQ_WZ(_) TGQ_DZ(_)
#define     TGQ_D_QZ(_)                               TGQ_DZ(_) TGQ_QZ(_)
#define     TGQ_B_WZ(_) TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_) 
#define     TGQ_H_DZ(_)           TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_) 
#define     TGQ_W_QZ(_)                     TGQ_WZ(_) TGQ_DZ(_) TGQ_QZ(_)
#define     TGQ_B_DZ(_) TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_)
#define     TGQ_H_QZ(_)           TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_) TGQ_QZ(_)
#define     TGQ_B_QZ(_) TGQ_BZ(_) TGQ_HZ(_) TGQ_WZ(_) TGQ_DZ(_) TGQ_QZ(_)

#define     TGQ_B_HS(_) TGQ_BS(_) TGQ_HS(_)
#define     TGQ_H_WS(_)           TGQ_HS(_) TGQ_WS(_) 
#define     TGQ_W_DS(_)                     TGQ_WS(_) TGQ_DS(_)
#define     TGQ_D_QS(_)                               TGQ_DS(_) TGQ_QS(_)
#define     TGQ_B_WS(_) TGQ_BS(_) TGQ_HS(_) TGQ_WS(_) 
#define     TGQ_H_DS(_)           TGQ_HS(_) TGQ_WS(_) TGQ_DS(_) 
#define     TGQ_W_QS(_)                     TGQ_WS(_) TGQ_DS(_) TGQ_QS(_)
#define     TGQ_B_DS(_) TGQ_BS(_) TGQ_HS(_) TGQ_WS(_) TGQ_DS(_)
#define     TGQ_H_QS(_)           TGQ_HS(_) TGQ_WS(_) TGQ_DS(_) TGQ_QS(_)
#define     TGQ_B_QS(_) TGQ_BS(_) TGQ_HS(_) TGQ_WS(_) TGQ_DS(_) TGQ_QS(_)

#define     TGQ_B_HN(_) TGQ_BN(_) TGQ_HN(_)
#define     TGQ_H_WN(_)           TGQ_HN(_) TGQ_WN(_) 
#define     TGQ_W_DN(_)                     TGQ_WN(_) TGQ_DN(_)
#define     TGQ_D_QN(_)                               TGQ_DN(_) TGQ_QN(_)
#define     TGQ_B_WN(_) TGQ_BN(_) TGQ_HN(_) TGQ_WN(_) 
#define     TGQ_H_DN(_)           TGQ_HN(_) TGQ_WN(_) TGQ_DN(_) 
#define     TGQ_W_QN(_)                     TGQ_WN(_) TGQ_DN(_) TGQ_QN(_)
#define     TGQ_B_DN(_) TGQ_BN(_) TGQ_HN(_) TGQ_WN(_) TGQ_DN(_)
#define     TGQ_H_QN(_)           TGQ_HN(_) TGQ_WN(_) TGQ_DN(_) TGQ_QN(_)
#define     TGQ_B_QN(_) TGQ_BN(_) TGQ_HN(_) TGQ_WN(_) TGQ_DN(_) TGQ_QN(_)

#define     TGQ_B_HR(_) TGQ_BR(_) TGQ_HR(_)
#define     TGQ_H_WR(_)           TGQ_HR(_) TGQ_WR(_) 
#define     TGQ_W_DR(_)                     TGQ_WR(_) TGQ_DR(_)
#define     TGQ_D_QR(_)                               TGQ_DR(_) TGQ_QR(_)
#define     TGQ_B_WR(_) TGQ_BR(_) TGQ_HR(_) TGQ_WR(_) 
#define     TGQ_H_DR(_)           TGQ_HR(_) TGQ_WR(_) TGQ_DR(_) 
#define     TGQ_W_QR(_)                     TGQ_WR(_) TGQ_DR(_) TGQ_QR(_)
#define     TGQ_B_DR(_) TGQ_BR(_) TGQ_HR(_) TGQ_WR(_) TGQ_DR(_)
#define     TGQ_H_QR(_)           TGQ_HR(_) TGQ_WR(_) TGQ_DR(_) TGQ_QR(_)
#define     TGQ_B_QR(_) TGQ_BR(_) TGQ_HR(_) TGQ_WR(_) TGQ_DR(_) TGQ_QR(_)

#define     TGO_BI(_)   Vobi: VOBI_SN(_),
#define     TGO_BU(_)   Vobu: VOBU_SN(_),
#define     TGO_BF(_)

#define     TGO_HI(_)   Vohi: VOHI_SN(_),
#define     TGO_HU(_)   Vohu: VOHU_SN(_),
#if 1
#   define  TGO_HF(_)
#else
#   define  TGO_HF(_)   Vohf: VOHF_SN(_),
#endif

#define     TGO_WI(_)   Vowi: VOWI_SN(_),
#define     TGO_WU(_)   Vowu: VOWU_SN(_),
#define     TGO_WF(_)   Vowf: VOWF_SN(_),

#define     TGO_DI(_)   Vodi: VODI_SN(_),
#define     TGO_DU(_)   Vodu: VODU_SN(_),
#define     TGO_DF(_)   Vodf: VODF_SN(_),

#define     TGO_QI(_)   Voqi: VOQI_SN(_),
#define     TGO_QU(_)   Voqu: VOQU_SN(_),
#define     TGO_QF(_)   Voqf: VOQF_SN(_),

#define     TGO_BZ(_)               TGO_BU(_)   TGO_BI(_) 
#define     TGO_BS(_)   TGO_BF(_)               TGO_BI(_)
#define     TGO_BN(_)   TGO_BF(_)   TGO_BU(_)
#define     TGO_BR(_)   TGO_BF(_)   TGO_BU(_)   TGO_BI(_)

#define     TGO_HZ(_)               TGO_HU(_)   TGO_HI(_)
#define     TGO_HS(_)   TGO_HF(_)               TGO_HI(_)
#define     TGO_HN(_)   TGO_HF(_)   TGO_HU(_)
#define     TGO_HR(_)   TGO_HF(_)   TGO_HU(_)   TGO_HI(_)

#define     TGO_WZ(_)               TGO_WU(_)   TGO_WI(_)
#define     TGO_WS(_)   TGO_WF(_)               TGO_WI(_)
#define     TGO_WN(_)   TGO_WF(_)   TGO_WU(_)
#define     TGO_WR(_)   TGO_WF(_)   TGO_WU(_)   TGO_WI(_)

#define     TGO_DZ(_)               TGO_DU(_)   TGO_DI(_)
#define     TGO_DS(_)   TGO_DF(_)               TGO_DI(_)
#define     TGO_DN(_)   TGO_DF(_)   TGO_DU(_)
#define     TGO_DR(_)   TGO_DF(_)   TGO_DU(_)   TGO_DI(_)

#define     TGO_QZ(_)               TGO_QU(_)   TGO_QI(_)
#define     TGO_QS(_)   TGO_QF(_)               TGO_QI(_)
#define     TGO_QN(_)   TGO_QF(_)   TGO_QU(_)
#define     TGO_QR(_)   TGO_QF(_)   TGO_QU(_)   TGO_QI(_)

#define     TGO_B_HI(_) TGO_BI(_) TGO_HI(_)
#define     TGO_H_WI(_)           TGO_HI(_) TGO_WI(_) 
#define     TGO_W_DI(_)                     TGO_WI(_) TGO_DI(_)
#define     TGO_D_QI(_)                               TGO_DI(_) TGO_QI(_)
#define     TGO_B_WI(_) TGO_BI(_) TGO_HI(_) TGO_WI(_) 
#define     TGO_H_DI(_)           TGO_HI(_) TGO_WI(_) TGO_DI(_) 
#define     TGO_W_QI(_)                     TGO_WI(_) TGO_DI(_) TGO_QI(_)
#define     TGO_B_DI(_) TGO_BI(_) TGO_HI(_) TGO_WI(_) TGO_DI(_)
#define     TGO_H_QI(_)           TGO_HI(_) TGO_WI(_) TGO_DI(_) TGO_QI(_)
#define     TGO_B_QI(_) TGO_BI(_) TGO_HI(_) TGO_WI(_) TGO_DI(_) TGO_QI(_)

#define     TGO_B_HU(_) TGO_BU(_) TGO_HU(_)
#define     TGO_H_WU(_)           TGO_HU(_) TGO_WU(_) 
#define     TGO_W_DU(_)                     TGO_WU(_) TGO_DU(_)
#define     TGO_D_QU(_)                               TGO_DU(_) TGO_QU(_)
#define     TGO_B_WU(_) TGO_BU(_) TGO_HU(_) TGO_WU(_) 
#define     TGO_H_DU(_)           TGO_HU(_) TGO_WU(_) TGO_DU(_) 
#define     TGO_W_QU(_)                     TGO_WU(_) TGO_DU(_) TGO_QU(_)
#define     TGO_B_DU(_) TGO_BU(_) TGO_HU(_) TGO_WU(_) TGO_DU(_)
#define     TGO_H_QU(_)           TGO_HU(_) TGO_WU(_) TGO_DU(_) TGO_QU(_)
#define     TGO_B_QU(_) TGO_BU(_) TGO_HU(_) TGO_WU(_) TGO_DU(_) TGO_QU(_)

#define     TGO_B_HF(_) TGO_BF(_) TGO_HF(_)
#define     TGO_H_WF(_)           TGO_HF(_) TGO_WF(_) 
#define     TGO_W_DF(_)                     TGO_WF(_) TGO_DF(_)
#define     TGO_D_QF(_)                               TGO_DF(_) TGO_QF(_)
#define     TGO_B_WF(_) TGO_BF(_) TGO_HF(_) TGO_WF(_) 
#define     TGO_H_DF(_)           TGO_HF(_) TGO_WF(_) TGO_DF(_) 
#define     TGO_W_QF(_)                     TGO_WF(_) TGO_DF(_) TGO_QF(_)
#define     TGO_B_DF(_) TGO_BF(_) TGO_HF(_) TGO_WF(_) TGO_DF(_)
#define     TGO_H_QF(_)           TGO_HF(_) TGO_WF(_) TGO_DF(_) TGO_QF(_)
#define     TGO_B_QF(_) TGO_BF(_) TGO_HF(_) TGO_WF(_) TGO_DF(_) TGO_QF(_)

#define     TGO_B_HZ(_) TGO_BZ(_) TGO_HZ(_)
#define     TGO_H_WZ(_)           TGO_HZ(_) TGO_WZ(_) 
#define     TGO_W_DZ(_)                     TGO_WZ(_) TGO_DZ(_)
#define     TGO_D_QZ(_)                               TGO_DZ(_) TGO_QZ(_)
#define     TGO_B_WZ(_) TGO_BZ(_) TGO_HZ(_) TGO_WZ(_) 
#define     TGO_H_DZ(_)           TGO_HZ(_) TGO_WZ(_) TGO_DZ(_) 
#define     TGO_W_QZ(_)                     TGO_WZ(_) TGO_DZ(_) TGO_QZ(_)
#define     TGO_B_DZ(_) TGO_BZ(_) TGO_HZ(_) TGO_WZ(_) TGO_DZ(_)
#define     TGO_H_QZ(_)           TGO_HZ(_) TGO_WZ(_) TGO_DZ(_) TGO_QZ(_)
#define     TGO_B_QZ(_) TGO_BZ(_) TGO_HZ(_) TGO_WZ(_) TGO_DZ(_) TGO_QZ(_)

#define     TGO_B_HS(_) TGO_BS(_) TGO_HS(_)
#define     TGO_H_WS(_)           TGO_HS(_) TGO_WS(_) 
#define     TGO_W_DS(_)                     TGO_WS(_) TGO_DS(_)
#define     TGO_D_QS(_)                               TGO_DS(_) TGO_QS(_)
#define     TGO_B_WS(_) TGO_BS(_) TGO_HS(_) TGO_WS(_) 
#define     TGO_H_DS(_)           TGO_HS(_) TGO_WS(_) TGO_DS(_) 
#define     TGO_W_QS(_)                     TGO_WS(_) TGO_DS(_) TGO_QS(_)
#define     TGO_B_DS(_) TGO_BS(_) TGO_HS(_) TGO_WS(_) TGO_DS(_)
#define     TGO_H_QS(_)           TGO_HS(_) TGO_WS(_) TGO_DS(_) TGO_QS(_)
#define     TGO_B_QS(_) TGO_BS(_) TGO_HS(_) TGO_WS(_) TGO_DS(_) TGO_QS(_)

#define     TGO_B_HN(_) TGO_BN(_) TGO_HN(_)
#define     TGO_H_WN(_)           TGO_HN(_) TGO_WN(_) 
#define     TGO_W_DN(_)                     TGO_WN(_) TGO_DN(_)
#define     TGO_D_QN(_)                               TGO_DN(_) TGO_QN(_)
#define     TGO_B_WN(_) TGO_BN(_) TGO_HN(_) TGO_WN(_) 
#define     TGO_H_DN(_)           TGO_HN(_) TGO_WN(_) TGO_DN(_) 
#define     TGO_W_QN(_)                     TGO_WN(_) TGO_DN(_) TGO_QN(_)
#define     TGO_B_DN(_) TGO_BN(_) TGO_HN(_) TGO_WN(_) TGO_DN(_)
#define     TGO_H_QN(_)           TGO_HN(_) TGO_WN(_) TGO_DN(_) TGO_QN(_)
#define     TGO_B_QN(_) TGO_BN(_) TGO_HN(_) TGO_WN(_) TGO_DN(_) TGO_QN(_)

#define     TGO_B_HR(_) TGO_BR(_) TGO_HR(_)
#define     TGO_H_WR(_)           TGO_HR(_) TGO_WR(_) 
#define     TGO_W_DR(_)                     TGO_WR(_) TGO_DR(_)
#define     TGO_D_QR(_)                               TGO_DR(_) TGO_QR(_)
#define     TGO_B_WR(_) TGO_BR(_) TGO_HR(_) TGO_WR(_) 
#define     TGO_H_DR(_)           TGO_HR(_) TGO_WR(_) TGO_DR(_) 
#define     TGO_W_QR(_)                     TGO_WR(_) TGO_DR(_) TGO_QR(_)
#define     TGO_B_DR(_) TGO_BR(_) TGO_HR(_) TGO_WR(_) TGO_DR(_)
#define     TGO_H_QR(_)           TGO_HR(_) TGO_WR(_) TGO_DR(_) TGO_QR(_)
#define     TGO_B_QR(_) TGO_BR(_) TGO_HR(_) TGO_WR(_) TGO_DR(_) TGO_QR(_)


#define     TGS_BI(_)   Vsbi: VSBI_SN(_),
#define     TGS_BU(_)   Vsbu: VSBU_SN(_),
#define     TGS_BF(_)

#define     TGS_HI(_)   Vshi: VSHI_SN(_),
#define     TGS_HU(_)   Vshu: VSHU_SN(_),

#if 1
#   define  TGS_HF(_)
#else
#   define  TGS_HF(_)   Vshf: VSHF_SN(_),
#endif

#define     TGS_WI(_)   Vswi: VSWI_SN(_),
#define     TGS_WU(_)   Vswu: VSWU_SN(_),
#define     TGS_WF(_)   Vswf: VSWF_SN(_),

#define     TGS_DI(_)   Vsdi: VSDI_SN(_),
#define     TGS_DU(_)   Vsdu: VSDU_SN(_),
#define     TGS_DF(_)   Vsdf: VSDF_SN(_),


#define     TGS_QI(_)   Vsqi: VSQI_SN(_),
#define     TGS_QU(_)   Vsqu: VSQU_SN(_),
#define     TGS_QF(_)   Vsqf: VSQF_SN(_),


#define     TGS_BZ(_)               TGS_BU(_)   TGS_BI(_) 
#define     TGS_BS(_)   TGS_BF(_)               TGS_BI(_)
#define     TGS_BN(_)   TGS_BF(_)   TGS_BU(_)
#define     TGS_BR(_)   TGS_BF(_)   TGS_BU(_)   TGS_BI(_)

#define     TGS_HZ(_)               TGS_HU(_)   TGS_HI(_)
#define     TGS_HS(_)   TGS_HF(_)               TGS_HI(_)
#define     TGS_HN(_)   TGS_HF(_)   TGS_HU(_)
#define     TGS_HR(_)   TGS_HF(_)   TGS_HU(_)   TGS_HI(_)

#define     TGS_WZ(_)               TGS_WU(_)   TGS_WI(_)
#define     TGS_WS(_)   TGS_WF(_)               TGS_WI(_)
#define     TGS_WN(_)   TGS_WF(_)   TGS_WU(_)
#define     TGS_WR(_)   TGS_WF(_)   TGS_WU(_)   TGS_WI(_)

#define     TGS_DZ(_)               TGS_DU(_)   TGS_DI(_)
#define     TGS_DS(_)   TGS_DF(_)               TGS_DI(_)
#define     TGS_DN(_)   TGS_DF(_)   TGS_DU(_)
#define     TGS_DR(_)   TGS_DF(_)   TGS_DU(_)   TGS_DI(_)

#define     TGS_QZ(_)               TGS_QU(_)   TGS_QI(_)
#define     TGS_QS(_)   TGS_QF(_)               TGS_QI(_)
#define     TGS_QN(_)   TGS_QF(_)   TGS_QU(_)
#define     TGS_QR(_)   TGS_QF(_)   TGS_QU(_)   TGS_QI(_)

#define     TGS_B_HI(_) TGS_BI(_) TGS_HI(_)
#define     TGS_H_WI(_)           TGS_HI(_) TGS_WI(_) 
#define     TGS_W_DI(_)                     TGS_WI(_) TGS_DI(_)
#define     TGS_D_QI(_)                               TGS_DI(_) TGS_QI(_)
#define     TGS_B_WI(_) TGS_BI(_) TGS_HI(_) TGS_WI(_) 
#define     TGS_H_DI(_)           TGS_HI(_) TGS_WI(_) TGS_DI(_) 
#define     TGS_W_QI(_)                     TGS_WI(_) TGS_DI(_) TGS_QI(_)
#define     TGS_B_DI(_) TGS_BI(_) TGS_HI(_) TGS_WI(_) TGS_DI(_)
#define     TGS_H_QI(_)           TGS_HI(_) TGS_WI(_) TGS_DI(_) TGS_QI(_)
#define     TGS_B_QI(_) TGS_BI(_) TGS_HI(_) TGS_WI(_) TGS_DI(_) TGS_QI(_)

#define     TGS_B_HU(_) TGS_BU(_) TGS_HU(_)
#define     TGS_H_WU(_)           TGS_HU(_) TGS_WU(_) 
#define     TGS_W_DU(_)                     TGS_WU(_) TGS_DU(_)
#define     TGS_D_QU(_)                               TGS_DU(_) TGS_QU(_)
#define     TGS_B_WU(_) TGS_BU(_) TGS_HU(_) TGS_WU(_) 
#define     TGS_H_DU(_)           TGS_HU(_) TGS_WU(_) TGS_DU(_) 
#define     TGS_W_QU(_)                     TGS_WU(_) TGS_DU(_) TGS_QU(_)
#define     TGS_B_DU(_) TGS_BU(_) TGS_HU(_) TGS_WU(_) TGS_DU(_)
#define     TGS_H_QU(_)           TGS_HU(_) TGS_WU(_) TGS_DU(_) TGS_QU(_)
#define     TGS_B_QU(_) TGS_BU(_) TGS_HU(_) TGS_WU(_) TGS_DU(_) TGS_QU(_)

#define     TGS_B_HF(_) TGS_BF(_) TGS_HF(_)
#define     TGS_H_WF(_)           TGS_HF(_) TGS_WF(_) 
#define     TGS_W_DF(_)                     TGS_WF(_) TGS_DF(_)
#define     TGS_D_QF(_)                               TGS_DF(_) TGS_QF(_)
#define     TGS_B_WF(_) TGS_BF(_) TGS_HF(_) TGS_WF(_) 
#define     TGS_H_DF(_)           TGS_HF(_) TGS_WF(_) TGS_DF(_) 
#define     TGS_W_QF(_)                     TGS_WF(_) TGS_DF(_) TGS_QF(_)
#define     TGS_B_DF(_) TGS_BF(_) TGS_HF(_) TGS_WF(_) TGS_DF(_)
#define     TGS_H_QF(_)           TGS_HF(_) TGS_WF(_) TGS_DF(_) TGS_QF(_)
#define     TGS_B_QF(_) TGS_BF(_) TGS_HF(_) TGS_WF(_) TGS_DF(_) TGS_QF(_)

#define     TGS_B_HZ(_) TGS_BZ(_) TGS_HZ(_)
#define     TGS_H_WZ(_)           TGS_HZ(_) TGS_WZ(_) 
#define     TGS_W_DZ(_)                     TGS_WZ(_) TGS_DZ(_)
#define     TGS_D_QZ(_)                               TGS_DZ(_) TGS_QZ(_)
#define     TGS_B_WZ(_) TGS_BZ(_) TGS_HZ(_) TGS_WZ(_) 
#define     TGS_H_DZ(_)           TGS_HZ(_) TGS_WZ(_) TGS_DZ(_) 
#define     TGS_W_QZ(_)                     TGS_WZ(_) TGS_DZ(_) TGS_QZ(_)
#define     TGS_B_DZ(_) TGS_BZ(_) TGS_HZ(_) TGS_WZ(_) TGS_DZ(_)
#define     TGS_H_QZ(_)           TGS_HZ(_) TGS_WZ(_) TGS_DZ(_) TGS_QZ(_)
#define     TGS_B_QZ(_) TGS_BZ(_) TGS_HZ(_) TGS_WZ(_) TGS_DZ(_) TGS_QZ(_)

#define     TGS_B_HS(_) TGS_BS(_) TGS_HS(_)
#define     TGS_H_WS(_)           TGS_HS(_) TGS_WS(_) 
#define     TGS_W_DS(_)                     TGS_WS(_) TGS_DS(_)
#define     TGS_D_QS(_)                               TGS_DS(_) TGS_QS(_)
#define     TGS_B_WS(_) TGS_BS(_) TGS_HS(_) TGS_WS(_) 
#define     TGS_H_DS(_)           TGS_HS(_) TGS_WS(_) TGS_DS(_) 
#define     TGS_W_QS(_)                     TGS_WS(_) TGS_DS(_) TGS_QS(_)
#define     TGS_B_DS(_) TGS_BS(_) TGS_HS(_) TGS_WS(_) TGS_DS(_)
#define     TGS_H_QS(_)           TGS_HS(_) TGS_WS(_) TGS_DS(_) TGS_QS(_)
#define     TGS_B_QS(_) TGS_BS(_) TGS_HS(_) TGS_WS(_) TGS_DS(_) TGS_QS(_)

#define     TGS_B_HN(_) TGS_BN(_) TGS_HN(_)
#define     TGS_H_WN(_)           TGS_HN(_) TGS_WN(_) 
#define     TGS_W_DN(_)                     TGS_WN(_) TGS_DN(_)
#define     TGS_D_QN(_)                               TGS_DN(_) TGS_QN(_)
#define     TGS_B_WN(_) TGS_BN(_) TGS_HN(_) TGS_WN(_) 
#define     TGS_H_DN(_)           TGS_HN(_) TGS_WN(_) TGS_DN(_) 
#define     TGS_W_QN(_)                     TGS_WN(_) TGS_DN(_) TGS_QN(_)
#define     TGS_B_DN(_) TGS_BN(_) TGS_HN(_) TGS_WN(_) TGS_DN(_)
#define     TGS_H_QN(_)           TGS_HN(_) TGS_WN(_) TGS_DN(_) TGS_QN(_)
#define     TGS_B_QN(_) TGS_BN(_) TGS_HN(_) TGS_WN(_) TGS_DN(_) TGS_QN(_)

#define     TGS_B_HR(_) TGS_BR(_) TGS_HR(_)
#define     TGS_H_WR(_)           TGS_HR(_) TGS_WR(_) 
#define     TGS_W_DR(_)                     TGS_WR(_) TGS_DR(_)
#define     TGS_D_QR(_)                               TGS_DR(_) TGS_QR(_)
#define     TGS_B_WR(_) TGS_BR(_) TGS_HR(_) TGS_WR(_) 
#define     TGS_H_DR(_)           TGS_HR(_) TGS_WR(_) TGS_DR(_) 
#define     TGS_W_QR(_)                     TGS_WR(_) TGS_DR(_) TGS_QR(_)
#define     TGS_B_DR(_) TGS_BR(_) TGS_HR(_) TGS_WR(_) TGS_DR(_)
#define     TGS_H_QR(_)           TGS_HR(_) TGS_WR(_) TGS_DR(_) TGS_QR(_)
#define     TGS_B_QR(_) TGS_BR(_) TGS_HR(_) TGS_WR(_) TGS_DR(_) TGS_QR(_)


#endif
