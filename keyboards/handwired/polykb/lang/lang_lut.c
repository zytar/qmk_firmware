//File content partially generated!
//Execute the following command to do so (via cogapp):
//cog -r lang_lut.c
#include "lang_lut.h"
#include "polyatom.h"

static const uint16_t* lang_plane [ALPHA + NUM + ADDITIONAL][NUM_LANG * 3] = {
    /*[[[cog
    import cog
    from openpyxl import load_workbook

    wb = load_workbook(filename = 'lang_lut.xlsx', data_only=True)
    sheet = wb['key_lut']

    #build a list of known glyphs
    named_glyphs = []
    sheet_named_glyphs = wb['named_glyphs']
    for row in range(2,sheet_named_glyphs.max_row+1):
        named_glyphs.append(sheet_named_glyphs[f"A{row}"].value)

    #build a dict with all languages
    lang_dict = {}
    lang_index = 0
    lang_key = sheet["B1"].value
    while lang_key:
        lang_dict[lang_index] = lang_key
        lang_index = lang_index + 1
        lang_key = sheet[chr(ord('B')+lang_index*3)+"1"].value

    #helper to make the string for a key
    def make_key(text, sub):
        if not text:
            if not sub:
                return "NULL"
            else:
                text = ""
        else:
            if text not in named_glyphs:
                text = f'u"{text}"'   
            if not sub:
                return text
        
        if sub in named_glyphs:
            return f'{text} u"\\r\\v\\t" {sub}'
        else:
            return f'{text} u"\\r\\v\\t{sub}"'

    #helper to make all 3 strings (lower, upper, caps) needed for a key and language
    def make_lang_key(idx, row, prepend_comment, append_comma):
        lang_row = ""
        if prepend_comment:
            lang_row = f'/*  {lang_dict[idx] : <9}*' + '/  '
        for case_idx in range(0, 3):
            text = sheet[f"{chr(ord('B')+idx*3+case_idx)}{row}"].value
            sub = sheet[f"{chr(ord('B')+idx*3+case_idx)}{row+1}"].value

            composed = make_key(text, sub)
            if case_idx != 2 or append_comma:
                composed = composed + ","
                lang_row = f"{lang_row}{composed:<30}"
            else:
                lang_row = f"{lang_row}{composed}"

        return lang_row
    
    #create actual language lookup table
    key_index = 2
    key_name = sheet["A2"].value
    glyph_code = sheet["D2"].value
    while key_name:
        cog.out(f'/*{key_name : <11}*' + '/ {')

        for idx in lang_dict:
            cog.outl(f'{make_lang_key(idx, key_index, idx>0, idx < lang_index-1)}')
        cog.outl("},")

        key_index = key_index + 2
        key_name = sheet[f"A{key_index}"].value

    ]]]*/
    /*KC_A       */ {u"a",                         u"A",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_MIEUM,                NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_TI,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_SHEEN,                 NULL,                         NULL
    },
    /*KC_B       */ {u"b",                         u"B",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_YU,                   NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_KO,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_LAM_ALEF,              ARABIC_LAM_ALEF_MADDA,        NULL
    },
    /*KC_C       */ {u"c",                         u"C",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_CHIEUCH,              NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_SO,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_WAW_HAMZA_A,           NULL,                         NULL
    },
    /*KC_D       */ {u"d",                         u"D",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_IEUNG,                NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_SI,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_YEH,                   NULL,                         NULL
    },
    /*KC_E       */ {u"e",                         u"E",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_TIKEUT,               HANGEUL_SSANGTIKEUT,          NULL,                         
    /*  LANG_JA  */  HIRAGANA_I,                   HIRAGANA_SMALL_I,             NULL,                         
    /*  LANG_AR  */  ARABIC_THEH,                  NULL,                         NULL
    },
    /*KC_F       */ {u"f",                         u"F",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_RIEUL,                NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_HA,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_BEH,                   NULL,                         NULL
    },
    /*KC_G       */ {u"g",                         u"G",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_HIEUH,                NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_KI,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_LAM,                   NULL,                         NULL
    },
    /*KC_H       */ {u"h",                         u"H",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_O,                    NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_KU,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_ALEF,                  NULL,                         NULL
    },
    /*KC_I       */ {u"i",                         u"I",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_YA,                   NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_RI,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_HEH,                   NULL,                         NULL
    },
    /*KC_J       */ {u"j",                         u"J",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_EO,                   NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_MA,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_TEH,                   NULL,                         NULL
    },
    /*KC_K       */ {u"k",                         u"K",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_A,                    NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_NO,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_NOON,                  NULL,                         NULL
    },
    /*KC_L       */ {u"l",                         u"L",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_I,                    NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_RI,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_MEEM,                  NULL,                         NULL
    },
    /*KC_M       */ {u"m",                         u"M",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_EU,                   NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_MO,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_WAW,                   COMMA,                        NULL
    },
    /*KC_N       */ {u"n",                         u"N",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_U,                    NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_MI,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_ALEF_MAKSURA,          NULL,                         NULL
    },
    /*KC_O       */ {u"o",                         u"O",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_AE,                   HANGEUL_YAE,                  NULL,                         
    /*  LANG_JA  */  HIRAGANA_RA,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_TEH_MARBUTA,           NULL,                         NULL
    },
    /*KC_P       */ {u"p",                         u"P",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_E,                    HANGEUL_YE,                   NULL,                         
    /*  LANG_JA  */  HIRAGANA_SE,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_HAH,                   NULL,                         NULL
    },
    /*KC_Q       */ {u"q",                         u"Q",                         NULL,                         
    /*  LANG_DE  */  u"q" u"\r\v\t@",              u"Q" u"\r\v\t@",              NULL,                         
    /*  LANG_KO  */  HANGEUL_PIEUP,                HANGEUL_SSANGPIEUP,           NULL,                         
    /*  LANG_JA  */  HIRAGANA_TA,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_DAD,                   NULL,                         NULL
    },
    /*KC_R       */ {u"r",                         u"R",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_KIYEOK,               HANGEUL_SSANGKIYEOK,          NULL,                         
    /*  LANG_JA  */  HIRAGANA_SU,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_QAF,                   NULL,                         NULL
    },
    /*KC_S       */ {u"s",                         u"S",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_NIEUN,                NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_TO,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_SEEN,                  NULL,                         NULL
    },
    /*KC_T       */ {u"t",                         u"T",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_SIOS,                 HANGEUL_SSANGSIOS,            NULL,                         
    /*  LANG_JA  */  HIRAGANA_KA,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_FEH,                   NULL,                         NULL
    },
    /*KC_U       */ {NULL,                         NULL,                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_YEO,                  NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_NA,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_AIN,                   NULL,                         NULL
    },
    /*KC_V       */ {u"v",                         u"V",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_PHIEUPH,              NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_HI,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_REH,                   NULL,                         NULL
    },
    /*KC_W       */ {u"w",                         u"W",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_CIEUC,                HANGEUL_SSANGCIEUC,           NULL,                         
    /*  LANG_JA  */  HIRAGANA_TE,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_SAD,                   NULL,                         NULL
    },
    /*KC_X       */ {u"x",                         u"X",                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  HANGEUL_THIEUTH,              NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_SA,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_HAMZA,                 NULL,                         NULL
    },
    /*KC_Y       */ {u"y",                         u"Y",                         NULL,                         
    /*  LANG_DE  */  u"z",                         u"Z",                         NULL,                         
    /*  LANG_KO  */  HANGEUL_YO,                   NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_N,                   NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_GHAIN,                 NULL,                         NULL
    },
    /*KC_Z       */ {u"z",                         u"Z",                         NULL,                         
    /*  LANG_DE  */  u"y",                         u"Y",                         NULL,                         
    /*  LANG_KO  */  HANGEUL_KHIEUKH,              NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_TU,                  HIRAGANA_SMALL_TU,            NULL,                         
    /*  LANG_AR  */  ARABIC_YEH_HAMZA_A,           NULL,                         NULL
    },
    /*KC_1       */ {u"1",                         u"!",                         u"1",                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_NU,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_1,               u"!",                         ARABIC_INDIC_1
    },
    /*KC_2       */ {u"2",                         u"@",                         u"2",                         
    /*  LANG_DE  */  u"2" u"\r\v\t" SUPER_SCRIPT_2,QUOTE u"\r\v\t" SUPER_SCRIPT_2,u"2" u"\r\v\t" SUPER_SCRIPT_2,
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_HU,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_2,               u"@",                         ARABIC_INDIC_2
    },
    /*KC_3       */ {u"3",                         u"#",                         u"3",                         
    /*  LANG_DE  */  u"3" u"\r\v\t" SUPER_SCRIPT_3,SECTION u"\r\v\t" SUPER_SCRIPT_3,u"3" u"\r\v\t" SUPER_SCRIPT_3,
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_A,                   HIRAGANA_SMALL_A,             NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_3,               u"#",                         ARABIC_INDIC_3
    },
    /*KC_4       */ {u"4",                         u"$",                         u"4",                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_U,                   HIRAGANA_SMALL_U,             NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_4,               u"$",                         ARABIC_INDIC_4
    },
    /*KC_5       */ {u"5",                         u"%",                         u"5",                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_E,                   HIRAGANA_SMALL_E,             NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_5,               u"%",                         ARABIC_INDIC_5
    },
    /*KC_6       */ {u"6",                         u"^",                         u"6",                         
    /*  LANG_DE  */  NULL,                         u"&",                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_O,                   HIRAGANA_SMALL_O,             NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_6,               u"^",                         ARABIC_INDIC_6
    },
    /*KC_7       */ {u"7",                         u"&",                         u"7",                         
    /*  LANG_DE  */  NULL,                         u"/" u"\r\v\t{",              NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_YA,                  HIRAGANA_SMALL_YA,            NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_7,               u"&",                         ARABIC_INDIC_7
    },
    /*KC_8       */ {u"8",                         u"*",                         u"8",                         
    /*  LANG_DE  */  NULL,                         u"(" u"\r\v\t[",              NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_YU,                  HIRAGANA_SMALL_YU,            NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_8,               u"*",                         ARABIC_INDIC_8
    },
    /*KC_9       */ {u"9",                         u"(",                         u"9",                         
    /*  LANG_DE  */  NULL,                         u")" u"\r\v\t]",              NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_YO,                  HIRAGANA_SMALL_YO,            NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_9,               u"(",                         ARABIC_INDIC_9
    },
    /*KC_0       */ {NULL,                         u")",                         NULL,                         
    /*  LANG_DE  */  NULL,                         u"EQUALS" u"\r\v\t}",         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_WA,                  HIRAGANA_WO,                  NULL,                         
    /*  LANG_AR  */  ARABIC_INDIC_0,               u")",                         ARABIC_INDIC_0
    },
    /*KC_ENTER   */ {u"Ent",                       NULL,                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_AR  */  NULL,                         NULL,                         NULL
    },
    /*KC_ESCAPE  */ {u"Esc",                       NULL,                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_AR  */  NULL,                         NULL,                         NULL
    },
    /*KC_BACKSPACE*/ {ICON_BACKSPACE,               NULL,                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_AR  */  NULL,                         NULL,                         NULL
    },
    /*KC_TAB     */ {u"Tab",                       NULL,                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_AR  */  NULL,                         NULL,                         NULL
    },
    /*KC_SPACE   */ {ICON_SPACE,                   NULL,                         NULL,                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_AR  */  NULL,                         NULL,                         NULL
    },
    /*KC_MINUS   */ {u"-",                         u"_",                         u"-",                         
    /*  LANG_DE  */  ESZETT u"\r\v\t" BACKSLASH,   u"?" u"\r\v\t" BACKSLASH,     ESZETT u"\r\v\t" BACKSLASH,   
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_HO,                  KH_PSOUNDM,                   NULL,                         
    /*  LANG_AR  */  NULL,                         NULL,                         NULL
    },
    /*KC_EQUAL   */ {u"=",                         u"+",                         u"=",                         
    /*  LANG_DE  */  GRAVE_ACCENT,                 ACUTE_ACCENT,                 GRAVE_ACCENT,                 
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_HE,                  NULL,                         NULL,                         
    /*  LANG_AR  */  NULL,                         NULL,                         NULL
    },
    /*KC_LBRC    */ {u"[",                         u"{",                         u"[",                         
    /*  LANG_DE  */  UMLAUT_U_SMALL,               UMLAUT_U,                     NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  KH_VSOUNDM,                   LCORNER_BRKT,                 NULL,                         
    /*  LANG_AR  */  ARABIC_JEEM,                  u"<",                         NULL
    },
    /*KC_RBRC    */ {u"]",                         u"}",                         u"]",                         
    /*  LANG_DE  */  u"+" u"\r\v\t~",              u"*" u"\r\v\t~",              u"+" u"\r\v\t~",              
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  KH_SEMI_VSOUNDM,              RCORNER_BRKT,                 NULL,                         
    /*  LANG_AR  */  ARABIC_DAL,                   u">",                         NULL
    },
    /*KC_BACKSLASH*/ {BACKSLASH,                    u"|",                         BACKSLASH,                    
    /*  LANG_DE  */  u"#",                         u"'",                         u"#",                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_MU,                  NULL,                         NULL,                         
    /*  LANG_AR  */  NULL,                         NULL,                         NULL
    },
    /*KC_NONUS_HASH*/ {u"#",                         u"~",                         u"#",                         
    /*  LANG_DE  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_AR  */  NULL,                         NULL,                         NULL
    },
    /*KC_SEMICOLON*/ {u";",                         u":",                         u";",                         
    /*  LANG_DE  */  UMLAUT_O_SMALL,               UMLAUT_O,                     NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_RE,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_KAF,                   NULL,                         NULL
    },
    /*KC_QUOTE   */ {u"'",                         QUOTE,                        u"'",                         
    /*  LANG_DE  */  UMLAUT_A_SMALL,               UMLAUT_A,                     NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_KE,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_TAH,                   NULL,                         NULL
    },
    /*KC_GRAVE   */ {u"`",                         u"~",                         u"`",                         
    /*  LANG_DE  */  u"^",                         DEGREE,                       u"^",                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_RO,                  NULL,                         NULL,                         
    /*  LANG_AR  */  ARABIC_THAL,                  NULL,                         NULL
    },
    /*KC_COMMA   */ {COMMA,                        u"<",                         COMMA,                        
    /*  LANG_DE  */  NULL,                         u";",                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_NE,                  CJK_IDEOG_COMMA,              NULL,                         
    /*  LANG_AR  */  ARABIC_WAW,                   COMMA,                        NULL
    },
    /*KC_DOT     */ {u".",                         u">",                         u".",                         
    /*  LANG_DE  */  NULL,                         u":",                         NULL,                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_RU,                  CJK_IDEOG_FSTOP,              NULL,                         
    /*  LANG_AR  */  ARABIC_ZAIN,                  u".",                         NULL
    },
    /*KC_SLASH   */ {u"/",                         u"?",                         u"/",                         
    /*  LANG_DE  */  u"-",                         u"_",                         u"-",                         
    /*  LANG_KO  */  NULL,                         NULL,                         NULL,                         
    /*  LANG_JA  */  HIRAGANA_ME,                  KATAKANA_MIDDLE_DOT,          NULL,                         
    /*  LANG_AR  */  ARABIC_ZAH,                   ARABIC_QMARK,                 NULL
    },
    //[[[end]]]
};

const uint16_t* translate_keycode(uint8_t used_lang, uint16_t keycode, bool shift, bool caps_lock) {
    if(keycode < KC_A || keycode > KC_SLASH) return NULL;

    uint16_t index = keycode - KC_A;

    const uint16_t* lower_case = lang_plane[index][used_lang*3];
    if(lower_case==NULL) {
        lower_case = lang_plane[index][0]; //english as backup
        used_lang = 0;
    }

    if(caps_lock) {
        const uint16_t* caps_case = lang_plane[index][used_lang*3 + 2];
        if(caps_case!=NULL) {
            if(!shift) {
                return caps_case;
            }
        } else {
           shift = !shift;
        }
    }

    if(shift) {
        const uint16_t* upper_case = lang_plane[index][used_lang*3 + 1];
        if(upper_case!=NULL) {
            return upper_case;
        }
    }
    return lower_case;
}
