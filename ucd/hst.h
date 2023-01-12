
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */

#ifndef UCD_HST_H
#define UCD_HST_H

/*  HangulSyllableType.txt
# Property:	Hangul_Syllable_Type
# @missing: 0000..10FFFF; Not_Applicable

1100..115F    ; L #
1160..11A7    ; V #
11A8..11FF    ; T #
AC00          ; LV #
AC01..AC1B    ; LVT #


* UTF-8 keys
* .type == untree_leaf ## [    1    ] key
* .type == untree_node ## [  0..  7 ] keys; linear search
* .type == untree_stem ## [  8.. 31 ] keys; binary search
* .type == untree_trie ## [ 32..256 ] keys; trie
* When .size == 1 and all descendants are also 1, the root
  node is compared as a string

enum {
    untree_node=0,
    untree_leaf=1,
    untree_stem=2,
    untree_trie=3,
};

struct untree_stem;
struct untree_node;
struct untree_leaf;
struct untree_trie;

typedef union untree {
    struct untree_leaf *leaf;
    struct untree_node *node;
    struct untree_stem *stem;
    struct untree_trie *trie;
} untree;

struct untree_leaf {
    int i;
    unsigned 
        type:  16,
        :       0;
};

struct untree_stem {
    int i;
    unsigned
        type:   16,
        size:   8,
        :       0;
    untree next;
}

struct untree_node {
    const char *k; // match 
    int         i; // index in (struct untree_root){.data}
    unsigned 
        type:  16, // untree_leaf || untree_stem || untree_trie 
        size:   8, // entries in .tree 
        :       0;
    untree   next;
};

struct untree_trie {
    untree  tree[256];
    int i;
    unsigned type:16, 0;
};

struct untree_root {
    unsigned            flags;     // reserved 
    unsigned            size;      // items in .data
    void *              data;      // table of values
    struct untree_stem  tree[256]; // actual mapping 
};

UCD_HST_MAP = (struct untree_root){
    .size = 6,
    .data = (const char *[]){
        [NA_HST]    = "NA",
        [L_HST]     = "L",
        [V_HST]     = "V",
        [T_HST]     = "T",
        [LV_HST]    = "LV",
        [LVT_HST]   = "LVT",
    },
    .tree = (struct untree_stem[3]){
        ['L'] = {
            "L", L_HST, untree_leaf, 0, 1, (untree[1]){
            "V", LV_HST, untree_leaf, 0, 1, (untree[1]){
                {"T", LVT_HST},
            },
        },
        ['{"N", N_HST},
        {"T", T_HST, 0, 0,
    }
}

*/

#define NA_HST  0 //
#define L_HST   1 // 
#define V_HST   2 // 
#define T_HST   3 //  
#define LV_HST  4 //  
#define LVT_HST 5 //  
#define   LEADING_JAMO_HST   L_HST
#define     VOWEL_JAMO_HST   V_HST
#define  TRAILING_JAMO_HST   T_HST
#define    LV_SYLLABLE_HST  LV_HST
#define NOT_APPLICABLE_HST  NA_HST
#define   LVT_SYLLABLE_HST LVT_HST

enum {
    UNTREE_LEAF=0,
    UNTREE_STEM,
    UNTREE_TRIE,
};
#define UNTREE_IGNORE_CASE  0x0001
#define UNTREE_RESET_FLAGS  0x4000
#define UNTREE_DONT_MATCH   0x8000
typedef struct untree untree;

struct untree {
    const char *    k;
    int             i;
    unsigned short  type;
    unsigned char   used;
    untree          *next;
};

struct untree_tree {
    unsigned short type;
    unsigned size;
    void *data;
    untree tree[256];
};

typedef struct {
    const char *name[2];
} UCD_Hangul_Syllable_Type;

ucd_hst_map = (struct untree_tree){
    UNTREE_IGNORE_CASE,
    .size = 6,
    .data = (UCD_Hangul_Syllable_Type){
        [L_HST] = {"L", "Leading_Jamo"},
        [LV_HST] = {"LV", "Lv_Syllable"},
        [LVT_HST] = {"LVT", "Lvt_Syllable"},
        [NA_HST] = {"NA", "Not_Applicable"},
        [T_HST] = {"T", "Trailing_Jamo"},
        [V_HST] = {"V", "Vowel_Jamo"},
    },
    .tree = {
        ['L'] = {
            "", L_HST, UNTREE_STEM, 1, (untree[]){
                "V", LV_HST, UNTREE_STEM, 1, (untree[]){
                    {"T", LVT_HST},
                },
            },
        },
        ['N'] = {"A", NA_HST},
        ['T'] = {"", T_HST},
        ['V'] = {"", V_HST},
    }
};

#endif