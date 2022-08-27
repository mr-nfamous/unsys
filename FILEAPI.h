/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#pragma once
typedef 
union _FILE_SEGMENT_ELEMENT {
    PVOID64   Buffer;
    ULONGLONG Alignment;
}   FILE_SEGMENT_ELEMENT;

typedef 
struct _OVERLAPPED {
    uintptr_t Internal;
    uintptr_t InternalHigh;
    union {
        struct {
            unsigned Offset;
            unsigned OffsetHigh;
        };
        void *Pointer;
    };
    void    *hEvent;
}   OVERLAPPED;

enum {
    FILE_ATTRIBUTE_MIN,
#   define FILE_ATTRIBUTE_READONLY  0x00000001 
#   define FILE_ATTRIBUTE_HIDDEN    0x00000002
#   define FILE_ATTRIBUTE_SYSTEM    0x00000004 
#   define FILE_ATTRIBUTE_ARCHIVE   0x00000020 
#   define FILE_ATTRIBUTE_NORMAL    0x00000080 
#   define FILE_ATTRIBUTE_TEMPORARY 0x00000100
#   define FILE_ATTRIBUTE_OFFLINE   0x00001000 
#   define FILE_ATTRIBUTE_ENCRYPTED 0x00004000 

#   define FILE_FLAG_OPEN_NO_RECALL        0x00100000
#   define FILE_FLAG_OPEN_REPARSE_POINT    0x00200000 
#   define FILE_FLAG_SESSION_AWARE         0x00800000
#   define FILE_FLAG_POSIX_SEMANTICS       0x01000000
#   define FILE_FLAG_BACKUP_SEMANTICS      0x02000000
#   define FILE_FLAG_DELETE_ON_CLOSE       0x04000000
#   define FILE_FLAG_SEQUENTIAL_SCAN       0x08000000
#   define FILE_FLAG_RANDOM_ACCESS         0x10000000
#   define FILE_FLAG_NO_BUFFERING          0x20000000
#   define FILE_FLAG_OVERLAPPED            0x40000000
#   define FILE_FLAG_WRITE_THROUGH         0x80000000

// CreateFileA accmode

//  dir handles
#   define FILE_LIST_DIRECTORY         1
#   define FILE_ADD_FILE               2 
#   define FILE_ADD_SUBDIRECTORY       4
#   define FILE_TRAVERSE               0x0020

//  file handles
#   define FILE_READ_DATA              1
#   define FILE_WRITE_DATA             2
#   define FILE_APPEND_DATA            4
#   define FILE_CREATE_PIPE_INSTANCE   4
#   define FILE_READ_EA                8
#   define FILE_WRITE_EA               0x0010

#   define FILE_EXECUTE                0x0020
/*
    Hmm....

    Iterating over a directory on a *ix system requires 
    "execute" permission (S_IXUSR).
    
    Iterating over a directory on a win system requires
    "execute" permission (FILE_EXECUTE|FILE_TRAVERSE).
*/
#   define FILE_DELETE_CHILD           0x0040
#   define FILE_READ_ATTRIBUTES        0x0080
#   define FILE_WRITE_ATTRIBUTES       0x0100
};

int ReadFileScatter(void *,FILE_SEGMENT_ELEMENT[],DWORD,DWORD *,OVERLAPPED *);
int CreateDirectoryW(const wchar_t *, SECURITY_ATTRIBUTES *);

HANDLE CreateFileA(
  [in]           LPCSTR                lpFileName,
  [in]           DWORD                 dwDesiredAccess,

    
  [in]           DWORD                 dwShareMode,
  FILE_SHARE_DELETE 0x04
  FILE_SHARE_READ   0x01
  FILE_SHARE_WRITE  0x02 
  [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [in]           DWORD                 dwCreationDisposition,
    CREATE_NEW          1   O_CREAT|O_EXCL 
    CREATE_ALWAYS       2   O_CREAT|O_TRUNC 
    OPEN_EXISTING       3   O_EXCL
    OPEN_ALWAYS         4   O_CREAT
    TRUNCATE_EXISTING   5   O_TRUNC
  [in]           DWORD                 dwFlagsAndAttributes,

  [in, optional] HANDLE                hTemplateFile
);
void * CreateFile2(
    const wchar_t *path, 
    unsigned access, 
    unsigned shared,
    unsigned create,
    CREATEFILE2_EXTENDED_PARAMETERS *xcreate);
  