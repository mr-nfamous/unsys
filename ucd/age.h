/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳ */
#ifndef UCD_AGE_H
#define UCD_AGE_H
/*
DerivedAge.txt

0000..001F    ; 1.1 #
0591..05A1    ; 2.0 #
20AC          ; 2.1 #
01F6..01F9    ; 3.0 #
0220          ; 3.2 #
0221          ; 4.0 #
0237..0241    ; 4.1 #
0242..024F    ; 5.0 #
0370..0373    ; 5.1 #
0524..0525    ; 5.2 #
0526..0527    ; 6.0 #
058F          ; 6.1 #
20BA          ; 6.2 #
061C          ; 6.3 #
037F          ; 7.0 #
08B3..08B4    ; 8.0 #
08B6..08BD    ; 9.0 #
0860..086A    ; 10.0 #
0560          ; 11.0 #
0C77          ; 12.0 #
32FF          ; 12.1 #
08BE..08C7    ; 13.0 #
061D          ; 14.0 #
0CF3          ; 15.0 #
*/
#define UCD_AGE_1 1 // 1.1
#define UCD_AGE_2 2 // 2.0; 2.1
#define UCD_AGE_3 3 // 3.0; 3.2
#define UCD_AGE_4 4 // 4.0; 4.1
#define UCD_AGE_5 5 // 5.0; 5.1; 5.2
#define UCD_AGE_6 6 // 6.0; 6.1; 6.2; 6.3
#define UCD_AGE_7 7 // 7.0
#define UCD_AGE_8 8// 8.0
#define UCD_AGE_9 9 // 9.0
#define UCD_AGE_10 10 // 10.0
#define UCD_AGE_11 11 // 11.0
#define UCD_AGE_12 12 // 12.0; 12.1
#define UCD_AGE_13 13 // 13.0
#define UCD_AGE_14 14 // 14.0
#define UCD_AGE_15 15 // 15.0
/*
enum {
    UCD_V1_1, // "1.1"      // 000000..00ffff N=33979   1993-06
    UCD_V2_0, // "2.0"      // 000591..10ffff N=144521  1996-07
    UCD_V2_1, // "2.1"      // 0020AC..00FFFC N=2       1998-05
    UCD_V3_0, // "3.0"      // 0001F6..00FFFB N=10307   1999-09
    UCD_V3_1, // "3.1"      // 0003F4..0E007F N=44978   2001-03
    UCD_V3_2, // "3.2"      // 000220..00FF60 N=1016    2002-03
    UCD_V4_0, // "4.0"      // 000221..0E01EF N=1226    2003-04
    UCD_V4_1, // "4.1"      // 000237..01D6A5 N=1273    2005-03
    UCD_V5_0, // "5.0"      // 000242..01D7CB N=1369    2006-07
    UCD_V5_1, // "5.1"      // 000370..01F093 N=1624    2008-03
    UCD_V5_2, // "5.2"      // 000524..02B734 N=6648    2009-10
    UCD_V6_0, // "6.0"      // 000526..02B81D N=2088    2010-10
    UCD_V6_1, // "6.1"      // 00058F..01F634 N=732     2012-01
    UCD_V6_2, // "6.2"      // 0020BA         N=1       2012-09
    UCD_V6_3, // "6.3"      // 00061C..002069 N=5       2013-09
    UCD_V7_0, // "7.0"      // 00037F..01F8AD N=2834    2014-06
    UCD_V8_0, // "8.0"      // 0008B3..02CEA1 N=7716    2015-06
    UCD_V9_0, // "9.0"      // 0008B6..01F991 N=7500    2016-06
    UCD_V10_0, // "10.0"     // 000860..02EBE0 N=8518    2017-06
    UCD_V11_0, // "11.0"     // 000560..01FA6D N=684     2018-06
    UCD_V12_0, // "12.0"     // 000C77..01FA95 N=554     2019-03
    UCD_V12_1, // "12.1"     // 0032FF         N=1       2019-05
    UCD_V13_0, // "13.0"     // 0008BE..03134A N=5930    2020-03
    UCD_V14_0, // "14.0"     // 00061D..02B738 N=838     2021-09
};
*/
#endif