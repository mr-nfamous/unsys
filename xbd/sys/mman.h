#pragma once

int include_sys_mman_h(Lib *self, FILE *file) {
    __basedef(sys_mman_h, "<sys/mman.h>")
    __dentr(enums, Enum[])
#   if (_POSIX_MAPPED_FILES < 1)
#       define BLTN_MMAP        0
#       define BLTN_MUNMAP      0
#       define BLTN_MSYNC       0
#       define BLTN_MPROTECT    0
#   else
#       ifndef BLTN_MMAP 
#       define BLTN_MMAP mmap
#       endif
#       ifndef BLTN_MUNMAP
#       define BLTN_MUNMAP munmap
#       endif

        __predef("MAP")
            EDEF_(MAP,SHARED)
            EDEF_(MAP,PRIVATE)
            EDEF_(MAP,FIXED)
        __preend("MA0", .sort=C__VSORT, .fmt="x")

        __predef("PROT")
            EDEF_(PROT, NONE)
            EDEF_(PROT, READ)
            EDEF_(PROT, WRITE)
            EDEF_(PROT, EXEC)
        __preend("PROT", .sort=C__VSORT, .fmt="x")

#       if (_POSIX_MEMORY_PROTECTION < 1)
#       define BLTN_MPROTECT 0
#       endif

#       ifndef BLTN_MPROTECT
#       define BLTN_MPROTECT mprotect
#       endif

#       if (_POSIX_SYNCHRONIZED_IO < 1)
#           define BLTN_MSYNC 0
#       else
            __predef("MS")
                EDEF_(MS,ASYNC)
                EDEF_(MS,INVALIDATE)
                EDEF_(MS,SYNC)
            __enddef("MS")
#           ifndef BLTN_MSYNC
#           define BLTN_MSYNC msync
#           endif
#       endif

#   endif

#   if (_POSIX_ADVISORY_INFO < 1)
#       define BLTN_POSIX_MADVISE 0
#   else
        __predef("POSIX")
            EDEF_(POSIX,MADV_NORMAL)
            EDEF_(POSIX,MADV_RANDOM)
            EDEF_(POSIX,MADV_SEQUENTIAL)
            EDEF_(POSIX,MADV_WILLNEED)
            EDEF_(POSIX,MADV_DONTNEED)
        __enddef("POSIX")
#       ifndef BLTN_POSIX_MADVISE
#       define BLTN_POSIX_MADVISE posix_madvise
#       endif
#   endif

#   if (_POSIX_MEMLOCK < 1)
#       define BLTN_MLOCKALL    0
#       define BLTN_MUNLOCKALL  0
#       define BLTN_MLOCK       0
#       define BLTN_MUNLOCK     0
#   else
        __predef("MCL")
            EDEF_(MCL,CURRENT)
            EDEF_(MCL,FUTURE)
        __enddef("MCL")
#       ifndef BLTN_MLOCKALL
#       define BLTN_MLOCKALL mlockall
#       endif
#       ifndef BLTN_MUNLOCKALL
#       define BLTN_MUNLOCKALL munlockall
#       endif

#       if (_POSIX_MEMLOCK_RANGE < 1)
#           define BLTN_MLOCK   0
#           define BLTN_MUNLOCK 0
#       else
#           ifndef BLTN_MLOCK
#           define BLTN_MLOCK mlock
#           endif
#           ifndef BLTN_MUNLOCK
#           define BLTN_MUNLOCK munlock
#           endif
#       endif

#   endif

#   if (_POSIX_SHARED_MEMORY_OBJECTS < 1)
#       define BLTN_SHM_OPEN    0
#       define BLTN_SHM_UNLINK  0
#   else
#       ifndef BLTN_SHM_OPEN
#       define BLTN_SHM_OPEN shm_open
#       endif
#       ifndef BLTN_SHM_UNLINK
#       define BLTN_SHM_UNLINK shm_unlink
#       endif
#   endif

#   if (_POSIX_TYPED_MEMORY_OBJECTS < 1)
#       define BLTN_POSIX_TYPED_MEM_GET_INFO    0
#       define BLTN_POSIX_TYPED_MEM_OPEN        0
#       define BLTN_POSIX_MEM_OFFSET            0
#   else

#       ifndef BLTN_POSIX_TYPED_MEM_OPEN
#       define BLTN_POSIX_TYPED_MEM_OPEN posix_typed_mem_open
#       endif

        __predef("POSIX")
            EDEF_(POSIX,TYPED_MEM_ALLOCATE)
            EDEF_(POSIX,TYPED_MEM_ALLOCATE_CONTIG)
            EDEF_(POSIX,TYPED_MEM_MAP_ALLOCATABLE)
        __enddef("POSIX")

#       ifndef BLTN_POSIX_TYPED_MEM_GET_INFO
#       define BLTN_POSIX_TYPED_MEM_GET_INFO posix_typed_mem_get_info
#       endif

#       ifndef BLTN_POSIX_MEM_OFFSET
#       define BLTN_POSIX_MEM_OFFSET posix_mem_offset
#       endif
#   endif

    __dexit(enums)

    __dentr(structs, Struct[])

#   if (_POSIX_TYPED_MEMORY_OBJECTS > 0)
        __memdef(posix_typed_mem_info_s)
        __member(posix_typed_mem_info_s, posix_tmi_length, "size_t")            
        __enddef(posix_typed_mem_info_s)
#   endif

    __dexit(structs)
    __baseret(sys_mman_h)
}

int test_sys_mmap_h(Lib *self, FILE *file) {

    self->mlock     = BLTN_MLOCK;
    self->mlockall  = BLTN_MLOCKALL;
    self->mmap      = BLTN_MMAP;
    self->mprotect  = BLTN_MPROTECT;
    self->msync     = BLTN_MSYNC;
    self->munlock   = BLTN_MUNLOCK;
    self->munlockall= BLTN_MUNLOCKALL;
    self->munmap    = BLTN_MUNMAP;
    
    self->posix.madvise             = BLTN_POSIX_MADVISE;
    self->posix.mem_offset          = BLTN_POSIX_MEM_OFFSET;
    self->posix.typed_mem.get_info  = BLTN_POSIX_TYPED_MEM_GET_INFO;
    self->posix.typed_mem.open      = BLTN_POSIX_TYPED_MEM_OPEN;

    self->shm.open  = BLTN_SHM_OPEN;
    self->shm.unlink= BLTN_SHM_UNLINK;
    

#   ifdef BLTN_MREMAP
    self->mremap    = BLTN_MREMAP;
#   endif

#   ifdef BLTN_MADVISE
    self->madvise   = BLTN_MADVISE;
#   endif

#   ifdef BLTN_MINCORE
    self->mincore   = BLTN_MINCORE;
#   endif

#   ifdef BLTN_MEMFD_CREATE
    self->memfd_create  = BLTN_MEMFD_CREATE;
#   endif

    return 0;
}