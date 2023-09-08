#pragma once
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#define __i64  long long int
#define CONST const

    typedef void       *PVOID;
    typedef CONST void *LPCVOID;
    typedef DWORD *LPDWORD;
    typedef HANDLE *LPHANDLE;
    typedef void *LPVOID;

typedef char
        CCHAR,
        CHAR,       *PCHAR,     *LPSTR;
typedef const char  *PCSTR;

#ifdef _WIN64
    typedef unsigned int    UHALF_PTR;
    typedef unsigned __i64   UINT_PTR;
    typedef unsigned __i64  ULONG_PTR; 
#else
    typedef unsigned short  UHALF_PTR, *PUHALF_PTR;
    typedef unsigned int     UINT_PTR,  *PUINT_PTR;
    typedef unsigned long   ULONG_PTR, *PULONG_PTR;
#endif

typedef unsigned char                   // __u8
        BYTE,       *PBYTE,     *LPBYTE,
        BOOLEAN,    *PBOOLEAN,
        UINT8,      *PUINT8,
        UCHAR,      *PUCHAR;
typedef unsigned short                  // __u16
        WORD,       *PWORD,     *LPWORD,
        UINT16,     *PUINT16,
        USHORT,     *PUSHORT;
typedef unsigned int                    // __u32
        UINT32,     *PUINT32,
        ULONG32,    *PULONG32,
        DWORD32,    *PDWORD32;
typedef unsigned long                   // __l32
        DWORD,      *PDWORD,    *LPDWORD;
typedef unsigned __i64                  // __u64
        QWORD,      *PQWORD,    *LPQWORD,
        UINT64,     *PINT64,
        ULONG64,    *PLONG64,
        DWORD64,    *PDWORD64,
        DWORDLONG,  *PDWORDLONG;

typedef ULONG_PTR 
        DWORD_PTR,  *PDWORD_PTR,
        SIZE_T;

#ifdef _WIN64
    typedef          int     HALF_PTR, *PHALF_PTR;
    typedef   signed __i64    INT_PTR, *PINT_PTR;
    typedef   signed __i64   LONG_PTR, *PLONG_PTR; 
#else
    typedef          short   HALF_PTR,  *PHALF_PTR;
    typedef          int      INT_PTR,   *PINT_PTR;
    typedef          long    LONG_PTR,  *PLONG_PTR;
#endif

typedef LONG_PTR SSIZE_T;

typedef signed char                     // __s8
        INT8,       *PINT8;
typedef signed short                    // __s16
        INT16,      *PINT16,
        SHORT,      *PSHORT;
typedef signed int                      // __s32
        INT,        *PINT,      *LPINT,
        INT32,      *PINT32,
        LONG32,     *PLONG32;
typedef long                            // __l32
        LONG, *LPLONG;
typedef signed __i64                    // __s64
        INT64,      *PINT64,
        LONG64,     *PLONG64;


// no explicit "signed" qualifier for "SHORT"
// no explicit "signed" qualifier for "INT"
// didn't actually see *[LP]QWORD defined anywhere 

