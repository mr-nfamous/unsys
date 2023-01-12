/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
/*
Operation prefixes:
    ucs-: nul terminated array of code units 
    mem-: array of code units 

Operation suffixes:
    -bis: binary search for char
    -brk: split at 
    -crc: cyclic redundancy check
    -cmp: compare with
    -cat: concatenate to
    -chr: linear search for char
    -cpy: copy into
    -del: delete at
    -dup: duplicate 
    -ins: insert at
    -len: length of 
    -max: find maximum value of
    -mov: move into
    -mem: memory search
    -mul: multiply into
    -prl: prefix length of
    -str: substring search
    -rev: reverse 
    -set: set all to 
    -sul: suffix length
    -cprl: complementary prefix length
    -csul: complementary suffix length 
    -sort: sort
    -rbrk: split at, from rtl
    -rcmp: compare with, from rtl
    -rchr: char search in reverse 
    -rcpy: copy reversed into
    -rdup: duplicate the reverse 
    -rstr: rtl find substring 
    -rmem: rtl find byte sequence 
*/

#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#include "unstddef.h"
#include "error.h"

#define TG_STR(F, x, ...) (_Generic((x),\
char32_t*:USTR##F,\const char32_t*:USTR##F,\
char16_t*:HSTR##F,\const char16_t*:HSTR##F,\
char*:    BSTR##F,\const char*:    BSTR##F,\
byte_t*:  BSTR##F,\const byte_t*:  BSTR##F)(x, __VA_ARGS__))

#define TG_MEM(F, x, ...) (_Generic((x),\
void*     BMEM##F,\const void *:   BMEM##F,\
char32_t*:UMEM##F,\const char32_t*:UMEM##F,\
char16_t*:HMEM##F,\const char16_t*:HMEM##F,\
char*:    BMEM##F,\const char*:    BMEM##F,\
byte_t*:  BMEM##F,\const byte_t*:  BMEM##F)(x, __VA_ARGS__))

static inline void *BMEMREV(void *, size_t);
static inline void *HMEMREV(void *, size_t);
static inline void *UMEMREV(void *, size_t);

static inline void *BMEMSET(void *, char,     size_t);
static inline void *HMEMSET(void *, char16_t, size_t);
static inline void *UMEMSET(void *, char32_t, size_t);

static inline void *BMEMCHR(const void *, char,     size_t);
static inline void *HMEMCHR(const void *, char16_t, size_t);
static inline void *UMEMCHR(const void *, char32_t, size_t);

static inline void *BMEMRCHR(const void *, char, size_t);
static inline void *HMEMRCHR(const void *, char16_t, size_t);
static inline void *UMEMRCHR(const void *, char32_t, size_t);

static inline char *    BSTRCHR(const char[], char);
static inline char16_t *HSTRCHR(const char16_t[], char16_t);
static inline char32_t *USTRCHR(const char32_t[], char32_t);

static inline char *    BSTRLCHR(const char[], char, size_t);
static inline char16_t *HSTRLCHR(const char16_t[], char16_t, size_t);
static inline char32_t *USTRLCHR(const char32_t[], char32_t, size_t);

static inline char *    BSTRRCHR(const char[], char);
static inline char16_t *HSTRRCHR(const char16_t[], char16_t);
static inline char32_t *USTRRCHR(const char32_t[], char32_t);

static inline size_t BSTRLEN(const char[]);
static inline size_t HSTRLEN(const char16_t[]);
static inline size_t USTRLEN(const char32_t[]);

static inline size_t BSTRNLEN(const char[], size_t);
static inline size_t HSTRNLEN(const char16_t[], size_t);
static inline size_t USTRNLEN(const char32_t[], size_t);

static inline size_t BSTRSIZE(const char[], size_t);
static inline size_t HSTRSIZE(const char16_t[], size_t);
static inline size_t USTRSIZE(const char32_t[], size_t);

static inline int BSTRCMP(const char *, const char *);
static inline int HSTRCMP(const char16_t *, const char16_t *);
static inline int USTRCMP(const char32_t *, const char32_t *);

static inline int BSTRNCMP(const char *, const char *, size_t);
static inline int HSTRNCMP(const char16_t *, const char16_t *, size_t);
static inline int HSTRNCMP(const char16_t *, const char16_t *, size_t);

static inline int BMEMCMP(const void *, const void *, size_t);
static inline int HMEMCMP(const void *, const void *, size_t);
static inline int UMEMCMP(const void *, const void *, size_t);

static inline int BMEMRCMP(const void *, const void *, size_t);
static inline int HMEMRCMP(const void *, const void *, size_t);
static inline int UMEMRCMP(const void *, const void *, size_t);

static inline void *BMEMCPY(void *, const void *, size_t);
static inline void *HMEMCPY(void *, const void *, size_t);
static inline void *UMEMCPY(void *, const void *, size_t);

static inline void *BMEMMOV(void *, const void *, size_t);
static inline void *HMEMMOV(void *, const void *, size_t);
static inline void *UMEMMOV(void *, const void *, size_t);

static inline char     *BSTPCPY(char *,     const char *);
static inline char16_t *HSTPCPY(char16_t *, const char16_t *);
static inline char32_t *USTPCPY(char32_t *, const char32_t *);

static inline char     *BSTRCPY(char *,     const char *);
static inline char16_t *HSTRCPY(char16_t *, const char16_t *);
static inline char32_t *USTRCPY(char32_t *, const char32_t *);

static inline char     *BSTRCAT(char *,     const char *);
static inline char16_t *HSTRCAT(char16_t *, const char16_t *);
static inline char32_t *USTRCAT(char32_t *, const char32_t *);

#define TESTS_PASSED() ((void)printf("passed all %zu in %s\n",ctr,__func__))

#define CMP_DEFAULT 0x0000
#define CMP_NFC     0x0001
#define CMP_NFD     0x0002
#define CMP_NFKC    0x0003
#define CMP_NFKD    0x0004

struct ucs_stat {
    const char *head;
    const char *tail;

    const char *mode;
    const char *min;
    const char *loq;
    const char *mid; 
    const char *hiq; 
    const char *max;

    char        size; // set cardinality, not length
    char        range;// *max-*min
};

/* Convert the unsigned integer at {src} into its base {base}
representation. The result is copied into the array of {nel}
elements which begins at {uca}. Returns the number of elements
(digits) copied. If {base} is not from [2..36], errno is set
to EINVAL. If the representation is longer than {nel}, errno 
is set to ENOMEM. Nothing is copied if an error occurs.
*/
int btomem(void *restrict uca, size_t nel, const void *restrict src, int base);
int htomem(void *restrict uca, size_t nel, const char *restrict src, int base);
int itomem(void *restrict uca, size_t nel, const char *restrict src, int base);
int qtomem(void *restrict uca, size_t nel, const char *restrict src, int base);


/* Compare the contents of two nul terminated arrays.

The {len} parameter of {ucslcmp} and {ucsrcmp} specifies the
maximum number of elements to compare. If {len} is -1, all of
{lhs} and {rhs} are compared.

{ucsrcmp} is identical to {ucslcmp} except that it behaves as
if {lhs} and {rhs} were reversed as if by {ucsrev}.

*/
int bucscmp (const char lhs[], const char rhs[]);
int bucslcmp(const char lhs[], const char rhs[], ssize_t len);
int bucsrcmp(const char lhs[], const char rhs[], ssize_t len);

/* Append elements from one nul terminated array to another.

The {nel} parameter of {ucsncat} and {ucpncat} specify the
maximum number of elements from {src} to copy, excluding the
terminator, which is always added to the end of {ucs}.

{ucpcat} and {ucncat} return pointers to the nul terminator
of {ucs} after {src} is concatenated. {ucscat} and {ucsncat}
return {ucs}.
*/
char *bucpcat (char ucs[restrict], const char src[restrict]);
char *bucpncat(char ucs[restrict], const char src[restrict], size_t nel);
char *bucscat (char dst[restrict], const char ucs[restrict]);
char *bucsncat(char ucs[restrict], const char src[restrict], size_t nel);

/* Copy elements from the nul terminated array {src} to the
array {uca}.

The result for any of these operations if {uca} and {src}
overlap is undefined.

{ucscpy}
{ucpcpy}
    Copy all of {src}, including its terminator, into {uca}.
    {ucpcpy} returns the address of the terminating nul of
    {uca} after the operation is complete. {ucscpy} returns
    {uca}.

{ucpncpy}
{ucsncpy}
    Copy exactly {nel} elements from {src} to {uca}. If {nel}
    elements are copied before the terminating nul in {src}
    is reached, {uca} will not be correctly terminated and
    {ucpncpy} returns {&uca[nel]}. If the size of {src} is
    less than {nel}, the end of {uca} is padded with nul
    until all {nel} of the elements of {uca} are overwritten.

The following always return a properly terminated result.

{ucpscpy}
{ucpscpy}
    Copies at most {ucslen(uca)} elements from {src} into
    {uca}. If {src} is shorter than {uca}, the terminator of
    {src} will *not* be copied.
    Semantically, {ucsscpy(d, "abc")} is indistinguishable
    from {memcpy(d, strlen(d), "abc", strlen("abc"))}.

{ucslcpy}
{ucplcpy}
    Copy at most the first {len} elements from the substring
    beginning at the start of {src}. When {len} is -1, the
    result is as if {(ssize_t) ucslen(src)} were used.

{ucsrcpy}
{ucprcpy}
    Identical to the corresponding -lcpy suffixed operation
    except that it behaves as if {ucsrev(src)} were called
    beforehand.
*/
char *bucpcpy (char uca[restrict], const char src[restrict]);
char *bucpncpy(char uca[restrict], const char src[restrict], size_t nel);
char *bucplcpy(char uca[restrict], const char src[restrict], ssize_t len);
char *bucprcpy(char uca[restrict], const char src[restrict], ssize_t len);
char *bucscpy (char uca[restrict], const char ucs[restrict]);
char *bucsncpy(char uca[restrict], const char src[restrict], size_t nel);
char *bucslcpy(char uca[restrict], const char src[restrict], ssize_t len);
char *bucsrcpy(char uca[restrict], const char src[restrict], ssize_t len);

/* Copy {chr} into each element of the nul terminated array
{ucs} (not including its terminator)

{memcset}, like {memccpy}, stops if {end} is encountered in
{uca} before {nel} elements are copied. When {end} is found,
a pointer to the element after it is returned. Otherwise,
NULL is.

{ucpncpy} returns {&uca[ucslen(uca)]} if {nel} was greater
than {ucslen(uca)}. Otherwise, like {ucsncpy}, {&uca[nel]}
is returned.
*/
void *bmemcset  (void *uca, size_t nel, char32_t chr);
char *bucpset   (char ucs[], char32_t chr);
char *bucsset   (char ucs[], char32_t chr);
char *bucpnset  (char ucs[], char32_t chr, size_t nel);
char *bucsnset  (char ucs[], char32_t chr, size_t nel);

/* Look for {chr} within the nul terminated array {ucs} via
binary search. If {ucs} isn't sorted the result is undefined.

If {chr} is indeed an element of {ucs}, a pointer to its
first occurrence is returned. Otherwise, NULL is.
*/
void *bmembis(const void *uca, size_t nel, char32_t chr);
char *bucsbis(const char ucs[], char32_t chr);

/* Look for an element from {brk}, a nul terminated array
representing a set, in the nul terminated array {ucs} and
return a pointer to it or NULL if none of the elements in
{ucs} are members of {brk}.

The {len} parameter of {ucslbrk} and {ucsrbrk} specifies the
maximum number of elements to search. If {len} is -1, all of
{ucs} is searched.

{ucsrbrk} returns the rightmost matching element.
*/
void *bmembrk  (const void *mem, size_t nel, const void *brk, size_t bsz);
char *bucsbrk  (const char ucs[], const char brk[]);
char *bucslbrk(const char ucs[], const char brk[], ssize_t len);
char *bucsrbrk(const char ucs[], const char brk[], ssize_t len);

/* Find the first element in the nul terminated array {ucs}
equal to {chr}. These operations are the same as the
corresponding -brk suffixed operation, when {brk} contains
only {chr}. The obvious exception to this is the nul element,
which by definition cannot be a member of the {brk} set.

*/
char *bucschr (const char ucs[], char32_t chr);
char *bucslchr(const char ucs[], char32_t chr, ssize_t len);
char *bucsrchr(const char ucs[], char32_t chr, ssize_t len);

/* Find the first overlapping occurrence in a nul terminated
array {ucs} of the nul terminated substring {str}. Neither
operand's terminator is considered. The empty string matches
the beginning of the searched substring. NULL is returned if
no match is located.

The {len} parameter of {ucslstr} and {ucsrstr} limits the
size of the substring searched. If -1, all of {ucs} is.
*/
char *bucsstr (const char ucs[], const char str[]);
char *bucslstr(const char ucs[], const char str[], ssize_t max);
char *bucsrstr(const char ucs[], const char str[], ssize_t max);
void *bmemrmem(const void *uca, size_t nel, const void *str, size_t ssz);

/* Copy the concatenation of {mul} repetitions of {str} into
the array {uca}.

{ucpmul} and {ucsmul} always return a properly terminated
result.

{ucssmul} and {ucpsmul} require a properly terminated {uca},
while the second parameter of {memsmul} specifies the size
of {uca}, in elements, and the result is truncated if {uca}
isn't large enough to accommodate it.

*/
char *bucpmul (char uca[], const char str[], size_t mul);
char *bucsmul (char uca[], const char str[], size_t mul);
char *bucpsmul(char uca[], const char str[], size_t mul);
char *bucssmul(char uca[], const char str[], size_t mul);
void *bmemmul (void *uca,  const void *str, size_t nel, size_t mul);
void *bmemsmul(void *uca, size_t len, const void *str, size_t nel, size_t mul);

/* (Symbolically) delete a up to {del} elements from {ucs}.

When a substring is "deleted", the elements following it
are moved into the resulting "hole" (as if by {memmove}).
Since this operation doesn't physically resize the memory
block in which the contents are of {ucs} are stored, when
{del} is less than {ucslen(ucs)}, the contents of the {del-1}
elements following the terminator are undefined. When it
would be impractical or unnecessary to physically resize the
memory, the value of {chr} will be used to fill the space.
Otherwise, if {chr} is -1, the operation terminates without
modifying it.

Returns the length of {ucs} after the deletion has occurred
and effect of the {chr} parameter applied.
*/
size_t bucsdel (char ucs[],            size_t del, int chr);
size_t bmemdel (void *uca, size_t nel, size_t del, int chr);

/* Reverse the contents of {ucs} */
char *bucsrev (char ucs[]);
char *bmemrev (void *uca, size_t nel);

/* Copy {ucs} into a block of memory returned by {malloc}

The {len} parameter of {ucsldup} and {ucsrdup} limits the
operation to at most a {len} element substring of {ucs}.

{ucsrdup} constructs a reversed copy of {ucs}.

The caller must call {free} on the result.
*/
void *bmemdup (const void *uca, size_t nel);
void *bmemrdup(const void *uca, size_t nel);
char *bucsdup (const char ucs[]);
char *bucsldup(const char ucs[], ssize_t len);
char *bucsrdup(const char ucs[], ssize_t len);

/* Count the number of elements before the end of the nul 
terminated array {ucs}.

{ucsnel} returns the number of elements needed to represent
{ucs}, including the nul.

{ucssize} calculates the number of bytes needed to store a 
nul terminated copy of an at most {len} element substring.
If {len} is -1, the effect is as id if len was {ucslen(ucs)}.

{ucsnlen} stops counting after {nel} elements.

{ucsslen} is identical to {ucsnlen} except the returned size
is a signed value.

*/
size_t  bucslen (const char ucs[]);
size_t  bucsnel (const char ucs[]);
size_t  bucssize(const char ucs[], ssize_t len);
size_t  bucsnlen(const char ucs[], size_t nel);
ssize_t bucsslen(const char ucs[], ssize_t len);

/* Get the size of the prefix of {ucs} which consists only
of elements of the set {acc}.
*/

size_t bucsprl(const char ucs[], const char acc[], ssize_t len);
size_t bmemprl(const void *uca, size_t nel, const void *acc, size_t asz);

/* Get the size of the prefix of {ucs} which consists only
of elements that are not members of the set {rej}*/

size_t bucscprl(const char ucs[], const char acc[], size_t max);
size_t bmemcprl(const void *seq, size_t nel, const void *acc, size_t len);

/* Get the size of the suffix of {ucs} which consists only
of elements of the set {acc}.
*/

size_t bucssul(const char ucs[], const char acc[], ssize_t len);
size_t bmemsul(const void *uca, size_t nel, const void *acc, size_t asz);

/* Get the size of the suffix of {ucs} which consists only
of elements that are not members of the set {rej}*/

size_t bucscsul(const char ucs[], const char acc[], size_t max);
size_t bmemcsul(const void *seq, size_t nel, const void *acc, size_t len);

size_t bucsstat(struct ucs_stat *stat, const char ucs[], ssize_t len);
