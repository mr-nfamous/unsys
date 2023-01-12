/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 

*/
#pragma once

typedef signed char ucd_plane_t;

#define UCD_PLANE_0  ((ucd_plane_t) 0)
#define UCD_PLANE_1  ((ucd_plane_t) 1)
#define UCD_PLANE_2  ((ucd_plane_t) 2)
#define UCD_PLANE_3  ((ucd_plane_t) 3)
#define UCD_PLANE_4  ((ucd_plane_t) 4)
#define UCD_PLANE_5  ((ucd_plane_t) 5)
#define UCD_PLANE_6  ((ucd_plane_t) 6)
#define UCD_PLANE_7  ((ucd_plane_t) 7)
#define UCD_PLANE_8  ((ucd_plane_t) 8)
#define UCD_PLANE_9  ((ucd_plane_t) 9)
#define UCD_PLANE_10 ((ucd_plane_t) 10)
#define UCD_PLANE_11 ((ucd_plane_t) 11)
#define UCD_PLANE_12 ((ucd_plane_t) 12)
#define UCD_PLANE_13 ((ucd_plane_t) 13)
#define UCD_PLANE_14 ((ucd_plane_t) 14)
#define UCD_PLANE_15 ((ucd_plane_t) 15)
#define UCD_PLANE_16 ((ucd_plane_t) 16)

#define UCD_PLANE_WIDTH     8
#define UCD_PLANE_MIN   UCD_PLANE_P
#define UCD_PLANE_MAX   UCD_PLANE_16

#define UCD_BMP  UCD_PLANE_0
#define UCD_SMP  UCD_PLANE_1
#define UCD_SIP  UCD_PLANE_2
#define UCD_TIP  UCD_PLANE_3
#define UCD_SSP  UCD_PLANE_14
#define UCD_PUA  UCD_PLANE_15
#define UCD_PUB  UCD_PLANE_16

/*  NORMATIVE */
/*  INFORMATIVE */
/*  CONTRIBUTORY */
/*  PROVISIONAL */
#define ucd_numeric_type                ucd_nt //
#define ucd_bidi_class                  ucd_bc 
#define ucd_bidi_paired_bracket_type    ucd_bpt 
#define ucd_canonical_combining_class   ucd_ccc 
#define ucd_decomposition_type          ucd_dt 
#define ucd_east_asian_width            ucd_ea 
#define ucd_general_category            ucd_gc 
#define ucd_grapheme_cluster_break      ucd_gcb 
#define ucd_hangul_syllable_type        ucd_hst 
#define ucd_indic_positional_category   ucd_inpc 
#define ucd_indic_syllabic_category     ucd_insc 
#define ucd_joining_group               ucd_jg 
#define ucd_joining_type                ucd_jt 
#define ucd_line_break                  ucd_lb 
#define ucd_nfc_quick_check             ucd_nfc_qc 
#define ucd_nfd_quick_check             ucd_nfd_qc 
#define ucd_nfkc_quick_check            ucd_nfkc_qc 
#define ucd_nfkd_quick_check            ucd_nfkd_qc 
#define ucd_sentence_break              ucd_sb 
#define ucd_vertical_orientation        ucd_vo 
#define ucd_word_break                  ucd_wb

#define UCD_NORMATIVE 1
#define UCD_INFORMATIVE 2
enum {
    UCD_NORMATIVE,
    UCD_INFORMATIVE,
    UCD_PROVISIONAL,
    UCD_CONTRIBUTORY,
};
enum {
    UCD_CATALOG,
    UCD_BOOL,
    UCD_CHRMAP,
    UCD_ENUM,
    UCD_NUMERIC,
    UCD_STRMAP,
};
#define UCD_CATALOG 1

// <extracted/DerivedName.txt>
// <extracted/DerivedCombiningClass.txt>
// <extracted/DerivedNumericValues.txt>
// <extracted/DerivedJoiningGroup.txt>       
// <extracted/DerivedEastAsianWidth.txt>
// <extracted/DerivedGeneralCategory.txt>
// <extracted/DerivedLineBreak.txt>
// <extracted/DerivedBinaryProperties.txt> 
// <extracted/DerivedNumericType.txt>       
// <extracted/DerivedJoiningType.txt>
// <extracted/DerivedDecompositionType.txt>
enum {
//  UCD_ENUM

/*  INFORMATIVE */
/*  CONTRIBUTORY */
/*  PROVISIONAL */

/*  NORMATIVE */


    ucd_bc, 

    ucd_bpt, 
    ucd_ccc,
    ucd_dt, 
    ucd_ea, 
    ucd_gc, 
    ucd_GCB, 
    ucd_hst, 
    ucd_InPC, 
    ucd_InSC, 
    ucd_jg, 
    ucd_jt, 
    ucd_lb, 
    ucd_NFC_QC,
    ucd_NFD_QC, 
    ucd_NFKC_QC, 
    ucd_NFKD_QC, 
    ucd_nt,
    ucd_vo, 
    ucd_sb, 
    ucd_wb, // <auxiliary/WordBreakProperty.txt>

// BOOL
    // <DerivedCoreProperties.txt>
//  
    #define ucd_default_ignorable_code_point    ucd_di
    #define ucd_math                            ucd_math
    #define ucd_alphabetic                      ucd_alpha
    #define ucd_lowercase                       ucd_lower
    #define ucd_uppercase                       ucd_upper
    #define ucd_cased                           ucd_cased
    #define ucd_case_ignorable                  ucd_ci
    #define ucd_changes_when_lowercased         ucd_cwl
    #define ucd_changes_when_uppercased         ucd_cwu
    #define ucd_changes_when_titlecased         ucd_cwt
    #define ucd_changes_when_casefolded         ucd_cwcf
    #define ucd_changes_when_casemapped         ucd_cwcm
    #define ucd_id_start                        ucd_ids
    #define ucd_id_continue                     ucd_idc
    #define ucd_xid_continue                    ucd_xidc
    #define ucd_xid_start                       ucd_xids
    #define ucd_grapheme_extend                 ucd_gr_ext
    #define ucd_grapheme_base                   ucd_gr_base
    #define ucd_grapheme_link                   ucd_gr_link
    ucd_di, //          0000AD..0E0FFF N=4174 
    ucd_math, //        00002B..01EEF1 N=2310
    ucd_alpha, //       000041..03134A N=133396
    ucd_lower, //       000061..01E943 N=2471
    ucd_upper, //       000041..01F189 N=1951 
    ucd_cased, //       000041..01F189 N=4453
    ucd_ci, //          000027..0E01EF N=2602
    ucd_cwl, //         000041..01E921 N=1433
    ucd_cwu, //         000061..01E943 N=1525
    ucd_cwt, //         000061..01E943 N=1452 
    ucd_cwcf, //        000041..01E921 N=1506
    ucd_cwcm, //        000041..01E943 N=2927
    ucd_ids, //         000041..03134A N=131997
    ucd_idc, //         000030..0E01EF N=135072 
    ucd_xidc, //        000030..0E01EF N=135053 
    ucd_xids, //        000041..03134A N=131974
    ucd_gr_ext, //      000300..0E01EF N=2090 
    ucd_gr_base, //     000020..03134A N=142539
    ucd_gr_link, //     00094D..011D97 N=63 
    // <PropList.txt>
/*  CONTRIBUTORY */
#define ucd_other_alphabetic                    ucd_oalpha
#define ucd_other_default_ignorable_code_point  ucd_odi
#define ucd_other_grapheme_extend               ucd_ogr_ext
#define ucd_other_id_continue                   ucd_oidc 
#define ucd_other_id_start                      ucd_oids
#define ucd_other_lowercase                     ucd_olower
#define ucd_other_math                          ucd_omath
#define ucd_other_uppercase                     ucd_oupper
/*  NORMATIVE */ 
#define ucd_ascii_hex_digit                     ucd_ahex 
#define ucd_bidi_control                        ucd_bidi_c
#define ucd_dash                                ucd_dash
#define ucd_deprecated                          ucd_dep 
#define ucd_diacritic                           ucd_dia
#define ucd_extender                            ucd_ext
#define ucd_hex_digit                           ucd_hex
#define ucd_hyphen                              ucd_hyphen
#define ucd_ideographic                         ucd_ideo
#define ucd_ids_binary_operator                 ucd_idsb 
#define ucd_ids_trinary_operator                ucd_idst
#define ucd_join_control                        ucd_join_c
#define ucd_quotation_mark                      ucd_qmark
#define ucd_terminal_punctuation                ucd_term

#define ucd_noncharacter_code_point             ucd_nchar
#define ucd_radical                             ucd_radical 
#define ucd_unified_ideograph                   ucd_uideo
#define ucd_soft_dotted                         ucd_sd
#define ucd_sentence_terminal                   ucd_sterm
#define ucd_variation_selector                  ucd_vs 
#define ucd_pattern_white_space                 ucd_pat_ws
#define ucd_pattern_syntax                      ucd_pat_syn
#define ucd_regional_indicator                  ucd_ri
#define ucd_white_space                         ucd_ws
#define ucd_prepended_concatenation_mark        ucd_pcm 
    ucd_ahex,   // 000030..000066 N=22
    ucd_bidi_c, // 00061C..002069 N=12
    ucd_dash,   // 00002D..010EAD N=30
    ucd_dep,    // 000149..0E0001 N=15
    ucd_dia,    // 00005E..01E94A N=1064
    ucd_ext,    // 0000B7..01E946 N=50
    ucd_hex,    // 000030..00FF46 N=44
    ucd_hyphen, // 00002D..00FF65 N=11

    ucd_ideo,   // 003006..03134A N=101661
    ucd_idsb,   // 002FF0..002FFB N=10
    ucd_idst,   // 002FF2..002FF3 N=2
    ucd_join_c, // 00200C..00200D N=2
    ucd_qmark,  // 000022..00FF63 N=30
    ucd_term,   // 000021..01DA8A N=276
    ucd_omath,  // 00005E..01EEBB N=1362
    ucd_oalpha, // 000345..01F189 N=1404
    ucd_olower, // 0000AA..0107BA N=244
    ucd_oupper, // 002160..01F189 N=120
    ucd_nchar,  // 00FDD0..10ffff N=66
    ucd_ogr_ext,// 0009BE..0E007F N=127
    ucd_radical,// 002E80..002FD5 N=329
    ucd_uideo,  // 003400..03134A N=92865
    ucd_sd,     // 000069..01DF1A N=47
    ucd_oids,   // 001885..00309C N=6
    ucd_oidc,   // 0000B7..0019DA N=12
    ucd_sterm,  // 000021..01DA88 N=152
    ucd_vs,     // 00180B..0E01EF N=260
    ucd_pat_ws, // 000009..002029 N=11
    ucd_pat_syn,// 000021..00FE46 N=2760
    ucd_ri,     // 01F1E6..01F1FF N=26
    ucd_ws,     // 000009..003000 N=25
    ucd_pcm,    // 000600..0110CD N=13
    ucd_odi,    //  00034F..0E0FFF N=3776

    // <emoji/emoji-data.txt>
    ucd_emoji,  // 000023..01FAF6 N=1404 
    ucd_ecomp,  // 000023..0E007F N=146
    ucd_emod,   // 01F3FB..01F3FF N=5
    ucd_ebase,  // 00261D..01FAF6 N=132
    ucd_epres,  // 00231A..01FAF6 N=1185
    ucd_extpic, // 0000A9..01FFFD N=3537
#define ucd_emoji_component                 ucd_ecomp
#define ucd_emoji_modifier                  ucd_emod
#define ucd_emoji_modifier_Base             ucd_ebase
#define ucd_emoji_presentation              ucd_epres
#define ucd_extended_pictographic           ucd_extpic
    // <extracted/DerivedBinaryProperties.txt>
    ucd_bidi_m, // 000028..01D7C3 N=553 
#define ucd_bidi_mirrored                   ucd_bidi_m

    // <CompositionExclusions.txt>
    ucd_ce, //  000958..00FB4E N=67 
#define ucd_composition_exclusion   ucd_ce

    // <DerivedNormalizationProps.txt>
#define ucd_fc_nfkc_closure                 ucd_fc_nfkc
#define ucd_expands_on_nfc                  ucd_xo_nfc
#define ucd_expands_on_nfd                  ucd_xo_nfd
#define ucd_expands_on_nfkc                 ucd_xo_nfkc
#define ucd_expands_on_nfkd                 ucd_xo_nfkd
#define ucd_changes_when_nfkc_casefolded    ucd_cwkcf
#define ucd_nfkc_casefold                   ucd_nfkc_cf
#define ucd_full_composition_exclusion      ucd_comp_ex
#define ucd_nfd_quick_check                 ucd_nfd_qc
#define ucd_logical_order_exception         ucd_loe
    ucd_fc_nfkc, //  037A..1F190 N=637 
    ucd_xo_nfc, //  0344..1D1C0 N=85 !DEP 6,0
    ucd_xo_nfd, //  1D1BB..1D1C0 N=12216 !DEP 6,0
    ucd_xo_nfkc, //  00A8..1F248 N=1237 !DEP 6,0 
    ucd_xo_nfkd, //  00A8..1F248 N=13390 !DEP 6,0
    ucd_cwkcf, //  0041..E0FFF N=10429
    ucd_nfkc_cf, //  //0041..E0FFF N=10429 
    
    ucd_comp_ex, //  0340..2FA1D N=1120 
    ucd_nfd_qc, //  00C0..2FA1D N=13233 (screwed) 

    ucd_loe, 

};

static const struct {
    _Bool
        lb: 1,
        :   0;
} UCD_PLANE_HASATTR[17] = {
    [UCD_BMP] = {
        .lb=1,
    },
    [UCD_SMP] = {
        .lb = 1,
    },
    [UCD_SIP] = {
        .lb = 1,
    },
    [UCD_TIP] = {
        .lb = 1,
    },
    [UCD_SSP] = {
        .lb=1,
    },
    [UCD_PUA] = {
        .lb=1,
    },
    [UCD_PUB] = {
        .lb=1,
    },
};

static inline ucd_plane_t
ucd_GET_PLANE(char32_t c) {
    return c>>16;
}
#define ucd_decomposition_mapping ucd_dm
#define ucd_name ucd_na
#define ucd_name_alias ucd_name_alias
#define ucd_numeric_value ucd_nv
#define ucd_script_extensions ucd_scx
#define ucd_snicode_1_name ucd_na1
    ucd_dm, //  
    ucd_na, //  
    ucd_name_alias, //  
    ucd_nv, //  
    ucd_scx, //  
    ucd_na1, //  
    ucd_bmg, // <BidiMirroring.txt>
#define ucd_bidi_mirroring_glyph ucd_bmg


<BidiMirroring.txt>

    #define ucd_Bidi_Paired_Bracket ucd_bpb
<BidiBrackets.txt>
CHARMAP
    ucd_bpb, //  
    ucd_cf, /*
    <CaseFolding.txt>
    00B5; C; 03BC; # MICRO SIGN
    00DF; F; 0073 0073; # LATIN SMALL LETTER SHARP S
    0130; T; 0069; # LATIN CAPITAL LETTER I WITH DOT ABOVE
    1E9E; S; 00DF; # LATIN CAPITAL LETTER SHARP S
    */  
    ucd_equideo, //  
    ucd_fc_nfkc, // 
    ucd_isc, //  
    ucd_lc, //  
    ucd_nfkc_cf, //  
    ucd_scf,    //
    ucd_slc,    // 
    ucd_stc,    //  
    ucd_suc,    //  
    ucd_tc,     // 
    ucd_uc,     // 
    #define ucd_case_folding                ucd_cf
    #define ucd_equivalent_unified_ideograph ucd_equideo
    #define ucd_fc_nfkc_closure             ucd_fc_nfkc
    #define ucd_iso_comment                 ucd_isc
    #define ucd_lowercase_mapping           ucd_lc
    #define ucd_nfkc_casefold               ucd_nfkc_cf
    #define ucd_simple_case_folding         ucd_scf
    #define ucd_simple_lowercase_mapping    ucd_slc
    #define ucd_simple_titlecase_mapping    ucd_stc
    #define ucd_simple_uppercase_mapping    ucd_suc
    #define ucd_titlecase_mapping           ucd_tc
    #define ucd_uppercase_mapping           ucd_uc
