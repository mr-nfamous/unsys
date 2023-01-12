/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

Pointer adjustment for stream buffers 

MEMSEEK(mem, len, pos, off, how)
    Adjust the "pointer" to the next element in an array {mem}
    of {len} elements located at {pos} according to the {how}
    and {off} parameters. 
    
    If {how == SEEK_SET}: {pos} is set to {off} unless it is
    negative, in which case {-EINVAL} is returned
    
    If how == SEEK_CUR: {off} is relative to {*pos}.

    If how == SEEK_END: {off} is relative to {len}
    
    If how == SEEK_DATA: {off} is the index, which must not
    be greater than {len} at which to begin a search for the
    next "data" segment (i.e. the next not nul element).
    
    If how == SEEK_HOLE: {off} is the index, which must not 
    be greater than {len} at which to begin a search for the
    next "hole" (i.e. the next nul)

    Returns a positive integer equivalent to {*pos} at the
    instant of return or a negative indicating an error 

*/

static inline ptrdiff_t
MEM_F(SEEK)
(
    const void*restrict mem, 
    size_t              len,
    ptrdiff_t *restrict pos, 
    ptrdiff_t           off, 
    int                 how
) 
{
    switch (how) {

        case SEEK_SET: { 
            return (off < 0) ? 0-(errno=EINVAL) : (*pos=off);
        }   // 0

        case SEEK_CUR: {
            return !off ? *pos : (*pos=((off+=*pos) < 0 ? 0 : off));
        }   // 1

        case SEEK_END: {
            return (*pos=((off+=len) < 0 ? 0 : off));
        }   // 2

        case SEEK_DATA: {
            if (off < 0) return 0-(errno=EINVAL);
            for (;off < len; off++) {
                if (UCA(mem)[off]) return (*pos=off);
            }
            return 0-(errno=ENOMEM);
        }

        case SEEK_HOLE: {
            if (off < 0) return 0-(errno=EINVAL);
            for (; off < len; off++) {
                if (!UCA(mem)[off]) return (*pos=off);
            }
            if (off == len) return (*pos=len);
            return 0-(errno=EINVAL);
        }

        default: unreachable();
    }
}

#if defined(TESTS_PASSED) && defined(MEMSEEK_TEST)
#endif // defined(TESTS_PASSED)
