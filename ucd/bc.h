/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ 
Bidi_Class: UCD  / 15.0 / extracted / DerivedBidiClass.txt

Used for UNICODE BIDIRECTIONAL ALGORITHM (Annex # 9)
Site: UNICORE_URL("/reports/tr9/tr9-46.html")

BC has a "complex" default value. In general, the default is
Left_To_Right, but certain ranges which usually but not
necessarily correspond with a particular block, use another
default. For now, these exceptions will need to be manually
added here. 

# @missing: 0000..10FFFF; L
# @missing: 0590..05FF; R
# @missing: 0600..07BF; AL
# @missing: 07C0..085F; R
# @missing: 0860..08FF; AL
# @missing: 20A0..20CF; ET
# @missing: FB1D..FB4F; R
# @missing: FB50..FDCF; AL
# @missing: FDF0..FDFF; AL
# @missing: FE70..FEFF; AL
# @missing: 10800..10CFF; R
# @missing: 10D00..10D3F; AL
# @missing: 10D40..10EBF; R
# @missing: 10EC0..10EFF; AL
# @missing: 10F00..10F2F; R
# @missing: 10F30..10F6F; AL
# @missing: 10F70..10FFF; R
# @missing: 1E800..1EC6F; R
# @missing: 1EC70..1ECBF; AL
# @missing: 1ECC0..1ECFF; R
# @missing: 1ED00..1ED4F; AL
# @missing: 1ED50..1EDFF; R
# @missing: 1EE00..1EEFF; AL
# @missing: 1EF00..1EFFF; R

0041..005A    ; L #
05BE          ; R #
0030..0039    ; EN #
002B          ; ES #
0023          ; ET #
0600..0605    ; AN #
002C          ; CS #
000A          ; B #
0009          ; S #
000C          ; WS #
0021..0022    ; ON #
0000..0008    ; BN #
0300..036F    ; NSM #
0608          ; AL #
202D          ; LRO #
202E          ; RLO #
202A          ; LRE #
202B          ; RLE #
202C          ; PDF #
2066          ; LRI #
2067          ; RLI #
2068          ; FSI #
2069          ; PDI #
*/
#ifndef UCD_BC_H
#define UCD_BC_H

#define   L_BC   0  // [S] Left_To_Right 
#define   R_BC   1  // [S] Right_To_Left
#define  EN_BC   2  // [W] European_Number
#define  ES_BC   3  // [W] European_Separator
#define  ET_BC   4  // [W] European_Terminator
#define  AN_BC   5  // [W] Arabic_Number
#define  CS_BC   6  // [W] Common_Separator
#define   B_BC   7  // [N] Paragraph_Separator
#define   S_BC   8  // [N] Segment_Separator
#define  WS_BC   9  // [N] White_Space
#define  ON_BC  10  // [N] Other_Neutral   
#define  BN_BC  11  // [W] Boundary_Neutral
#define NSM_BC  12  // [W] Nonspacing_Mark
#define  AL_BC  13  // [S] Arabic_Letter 
#define LRO_BC  14  // [X] Left_To_Right_Override
#define RLO_BC  15  // [X] Right_To_Left_Override
#define LRE_BC  16  // [X] Left_To_Right_Embedding
#define RLE_BC  17  // [X] Right_To_Left_Embedding
#define PDF_BC  18  // [X] Pop_Directional_Format
#define LRI_BC  19  // [X] Left_To_Right_Isolate
#define RLI_BC  20  // [X] Right_To_Left_Isolate
#define FSI_BC  21  // [X] First_Strong_Isolate
#define PDI_BC  22  // [X] Pop_Directional_Isolate

#define ARABIC_LETTER_BC            AL_BC
#define ARABIC_NUMBER_BC            AN_BC
#define PARAGRAPH_SEPARATOR_BC      B_BC
#define BOUNDARY_NEUTRAL_BC         BN_BC
#define COMMON_SEPARATOR_BC         NS_BC
#define EUROPEAN_NUMBER_BC          EN_BC
#define EUROPEAN_SEPARATOR_BC       ES_BC
#define EUROPEAN_TERMINATOR_BC      ET_BC
#define NONSPACING_MARK_BC          NSM_BC
#define OTHER_NEUTRAL_BC            ON_BC
#define SEGMENT_SEPARATOR_BC        S_BC
#define WHITE_SPACE_BC              WS_BC
#define LEFT_TO_RIGHT_BC            L_BC
#define LEFT_TO_RIGHT_EMBEDDING_BC  LRE_BC
#define LEFT_TO_RIGHT_ISOLATE_BC    LRI_BC
#define LEFT_TO_RIGHT_OVERRIDE_BC   LRO_BC
#define RIGHT_TO_LEFT_BC            R_BC
#define RIGHT_TO_LEFT_EMBEDDING_BC  RLE_BC
#define RIGHT_TO_LEFT_ISOLATE_BC    RLI_BC
#define RIGHT_TO_LEFT_OVERRIDE_BC   RLO_BC
#define POP_DIRECTIONAL_FORMAT_BC   PDF_BC
#define POP_DIRECTIONAL_ISOLATE_BC  PDI_BC
#define FIRST_STRONG_ISOLATE_BC     FSI_BC

#endif
