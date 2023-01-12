/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UCD_SC_H
#define UCD_SC_H

/* Scripts.txt

[0] = "%x..%x;%[^ ] #"

A script's enum value matches the corresponding ISO 15924 code.

# @MISSING: 0000..10FFFF; UNKNOWN
0000..001F    ; Common #
0041..005A    ; Latin #
0370..0373    ; Greek #
0400..0481    ; Cyrillic #

0b ---- ---- ---- 1111 SC_DIR 
0b ---- ---- --11 ---- SC_STATUS
0b ---- ---- -1-- ---- SC_HISTORIC
0b ---- ---- 1--- ---- SC_DESIGNED
0b ---- ---1 ---- ---- SC_ESOTERIC

*/

/*
The following flags are not part of any ISO standard.

SC_DIR:4
    AMB_SC is for mixed directional scripts
    LTR_SC is for dextrosinistral scripts, e.g. Arabic, Hebrew
    RTL_SC is for sinistrodextral scripts, e.g. Latin, Greekw
    LTB_SC is for vertical ttb-ltr scripts, e.g. Mongolian
    RTB_SC is for vertical ttb-rtl scripts, e.g. Chorasmian
    LBT_SC is for vertical btt-ltr scripts, e.g. Hanunoo, Ogham
    RTB_SC would be for vertical btt-rtl scripts
    ALT_SC would be for boustrophedon scripts 

SC_STATUS:2

    SC_APPROVED scripts appear in UCD

    SC_PROPOSED have ISO 15924 codes but aren't in UCD

    SC_REJECTED have ISO 15924 codes but will never be in UCD

SC_CLASS:*

    HISTORIC_SC scripts aren't a component of a modern lang

    DESIGNED_SC scripts were... designed. e.g. Cherokee or 
    Klingon

    ESOTERIC_SC scripts are the writing system of "esoteric" 
    languages. For now this isn't used.

""
*/
#define BF__X(m, __x) m##__x

#define BF__I(s, n) s##_##n

#define BF__M(s) (0xFFFFFFFFU>>(32-s##__W))

#define BF_M(s, n) (s##__M>>(s##__W-s##_##n##__W))
#define BF_L(s, p) (s##_##p##__L+ s##_##p##__W)
#define BF_B(s, n) (s##_##n##__M<<s##_##n##__L)

#define SC__W 16
#define SC__L 0
#define SC__M BF__M(SC)

#define SC_DIR__W 4
#define SC_DIR__L 0
#define SC_DIR__M BF_M(SC, DIR)
#define SC_DIR    BF_B(SC, DIR)

#define AMB_SC 0
#define LTR_SC 1
#define RTL_SC 2
#define LTB_SC 3
#define RTB_SC 4
#define LBT_SC 5
#define RTB_SC 6
#define ALT_SC 7

#define SC_STATUS__W 2
#define SC_STATUS__L BF_L(SC, DIR)
#define SC_STATUS__M BF_M(SC, STATUS)
#define SC_STATUS    BF_B(SC, STATUS)

#define OFFICIAL_SC (0<<SC_STATUS__L)
#define PROPOSED_SC (1<<SC_STATUS__L)
#define REJECTED_SC (2<<SC_STATUS__L)

#define SC_CLASS__W 3
#define SC_CLASS__L BF_L(SC, STATUS)
#define SC_CLASS__M BF_M(SC, CLASS)
#define SC_CLASS    BF_B(SC, CLASS)

#define HISTORIC_SC (1<<(SC_CLASS__L+0))
#define DESIGNED_SC (1<<(SC_CLASS__L+1))
#define ESOTERIC_SC (1<<(SC_CLASS__L+2))

typedef short ucd_sc_t;
typedef unsigned short ucd_sc_flags_t;
typedef signed char ucd_sc_dir_t;
typedef signed char ucd_sc_status_t;
typedef signed char ucd_sc_class_t;

struct ucd_sc {
    const char *sc_iso_name;// ISO 15924 name
    const char *sc_ucd_name;// as it appears in Scripts.txt
    const char sc_age[6];// {'1', '5', '.', '9', '9', 0}
    unsigned short sc_flags;
};

enum {
    sc_iso_name,
    sc_ucd_name,
    sc_
}
extern struct ucd_sc *UCD_SCRIPT;

static inline const char *
ucd_sc_GET_ISO_NAME(ucd_sc_t sc) {
    return UCD_SCRIPT[sc].sc_iso_name;
}

static inline const char *
ucd_sc_GET_UCD_NAME(ucd_sc_t sc) {
    return UCD_SCRIPT[sc].sc_ucd_name;
}

static inline const char *
ucd_sc_GET_AGE(ucd_sc_t sc) {
    return UCD_SCRIPT[sc].sc_age;
}

static inline ucd_sc_flags_t
ucd_sc_GET_FLAGS(ucd_sc_t sc) {
    return UCD_SCRIPT[sc].flags;
}

static inline ucd_sc_status_t
ucd_sc_GET_STATUS(ucd_sc_t sc) {
    return ucd_sc_GET_FLAGS(sc)&SC_STATUS;
}

static inline ucd_sc_class_t
ucd_sc_GET_CLASS(ucd_sc_t sc) {
    return ucd_sc_GET_FLAGS(sc)&SC_CLASS;
}

static inline ucd_sc_dir_t
ucd_sc_GET_DIR(ucd_sc_t sc) {
    return sc->sc_flags&SC_DIR;
}

/* [000..099] Hieroglyphical; cuneiform */
#define PCUN_SC  15 // *** proto-cuneiform
#define PELM_SC  16 // **** proto-elamite
#define XSUX_SC  20 // 5.1 CUNEIFORM
#define XPEO_SC  30 // OLD_PERSIAN
#define UGAR_SC  40 // UGARITIC
#define EGYP_SC  50 // egyptian_hieroglyphs
#define EGYH_SC  60 // *** Egyptian hieratic
#define EGYD_SC  70 // *** Egyptian demotic
#define HLUW_SC  80 // ANATOLIAN_HIEROGLYPHS
#define NKDB_SC  85 // *** Dongba
#define MAYA_SC  90 // *** Mayan
#define SGNW_SC  95 // SIGNWRITING
/* [100..199] Alphabetical; right-to-left */
#define MERO_SC 100 // MEROITIC_HIEROGLYPHS
#define MERC_SC 101 // MEROITIC_CURSIVE
#define PSIN_SC 103 // ***
#define SARB_SC 105 // OLD_SOUTH_ARABIAN
#define NARB_SC 106 // OLD_NORTH_ARABIAN
#define CHRS_SC 109 // CHORASMIAN
#define PHNX_SC 115 // PHOENICIAN
#define LYDI_SC 116 // LYDIAN
#define TFNG_SC 120 // TIFINAGH
#define SAMR_SC 123 // SAMARITAN
#define ARMI_SC 124 // IMPERIAL_ARAMAIC
#define HEBR_SC 125 // HEBREW
#define PALM_SC 126 // PALMYRENE
#define HATR_SC 127 // HATRAN
#define ELYM_SC 128 // ELYMAIC
#define PRTI_SC 130 // INSCRIPTIONAL_PARTHIAN
#define PHLI_SC 131 // INSCRIPTIONAL_PAHLAVI
#define PHLP_SC 132 // PSALTER_PAHLAVI
#define AVST_SC 134 // AVESTAN
#define SYRC_SC 135 // SYRIAC
#define SYRN_SC 136 // ***
#define SYRJ_SC 137 // ***
#define MANI_SC 139 // MANICHAEAN
#define MAND_SC 140 // MANDAIC
#define SOGD_SC 141 // SOGDIAN
#define SOGO_SC 142 // OLD_SOGDIAN
#define OUGR_SC 143 // OLD_UYGHUR
#define MONG_SC 145 // MONGOLIAN
#define NBAT_SC 159 // NABATAEAN
#define ARAB_SC 160 // ARABIC
#define NKOO_SC 165 // NKO
#define ADLM_SC 166 // ADLAM
#define ROHG_SC 167 // HANIFI_ROHINGYA
#define ARAN_SC 169 // ***
#define THAA_SC 170 // THAANA
#define ORKH_SC 175 // OLD_TURKIC
#define HUNG_SC 176 // OLD_HUNGARIAN
#define YEZI_SC 192 // YEZIDI
/* [200..299] Alphabetical; left-to-right */
#define GREK_SC 200 // GREEK
#define CARI_SC 201 // CARIAN
#define LYCI_SC 202 // LYCIAN
#define COPT_SC 204 // COPTIC
#define GOTH_SC 206 // GOTHIC
#define ITAL_SC 210 // OLD_ITALIC
#define RUNR_SC 211 // RUNIC
#define OGAM_SC 212 // OGHAM
#define LATN_SC 215 // LATIN
#define LATG_SC 216 // *** Latin (Gaelic)
#define LATF_SC 217 // *** Latin (fraktur)
#define MOON_SC 218 // ***
#define OSGE_SC 219 // OSAGE
#define CYRL_SC 220 // CYRILLIC
#define CYRS_SC 221 // ***
#define GLAG_SC 225 // GLAGOLITIC
#define ELBA_SC 226 // ELBASAN
#define PERM_SC 227 // OLD_PERMIC
#define VITH_SC 228 // VITHKUQI
#define ARMN_SC 230 // ARMENIAN
#define AGHB_SC 239 // CAUCASIAN_ALBANIAN
#define GEOR_SC 240 // GEORGIAN
#define GEOK_SC 241 // ***
#define DSRT_SC 250 // DESERET
#define BASS_SC 259 // BASSA_VAH
#define OSMA_SC 260 // OSMANYA
#define OLCK_SC 261 // OL_CHIKI
#define WARA_SC 262 // WARANG_CITI
#define PAUC_SC 263 // PAU_CIN_HAU
#define MROO_SC 264 // MRO
#define MEDF_SC 265 // MEDEFAIDRIN
#define TNSA_SC 275 // TANGSA
#define VISP_SC 280 // ***
#define SHAW_SC 281 // SHAVIAN
#define PLRD_SC 282 // MIAO
#define WCHO_SC 283 // WANCHO
#define JAMO_SC 284 // ***
#define BOPO_SC 285 // BOPOMOFO
#define HANG_SC 286 // HANGUL
#define KORE_SC 287 // ***
#define KITS_SC 288 // KHITAN_SMALL_SCRIPT
#define TENG_SC 290 // ***
#define CIRT_SC 291 // ***
#define SARA_SC 292 // ***
#define PIQD_SC 293 // ***
#define TOTO_SC 294 //
#define NAGM_SC 295 // NAG_MUNDARI
/* 300..399 alphasyllabic */
#define BRAH_SC 300 // BRAHMI
#define SIDD_SC 302 // SIDDHAM
#define RANJ_SC 303 // *** Ranjana
#define KHAR_SC 305 // KHAROSHTHI
#define GURU_SC 310 // GURMUKHI
#define NAND_SC 311 // NANDINAGARI
#define GONG_SC 312 // GUNJALA_GONDI
#define GONM_SC 313 // MASARAM_GONDI
#define MAHJ_SC 314 // MAHAJANI
#define DEVA_SC 315 // DEVANAGARI
#define SYLO_SC 316 // SYLOTI_NAGRI
#define KTHI_SC 317 // KAITHI
#define SIND_SC 318 // KHUDAWADI
#define SHRD_SC 319 // SHARADA
#define GUJR_SC 320 // GUJARATI
#define TAKR_SC 321 // TAKRI
#define KHOJ_SC 322 // KHOJKI
#define MULT_SC 323 // MULTANI
#define MODI_SC 324 //
#define BENG_SC 325 // BENGALI
#define TIRH_SC 326 // TIRHUTA
#define ORYA_SC 327 // ORIYA
#define DOGR_SC 328 // DOGRA
#define SOYO_SC 329 // SOYOMBO
#define TIBT_SC 330 // TIBETAN
#define PHAG_SC 331 // PHAGS_PA
#define MARC_SC 332 // MARCHEN
#define NEWA_SC 333 //
#define BHKS_SC 334 // BHAIKSUKI
#define LEPC_SC 335 // LEPCHA
#define LIMB_SC 336 // LIMBU
#define MTEI_SC 337 // MEETEI_MAYEK
#define AHOM_SC 338 //
#define ZANB_SC 339 // ZANABAZAR_SQUARE
#define TELU_SC 340 // TELUGU
#define DIAK_SC 342 // DIVES_AKURU
#define GRAN_SC 343 // GRANTHA
#define SAUR_SC 344 // SAURASHTRA
#define KNDA_SC 345 // KANNADA
#define TAML_SC 346 // TAMIL
#define MLYM_SC 347 // MALAYALAM
#define SINH_SC 348 // SINHALA
#define CAKM_SC 349 // CHAKMA
#define MYMR_SC 350 // MYANMAR
#define LANA_SC 351 // TAI_THAM
#define THAI_SC 352 //
#define TALE_SC 353 // TAI_LE
#define TALU_SC 354 // NEW_TAI_LUE
#define KHMR_SC 355 // KHMER
#define LAOO_SC 356 // LAO
#define KALI_SC 357 // KAYAH_LI
#define CHAM_SC 358 //
#define TAVT_SC 359 // TAI_VIET
#define BALI_SC 360 // BALINESE
#define JAVA_SC 361 // JAVANESE
#define SUND_SC 362 // SUNDANESE
#define RJNG_SC 363 // REJANG
#define LEKE_SC 364 // ***
#define BATK_SC 365 // BATAK
#define MAKA_SC 366 // MAKASAR
#define BUGI_SC 367 // BUGINESE
#define KAWI_SC 368 //
#define TGLG_SC 370 // TAGALOG
#define HANO_SC 371 // HANUNOO
#define BUHD_SC 372 // BUHID
#define TAGB_SC 373 // TAGBANWA
#define SORA_SC 398 // SORA_SOMPENG
#define LISU_SC 399 // LISU
/* [400..499] Syllabic */
#define LINA_SC 400 // LINEAR_A
#define LINB_SC 401 // LINEAR_B
#define CPMN_SC 402 // CYPRO_MINOAN
#define CPRT_SC 403 // CYPRIOT
#define HIRA_SC 410 // HIRAGANA
#define KANA_SC 411 // KATAKANA
#define HRKT_SC 412 // KATAKANA_OR_HIRAGANA
#define JPAN_SC 413 // ***
#define ETHI_SC 430 // ETHIOPIC
#define BAMU_SC 435 // BAMUM
#define KPEL_SC 436 // ***
#define MEND_SC 438 // MENDE_KIKAKUI
#define AFAK_SC 439 // ***
#define CANS_SC 440 // CANADIAN_ABORIGINAL
#define CHER_SC 445 // CHEROKEE
#define HMNG_SC 450 // PAHAWH_HMONG
#define HMNP_SC 451 // NYIAKENG_PUACHUE_HMONG
#define YIII_SC 460 // YI
#define VAII_SC 470 // VAI
#define NSHU_SC 499 // NUSHU
/* [500..599] Ideographic */
#define HANI_SC 500 // HAN
#define HANS_SC 501 // *** Han (Simplified variant)
#define KITL_SC 505 // ***
#define JURC_SC 510 // ***
#define TANG_SC 529 // TANGUT
#define BLIS_SC 550 // *** Blissymbols
#define BRAI_SC 570 // BRAILLE
/* [600..699] Undeciphered */
#define INDS_SC 610 // ***
#define RORO_SC 620 // ***
/* [700..799] Notational; shorthand */
#define DUPL_SC 755 // DUPLOYAN
/* [800..899] <unused> */
/* [900..999] Special */
#define QAAA_SC 900 // ***
#define QABX_SC 949 // ***
#define ZSYE_SC 993 // ***
#define ZINH_SC 994 // INHERITED
#define ZMTH_SC 995 // ***
#define ZSYM_SC 996 // ***
#define VXXX_SC 997 // ***
#define ZYYY_SC 998 // COMMON
#define ZZZZ_SC 999 // UNKNOWN

// 000..099 aliases
#define             CUNEIFORM_SC XSUX_SC
#define           OLD_PERSIAN_SC XPEO_SC
#define              UGARITIC_SC UGAR_SC
#define  EGYPTIAN_HIEROGLYPHS_SC EGYP_SC
#define ANATOLIAN_HIEROGLYPHS_SC HLUW_SC
#define           SIGNWRITING_SC SGNW_SC

//100
#define                 ARABIC_SC ARAB_SC
#define       IMPERIAL_ARAMAIC_SC ARMI_SC
#define                AVESTAN_SC AVST_SC
#define                  ADLAM_SC ADLM_SC
#define   MEROITIC_HIEROGLYPHS_SC MERO_SC
#define       MEROITIC_CURSIVE_SC MERC_SC
#define      OLD_SOUTH_ARABIAN_SC SARB_SC
#define      OLD_NORTH_ARABIAN_SC NARB_SC
#define             CHORASMIAN_SC CHRS_SC
#define             PHOENICIAN_SC PHNX_SC
#define                 LYDIAN_SC LYDI_SC
#define               TIFINAGH_SC TFNG_SC
#define              SAMARITAN_SC SAMR_SC
#define                 HEBREW_SC HEBR_SC
#define              PALMYRENE_SC PALM_SC
#define                 HATRAN_SC HATR_SC
#define                ELYMAIC_SC ELYM_SC
#define INSCRIPTIONAL_PARTHIAN_SC PRTI_SC
#define  INSCRIPTIONAL_PAHLAVI_SC PHLI_SC
#define        PSALTER_PAHLAVI_SC PHLP_SC
#define                 SYRIAC_SC SYRC_SC
#define             MANICHAEAN_SC MANI_SC
#define                MANDAIC_SC MAND_SC
#define                SOGDIAN_SC SOGD_SC
#define            OLD_SOGDIAN_SC SOGO_SC
#define             OLD_UYGHUR_SC OUGR_SC
#define              MONGOLIAN_SC MONG_SC
#define              NABATAEAN_SC NBAT_SC
#define                    NKO_SC NKOO_SC
#define        HANIFI_ROHINGYA_SC ROHG_SC
#define                 THAANA_SC THAA_SC
#define             OLD_TURKIC_SC ORKH_SC
#define          OLD_HUNGARIAN_SC HUNG_SC
#define                 YEZIDI_SC YEZI_SC
#define                   QAAC_SC COPT_SC
#define                 COPTIC_SC COPT_SC
// 200
#define  CAUCASIAN_ALBANIAN_SC AGHB_SC
#define            ARMENIAN_SC ARMN_SC
#define           BASSA_VAH_SC BASS_SC
#define            BOPOMOFO_SC BOPO_SC
#define                 MRO_SC MROO_SC
#define               GREEK_SC GREK_SC
#define              CARIAN_SC CARI_SC
#define              LYCIAN_SC LYCI_SC
#define              GOTHIC_SC GOTH_SC
#define          OLD_ITALIC_SC ITAL_SC
#define               RUNIC_SC RUNR_SC
#define               OGHAM_SC OGAM_SC
#define               LATIN_SC LATN_SC
#define               OSAGE_SC OSGE_SC
#define            CYRILLIC_SC CYRL_SC
#define          GLAGOLITIC_SC GLAG_SC
#define             ELBASAN_SC ELBA_SC
#define          OLD_PERMIC_SC PERM_SC
#define            VITHKUQI_SC VITH_SC
#define            GEORGIAN_SC GEOR_SC
#define             DESERET_SC DSRT_SC
#define             OSMANYA_SC OSMA_SC
#define            OL_CHIKI_SC OLCK_SC
#define         WARANG_CITI_SC WARA_SC
#define         PAU_CIN_HAU_SC PAUC_SC
#define         MEDEFAIDRIN_SC MEDF_SC
#define              TANGSA_SC TNSA_SC
#define             SHAVIAN_SC SHAW_SC
#define                MIAO_SC PLRD_SC
#define              WANCHO_SC WCHO_SC
#define              HANGUL_SC HANG_SC
#define KHITAN_SMALL_SCRIPT_SC KITS_SC
#define         NAG_MUNDARI_SC NAGM_SC

// 300
#define         BALINESE_SC BALI_SC
#define          BENGALI_SC BENG_SC
#define        BHAIKSUKI_SC BHKS_SC
#define            BATAK_SC BATK_SC
#define           BRAHMI_SC BRAH_SC
#define          SIDDHAM_SC SIDD_SC
#define       KHAROSHTHI_SC KHAR_SC
#define         GURMUKHI_SC GURU_SC
#define      NANDINAGARI_SC NAND_SC
#define    GUNJALA_GONDI_SC GONG_SC
#define    MASARAM_GONDI_SC GONM_SC
#define         MAHAJANI_SC MAHJ_SC
#define       DEVANAGARI_SC DEVA_SC
#define     SYLOTI_NAGRI_SC SYLO_SC
#define           KAITHI_SC KTHI_SC
#define        KHUDAWADI_SC SIND_SC
#define          SHARADA_SC SHRD_SC
#define         GUJARATI_SC GUJR_SC
#define            TAKRI_SC TAKR_SC
#define           KHOJKI_SC KHOJ_SC
#define          MULTANI_SC MULT_SC
#define          TIRHUTA_SC TIRH_SC
#define            ORIYA_SC ORYA_SC
#define            DOGRA_SC DOGR_SC
#define          SOYOMBO_SC SOYO_SC
#define          TIBETAN_SC TIBT_SC
#define         PHAGS_PA_SC PHAG_SC
#define          MARCHEN_SC MARC_SC
#define           LEPCHA_SC LEPC_SC
#define            LIMBU_SC LIMB_SC
#define     MEETEI_MAYEK_SC MTEI_SC
#define ZANABAZAR_SQUARE_SC ZANB_SC
#define           TELUGU_SC TELU_SC
#define      DIVES_AKURU_SC DIAK_SC
#define          GRANTHA_SC GRAN_SC
#define       SAURASHTRA_SC SAUR_SC
#define          KANNADA_SC KNDA_SC
#define            TAMIL_SC TAML_SC
#define        MALAYALAM_SC MLYM_SC
#define          SINHALA_SC SINH_SC
#define           CHAKMA_SC CAKM_SC
#define          MYANMAR_SC MYMR_SC
#define         TAI_THAM_SC LANA_SC
#define           TAI_LE_SC TALE_SC
#define      NEW_TAI_LUE_SC TALU_SC
#define            KHMER_SC KHMR_SC
#define              LAO_SC LAOO_SC
#define         KAYAH_LI_SC KALI_SC
#define         TAI_VIET_SC TAVT_SC
#define         JAVANESE_SC JAVA_SC
#define        SUNDANESE_SC SUND_SC
#define           REJANG_SC RJNG_SC
#define          MAKASAR_SC MAKA_SC
#define         BUGINESE_SC BUGI_SC
#define          TAGALOG_SC TGLG_SC
#define          HANUNOO_SC HANO_SC
#define            BUHID_SC BUHD_SC
#define         TAGBANWA_SC TAGB_SC
#define     SORA_SOMPENG_SC SORA_SC
// 400
#define                  BAMUM_SC BAMU_SC
#define               LINEAR_A_SC LINA_SC
#define               LINEAR_B_SC LINB_SC
#define           CYPRO_MINOAN_SC CPMN_SC
#define                CYPRIOT_SC CPRT_SC
#define               HIRAGANA_SC HIRA_SC
#define               KATAKANA_SC KANA_SC
#define   KATAKANA_OR_HIRAGANA_SC HRKT_SC
#define               ETHIOPIC_SC ETHI_SC
#define          MENDE_KIKAKUI_SC MEND_SC
#define    CANADIAN_ABORIGINAL_SC CANS_SC
#define               CHEROKEE_SC CHER_SC
#define           PAHAWH_HMONG_SC HMNG_SC
#define NYIAKENG_PUACHUE_HMONG_SC HMNP_SC
#define                     YI_SC YIII_SC
#define                    VAI_SC VAII_SC
#define                  NUSHU_SC NSHU_SC

// 500..
#define         HAN_SC HANI_SC
#define      TANGUT_SC TANG_SC
#define     BRAILLE_SC BRAI_SC
#define BLISSYMBOLS_SC BLIS_SC

// 700..
#define DUPLOYAN_SC DUPL_SC

// 900..
#define    COMMON_SC ZYYY_SC
#define   UNKNOWN_SC ZZZZ_SC
#define INHERITED_SC ZINH_SC
#define      QAAI_SC ZINH_SC
#define QAAA_SC 900
#define QAAB_SC 901
#define QAAC_SC 902
#define QAAD_SC 903
#define QAAE_SC 904
#define QAAF_SC 905
#define QAAG_SC 906
#define QAAH_SC 907
#define QAAI_SC 908
#define QAAJ_SC 909
#define QAAK_SC 910
#define QAAL_SC 911
#define QAAM_SC 912
#define QAAN_SC 913
#define QAAO_SC 914
#define QAAP_SC 915
#define QAAQ_SC 916
#define QAAR_SC 917
#define QAAS_SC 918
#define QAAT_SC 919
#define QAAU_SC 920
#define QAAV_SC 921
#define QAAW_SC 922
#define QAAX_SC 923
#define QAAY_SC 924
#define QAAZ_SC 925
#define QABA_SC 926
#define QABB_SC 927
#define QABC_SC 928
#define QABD_SC 929
#define QABE_SC 930
#define QABF_SC 931
#define QABG_SC 932
#define QABH_SC 933
#define QABI_SC 934
#define QABJ_SC 935
#define QABK_SC 936
#define QABL_SC 937
#define QABM_SC 938
#define QABN_SC 939
#define QABO_SC 940
#define QABP_SC 941
#define QABQ_SC 942
#define QABR_SC 943
#define QABS_SC 944
#define QABT_SC 945
#define QABU_SC 946
#define QABV_SC 947
#define QABW_SC 948
#define QABX_SC 949

#endif
