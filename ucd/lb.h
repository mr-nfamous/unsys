/*°′″  «»  ≤≥  ≠≈  —¦  ÷×  !¡  ©®  £€  $¢  №⋕  λμ  πφ  ∑∏  ¶§  †‡  ±∞  √∆  ∫∳  
notes on the unicode line breaking algorithmr
´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´´
````````````````````````````````````````
{
    [0x00: 8]=lb_cm,
    [0x09: 1]=lb_ba, "\t"
    [0x0A: 1]=lb_lf, "\n"
    [0x0B: 2]=lb_bk, "\v\f"
    [0x0D: 1]=lb_cr, '\r'
    [0x0E:18]=lb_cm, 
    [0x20: 1]=lb_sp, ' '
    [0x21: 1]=lb_ex, '!'
    [0x22: 1]=lb_qu, '"'
    [0x23: 1]=lb_al, '#'
    
}
0000..0008;CM     # Cc     [9] <control-0000>..<control-0008>
0009;BA           # Cc         <control-0009>
000A;LF           # Cc         <control-000A>
000B..000C;BK     # Cc     [2] <control-000B>..<control-000C>
000D;CR           # Cc         <control-000D>
0020;SP           # Zs         SPACE
002F;SY           # Po         SOLIDUS
0085;NL           # Cc         <control-0085>
00AD;BA           # Cf         SOFT HYPHEN

# Line_Break (lb)
<LineBreak.txt>
<extracted/DerivedLineBreak.txt>
*/

#pragma once

enum {
    lb_xx=0, // Unknown 
    // Not Tailorable
    lb_bk, // Mandatory_Break    // N=4      00000b..002029  (\v\f)
    lb_cm, // Combining_Mark     // N=2399   000000..0E01EF  
    lb_cr, // Carriage_Return    // N=1      00000d          (\r)
    lb_lf, // Line_Feed          // N=1      00000a          (\n)
    lb_gl, // Glue               // N=26     0000a0..016FE4  
    lb_nl, // Next_Line          // N=1      000085
    lb_sp, // Space              // N=1      000020          ( )
    lb_wj, // Word_Joiner        // N=2      002026..00feff
    lb_zw, // ZW : ZWSpace       // N=1      00200b
    lb_zwj,// ZWJ: ZWJ           // N=1      00200d
    // opportunities
    lb_b2, // Break_Both         // N=3      002014..002E3B  (\u2E3A)
    lb_ba, // Break_After        // N=247    000009..01DA8A  (\t)
    lb_bb, // Break_Before       // N=45     0000b4..011C70  (´)
    lb_cb, // Contingent_Break   // N=1      00fffc          (￼)
    lb_hy, // Hyphen             // N=1      00002d          (-)
    // preventers 
    lb_cl, // Close_Punctuation  // N=95     000028..0145CF
    lb_cp, // Close_Parenthesis  // N=2      000029..00005d
    lb_ex, // Exclamation        // N=40     000021..011c71  (!)
    lb_in, // Inseparable        // N=6      002024..010AF6
    lb_op, // Open_Punctuation   // N=92     000028..01e95f
    lb_ns, // Nonstarter         // N=33     0017D6..01f67b
    lb_qu, // Quotation          // N=39     000022..01f678  (")
    // numbers
    lb_ai, // Ambiguous          // N=707    01F170..01F1AC  (§)
    lb_al, // Alphabetic         // N=22043  01FB94..01FBCA  (#)
    lb_is, // Infix_Numeric      // N=13     00002c..00fe14  (,)
    lb_nu, // Numeric            // N=652    000030..01fbf9  (0)
    lb_pr, // Prefix_Numeric     // N=67     000024..01e2ff  ($)
    lb_sy, // Break_Symbols      // N=1      00002f          (/)
    // other 
    lb_cj, //                    // N=58     003041..01b167
    lb_sg, // Surrogate          // N=2400   00D800..00DFFF
    lb_eb, // E_Base             // N=132    00261d..01faf6
    lb_em, // E_Modifier         // N=5      01f3fb..01f3ff
    lb_h2, // H2                 // N=399    00AC00..00D788
    lb_h3, // H3                 // N=10773  00AC01..00D7A3
    lb_hl, // Hebrew_Letter      // N=75     0005D0..00FB4F
    lb_id, // Ideographic        // N=172456 00231A..03FFFD
    lb_jl, // JL                 // N=125    001100..00a97c
    lb_jt, // JT                 // N=137    0011a8..00d7fb
    lb_po, // Postfix_Numeric    // N=37     000025..01ecac  (%)
    lb_jv, // JV                 // N=95     001160..00d7c6
    lb_ri, // Regional_Indicator // N=26     01f1e6..01f1ff
    lb_sa, // Complex_Context    // N=757    000E01..011746

    lb__max,
};

#define lb_mandatory_break              lb_bk
#define lb_combining_mark               lb_cm
#define lb_carriage_return              lb_cr
#define lb_line_feed                    lb_lf
#define lb_next_line                    lb_nl
#define lb_surrogate                    lb_sg
#define lb_word_joiner                  lb_wj
#define lb_zwspace                      lb_zw
#define lb_glue                         lb_gl
#define lb_space                        lb_sp
#define lb_zwj                          lb_zwj
#define lb_break_both                   lb_b2
#define lb_break_after                  lb_ba
#define lb_break_before                 lb_bb
#define lb_contingent_break             lb_cb
#define lb_hyphen                       lb_hy
#define lb_close_punctuation            lb_cl
#define lb_close_parenthesis            lb_cp
#define lb_exclamation                  lb_ex
#define lb_inseparable                  lb_in   
#define lb_nonstarter                   lb_ns
#define lb_open_punctuation             lb_op
#define lb_quotation                    lb_qu
#define lb_infix_numeric                lb_is
#define lb_numeric                      lb_nu
#define lb_prefix_numeric               lb_pr
#define lb_break_symbols                lb_sy
#define lb_ambiguous                    lb_ai
#define lb_alphabetic                   lb_al
#define lb_conditional_japanese_starter lb_cj
#define lb_e_base                       lb_eb
#define lb_e_modifier                   lb_em
#define lb_hebrew_letter                lb_hl
#define lb_ideographic                  lb_id
#define lb_postfix_numeric              lb_po
#define lb_regional_indicator           lb_ri
#define lb_complex_context              lb_sa
#define lb_unknown                      lb_xx

typedef unsigned char ucd_lb_t;

ucd_lb_t ucd_lb(char32_t);
