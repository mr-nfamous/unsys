
/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳
Unicode "blk" and "plane" properties

DONT INCLUDE DIRECTLY

Unicode divides 1,114,112 (0x110000) individual code points 
across 17 equally sized subregions of 65535 code points know
as planes. Each plane is then further divided, semantically,
into a sequence of 4096 ranges, with each range starting on a 
code point multiple of 16 (16×4096 = 65536). Blocks are then 
defined as slices of one or more of these ranges. For example,
the first two blocks:

    [0] [0x000..0x000] = "US-ASCII"
    [0] [0x008..0x010] = "Latin-1 Supplement"

Note: integer division by 16 is equivalent to right shifting 
by 4.

Blocks are guaranteed to exist wholly within a single plane, 
so identification of the block in which a code point belongs 
can be accomplished by obtaining the code point's plane by 
right shifting the low 16 bits out then determining the index
of the start range by right shifting the low 16 bits by 4.

For example, for the Euro sign U+20AC:
    plane = (0x20AC >> 16) (0) 
    range = (0x20AC & 0xFFFF) >> 4 (532)

With range from the previous example, UCD_BLK[range] would
return (ucd_blk_t) currency_blk. From this, the attributes
associated with the 48 code point "Currency Symbols" block 
at [20A0..20CF] can be acquired.

*/
#pragma once
#include <stdlib.h>
#include <stdint.h>
#include <uchar.h>


/*  IMPORTANT NOTE:

    The types used to represent Unicode property values are 
    necessarily as compact as possible. As one of the few 
    "catalog" properties, blk actually has the potential to
    require more than 1 byte to represent. If an application
    defines more than 255 custom block properties for one of 
    the private use areas it must ensure that UCD_BLK_WIDTH 
    and UCD_BLK_TYPE are defined before including this file,
    to the width and qualifier of ucd_blk_t, respectively.

*/


#ifndef    UCD_BLK_WIDTH
#   define UCD_BLK_WIDTH 8
#   define UCD_BLK_TYPE unsigned char 
#endif

typedef UCD_BLK_TYPE ucd_blk_t;
#define UCD_BLK_MAX (((1<<UCD_BLK_WIDTH-1)-1)<<1+1)

// Plane 0: Basic Multilingual Plane
enum UCD_BMP_BLOCKS {
    nb_blk,
    ascii_blk=nb_blk+1,
    latin_1_blk,
    latin_a_blk,
    latin_b_blk,
    ipa_blk,
    spacing_modifier_blk,
    cmb_diacritical_blk,
    greek_and_coptic_blk,
    cyrillic_blk,
    cyrillic_1_blk,
    armenian_blk,
    hebrew_blk,
    arabic_blk,
    syriac_blk,
    arabic_1_blk,
    thaana_blk,
    nko_blk,
    samaritan_blk,
    mandaic_blk,
    syriac_1_blk,
    arabic_b_blk,
    arabic_a_blk,
    devanagari_blk,
    bengali_blk,
    gurmukhi_blk,
    gujarati_blk,
    oriya_blk,
    tamil_blk,
    telugu_blk,
    kannada_blk,
    malayalam_blk,
    sinhala_blk,
    thai_blk,
    lao_blk,
    tibetan_blk,
    myanmar_blk,
    georgian_blk,
    hangul_jamo_blk,
    ethiopic_blk,
    ethiopic_1_blk,
    cherokee_blk,
    ucas_blk,
    ogham_blk,
    runic_blk,
    tagalog_blk,
    hanunoo_blk,
    buhid_blk,
    tagbanwa_blk,
    khmer_blk,
    mongolian_blk,
    ucas_x_blk, 
    limbu_blk,
    tai_le_blk,
    new_tai_lue_blk,
    khmer_symbol_blk,
    buginese_blk,
    tai_tham_blk,
    cmb_diacritical_x_blk,
    balinese_blk,
    sundanese_blk,
    batak_blk,
    lepcha_blk,
    ol_chiki_blk,
    cyrillic_c_blk,
    georgian_x_blk,
    sundanese_1_blk,
    vedic_x_blk,
    phonetics_blk,
    phonetics_x_blk,
    cmb_diacritical_1_blk,
    latin_x_blk,
    greek_x_blk,
    punct_blk,
    super_and_subscript_blk,
    currency_blk,
    cmb_diacriticals_for_symbol_blk,
    letterlike_blk,
    number_forms_blk,
    arrows_blk,
    math_operator_blk,
    misc_tech_blk,
    cntrl_pic_blk,
    ocr_blk,
    enclosed_alnum_blk,
    box_drawing_blk,
    block_elements_blk,
    geometric_shape_blk,
    misc_symbol_blk,
    dingbat_blk,
    misc_math_symbol_a_blk,
    sup_arrow_a_blk,
    braille_blk,
    sup_arrow_b_blk,
    misc_math_symbol_b_blk,
    sup_math_operator_blk,
    misc_symbol_and_arrow_blk,
    glagolitic_blk,
    latin_c_blk,
    coptic_blk,
    georgian_1_blk,
    tifinagh_blk,
    ethiopic_x_blk,
    cyrillic_a_blk,
    sup_punct_blk,
    cjk_radical_1_blk,
    kangxi_radical_blk,
    idc_blk,
    cjk_symbol_and_punct_blk,
    hiragana_blk,
    katakana_blk,
    bopomofo_blk,
    compat_jamo_blk,
    kanbun_blk,
    bopomofo_x_blk,
    cjk_strokes_blk,
    katakana_phonetics_blk,
    enclosed_cjk_blk,
    cjk_compat_ideographs_blk,
    cjk_a_blk,
    yijing_hexagram_blk,
    cjk_blk,
    yi_syllables_blk,
    yi_radical_blk,
    lisu_blk,
    vai_blk,
    cyrillic_b_blk,
    bamum_blk,
    modifier_tone_letters_blk,
    latin_d_blk,
    syloti_nagri_blk,
    indic_number_fs_blk,
    phags_pa_blk,
    saurashtra_blk,
    devanagari_x_blk,
    kayah_li_blk,
    rejang_blk,
    hangul_jamo_a_blk,
    javanese_blk,
    myanmar_b_blk,
    cham_blk,
    myanmar_a_blk,
    tai_viet_blk,
    meetei_mayek_x_blk,
    ethiopic_a_blk,
    latin_e_blk,
    cherokee_1_blk,
    meetei_mayek_blk,
    hangul_syllables_blk,
    hangul_jamo_b_blk,
    high_surrogates_blk,
    high_pu_surrogates_blk,
    low_surrogates_blk,
    pua_blk,
    cjk_compat_ideographs_1_blk,
    cjk_compat_blk,
    alpha_pf_blk,
    arabic_pf_a_blk,
    vs_blk,
    vertical_fs_blk,
    cmb_half_marks_blk,
    cjk_cfs_blk,
    small_fs_blk,
    arabic_pf_b_blk,
    hwfwf_blk,
    specials_blk,
};

enum UCD_SMP_BLOCKS {
    // Plane 1: Supplementary Multilingual Plane
    linear_b_syllabary_blk=nb_blk+1,
    linear_b_ideogram_blk,
    aegean_nbs_blk,
    ancient_greek_nbs_blk,
    ancient_symbol_blk,
    phaistos_disc_blk,
    lycian_blk,
    carian_blk,
    coptic_epact_nbs_blk,
    old_italic_blk,
    gothic_blk,
    old_permic_blk,
    ugaritic_blk,
    old_persian_blk,
    deseret_blk,
    shavian_blk,
    osmanya_blk,
    osage_blk,
    elbasan_blk,
    caucasian_albanian_blk,
    linear_a_blk,
    cypriot_syllabary_blk,
    imperial_aramaic_blk,
    palmyrene_blk,
    nabataean_blk,
    hatran_blk,
    phoenician_blk,
    lydian_blk,
    meroitic_cursive_blk,
    meroitic_hieroglyph_blk,
    kharoshthi_blk,
    old_south_arabian_blk,
    old_north_arabian_blk,
    manichaean_blk,
    avestan_blk,
    inscriptional_parthian_blk,
    inscriptional_pahlavi_blk,
    psalter_pahlavi_blk,
    old_turkic_blk,
    old_hungarian_blk,
    hanifi_rohingya_blk,
    rumi_numeral_blk,
    yezidi_blk,
    old_sogdian_blk,
    sogdian_blk,
    chorasmian_blk,
    elymaic_blk,
    brahmi_blk,
    kaithi_blk,
    sora_sompeng_blk,
    chakma_blk,
    mahajani_blk,
    sharada_blk,
    sinhala_archaic_nbs_blk,
    khojki_blk,
    multani_blk,
    khudawadi_blk,
    grantha_blk,
    newa_blk,
    tirhuta_blk,
    siddham_blk,
    modi_blk,
    mongolian_1_blk,
    takri_blk,
    ahom_blk,
    dogra_blk,
    warang_citi_blk,
    dives_akuru_blk,
    nandinagari_blk,
    zanabazar_sq_blk,
    soyombo_blk,
    pau_cin_hau_blk,
    bhaiksuki_blk,
    marchen_blk,
    masaram_gondi_blk,
    gunjala_gondi_blk,
    makasar_blk,
    lisu_1_blk,
    tamil_1_blk,
    cuneiform_blk,
    cuneiform_nbs_and_punct_blk,
    early_dynastic_cuneiform_blk,
    egyptian_hieroglyph_blk,
    egyptian_hieroglyph_format_cntrl_blk,
    anatolian_hieroglyph_blk,
    bamum_1_blk,
    mro_blk,
    bassa_vah_blk,
    pahawh_hmong_blk,
    medefaidrin_blk,
    miao_blk,
    ideographic_symbol_and_punct_blk,
    tangut_blk,
    tangut_components_blk,
    khitan_small_script_blk,
    tangut_1_blk,
    kana_1_blk,
    kana_a_blk,
    small_kana_x_blk,
    nushu_blk,
    duployan_blk,
    shorthand_format_cntrl_blk,
    byzantine_musical_symbol_blk,
    musical_symbol_blk,
    ancient_greek_musical_notation_blk,
    mayan_numeral_blk,
    tai_xuan_jing_symbol_blk,
    counting_rods_blk,
    math_alnum_blk,
    sutton_signwriting_blk,
    glagolitic_1_blk,
    nyiakeng_puachue_hmong_blk,
    wancho_blk,
    mende_kikakui_blk,
    adlam_blk,
    indic_siyaq_nbs_blk,
    ottoman_siyaq_nbs_blk,
    arabic_math_symbol_blk,
    mahjong_tile_blk,
    domino_tile_blk,
    playing_card_blk,
    enclosed_alnum_1_blk,
    enclosed_ideographic_1_blk,
    misc_pictographs_blk,
    emoticon_blk,
    ornamental_dingbat_blk,
    transport_and_map_blk,
    alchemy_blk,
    geometric_shape_x_blk,
    sup_arrow_c_blk,
    sup_symbol_and_pictographs_blk,
    chess_blk,
    symbol_and_pictographs_a_blk,
    legacy_computing_blk,
};

enum UCD_SIP_BLOCKS {
    // Plane 2: Supplementary Ideographic Plane
    cjk_b_blk=nb_blk+1,
    cjk_c_blk,
    cjk_d_blk, 
    cjk_e_blk, 
    cjk_f_blk,
    cjk_compat_ideographs_1_blk,
};

enum UCD_TIP_BLOCKS {
    // Plane 3: Tertiary Ideographic Plane
    cjk_g_blk=nb_blk+1,
    cjk_h_blk,
};

enum UCD_SSP_BLOCKS {
    // Plane 14: Supplementary Special-purpose Plane
    tags_blk=nb_blk+1,
    vs_1_blk,
};

enum UCD_PUA_BLOCKS {
    // Plane 15: Supplementary Private Use Area-A
    spua_a_blk=nb_blk+1,
};

enum UCD_PUB_BLOCKS {
    // Plane 16: Supplementary Private Use Area-B
    spua_b_blk=1+nb_blk,
};

struct ucd_blk_range {
    unsigned short  start;
    unsigned short  count;
    ucd_blk_t       value;
};

typedef ucd_blk_t ucd_blk_map_t[4096];

union ucd_blk {
    struct {
        ucd_blk_t *bmp;
        ucd_blk_t *smp;
        ucd_blk_t *sip;
        ucd_blk_t *tip;
        ucd_blk_t *_p4;
        ucd_blk_t *_p5;
        ucd_blk_t *_p6;
        ucd_blk_t *_p7;
        ucd_blk_t *_p8;
        ucd_blk_t *_p9;
        ucd_blk_t *_pa;
        ucd_blk_t *_pb;
        ucd_blk_t *_pc;
        ucd_blk_t *_pd;
        ucd_blk_t *ssp;
        ucd_blk_t *pua;
        ucd_blk_t *pub;
    };
    ucd_blk_t *by_plane[17];
};

extern union ucd_blk ucd_blk ={0};

static inline void
ucd_blk_ranges_INIT_BY_PLANE(struct ucd_blk_range *r, ucd_plane_t i) {
    ucd_blk_map_t *tab = ucd_blk.by_plane[i];
    if (tab == NULL) {
        tab = (ucd_blk.by_plane[i]=malloc(sizeof(ucd_blk_map_t)));
    }
    for (int b=0; r[b]; b++) {
        struct ucd_blk_range *range = r[b];
        const ucd_blk_t v = range->value
        unsigned a = range->start*16;
        unsigned b = range->count*a;
        do {tab[a] = v;} while (++a < b);
    }
}

static inline void
ucd_INIT_BMP_BLOCKS(void) {
    (ucd_blk_ranges_INIT_BY_PLANE)
    (UCD_BMP, (struct ucd_blk_range []){
        {0x000,  010, ascii_blk},
        {0x008,  010, latin_1_blk},
        {0x010,  010, latin_a_blk},
        {0x018,  015, latin_b_blk},
        {0x025,  006, ipa_blk},
        {0x02b,  005, spacing_modifier_blk},
        {0x030,  007, cmb_diacritical_blk},
        {0x037,  011, greek_and_coptic_blk},
        {0x040,  020, cyrillic_blk},
        {0x050,  003, cyrillic_1_blk},
        {0x053,  006, armenian_blk},
        {0x059,  007, hebrew_blk},
        {0x060,  020, arabic_blk},
        {0x070,  005, syriac_blk},
        {0x075,  003, arabic_1_blk},
        {0x078,  004, thaana_blk},
        {0x07c,  004, nko_blk},
        {0x080,  004, samaratin_blk},
        {0x084,  002, mandaic_blk},
        {0x086,  004, syriac_1_blk},
        {0x08a,  006, arabic_a_blk},
        {0x090,  010, devanagari_blk},
        {0x098,  010, bengali_blk},
        {0x0a0,  010, gurmukhi_blk},
        {0x0a8,  010, gujarati_blk},
        {0x0b0,  010, oriya_blk},
        {0x0b8,  010, tamil_blk},
        {0x0c0,  010, telugu_blk},
        {0x0c8,  010, kannada_blk},
        {0x0D0,  010, malayalam_blk},
        {0x0D8,  010, sinhala_blk},
        {0x0E0,  010, thai_blk},
        {0x0E8,  010, lao_blk},
        {0x0F0,  020, tibetan_blk},
        {0x100,  012, myanmar_blk},
        {0x10A,  006, georgian_blk},
        {0x110,  020, hangul_jamo_blk},
        {0x120,  030, ethiopic_blk},
        {0x138,  002, ethiopic_1_blk},
        {0x13A,  006, cherokee_blk},
        {0x140,  050, ucas_blk},
        {0x168,  002, ogham_blk},
        {0x16A,  006, runic_blk},
        {0x170,  002, tagalog_blk},
        {0x172,  002, hanunoo_blk},
        {0x174,  002, buhid_blk},
        {0x176,  002, tagbanwa_blk},
        {0x178,  010, khmer_blk},
        {0x180,  012, mongolian_blk},
        {0x18B,  005, ucas_x_blk},
        {0x190,  005, limbu_blk},
        {0x195,  003, tai_le_blk},
        {0x198,  006, new_tai_lue_blk},
        {0x19E,  002, khmer_symbol_blk},
        {0x1A0,  002, buginese_blk},
        {0x1A2,  012, tai_tham_blk},
        {0x1AB,  005, cmb_diacritical_x_blk},
        {0x1b0,  010, balinese_blk},
        {0x1b8,  040, sudanese_blk},
        {0x1bc,  004, batak_blk},
        {0x1c0,  005, lepcha_blk},
        {0x1c5,  003, ol_chiki_blk},
        {0x1c8,  001, cyrillic_c_blk},
        {0x1c9,  003, georgian_x_blk},
        {0x1cc,  001, sudanese_1_blk},
        {0x1cd,  003, vedic_x_blk},
        {0x1d0,  010, phonetics_blk},
        {0x1d8,  004, phonetics_x_blk},
        {0x1dc,  004, cmb_diacritical_1_blk},
        {0x1e0,  020, latin_x_blk},
        {0x1f0,  020, greek_x_blk},
        {0x200,  007, general_punct_blk},
        {0x207,  003, super_and_subscript_blk},
        {0x20a,  003, currency_blk},
        {0x20d,  003, cmb_diacritical_for_symbol_blk},
        {0x210,  005, letterlike_blk},
        {0x215,  004, number_forms_blk},
        {0x219,  007, arrows_blk},
        {0x220,  020, math_operator_blk},
        {0x230,  020, misc_tech_blk},
        {0x240,  004, cntrl_pic_blk},
        {0x244,  002, ocr_blk},
        {0x246,  012, enclosed_alnum_blk},
        {0x250,  010, box_drawing_blk},
        {0x258,  002, block_elements_blk},
        {0x25a,  006, geometric_shape_blk},
        {0x260,  020, misc_symbol_blk},
        {0x270,  014, dingbat_blk},
        {0x27c,  003, misc_math_symbol_a_blk},
        {0x27f,  001, sup_arrow_a_blk},
        {0x280,  020, braille_blk},
        {0x290,  010, sup_arrow_b_blk},
        {0x298,  010, misc_math_symbol_b_blk},
        {0x2a0,  020, sup_math_operator_blk},
        {0x2b0,  020, misc_symbol_and_arrow_blk},
        {0x2c0,  006, glagolitic_blk},
        {0x2c6,  002, latin_c_blk},
        {0x2c8,  010, coptic_blk},
        {0x2d0,  003, georgian_1_blk},
        {0x2d3,  005, tifinagh_blk},
        {0x2d8,  006, ethiopic_x_blk},
        {0x2de,  002, cyrillic_a_blk},
        {0x2e0,  010, sup_punct_blk},
        {0x2e8,  010, cjk_radical_1_blk},
        {0x2f0,  016, kangxi_radical_blk},
        {0x2ff,  001, ids_blk},
        {0x300,  004, cjk_symbol_and_punct_blk},
        {0x304,  006, hiragana_blk},
        {0x30a,  006, katakana_blk},
        {0x310,  003, bopomofo_blk},
        {0x313,  006, hangul_compat_jamo_blk},
        {0x319,  001, kanbun_blk},
        {0x31a,  002, bopomofo_x_blk},
        {0x31c,  003, cjk_strokes_blk},
        {0x31f,  001, katakana_phonetics_blk},
        {0x320,  020, cjk_letters_and_months_blk},
        {0x330,  020, cjk_compat_blk},
        {0x340, 0634, cjk_a_blk},
        {0x4dc,  004, yijing_hexagram_blk},
        {0x4e0,02440, cjk_blk},
        {0xa00, 0111, yi_syllables_blk},
        {0xa49,  004, yi_radical_blk},
        {0xa4d,  003, lisu_blk},
        {0xa50,  024, vai_blk},
        {0xa64,  006, cyrillic_b_blk},
        {0xa6a,  006, bamum_blk},
        {0xa70,  002, modifier_tone_letters_blk},
        {0xa72,  016, latin_d_blk},
        {0xa80,  003, syloti_nagri_blk},
        {0xa83,  001, common_indic_number_fs_blk},
        {0xa84,  004, phags_pa_blk},
        {0xa88,  006, saurashtra_blk},
        {0xa8e,  002, devanagari_x_blk},
        {0xa90,  003, kayah_li_blk},
        {0xa93,  003, rejang_blk},
        {0xa96,  002, hangul_jamo_a_blk},
        {0xa98,  006, javanese_blk},
        {0xa9e,  002, myanmar_b_blk},
        {0xaa0,  006, cham_blk},
        {0xaa6,  002, myanmar_a_blk},
        {0xaa8,  006, tai_viet_blk},
        {0xaae,  002, meetei_mayek_x_blk},
        {0xab0,  003, ethiopic_a_blk},
        {0xab3,  004, latin_e_blk},
        {0xab7,  005, cherokee_1_blk},
        {0xabc,  004, meetei_mayek_blk},
        {0xac0,01273, hangul_syllables_blk},
        {0xd7b,  005, hangul_jamo_b_blk},
        {0xd80,  070, high_surrogates_blk},
        {0xdb8,  010, high_pu_surrogates_blk},
        {0xdc0, 0100, low_surrogates_blk},
        {0xe00, 0620, pua_blk},
        {0xf90,  040, cjk_compat_ideographs_blk},
        {0xfb0,  005, alpha_pf_blk},
        {0xfb5,  053, arabic_pf_a_blk},
        {0xfe0,  001, vs_blk},
        {0xfe1,  001, vertical_forms_blk},
        {0xfe2,  001, cmb_half_marks_blk},
        {0xfe3,  002, cjk_cf_blk},
        {0xfe5,  002, small_variants_blk},
        {0xfe7,  011, arabic_pf_b_blk},
        {0xff0,  017, hwfwf_blk},
        {0xfff,  001, specials_blk},
        {0}
    });
}

static inline void
ucd_INIT_SMP_BLOCKS(void) {
    (ucd_blk_ranges_INIT_BY_PLANE)
    (UCD_SMP, (struct ucd_blk_range []){
        {0x000,  010, linear_b_syllabary_blk}, 
        {0x008,  010, linear_b_ideogram_blk}, 
        {0x010,  010, aegean_nbs_blk},
        {0x014,  004, ancient_greek_nbs_blk},
        {0x019,  004, ancient_symbol_blk}, 
        {0x01D,  003, phaistos_disc_blk}, 
        {0x028,  002, lycian_blk}, //"Lycian",
        {0x02a,  004, carian_blk}, //"Carian",
        {0x02e,  002, coptic_epact_nbs_blk}, //"Coptic Epact Numbers",
        {0x030,  003, old_italic_blk}, //"Old Italic",
        {0x033,  002, gothic_blk}, //"Gothic",
        {0x035,  003, old_permic_blk}, //"Old Permic",
        {0x038,  002, ugaritic_blk}, //"Ugaritic",
        {0x03a,  004, old_persian_blk}, //"Old Persian",
        {0x040,  005, deseret_blk}, //"Deseret",
        {0x045,  003, shavian_blk}, //"Shavian",
        {0x048,  003, osmanya_blk}, //"Osmanya",
        {0x04b,  005, osage_blk}, //"Osage",
        {0x050,  003, elbasan_blk}, //"Elbasan",
        {0x053,  004, caucasian_blk}, //"Caucasian Albanian",
        {0x060,  030, linear_a_blk}, //"Linear A",
        {0x080,  004, cypriot_syllabary_blk}, //"Cypriot Syllabary",
        {0x084,  002, imperial_aramaic_blk}, //"Imperial Aramaic",
        {0x086,  002, palmyrene_blk}, //"Palmyrene",
        {0x088,  003, nabataean_blk}, //"Nabataean",
        {0x08e,  002, hatran_blk}, //"Hatran",
        {0x090,  002, phoenician_blk}, //"Phoenician",
        {0x092,  002, lydian_blk}, //"Lydian",
        {0x098,  002, meroitic_hieroglyph_blk}, //"Meroitic Hieroglyph",
        {0x09a,  006, meroitic_cursive_blk}, //"Meroitic Cursive",
        {0x0a0,  006, kharoshthi_blk}, //"Kharoshthi",
        {0x0a6,  002, old_south_arabian_blk}, //"Old South Arabian",
        {0x0a8,  002, old_north_arabian_blk}, //"Old North Arabian",
        {0x0ac,  004, manichaean_blk}, //"Manichaean",
        {0x0b0,  004, avestan_blk}, //"Avestan",
        {0x0b4,  002, inscriptional_parthian_blk}, //"Inscriptional Parthian",
        {0x0b6,  002, inscriptional_pahlavi_blk}, //"Inscriptional Pahlavi",
        {0x0b8,  003, psalter_pahlavi_blk}, //"Psalter Pahlavi",
        {0x0c0,  005, old_turkic_blk}, //"Old Turkic",
        {0x0c8,  010, old_hungarian_blk}, //"Old Hungarian",
        {0x0d0,  004, hanifi_rohingya_blk}, //"Hanifi Rohingya",
        {0x0e6,  002, rumi_numeral_blk}, //"Rumi Numeral Symbols",
        {0x0e8,  004, yezidi_blk}, //"Yezidi",
        {0x0f0,  003, old_sogdian_blk}, //"Old Sogdian",
        {0x0f3,  004, sogdian_blk}, //"Sogdian",
        {0x0fb,  003, chorasmian_blk}, //"Chorasmian",
        {0x0fe,  002, elymaic_blk}, //"Elymaic",
        {0x100,  010, brami_blk}, //"Brahmi",
        {0x108,  005, kaithi_blk}, //"Kaithi",
        {0x10d,  003, sora_sompeng_blk}, //"Sora Sompeng",
        {0x110,  005, chakma_blk}, //"Chakma",
        {0x115,  003, mahajani_blk}, //"Mahajani",
        {0x118,  006, sharada_blk}, //"Sharada",
        {0x11e,  002, sinhala_archaic_nbs_blk}, //"Sinhala Archaic Numbers",
        {0x120,  005, khojki_blk}, //"Khojki",
        {0x128,  003, multani_blk}, //"Multani",
        {0x12b,  005, khudawadi_blk}, //"Khudawadi",
        {0x130,  010, grantha_blk}, //"Grantha",
        {0x140,  010, newa_blk}, //"Newa",
        {0x148,  006, tirhuta_blk}, //"Tirhuta",
        {0x158,  010, siddham_blk}, //"Siddham",
        {0x160,  006, modi_blk}, //"Modi",
        {0x166,  002, mongolian_1_blk}, //"Mongolian Supplement",
        {0x168,  005, takri}, //"Takri",
        {0x170,  004, ahom_blk}, //"Ahom",
        {0x180,  005, dogra_blk}, //"Dogra",
        {0x18a,  006, warang_citi_blk}, //"Warang Citi",
        {0x190,  006, dives_akuru_blk}, //"Dives Akuru",
        {0x19a,  006, nandinagari_blk}, //"Nandinagari",
        {0x1a0,  005, zanabazar_sq_blk}, //"Zanabazar Square",
        {0x1a5,  006, soyombo_blk}, //"Soyombo",
        {0x1ac,  004, pau_cin_hau_blk}, //"Pau Cin Hau",
        {0x1c0,  007, bhaiksuki_blk}, //"Bhaiksuki",
        {0x1c7,  005, marchen_blk}, //"Marchen",
        {0x1d0,  006, masaram_gondi_blk}, //"Masaram Gondi",
        {0x1d6,  005, gunjala_gondi_blk}, //"Gunjala Gondi",
        {0x1ee,  002, makasar_blk}, //"Makasar",
        {0x1fb,  001, lisu_1_blk}, //"Lisu Supplement",
        {0x1fc,  004, tamil_1_blk}, //"Tamil Supplement",
        {0x200, 0100, cuneiform_blk}, //"Cuneiform",
        {0x240,  010, cuneiform_nbs_and_punct_blk}, //"Cuneiform Numbers and Punctuation",
        {0x248,  015, early_dynastic_cuneiform_blk}, //"Early Dynastic Cuneiform",
        {0x300, 0103, egyptian_hieroglyph_blk }, //"Egyptian Hieroglyphs",
        {0x343,  001, egyptian_hieroglyph_format_cntrl_blk}, //"Egyptian Hieroglyph Format Controls",
        {0x440,  050, anatolian_hieroglyph_blk}, //"Anatolian Hieroglyphs",
        {0x680,  044, bamum_1_blk}, //"Bamum Supplement",
        {0x6a4,  003, mro_blk}, //"Mro",
        {0x6ad,  003, bassa_vah_blk}, //"Bassa Vah",
        {0x6b0,  011, pahawh_hmong_blk}, //"Pahawh Hmong",
        {0x6e4,  006, medefaidrin_blk}, //"Medefaidrin",
        {0x6f0,  012, miao_blk}, //"Miao",
        {0x6fe,  002, ideographic_symbol_and_punct_blk}, //"Ideographic Symbols and Punctuation",
        {0x700, 0600, tangut_blk}, //"Tangut",
        {0x880,  060, tangut_components_blk}, //"Tangut Components",
        {0x8b0,  040, khitan_small_script_blk}, //"Khitan Small Script",
        {0x8d0,  011, tangut_1_blk}, //"Tangut Supplement",
        {0xb00,  020, kana_1_blk}, //"Kana Supplement",
        {0xb10,  003, kana_a_blk}, //"Kana Extended-A",
        {0xb13,  004, small_kana_x_blk}, //"Small Kana Extension",
        {0xb17,  031, nushu_blk}, //"Nushu",
        {0xbc0,  012, duployan_blk}, //"Duployan",
        {0xbca,  001, shorthand_fmt_blk}, //"Shorthand Format Controls",
        {0xd00,  020, byzantine_musical_symbol_blk}, //"Byzantine Musical Symbols",
        {0xd10,  020, musical_symbol_blk}, //"Musical Symbols",
        {0xd20,  005, ancient_greek_musical_notation_blk}, //"Ancient Greek Musical Notation",
        {0xd2e,  002, mayan_numeral_blk}, //"Mayan Numerals",
        {0xd30,  006, tai_xuan_jing_symbol_blk}, //"Tai Xuan Jing Symbols",
        {0xd36,  002, counting_rods_blk}, //"Counting Rod Numerals",
        /*
        +0x1a*0 = MATHEMATICAL BOLD SMALL A
        0x1d400 = MATHEMATICAL BOLD CAPITAL A 
        +0x34*1 = MATHEMATICAL ITALIC CAPITAL A 
        +0x34*2 = MATHEMATICAL BOLD ITALIC CAPITAL A
        +0x34*3 = MATHEMATICAL SCRIPT CAPITAL A 
        +0x34*4 = MATHEMATICAL BOLD SCRIPT CAPITAL A 
        +0x34*5 = MATHEMATICAL FRAKTUR CAPITAL A 
        +0x34*6 = MATHEMATICAL DOUBLE-STRUCK CAPITAL A 
        +0x34*7 = MATHEMATICAL BOLD FRAKTUR CAPITAL A 
        +0x34*8 = MATHEMATICAL SANS-SERIF CAPITAL A 
        +0x34*9 = MATHEMATICAL SANS-SERIF BOLD CAPITAL A 
        +0x34*10= MATHEMATICAL SANS-SERIF ITALIC CAPITAL A 
        +0x34*11= MATHEMATICAL SANS-SERIF BOLD ITALIC CAPITAL A 
        +0x34*12= MATHEMATICAL MONOSPACE CAPITAL A 
        0x1d7ce = MATHEMATICAL BOLD DIGIT ZERO 
                  MATHEMATICAL DOUBLE-STRUCK DIGIT ZERO 
                  MATHEMATICAL SANS-SERIF DIGIT ZERO
                  MATHEMATICAL SANS-SERIF BOLD DIGIT ZERO 
        0x1d7f6   MATHEMATICAL MONOSPACE DIGIT ZERO 
        
        */
        {0xd40, 0100, math_alnum_blk}, //"Mathematical Alphanumeric Symbols",
        {0xd80,  053, sutton_signwriting_blk}, //"Sutton SignWriting",
        {0xe00,   03, glagolitic_1_blk}, //"Glagolitic Supplement",
        {0xe10,   05, nyiakeng_puache_hmong_blk}, //"Nyiakeng Puachue Hmong",
        {0xe2c,   04, wancho_blk}, //"Wancho",
        {0xe80,  016, mende_kikakui_blk}, //"Mende Kikakui",
        {0xe90,   06, adlam_blk}, //"Adlam",
        {0xec7,   05, indic_siyaq_nbs_blk}, //"Indic Siyaq Numbers",
        {0xed0,   05, ottoman_siyaq_nbs_blk}, //"Ottoman Siyaq Numbers",
        {0xee0,  020, arabic_math_alnum_blk}, //"Arabic Mathematical Alphabetic Symbols",
        {0xf00,   03, mahjong_tile_blk}, //"Mahjong Tiles",
        {0xf03,   07, domino_tile_blk}, //"Domino Tiles",
        {0xf0a,   06, playing_card_blk}, //"Playing Cards",
        {0xf10,  020, enclosed_alnum_1_blk}, //"Enclosed Alphanumeric Supplement",
        {0xf20,  020, enclosed_ideographic_1_blk}, //"Enclosed Ideographic Supplement",
        {0xf30,  060, misc_symbol_and_pictographs_blk}, //"Miscellaneous Symbols and Pictographs",
        {0xf60,   05, emoticon_blk}, //"Emoticons",
        {0xf65,   03, ornamental_dingbat_blk}, //"Ornamental Dingbats",
        {0xf68,  010, transport_and_map_blk}, //"Transport and Map Symbols",
        {0xf70,  010, alchemy_blk},
        {0xf78,  010, geometric_shape_x_blk}, //"Geometric Shapes Extended",
        {0xf80,  020, sup_arrow_c_blk}, //"Supplemental Arrows-C",
        {0xF90,  020, sup_symbol_and_pictographs_blk},
        {0xFA0,  007, chess_blk},
        {0xFA7,  011, symbol_and_pictographs_a_blk},
        {0xFB0,  020, legacy_computing_blk},
        {0}
    });
}

static inline void
ucd_INIT_SIP_BLOCKS(void) {
    (ucd_blk_ranges_INIT_BY_PLANE)
    (UCD_SIP, (struct ucd_blk_range []){
        {0x000, 05156, cjk_b_blk},
        {0xA70, 00404, cjk_c_blk}, 
        {0xB74, 00016, cjk_d_blk}, 
        {0xB82, 00551, cjk_e_blk}, 
        {0xCEB, 00724, cjk_f_blk}, 
        {0xF80, 00042, cjk_compat_ideographs_1_blk},
        {0}
    });
}

static inline void 
ucd_INIT_TIP_BLOCKS(void) {
    (ucd_blk_ranges_INIT_BY_PLANE)
    (UCD_TIP, (struct ucd_blk_range []){
        {0x000, 0465, cjk_g_blk},
        {0x135, 0406, cjk_h_blk},
        {0}
    });
}

static inline void 
ucd_INIT_SSP_BLOCKS(void) {
    (ucd_blk_ranges_INIT_BY_PLANE)
    (UCD_SSP, (struct ucd_blk_range []){
        {0x000, 010, tags_blk}, 
        {0x010, 017, vs_1_blk},
        {0}
    });
}

static inline void 
ucd_INIT_PUA_BLOCKS(void) {
    ucd_init_blk_property((struct ucd_blk_range []){
        {0x0000, 010000, pua_blk},
        {0}
    }, UCD_PUA);
}

static inline void 
ucd_INIT_PUB_BLOCKS(void) {
    ucd_init_blk_property((struct ucd_blk_range []){
        {0x0000, 010000, pub_blk},
        {0}
    }, UCD_PUB);
}
