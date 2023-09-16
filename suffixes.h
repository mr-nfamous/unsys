/*
Affix guide

The 3-5 ASCII letter operation names are enough to describe
what it does, but isn't enough to identify the version that 
is specific to a particular type. 

Base types

u = unsigned int        {F, I, U} - {F, I}  = {U}
i = signed int          {F, I, U} - {F, U}  = {I}
f = float               {F, I, U} - {I, U}  = {F}
z = 'integer'           {F, I, U} - {F}     = {I, U}
s = 'signed'*           {F, I, U} - {U}     = {F, I}
n = 'natural'*          {F, I, U} - {I}     = {F, U}
r = 'real'              {F, I, U} - {}      = {F, U, I}
c = char
* s and n will almost always mean floats rounded towards zero


Base type size prefixes 

y = book    y×  1
b = Byte    y×  8  b× 1
h = Half    y× 16  b× 2  h× 1
w = Word    y× 32  b× 4  h× 2  w× 1
d = Dwrd    y× 64  b× 8  h× 4  w× 2  d×1
q = Quad    y×128  b×16  h× 8  w× 4  d×2  q×1
o = Octa    y×256  b×32  h×16  w× 8  d×4  q×2
s = Sexd    y×512  b×64  h×32  w×16  d×8  q×4
l = Long    (varies)

Note: as can be seen in the source code of <extnum.h>, our 
"long" type is whichever integer and/or float types have the 
same length as `intmax_t` or `fltmax_t` but isn't compatible
with either. E.g. if a target defines `long` as 32 bits, the
'lz' affix means "unsigned long or signed long". There's no
need to distinguish between `long` and `long long` in such 
cases because `long long` will be synonymous with `uint64_t`
and use the 'dz' affix.

Functions will almost always be defined for both `long` and
`long long`, but users are strongly discouraged from using 
native C types in new code.


The following table contains the full suffixes for the basic
numeric C types:
    
    bu = uint8_t
    bi = int8_t

    hu = uint16_t
    hi = int16_t
    hf*= _Float16

    wu = uint32_t
    wi = int32_t
    wf = float

    du = uint64_t
    di = int64_t
    df = double
    
    qu*= uint128_t
    qi*= int128_t
    qf*= _Float128

    * reserved but presently unimplemented 

Those one or two letter suffixes can be further modified by
prepending one of the following sequences:
    a       address of _
    aa      address of pointer to _
    aaa     address of pointer to pointer to _
    aaaa    address of ...
    x       split _
    ax      address of split _
    aax     address of pointer to split _

    d       64 bit vector of _
    kd      lane in 64 bit vector of _
    xd      32+32 bit vector of _
    kxd     lane in 32+32 bit of _

    q       128 bit vector of _
    kq      lane in 128 bit vector of _
    xq      64+64 bit vector of _
    kxq     lane in 64+64 bit vector of _

    o       256 bit vector of _
    ko      lane in 256 bit vector of _
    xo      128+128 bit vector of _
    kxo     lane in 128+128 bit vector of _

    s       512 bit vector of _
    ks      lane in 512 bit vector of _
    xs      256+256 bit vector of _
    kxs     lane in 256+256 bit vector of _

    E.g. 
    Vdhi mv1rkdhi(Vdhi a, int const b, Hi c);
    Vdhi mvvsdhi(Vdhi a, V)
    Wf * ld1raawf(Wf *volatile const a[1]);
    Vdhu sl
    
        ld1 = load atomic memory_order_relaxed
        r   = real number
        kdhu = 
    
or more sequences from the following table.
Note that not all  combinations are valid, and the order 
each entry appears in the table, from top to bottom, is the
same as order each affix must be arranged in from left to
right when used as a prefic. E.g. since "a" occurs before 
"x", the suffix for an operation on the address of a `Xqu`
is "axqu", not "xaqu". A "pointer to pointer" is identified
by simply stringing together multiple "a"s, as in the name
of the operation that atomically loads a "int64_t *" with 
`memory_order_relaxed` semantics, `ld1raadi`, which can be
broken down into the following components:

    "ld": load
    "1": atomically, with `memory_order_relaxed`
    "r": into a general purpose register
    "aadi": the value at "int64_t const *volatile[1]"

Base type qualifiers:

Since there's no such thing as a pointer to a vector,
Prefixed 
ab = (Byte[]){...}
abu = (uint8_t[]){...}

KB = 8 bit vector element
DB = 8×8 bit bit vector
KDBU 
DB[UIFZZSNR] = 64÷8 bit [UIFZSNR] = 8×B
QB[UIFZZSNR] = 128÷8 bit [UIFZSNR] = 16×B
*/
