//----------------------------------------------------------------------------------------------------------------------------------------------
//                  Filename: stdfonts.h
//              Font definitions as used in the GraphLCD project
//              Copyright (C) 1999 - 2017 Jason Mitchell
//
//              8/7/17 - Merged fonts done in previous years into the master font file
//                       Font 3 is the Nokia 5110 font, which is a subset (not the whole font)- working on stripping the rest from NSE-1 f/w
//                       At this point it stops after ASCII 'Z' (0x5A)
//
//      Font1 = Standard Hitachi HD44780 matrix font for 5x7 character cells
//      Font2 = Akzidenz Grotesk (widely copied by the Chinese from my repo and seen on outdoor displays and bus front consoles)
//      Font3 = NSE-1 (The Nokia 5110's primary rendering font)
//      Font4 = My rendition of Trebuchet MS from Windows XP - This was originally used in a commercial product and since they have long since tossed
//              my code into file #13 I can use it here- Bite my ass Ian Rozowsky- think next time before you fucking accuse me of stealing your IP!!
//
//----------------------------------------------------------------------------------------------------------------------------------------------
#ifndef __STDFONTS_H_
#define __STDFONTS_H_

//---------------------------------------------------------------------------------------
// Font 1 - Hitachi HD44780 5 x 7 font
//---------------------------------------------------------------------------------------

const char f01_00 [] = {
                        0x05,
                        0x55, 0xAA, 0x55, 0xAA, 0x55
};
const char f01_01 [] = {
                         0x05,
                         0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};
const char f01_02 [] = {
                         0x07,
                         0x3E, 0x7F, 0x7B, 0x41, 0x7F, 0x7F, 0x3E
};
const char f01_03 [] = {
                         0x12,
                         0x1C, 0x14, 0x7F, 0x41, 0x71, 0x7D, 0x5F, 0x47,
                         0x71, 0x7D, 0x5F, 0x47, 0x71, 0x7D, 0x5F, 0x47, 0x41, 0x7F
};
const char f01_04 [] = {
                         0x0C,
                         0x12, 0x12, 0x3F, 0x21, 0x21, 0x21, 0x1E, 0x1C, 0x6C, 0x6C, 0x7C, 0x38
};
const char f01_05 [] = {
                         0x0A,
                         0x7F, 0x43, 0x45, 0x45, 0x49, 0x49, 0x45, 0x45, 0x43, 0x7F
};
const char f01_06 [] = {
                         0x13,
                         0x3E, 0x7F, 0x41, 0x7B, 0x77, 0x7B, 0x41, 0x7F, 0x41,
                         0x55, 0x5D, 0x7F, 0x41, 0x7B, 0x77, 0x7B, 0x41, 0x7F, 0x3E
};
const char f01_07 [] = {
                         0x07,
                         0x1C, 0x1C, 0x7F, 0x7F, 0x7F, 0x1C, 0x1C
};
const char f01_08 [] = {
                         0x0E,
                         0x06, 0x09, 0x06, 0x09, 0x40, 0x66, 0x7F, 0x7F, 0x66,
                         0x40, 0x09, 0x06, 0x09, 0x06
};
const char f01_09 [] = {
                         0x07,
                         0xDE, 0x57, 0x53, 0x51, 0x53, 0x57, 0xDE
};
const char f01_10 [] = {
                         0x07,
                         0x7B, 0xEA, 0xCA, 0x8A, 0xCA, 0xEA, 0x7B
};
const char f01_11 [] = {
                         0x07,
                         0xFF, 0x03, 0x03, 0x03, 0x03, 0x03, 0xFF
};
const char f01_12 [] = {
                         0x07,
                         0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF
};
const char f01_13 [] = {
                         0x12,
                         0x1C, 0x14, 0x7F, 0x41, 0x41, 0x41, 0x41, 0x41,
                         0x71, 0x7D, 0x5F, 0x47, 0x71, 0x7D, 0x5F, 0x47, 0x41, 0x7F
};
const char f01_14 [] = {
                         0x12,
                         0x1C, 0x14, 0x7F, 0x41, 0x41, 0x41, 0x41, 0x41,
                         0x41, 0x41, 0x41, 0x41, 0x71, 0x7D, 0x5F, 0x47, 0x41, 0x7F

};
const char f01_15 [] = {
                         0x12,
                         0x1C, 0x14, 0x7F, 0x41, 0x41, 0x41, 0x41, 0x41,
                         0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x41, 0x7F

};
const char f01_16 [] = {
                         0x05,
                         0x00, 0x7F, 0x3E, 0x1C, 0x08
};
const char f01_17 [] = {
                         0x05,
                         0x08, 0x1C, 0x3E, 0x7F, 0x00
};
const char f01_18 [] = {
                         0x05,
                         0x06, 0x05, 0x00, 0x06, 0x05
};
const char f01_19 [] = {
                         0x05,
                         0x05, 0x06, 0x00, 0x05, 0x06
};
const char f01_20 [] = {
                         0x05,
                         0x44, 0x66, 0x77, 0x66, 0x44
};
const char f01_21 [] = {
                         0x05,
                         0x11, 0x33, 0x77, 0x33, 0x11
};
const char f01_22 [] = {
                         0x05,
                         0x1C, 0x3E, 0x3E, 0x3E, 0x1C
};
const char f01_23 [] = {
                         0x05,
                         0x10, 0x38, 0x54, 0x10, 0x1F
};
const char f01_24 [] = {
                         0x05,
                         0x04, 0x02, 0x7F, 0x02, 0x04
};
const char f01_25 [] = {
                         0x05,
                         0x10, 0x20, 0x7F, 0x20, 0x10
};
const char f01_26 [] = {
                         0x05,
                         0x08, 0x08, 0x2A, 0x1C, 0x08
};
const char f01_27 [] = {
                         0x05,
                         0x08, 0x1C, 0x2A, 0x08, 0x08
};
const char f01_28 [] = {
                         0x05,
                         0x40, 0x44, 0x4A, 0x51, 0x40
};
const char f01_29 [] = {
                         0x05,
                         0x40, 0x51, 0x4A, 0x44, 0x40
};
const char f01_30 [] = {
                         0x05,
                         0x20, 0x38, 0x3E, 0x38, 0x20
};
const char f01_31 [] = {
                         0x05,
                         0x02, 0x0E, 0x3E, 0x0E, 0x02
};
const char f01_32 [] = {
                         0x05,
                         0x00, 0x00, 0x00, 0x00, 0x00
};
const char f01_33 [] = {
                         0x05,
                         0x00, 0x00, 0x4F, 0x00, 0x00
};
const char f01_34 [] = {
                         0x05,
                         0x00, 0x07, 0x00, 0x07, 0x00
};
const char f01_35 [] = {
                         0x05,
                         0x14, 0x7F, 0x14, 0x7F, 0x14
};
const char f01_36 [] = {
                         0x05,
                         0x24, 0x2A, 0x7F, 0x2A, 0x12
};
const char f01_37 [] = {
                         0x05,
                         0x23, 0x13, 0x08, 0x64, 0x62
};
const char f01_38 [] = {
                         0x05,
                         0x36, 0x49, 0x55, 0x22, 0x50
};
const char f01_39 [] = {
                         0x05,
                         0x00, 0x05, 0x03, 0x00, 0x00
};
const char f01_40 [] = {
                         0x05,
                         0x00, 0x1C, 0x22, 0x41, 0x00
};
const char f01_41 [] = {
                         0x05,
                         0x00, 0x41, 0x22, 0x1C, 0x00
};
const char f01_42 [] = {
                         0x05,
                         0x14, 0x08, 0x3E, 0x08, 0x14
};
const char f01_43 [] = {
                         0x05,
                         0x08, 0x08, 0x3E, 0x08, 0x08
};
const char f01_44 [] = {
                         0x05,
                         0x00, 0x50, 0x30, 0x00, 0x00
};
const char f01_45 [] = {
                         0x05,
                         0x08, 0x08, 0x08, 0x08, 0x08
};
const char f01_46 [] = {
                         0x05,
                         0x00, 0x60, 0x60, 0x00, 0x00
};
const char f01_47 [] = {
                         0x05,
                         0x20, 0x10, 0x08, 0x04, 0x02
};
const char f01_48 [] = {
                         0x05,
                         0x3E, 0x51, 0x49, 0x45, 0x3E
};
const char f01_49 [] = {
                         0x05,
                         0x00, 0x42, 0x7F, 0x40, 0x00
};
const char f01_50 [] = {
                         0x05,
                         0x42, 0x61, 0x51, 0x49, 0x46
};
const char f01_51 [] = {
                         0x05,
                         0x21, 0x41, 0x45, 0x4B, 0x31
};
const char f01_52 [] = {
                         0x05,
                         0x18, 0x14, 0x12, 0x7F, 0x10
};
const char f01_53 [] = {
                         0x05,
                         0x27, 0x45, 0x45, 0x45, 0x39
};
const char f01_54 [] = {
                         0x05,
                         0x3C, 0x4A, 0x49, 0x49, 0x30
};
const char f01_55 [] = {
                         0x05,
                         0x03, 0x01, 0x71, 0x09, 0x07
};
const char f01_56 [] = {
                         0x05,
                         0x36, 0x49, 0x49, 0x49, 0x36
};
const char f01_57 [] = {
                         0x05,
                         0x06, 0x49, 0x49, 0x29, 0x1E
};
const char f01_58 [] = {
                         0x05,
                         0x00, 0x36, 0x36, 0x00, 0x00
};
const char f01_59 [] = {
                         0x05,
                         0x00, 0x56, 0x36, 0x00, 0x00
};
const char f01_60 [] = {
                         0x05,
                         0x08, 0x14, 0x22, 0x41, 0x00
};
const char f01_61 [] = {
                         0x05,
                         0x14, 0x14, 0x14, 0x14, 0x14
};
const char f01_62 [] = {
                         0x05,
                         0x00, 0x41, 0x22, 0x14, 0x08
};
const char f01_63 [] = {
                         0x05,
                         0x02, 0x01, 0x51, 0x09, 0x06
};
const char f01_64 [] = {
                         0x05,
                         0x32, 0x49, 0x79, 0x41, 0x3E
};
const char f01_65 [] = {
                         0x05,
                         0x7C, 0x12, 0x11, 0x12, 0x7C
};

const char f01_66 [] = {
                         0x05,
                         0x7F, 0x49, 0x49, 0x49, 0x36
};
const char f01_67 [] = {
                         0x05,
                         0x3E, 0x41, 0x41, 0x41, 0x22
};
const char f01_68 [] = {
                         0x05,
                         0x7F, 0x41, 0x41, 0x22, 0x1C
};
const char f01_69 [] = {
                         0x05,
                         0x7F, 0x49, 0x49, 0x49, 0x41
};
const char f01_70 [] = {
                         0x05,
                         0x7F, 0x09, 0x09, 0x09, 0x01
};
const char f01_71 [] = {
                         0x05,
                         0x3E, 0x41, 0x49, 0x49, 0x7A
};
const char f01_72 [] = {
                         0x05,
                         0x7F, 0x08, 0x08, 0x08, 0x7F
};
const char f01_73 [] = {
                         0x05,
                         0x00, 0x41, 0x7F, 0x41, 0x00
};
const char f01_74 [] = {
                         0x05,
                         0x20, 0x40, 0x41, 0x3F, 0x01
};
const char f01_75 [] = {
                         0x05,
                         0x7F, 0x08, 0x14, 0x22, 0x41
};
const char f01_76 [] = {
                         0x05,
                         0x7F, 0x40, 0x40, 0x40, 0x40
};
const char f01_77 [] = {
                         0x05,
                         0x7F, 0x02, 0x0C, 0x02, 0x7F
};
const char f01_78 [] = {
                         0x05,
                         0x7F, 0x04, 0x08, 0x10, 0x7F
};
const char f01_79 [] = {
                         0x05,
                         0x3E, 0x41, 0x41, 0x41, 0x3E
};
const char f01_80 [] = {
                         0x05,
                         0x7F, 0x09, 0x09, 0x09, 0x06
};
const char f01_81 [] = {
                         0x05,
                         0x3E, 0x41, 0x51, 0x21, 0x5E
};
const char f01_82 [] = {
                         0x05,
                         0x7F, 0x09, 0x19, 0x29, 0x46
};
const char f01_83 [] = {
                         0x05,
                         0x26, 0x49, 0x49, 0x49, 0x32
};
const char f01_84 [] = {
                         0x05,
                         0x01, 0x01, 0x7F, 0x01, 0x01
};
const char f01_85 [] = {
                         0x05,
                         0x3F, 0x40, 0x40, 0x40, 0x3F
};
const char f01_86 [] = {
                         0x05,
                         0x1F, 0x20, 0x40, 0x20, 0x1F
};
const char f01_87 [] = {
                         0x05,
                         0x3F, 0x40, 0x38, 0x40, 0x3F
};
const char f01_88 [] = {
                         0x05,
                         0x63, 0x14, 0x08, 0x14, 0x63
};
const char f01_89 [] = {
                         0x05,
                         0x07, 0x08, 0x70, 0x08, 0x07
};
const char f01_90 [] = {
                         0x05,
                         0x61, 0x51, 0x49, 0x45, 0x43
};
const char f01_91 [] = {
                         0x05,
                         0x00, 0x7F, 0x41, 0x41, 0x00
};
const char f01_92 [] = {
                         0x05,
                         0x02, 0x04, 0x08, 0x10, 0x20
};
const char f01_93 [] = {
                         0x05,
                         0x00, 0x41, 0x41, 0x7F, 0x00
};
const char f01_94 [] = {
                         0x05,
                         0x04, 0x02, 0x01, 0x02, 0x04
};
const char f01_95 [] = {
                         0x05,
                         0x40, 0x40, 0x40, 0x40, 0x40
};
const char f01_96 [] = {
                         0x05,
                         0x00, 0x01, 0x02, 0x04, 0x00
};
const char f01_97 [] = {
                         0x05,
                         0x20, 0x54, 0x54, 0x54, 0x78
};
const char f01_98 [] = {
                         0x05,
                         0x7F, 0x48, 0x44, 0x44, 0x38
};
const char f01_99 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x44, 0x20
};
const char f01_100 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x48, 0x7F
};
const char f01_101 [] = {
                         0x05,
                         0x38, 0x54, 0x54, 0x54, 0x18
};
const char f01_102 [] = {
                         0x05,
                         0x08, 0x7E, 0x09, 0x09, 0x02
};
const char f01_103 [] = {
                         0x05,
                         0x08, 0x54, 0x54, 0x54, 0x3C
};
const char f01_104 [] = {
                         0x05,
                         0x7F, 0x08, 0x04, 0x04, 0x78
};
const char f01_105 [] = {
                         0x05,
                         0x00, 0x48, 0x7D, 0x40, 0x00
};
const char f01_106 [] = {
                         0x05,
                         0x20, 0x40, 0x44, 0x3D, 0x00
};
const char f01_107 [] = {
                         0x05,
                         0x7F, 0x10, 0x28, 0x44, 0x00
};
const char f01_108 [] = {
                         0x05,
                         0x00, 0x41, 0x7F, 0x40, 0x00
};
const char f01_109 [] = {
                         0x05,
                         0x7C, 0x04, 0x78, 0x04, 0x78
};
const char f01_110 [] = {
                         0x05,
                         0x7C, 0x08, 0x04, 0x04, 0x78
};
const char f01_111 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x44, 0x38
};
const char f01_112 [] = {
                         0x05,
                         0x7C, 0x14, 0x14, 0x14, 0x08
};
const char f01_113 [] = {
                         0x05,
                         0x08, 0x14, 0x14, 0x18, 0x7C
};
const char f01_114 [] = {
                         0x05,
                         0x7C, 0x08, 0x04, 0x04, 0x08
};
const char f01_115 [] = {
                         0x05,
                         0x48, 0x54, 0x54, 0x54, 0x20,
};
const char f01_116 [] = {
                         0x05,
                         0x04, 0x3F, 0x44, 0x40, 0x20
};
const char f01_117 [] = {
                         0x05,
                         0x3C, 0x40, 0x40, 0x20, 0x7C
};
const char f01_118 [] = {
                         0x05,
                         0x1C, 0x20, 0x40, 0x20, 0x1C
};
const char f01_119 [] = {
                         0x05,
                         0x3C, 0x40, 0x30, 0x40, 0x3C
};

const char f01_120 [] = {
                         0x05,
                         0x44, 0x28, 0x10, 0x28, 0x44
};
const char f01_121 [] = {
                         0x05,
                         0x0C, 0x50, 0x50, 0x50, 0x3C
};
const char f01_122 [] = {
                         0x05,
                         0x44, 0x64, 0x54, 0x4C, 0x44
};
const char f01_123 [] = {
                         0x05,
                         0x00, 0x08, 0x36, 0x41, 0x00
};
const char f01_124 [] = {
                         0x05,
                         0x00, 0x00, 0x7F, 0x00, 0x00
};
const char f01_125 [] = {
                         0x05,
                         0x00, 0x41, 0x36, 0x08, 0x00
};
const char f01_126 [] = {
                         0x05,
                         0x10, 0x08, 0x08, 0x10, 0x08
};
const char f01_127 [] = {
                         0x05,
                         0x3C, 0x22, 0x21, 0x22, 0x3C
};
const char f01_128 [] = {
                         0x05,
                         0x7F, 0x49, 0x49, 0x49, 0x33
};
const char f01_129 [] = {
                         0x05,
                         0x70, 0x29, 0x27, 0x21, 0x7F
};
const char f01_130 [] = {
                         0x05,
                         0x77, 0x08, 0x7F, 0x08, 0x77
};
const char f01_131 [] = {
                         0x05,
                         0x41, 0x41, 0x49, 0x49, 0x36
};
const char f01_132 [] = {
                         0x05,
                         0x7F, 0x10, 0x08, 0x04, 0x7F
};
const char f01_133 [] = {
                         0x05,
                         0x7C, 0x21, 0x12, 0x09, 0x7C
};
const char f01_134 [] = {
                         0x05,
                         0x20, 0x41, 0x3F, 0x01, 0x7F
};
const char f01_135 [] = {
                         0x05,
                         0x7F, 0x01, 0x01, 0x01, 0x7F
};
const char f01_136 [] = {
                         0x05,
                         0x47, 0x28, 0x10, 0x08, 0x07
};
const char f01_137 [] = {
                         0x05,
                         0x3F, 0x20, 0x20, 0x20, 0x7F
};
const char f01_138 [] = {
                         0x05,
                         0x07, 0x08, 0x08, 0x08, 0x7F
};
const char f01_139 [] = {
                         0x05,
                         0x7E, 0x40, 0x7E, 0x40, 0x7E
};
const char f01_140 [] = {
                         0x05,
                         0x3F, 0x20, 0x3F, 0x20, 0x7F
};
const char f01_141 [] = {
                         0x05,
                         0x01, 0x7F, 0x48, 0x48, 0x30
};
const char f01_142 [] = {
                         0x05,
                         0x7F, 0x48, 0x30, 0x00, 0x7F
};
const char f01_143 [] = {
                         0x05,
                         0x22, 0x49, 0x45, 0x49, 0x3E
};
const char f01_144 [] = {
                         0x05,
                         0x38, 0x44, 0x48, 0x30, 0x4C
};
const char f01_145 [] = {
                         0x05,
                         0x60, 0x60, 0x7F, 0x02, 0x0C
};
const char f01_146 [] = {
                         0x05,
                         0x7F, 0x01, 0x01, 0x01, 0x03
};
const char f01_147 [] = {
                         0x05,
                         0x44, 0x3C, 0x04, 0x7C, 0x44
};
const char f01_148 [] = {
                         0x05,
                         0x63, 0x55, 0x49, 0x41, 0x41
};
const char f01_149 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x3C, 0x04
};
const char f01_150 [] = {
                         0x05,
                         0x30, 0x30, 0x1F, 0x65, 0x7F
};
const char f01_151 [] = {
                         0x05,
                         0x08, 0x04, 0x3C, 0x44, 0x02
};
const char f01_152 [] = {
                         0x05,
                         0x10, 0x1E, 0x3F, 0x1E, 0x10
};
const char f01_153 [] = {
                         0x05,
                         0x3E, 0x49, 0x49, 0x49, 0x3E
};
const char f01_154 [] = {
                         0x05,
                         0x5C, 0x62, 0x02, 0x62, 0x5C
};
const char f01_155 [] = {
                         0x05,
                         0x30, 0x4A, 0x45, 0x49, 0x32
};
const char f01_156 [] = {
                         0x05,
                         0x18, 0x14, 0x08, 0x14, 0x0C
};
const char f01_157 [] = {
                         0x05,
                         0x1C, 0x3E, 0x7C, 0x3E, 0x1C
};
const char f01_158 [] = {
                         0x05,
                         0x28, 0x54, 0x54, 0x44, 0x20
};
const char f01_159 [] = {
                         0x05,
                         0x7E, 0x01, 0x01, 0x01, 0x7E
};
const char f01_160 [] = {
                         0x05,
                         0x7F, 0x7F, 0x00, 0x7F, 0x7F
};
const char f01_161 [] = {
                         0x05,
                         0x00, 0x00, 0x79, 0x00, 0x00
};
const char f01_162 [] = {
                         0x05,
                         0x1C, 0x22, 0x7F, 0x22, 0x10
};
const char f01_163 [] = {
                         0x05,
                         0x48, 0x3E, 0x49, 0x41, 0x20
};
const char f01_164 [] = {
                         0x05,
                         0x22, 0x1C, 0x14, 0x1C, 0x22
};
const char f01_165 [] = {
                         0x05,
                         0x15, 0x16, 0x7C, 0x16, 0x15
};
const char f01_166 [] = {
                         0x05,
                         0x00, 0x00, 0x77, 0x00, 0x00
};
const char f01_167 [] = {
                         0x05,
                         0x20, 0x4A, 0x55, 0x29, 0x02
};
const char f01_168 [] = {
                         0x05,
                         0x28, 0x48, 0x3E, 0x09, 0x0A
};
const char f01_169 [] = {
                         0x05,
                         0x7F, 0x41, 0x5D, 0x49, 0x7F
};
const char f01_170 [] = {
                         0x05,
                         0x48, 0x55, 0x55, 0x55, 0x5E
};
const char f01_171 [] = {
                         0x05,
                         0x08, 0x14, 0x2A, 0x14, 0x22
};
const char f01_172 [] = {
                         0x05,
                         0x7F, 0x08, 0x3E, 0x41, 0x3E
};
const char f01_173 [] = {
                         0x05,
                         0x46, 0x29, 0x19, 0x09, 0x7F
};
const char f01_174 [] = {
                         0x05,
                         0x7F, 0x41, 0x65, 0x51, 0x7F
};
const char f01_175 [] = {
                         0x05,
                         0x00, 0x06, 0x05, 0x00, 0x00
};
const char f01_176 [] = {
                         0x05,
                         0x0E, 0x11, 0x11, 0x0E, 0x00
};
const char f01_177 [] = {
                         0x05,
                         0x44, 0x44, 0x5F, 0x44, 0x44
};
const char f01_178 [] = {
                         0x05,
                         0x12, 0x19, 0x15, 0x12, 0x00
};
const char f01_179 [] = {
                         0x05,
                         0x11, 0x15, 0x15, 0x0A, 0x00
};
const char f01_180 [] = {
                         0x05,
                         0x7F, 0x05, 0x15, 0x7A, 0x50
};
const char f01_181 [] = {
                         0x05,
                         0x7F, 0x10, 0x10, 0x08, 0x1F
};
const char f01_182 [] = {
                         0x05,
                         0x06, 0x09, 0x09, 0x7F, 0x7F
};
const char f01_183 [] = {
                         0x05,
                         0x00, 0x18, 0x18, 0x00, 0x00
};
const char f01_184 [] = {
                         0x05,
                         0x38, 0x44, 0x30, 0x44, 0x38
};
const char f01_185 [] = {
                         0x05,
                         0x12, 0x1F, 0x10, 0x00, 0x00
};
const char f01_186 [] = {
                         0x05,
                         0x4E, 0x51, 0x51, 0x51, 0x4E
};
const char f01_187 [] = {
                         0x05,
                         0x22, 0x14, 0x2A, 0x14, 0x08
};
const char f01_188 [] = {
                         0x05,
                         0x17, 0x68, 0x54, 0xFA, 0x41
};
const char f01_189 [] = {
                         0x05,
                         0x17, 0x08, 0x94, 0xCA, 0xB1
};
const char f01_190 [] = {
                         0x05,
                         0x15, 0x1F, 0x60, 0x50, 0xF8
};
const char f01_191 [] = {
                         0x05,
                         0x30, 0x48, 0x45, 0x40, 0x20
};
const char f01_192 [] = {
                         0x05,
                         0x70, 0x29, 0x26, 0x28, 0x70
};
const char f01_193 [] = {
                         0x05,
                         0x70, 0x28, 0x26, 0x29, 0x70
};
const char f01_194 [] = {
                         0x05,
                         0x70, 0x2A, 0x29, 0x2A, 0x70
};
const char f01_195 [] = {
                         0x05,
                         0x72, 0x29, 0x29, 0x2A, 0x71
};
const char f01_196 [] = {
                         0x05,
                         0x70, 0x29, 0x24, 0x29, 0x70
};
const char f01_197 [] = {
                         0x05,
                         0x70, 0x2A, 0x2D, 0x2A, 0x70
};
const char f01_198 [] = {
                         0x05,
                         0x7C, 0x12, 0x7F, 0x49, 0x49
};
const char f01_199 [] = {
                         0x05,
                         0x0E, 0x51, 0x51, 0x71, 0x0A
};
const char f01_200 [] = {
                         0x05,
                         0x7C, 0x55, 0x56, 0x54, 0x44
};
const char f01_201 [] = {
                         0x05,
                         0x7C, 0x54, 0x56, 0x55, 0x44
};
const char f01_202 [] = {
                         0x05,
                         0x7C, 0x56, 0x55, 0x56, 0x44
};
const char f01_203 [] = {
                         0x05,
                         0x7C, 0x55, 0x54, 0x55, 0x44
};
const char f01_204 [] = {
                         0x05,
                         0x00, 0x49, 0x7A, 0x48, 0x00
};
const char f01_205 [] = {
                         0x05,
                         0x00, 0x48, 0x7A, 0x49, 0x00
};
const char f01_206 [] = {
                         0x05,
                         0x00, 0x4A, 0x79, 0x4A, 0x00
};
const char f01_207 [] = {
                         0x05,
                         0x00, 0x45, 0x7C, 0x45, 0x00
};
const char f01_208 [] = {
                         0x05,
                         0x08, 0x7F, 0x49, 0x41, 0x3E
};
const char f01_209 [] = {
                         0x05,
                         0x7A, 0x09, 0x11, 0x22, 0x79
};
const char f01_210 [] = {
                         0x05,
                         0x38, 0x45, 0x46, 0x44, 0x38
};
const char f01_211 [] = {
                         0x05,
                         0x38, 0x44, 0x46, 0x45, 0x38
};
const char f01_212 [] = {
                         0x05,
                         0x38, 0x46, 0x45, 0x46, 0x38
};
const char f01_213 [] = {
                         0x05,
                         0x72, 0x89, 0x89, 0x8A, 0x71
};
const char f01_214 [] = {
                         0x05,
                         0x38, 0x45, 0x44, 0x45, 0x38
};
const char f01_215 [] = {
                         0x05,
                         0x22, 0x14, 0x08, 0x14, 0x22
};
const char f01_216 [] = {
                         0x05,
                         0x08, 0x55, 0x7F, 0x55, 0x08
};
const char f01_217 [] = {
                         0x05,
                         0x3C, 0x41, 0x42, 0x40, 0x3C
};
const char f01_218 [] = {
                         0x05,
                         0x3C, 0x40, 0x42, 0x41, 0x3C
};
const char f01_219 [] = {
                         0x05,
                         0x38, 0x42, 0x41, 0x42, 0x38
};
const char f01_220 [] = {
                         0x05,
                         0x3C, 0x41, 0x40, 0x41, 0x3C
};
const char f01_221 [] = {
                         0x05,
                         0x04, 0x08, 0x72, 0x09, 0x04
};
const char f01_222 [] = {
                         0x05,
                         0x41, 0x7F, 0x52, 0x12, 0x0C
};
const char f01_223 [] = {
                         0x05,
                         0x40, 0x3E, 0x49, 0x49, 0x36
};
const char f01_224 [] = {
                         0x05,
                         0x40, 0xA9, 0xAA, 0xA8, 0xF0
};
const char f01_225 [] = {
                         0x05,
                         0x20, 0x54, 0x56, 0x55, 0x78
};
const char f01_226 [] = {
                         0x05,
                         0x20, 0x56, 0x55, 0x56, 0x78
};
const char f01_227 [] = {
                         0x05,
                         0x42, 0xA9, 0xA9, 0xAA, 0xF1
};
const char f01_228 [] = {
                         0x05,
                         0x20, 0x55, 0x54, 0x55, 0x78
};
const char f01_229 [] = {
                         0x05,
                         0x40, 0xAA, 0xAD, 0xAA, 0xF0
};
const char f01_230 [] = {
                         0x05,
                         0x32, 0x4A, 0x3C, 0x4A, 0x2C
};
const char f01_231 [] = {
                         0x05,
                         0x0C, 0x52, 0x72, 0x12, 0x08
};
const char f01_232 [] = {
                         0x05,
                         0x38, 0x55, 0x56, 0x54, 0x18
};
const char f01_233 [] = {
                         0x05,
                         0x38, 0x54, 0x56, 0x55, 0x18
};
const char f01_234 [] = {
                         0x05,
                         0x38, 0x56, 0x55, 0x56, 0x18
};
const char f01_235 [] = {
                         0x05,
                         0x38, 0x55, 0x54, 0x55, 0x18
};
const char f01_236 [] = {
                         0x05,
                         0x00, 0x51, 0x7A, 0x40, 0x00
};
const char f01_237 [] = {
                         0x05,
                         0x00, 0x50, 0x7A, 0x41, 0x00
};
const char f01_238 [] = {
                         0x05,
                         0x00, 0x92, 0xF9, 0x82, 0x00
};
const char f01_239 [] = {
                         0x05,
                         0x00, 0x49, 0x7C, 0x41, 0x00
};
const char f01_240 [] = {
                         0x05,
                         0x25, 0x52, 0x55, 0x58, 0x30
};
const char f01_241 [] = {
                         0x05,
                         0x7A, 0x11, 0x09, 0x0A, 0x71
};
const char f01_242 [] = {
                         0x05,
                         0x38, 0x45, 0x46, 0x44, 0x38
};
const char f01_243 [] = {
                         0x05,
                         0x38, 0x44, 0x46, 0x45, 0x38
};
const char f01_244 [] = {
                         0x05,
                         0x30, 0x4A, 0x49, 0x4A, 0x30
};
const char f01_245 [] = {
                         0x05,
                         0x32, 0x49, 0x49, 0x4A, 0x31
};
const char f01_246 [] = {
                         0x05,
                         0x38, 0x45, 0x44, 0x45, 0x38
};
const char f01_247 [] = {
                         0x05,
                         0x08, 0x08, 0x2A, 0x08, 0x08
};
const char f01_248 [] = {
                         0x05,
                         0x08, 0x54, 0x3E, 0x15, 0x08
};
const char f01_249 [] = {
                         0x05,
                         0x3C, 0x41, 0x42, 0x20, 0x7C
};
const char f01_250 [] = {
                         0x05,
                         0x38, 0x40, 0x42, 0x21, 0x78
};
const char f01_251 [] = {
                         0x05,
                         0x38, 0x42, 0x41, 0x22, 0x78
};
const char f01_252 [] = {
                         0x05,
                         0x3C, 0x41, 0x40, 0x21, 0x7C
};
const char f01_253 [] = {
                         0x05,
                         0x0C, 0x50, 0x52, 0x51, 0x3C
};
const char f01_254 [] = {
                         0x05,
                         0x00, 0x41, 0x7F, 0x54, 0x08
};
const char f01_255 [] = {
                         0x05,
                         0x0C, 0x51, 0x50, 0x51, 0x3C
};

/* Font indexing table */
const int Font1 [] = {
          (int) &f01_00,
          (int) &f01_01,
          (int) &f01_02,
          (int) &f01_03,
          (int) &f01_04,
          (int) &f01_05,
          (int) &f01_06,
          (int) &f01_07,
          (int) &f01_08,
          (int) &f01_09,
          (int) &f01_10,
          (int) &f01_11,
          (int) &f01_12,
          (int) &f01_13,
          (int) &f01_14,
          (int) &f01_15,
          (int) &f01_16,
          (int) &f01_17,
          (int) &f01_18,
          (int) &f01_19,
          (int) &f01_20,
          (int) &f01_21,
          (int) &f01_22,
          (int) &f01_23,
          (int) &f01_24,
          (int) &f01_25,
          (int) &f01_26,
          (int) &f01_27,
          (int) &f01_28,
          (int) &f01_29,
          (int) &f01_30,
          (int) &f01_31,
          (int) &f01_32,
          (int) &f01_33,
          (int) &f01_34,
          (int) &f01_35,
          (int) &f01_36,
          (int) &f01_37,
          (int) &f01_38,
          (int) &f01_39,
          (int) &f01_40,
          (int) &f01_41,
          (int) &f01_42,
          (int) &f01_43,
          (int) &f01_44,
          (int) &f01_45,
          (int) &f01_46,
          (int) &f01_47,
          (int) &f01_48,
          (int) &f01_49,
          (int) &f01_50,
          (int) &f01_51,
          (int) &f01_52,
          (int) &f01_53,
          (int) &f01_54,
          (int) &f01_55,
          (int) &f01_56,
          (int) &f01_57,
          (int) &f01_58,
          (int) &f01_59,
          (int) &f01_60,
          (int) &f01_61,
          (int) &f01_62,
          (int) &f01_63,
          (int) &f01_64,
          (int) &f01_65,
          (int) &f01_66,
          (int) &f01_67,
          (int) &f01_68,
          (int) &f01_69,
          (int) &f01_70,
          (int) &f01_71,
          (int) &f01_72,
          (int) &f01_73,
          (int) &f01_74,
          (int) &f01_75,
          (int) &f01_76,
          (int) &f01_77,
          (int) &f01_78,
          (int) &f01_79,
          (int) &f01_80,
          (int) &f01_81,
          (int) &f01_82,
          (int) &f01_83,
          (int) &f01_84,
          (int) &f01_85,
          (int) &f01_86,
          (int) &f01_87,
          (int) &f01_88,
          (int) &f01_89,
          (int) &f01_90,
          (int) &f01_91,
          (int) &f01_92,
          (int) &f01_93,
          (int) &f01_94,
          (int) &f01_95,
          (int) &f01_96,
          (int) &f01_97,
          (int) &f01_98,
          (int) &f01_99,
          (int) &f01_100,
          (int) &f01_101,
          (int) &f01_102,
          (int) &f01_103,
          (int) &f01_104,
          (int) &f01_105,
          (int) &f01_106,
          (int) &f01_107,
          (int) &f01_108,
          (int) &f01_109,
          (int) &f01_110,
          (int) &f01_111,
          (int) &f01_112,
          (int) &f01_113,
          (int) &f01_114,
          (int) &f01_115,
          (int) &f01_116,
          (int) &f01_117,
          (int) &f01_118,
          (int) &f01_119,
          (int) &f01_120,
          (int) &f01_121,
          (int) &f01_122,
          (int) &f01_123,
          (int) &f01_124,
          (int) &f01_125,
          (int) &f01_126,
          (int) &f01_127,
          (int) &f01_128,
          (int) &f01_129,
          (int) &f01_130,
          (int) &f01_131,
          (int) &f01_132,
          (int) &f01_133,
          (int) &f01_134,
          (int) &f01_135,
          (int) &f01_136,
          (int) &f01_137,
          (int) &f01_138,
          (int) &f01_139,
          (int) &f01_140,
          (int) &f01_141,
          (int) &f01_142,
          (int) &f01_143,
          (int) &f01_144,
          (int) &f01_145,
          (int) &f01_146,
          (int) &f01_147,
          (int) &f01_148,
          (int) &f01_149,
          (int) &f01_150,
          (int) &f01_151,
          (int) &f01_152,
          (int) &f01_153,
          (int) &f01_154,
          (int) &f01_155,
          (int) &f01_156,
          (int) &f01_157,
          (int) &f01_158,
          (int) &f01_159,
          (int) &f01_160,
          (int) &f01_161,
          (int) &f01_162,
          (int) &f01_163,
          (int) &f01_164,
          (int) &f01_165,
          (int) &f01_166,
          (int) &f01_167,
          (int) &f01_168,
          (int) &f01_169,
          (int) &f01_170,
          (int) &f01_171,
          (int) &f01_172,
          (int) &f01_173,
          (int) &f01_174,
          (int) &f01_175,
          (int) &f01_176,
          (int) &f01_177,
          (int) &f01_178,
          (int) &f01_179,
          (int) &f01_180,
          (int) &f01_181,
          (int) &f01_182,
          (int) &f01_183,
          (int) &f01_184,
          (int) &f01_185,
          (int) &f01_186,
          (int) &f01_187,
          (int) &f01_188,
          (int) &f01_189,
          (int) &f01_190,
          (int) &f01_191,
          (int) &f01_192,
          (int) &f01_193,
          (int) &f01_194,
          (int) &f01_195,
          (int) &f01_196,
          (int) &f01_197,
          (int) &f01_198,
          (int) &f01_199,
          (int) &f01_200,
          (int) &f01_201,
          (int) &f01_202,
          (int) &f01_203,
          (int) &f01_204,
          (int) &f01_205,
          (int) &f01_206,
          (int) &f01_207,
          (int) &f01_208,
          (int) &f01_209,
          (int) &f01_210,
          (int) &f01_211,
          (int) &f01_212,
          (int) &f01_213,
          (int) &f01_214,
          (int) &f01_215,
          (int) &f01_216,
          (int) &f01_217,
          (int) &f01_218,
          (int) &f01_219,
          (int) &f01_220,
          (int) &f01_221,
          (int) &f01_222,
          (int) &f01_223,
          (int) &f01_224,
          (int) &f01_225,
          (int) &f01_226,
          (int) &f01_227,
          (int) &f01_228,
          (int) &f01_229,
          (int) &f01_230,
          (int) &f01_231,
          (int) &f01_232,
          (int) &f01_233,
          (int) &f01_234,
          (int) &f01_235,
          (int) &f01_236,
          (int) &f01_237,
          (int) &f01_238,
          (int) &f01_239,
          (int) &f01_240,
          (int) &f01_241,
          (int) &f01_242,
          (int) &f01_243,
          (int) &f01_244,
          (int) &f01_245,
          (int) &f01_246,
          (int) &f01_247,
          (int) &f01_248,
          (int) &f01_249,
          (int) &f01_250,
          (int) &f01_251,
          (int) &f01_252,
          (int) &f01_253,
          (int) &f01_254,
          (int) &f01_255

};


//----------------------------------------------------------------------
// Font 2- Akzidenz Grotesk 10pt
//----------------------------------------------------------------------
const char f02_default [] = {
                              0x47,
                              0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0xFE,
                              0x1F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F
};

const char f02_29 [] = {
                         0x48,
                         0xFE, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0x3E, 0xFE,
                         0x1F, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x1F
};

const char f02_30 [] = {
                         0x48,
                         0xFE, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xE2, 0xFE,
                         0x1F, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1F
};

const char f02_31 [] = {
                         0x48,
                         0xFE, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 0xFE,
                         0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F
};

const char f02_32 [] = {
                         0x48,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const char f02_33 [] = {
                         0x43,
                         0xFE, 0xFE, 0xFE,
                         0x0E, 0x0E, 0x0E
};
const char f02_34 [] = {
                         0x45,
                         0x7E, 0x7E, 0x00, 0x7E, 0x7E,
                         0x00, 0x00, 0x00, 0x00, 0x00
};
const char f02_35 [] = {
                         0x4B,
                         0x80, 0x98, 0xF8, 0xFF, 0xFF, 0x9F, 0xF8, 0xFF, 0xFF, 0x9F, 0x18,
                         0x01, 0x0F, 0x0F, 0x0F, 0x01, 0x0F, 0x0F, 0x0F, 0x01, 0x01, 0x00
};
const char f02_36 [] = {
                         0x49,
                         0x78, 0xFC, 0xFC, 0xCF, 0xCF, 0xCC, 0x9C, 0x98, 0x00,
                         0x0C, 0x1C, 0x18, 0x78, 0x79, 0x19, 0x1F, 0x0F, 0x07
};
const char f02_37 [] = {
                         0x4E,
                         0x78, 0xFC, 0x84, 0x84, 0xFC, 0xF8, 0xC0, 0xE0, 0x78, 0xBC, 0x9C, 0x84, 0x80, 0x00,
                         0x00, 0x00, 0x10, 0x1C, 0x1E, 0x0F, 0x03, 0x01, 0x0F, 0x1F, 0x10, 0x10, 0x1F, 0x0F
};
const char f02_38 [] = {
                         0x4A,
                         0x00, 0x80, 0xF8, 0xFC, 0xEC, 0xEC, 0x7C, 0x38, 0x00, 0x00,
                         0x07, 0x0F, 0x1F, 0x19, 0x19, 0x1F, 0x0F, 0x0E, 0x1F, 0x1B
};
const char f02_39 [] = {
                         0x42,
                         0x0E, 0x0E,
                         0x00, 0x00
};
const char f02_40 [] = {
                         0x45,
                         0xE0, 0xF0, 0xFC, 0x1E, 0x02,
                         0x07, 0x1F, 0x3F, 0x70, 0x40
};
const char f02_41 [] = {
                         0x45,
                         0x02, 0x0E, 0xFC, 0xF0, 0xE0,
                         0x40, 0x78, 0x3F, 0x1F, 0x07
};
const char f02_42 [] = {
                         0x48,
                         0x30, 0xF0, 0xE0, 0xF8, 0xF8, 0xE0, 0xF0, 0x30,
                         0x06, 0x07, 0x03, 0x0F, 0x0F, 0x03, 0x07, 0x06
};
const char f02_43 [] = {
                         0x47,
                         0x80, 0x80, 0xF0, 0xF0, 0xF0, 0x80, 0x80,
                         0x01, 0x01, 0x0F, 0x0F, 0x0F, 0x01, 0x01
};
const char f02_44 [] = {
                         0x44,
                         0x00, 0x00, 0x00, 0x00,
                         0x4E, 0x2E, 0x3E, 0x1E
};
const char f02_45 [] = {
                         0x44,
                         0x80, 0x80, 0x80, 0x80,
                         0x01, 0x01, 0x01, 0x01
};
const char f02_46 [] = {
                         0x44,
                         0x00, 0x00, 0x00, 0x00,
                         0x0E, 0x0E, 0x0E, 0x0E
};
const char f02_47 [] = {
                         0x47,
                         0x00, 0x00, 0xC0, 0xF8, 0xFE, 0x3E, 0x06,
                         0x18, 0x1F, 0x1F, 0x07, 0x00, 0x00, 0x00
};
const char f02_48 [] = {
                         0x48,
                         0xF0, 0xFC, 0xFE, 0x06, 0x06, 0xFE, 0xFC, 0xF0,
                         0x01, 0x07, 0x0F, 0x0C, 0x0C, 0x0F, 0x07, 0x01
};

const char f02_49 [] = {
                         0x45,
                         0x18, 0x18, 0xFC, 0xFE, 0xFE,
                         0x00, 0x00, 0x0F, 0x0F, 0x0F
};
const char f02_50 [] = {
                         0x47,
                         0x1C, 0x1E, 0x06, 0x86, 0xFE, 0xFE, 0x3C,
                         0x0C, 0x0E, 0x0F, 0x0F, 0x0D, 0x0C, 0x0C
};
const char f02_51 [] = {
                         0x48,
                         0x0C, 0x0E, 0x0E, 0x66, 0x66, 0xFE, 0xFE, 0x9C,
                         0x07, 0x0F, 0x0F, 0x0C, 0x0C, 0x0F, 0x07, 0x03
};
const char f02_52 [] = {
                         0x48,
                         0x80, 0xE0, 0x70, 0x3C, 0xFE, 0xFE, 0xFE, 0x00,
                         0x03, 0x03, 0x03, 0x03, 0x0F, 0x0F, 0x0F, 0x03
};
const char f02_53 [] = {
                         0x48,
                         0x7E, 0x7E, 0x3E, 0x36, 0x36, 0xF6, 0xE6, 0xC6,
                         0x03, 0x07, 0x0F, 0x0C, 0x0C, 0x0F, 0x07, 0x03
};
const char f02_54 [] = {
                         0x48,
                         0xF0, 0xFC, 0xFE, 0x6E, 0x66, 0xE6, 0xEE, 0xCC,
                         0x03, 0x07, 0x0F, 0x0C, 0x0C, 0x0F, 0x07, 0x03
};

const char f02_55 [] = {
                         0x48,
                         0x06, 0x06, 0x06, 0xC6, 0xE6, 0xFE, 0x3E, 0x0E,
                         0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x01, 0x00, 0x00
};

const char f02_56 [] = {
                         0x48,
                         0x98, 0xFC, 0xFE, 0x66, 0x66, 0xFE, 0xFC, 0x98,
                         0x03, 0x07, 0x0F, 0x0C, 0x0C, 0x0F, 0x07, 0x03
};

const char f02_57 [] = {
                         0x48,
                         0x78, 0xFC, 0xFE, 0xC6, 0xC6, 0xFE, 0xFC, 0xF8,
                         0x06, 0x0E, 0x0C, 0x0C, 0x0E, 0x0F, 0x07, 0x01
};
const char f02_58 [] = {
                         0x43,
                         0x38, 0x38, 0x38,
                         0x0E, 0x0E, 0x0E
};
const char f02_59 [] = {
                         0x43,
                         0x38, 0x38, 0x38,
                         0x6E, 0x3E, 0x1E
};

const char f02_60 [] = {
                         0x48,
                         0x80, 0xC0, 0xC0, 0xE0, 0x60, 0x60, 0x70, 0x70,
                         0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07
};
const char f02_61 [] = {
                         0x48,
                         0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
                         0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06
};
const char f02_62 [] = {
                         0x48,
                         0x70, 0x70, 0x60, 0x60, 0xE0, 0xC0, 0xC0, 0x80,
                         0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00
};
const char f02_63 [] = {
                         0x49,
                         0x00, 0x18, 0x1C, 0x9E, 0xCE, 0xC6, 0xFE, 0x7E, 0x3C,
                         0x00, 0x00, 0x00, 0x1D, 0x1D, 0x1D, 0x00, 0x00, 0x00
};
const char f02_64 [] = {
                         0x4C,
                         0xE0, 0xF0, 0x18, 0xC8, 0xE4, 0x64, 0x34, 0xF4, 0xE4, 0x48, 0x18, 0xE0,
                         0x03, 0x07, 0x0C, 0x0B, 0x17, 0x17, 0x16, 0x17, 0x17, 0x0E, 0x0B, 0x01
};
const char f02_65 [] = {
                         0x49,
                         0x80, 0xF0, 0xFC, 0x3E, 0x0E, 0x3E, 0xFC, 0xF0, 0x80,
                         0x0F, 0x0F, 0x0F, 0x03, 0x03, 0x03, 0x0F, 0x0F, 0x0F
};
const char f02_66 [] = {
                         0x4A,
                         0xFE, 0xFE, 0xFE, 0x66, 0x66, 0x66, 0xFE, 0xFE, 0xDC, 0x00,
                         0x0F, 0x0F, 0x0F, 0x0C, 0x0C, 0x0C, 0x0C, 0x0F, 0x07, 0x03
};
const char f02_67 [] = {
                         0x4A,
                         0xF0, 0xF8, 0xFC, 0x1E, 0x0E, 0x06, 0x06, 0x0E, 0x0C, 0x08,
                         0x01, 0x03, 0x07, 0x0F, 0x0E, 0x0C, 0x0C, 0x0E, 0x06, 0x02
};
const char f02_68 [] = {
                         0x4A,
                         0xFE, 0xFE, 0xFE, 0x06, 0x06, 0x06, 0x0E, 0xFC, 0xFC, 0xF0,
                         0x0F, 0x0F, 0x0F, 0x0C, 0x0C, 0x0C, 0x0E, 0x07, 0x07, 0x01
};

const char f02_69 [] = {
                         0x48,
                         0xFE, 0xFE, 0xFE, 0x66, 0x66, 0x66, 0x66, 0x66,
                         0x0F, 0x0F, 0x0F, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C
};
const char f02_70 [] = {
                         0x48,
                         0xFE, 0xFE, 0xFE, 0x66, 0x66, 0x66, 0x66, 0x66,
                         0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00
};
const char f02_71 [] = {
                         0x4B,
                         0xF0, 0xF8, 0xFC, 0x1E, 0x0E, 0x06, 0xC6, 0xC6, 0xCE, 0xCE, 0xCC,
                         0x01, 0x07, 0x07, 0x0F, 0x0E, 0x0C, 0x0C, 0x0C, 0x07, 0x0F, 0x0F
};
const char f02_72 [] = {
                         0x4A,
                         0xFE, 0xFE, 0xFE, 0x60, 0x60, 0x60, 0x60, 0xFE, 0xFE, 0xFE,
                         0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F
};
const char f02_73 [] = {
                         0x43,
                         0xFE, 0xFE, 0xFE,
                         0x0F, 0x0F, 0x0F
};
const char f02_74 [] = {
                         0x45,
                         0x00, 0x00, 0xFE, 0xFE, 0xFE,
                         0x0C, 0x0C, 0x0F, 0x0F, 0x07
};
const char f02_75 [] = {
                         0x4B,
                         0xFE, 0xFE, 0xFE, 0xE0, 0xF0, 0xF8, 0x9C, 0x0E, 0x06, 0x02, 0x00,
                         0x0F, 0x0F, 0x0F, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x0E, 0x0C, 0x08
};
const char f02_76 [] = {
                         0x47,
                         0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00,
                         0x0F, 0x0F, 0x0F, 0x0C, 0x0C, 0x0C, 0x0C
};
const char f02_77 [] = {
                         0x4C,
                         0xFE, 0xFE, 0xFE, 0x1E, 0xF8, 0x80, 0x80, 0xF8, 0x1E, 0xFE, 0xFE, 0xFE,
                         0x0F, 0x0F, 0x0F, 0x00, 0x01, 0x0F, 0x0F, 0x01, 0x00, 0x0F, 0x0F, 0x0F
};
const char f02_78 [] = {
                         0x4A,
                         0xFE, 0xFE, 0xFE, 0x38, 0xF0, 0xC0, 0x80, 0xFE, 0xFE, 0xFE,
                         0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x03, 0x0F, 0x0F, 0x0F, 0x0F
};
const char f02_79 [] = {
                         0x4C,
                         0xF0, 0xF8, 0xFC, 0x1E, 0x0E, 0x06, 0x06, 0x0E, 0x1E, 0xFC, 0xF8, 0xF0,
                         0x01, 0x03, 0x07, 0x0F, 0x0E, 0x0C, 0x0C, 0x0E, 0x0F, 0x07, 0x03, 0x01
};
const char f02_80 [] = {
                         0x4A,
                         0xFE, 0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xFE, 0x7C, 0x38,
                         0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 ,0x00
};
const char f02_81 [] = {
                         0x4C,
                         0xF0, 0xF8, 0xFC, 0x0E, 0x0E, 0x06, 0x0E, 0x1E, 0xFC, 0xF8, 0xF0, 0x00,
                         0x01, 0x03, 0x07, 0x0F, 0x0E, 0x0C, 0x0E, 0x0F, 0x07, 0x0F, 0x1D, 0x18
};
const char f02_82 [] = {
                         0x4A,
                         0xFE, 0xFE, 0xFE, 0xC6, 0xC6, 0xC6, 0xC6, 0xFE, 0x7C, 0x38,
                         0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0E, 0x0C
};
const char f02_83 [] = {
                         0x49,
                         0x38, 0x7C, 0x7E, 0x66, 0x66, 0xE6, 0xEE, 0xCE, 0xCC,
                         0x06, 0x0E, 0x0E, 0x0C, 0x0C, 0x0C, 0x0F, 0x07, 0x03
};
const char f02_84 [] = {
                         0x49,
                         0x06, 0x06, 0x06, 0xFE, 0xFE, 0xFE, 0x06, 0x06, 0x06,
                         0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00
};
const char f02_85 [] = {
                         0x4A,
                         0xFE, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFE,
                         0x03, 0x07, 0x0F, 0x0E, 0x0C, 0x0C, 0x0E, 0x0F, 0x07, 0x03
};
const char f02_86 [] = {
                         0x49,
                         0x1E, 0xFE, 0xFE, 0xE0, 0x00, 0xE0, 0xFE, 0xFE, 0x1E,
                         0x00, 0x00, 0x03, 0x0F, 0x0E, 0x0F, 0x03, 0x00, 0x00

};
const char f02_87 [] = {
                         0x4F,
                         0x1E, 0xFE, 0xFE, 0xE0, 0x00, 0xE0, 0xFE, 0x3E, 0xFE, 0xE0, 0x00, 0xE0, 0xFE, 0xFE, 0x1E,
                         0x00, 0x00, 0x07, 0x0F, 0x0E, 0x0F, 0x07, 0x00, 0x07, 0x0F, 0x0F, 0x0F, 0x07, 0x00, 0x00
};
const char f02_88 [] = {
                         0x4B,
                         0x02, 0x06, 0x1E, 0xBe, 0xF8, 0xF0, 0xF8, 0xBE, 0x1E, 0x06, 0x02,
                         0x08, 0x0C, 0x0F, 0x0F, 0x03, 0x01, 0x03, 0x0F, 0x0F, 0x0C, 0x08
};
const char f02_89 [] = {
                         0x4B,
                         0x02, 0x0E, 0x1E, 0x3E, 0xF8, 0xE0, 0xF8, 0x3E, 0x1E, 0x0E, 0x02,
                         0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00
};
const char f02_90 [] = {
                         0x4A,
                         0x06, 0x06, 0x86, 0xc6, 0xE6, 0x76, 0x3E, 0x1E, 0x0E, 0x06,
                         0x0E, 0x0F, 0x0F, 0x0D, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C, 0x0C
};
const char f02_91 [] = {
                         0x45,
                         0xFE, 0xFE, 0xFE, 0x02, 0x02,
                         0x3F, 0x3F, 0x3F, 0x20, 0x20
};
const char f02_92 [] = {
                         0x46,
                         0x00, 0x00, 0x1E, 0xFE, 0xE0, 0x00,
                         0x00, 0x00, 0x00, 0x01, 0x1F, 0x1E
};
const char f02_93 [] = {
                         0x45,
                         0x02, 0x02, 0xFE, 0xFE, 0xFE,
                         0x20, 0x20, 0x3F, 0x3F, 0x3F
};
const char f02_94 [] = {
                         0x47,
                         0x60, 0x78, 0x3E, 0x0E, 0x3E, 0x78, 0x60,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
const char f02_95 [] = {
                         0x48,
                         0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                         0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20
};
const char f02_96 [] = {
                         0x44,
                         0x02, 0x06, 0x06, 0x04,
                         0x00, 0x00, 0x00, 0x00
};
const char f02_97 [] = {
                         0x48,
                         0x30, 0xB8, 0xB8, 0xD8, 0xD8, 0xF8, 0xF8, 0xF0,
                         0x07, 0x0F, 0x0F, 0x0C, 0x0C, 0x07, 0x0F, 0x0F
};
const char f02_98 [] = {
                         0x48,
                         0xFE, 0xFE, 0xFE, 0x10, 0x18, 0xF8, 0xF8, 0xE0,
                         0x0F, 0x0F, 0x0F, 0x0C, 0x0C, 0x0F, 0x07, 0x03
};
const char f02_99 [] = {
                         0x48,
                         0xE0, 0xF0, 0xF8, 0x38, 0x18, 0x18, 0x38, 0x30,
                         0x03, 0x07, 0x0F, 0x0E, 0x0C, 0x0C, 0x0E, 0x06
};
const char f02_100 [] = {
                          0x48,
                          0xF0, 0xF8, 0xF8, 0x18, 0x10, 0xFE, 0xFE, 0xFE,
                          0x07, 0x0F, 0x0F, 0x0C, 0x0C, 0x0F, 0x0F, 0x0F
};
const char f02_101 [] = {
                          0x48,
                          0xE0, 0xF0, 0xF8, 0xD8, 0xD8, 0xF8, 0xF0, 0xE0,
                          0x03, 0x07, 0x0F, 0x0E, 0x0C, 0x0C, 0x0E, 0x06
};
const char f02_102 [] = {
                          0x46,
                          0x30, 0xF8, 0xFC, 0xFE, 0x36, 0x36,
                          0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00
};
const char f02_103 [] = {
                          0x48,
                          0xE0, 0xF0, 0xF8, 0x18, 0x18, 0xF8, 0xF8, 0xF8,
                          0x30, 0x73, 0x77, 0x66, 0x66, 0x7F, 0x3F, 0x1F
};
const char f02_104 [] = {
                          0x48,
                          0xFE, 0xFE, 0xFE, 0x10, 0x18, 0xF8, 0xF8, 0xF0,
                          0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x0F
};
const char f02_105 [] = {
                          0x43,
                          0xF6, 0xF6, 0xF6,
                          0x0F, 0x0F, 0x0F
};
const char f02_106 [] = {
                          0x44,
                          0x00, 0xF6, 0xF6, 0xF6,
                          0x60, 0x7F, 0x7F, 0x3F
};
const char f02_107 [] = {
                          0x48,
                          0xFE, 0xFE, 0xFE, 0xE0, 0xF0, 0xB8, 0x18, 0x08,
                          0x0F, 0x0F, 0x0F, 0x01, 0x03, 0x0F, 0x0E, 0x0C
};
const char f02_108 [] = {
                          0x43,
                          0xFE, 0xFE, 0xFE,
                          0x0F, 0x0F, 0x0F
};
const char f02_109 [] = {
                          0x4D,
                          0xF8, 0xF8, 0xF8, 0x10, 0x18, 0xF8, 0xF8, 0xF0, 0x18, 0x18, 0xF8, 0xF8, 0xF0,
                          0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x0F
};
const char f02_110 [] = {
                          0x48,
                          0xF8, 0xF8, 0xF8, 0x10, 0x18, 0xF8, 0xF8, 0xF0,
                          0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x0F, 0x0F, 0x0F
};
const char f02_111 [] = {
                          0x49,
                          0xE0, 0xF0, 0xF8, 0x38, 0x18, 0x38, 0xF8, 0xF0, 0xE0,
                          0x03, 0x07, 0x0F, 0x0E, 0x0C, 0x0E, 0x0F, 0x07, 0x03
};
const char f02_112 [] = {
                          0x48,
                          0xF8, 0xF8, 0xF8, 0x18, 0x18, 0xF8, 0xF0, 0xE0,
                          0x7F, 0x7F, 0x7F, 0x0C, 0x0C, 0x0F, 0x07, 0x03
};
const char f02_113 [] = {
                          0x48,
                          0xE0, 0xF0, 0xF8, 0x18, 0x18, 0xF8, 0xF8, 0xF8,
                          0x03, 0x07, 0x0F, 0x0C, 0x0C, 0x7F, 0x7F, 0x7F
};
const char f02_114 [] = {
                          0x48,
                          0xF8, 0xF8, 0xF8, 0x30, 0x18, 0x18, 0x38, 0x30,
                          0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00
};
const char f02_115 [] = {
                          0x47,
                          0x70, 0xF8, 0xF8, 0xD8, 0x98, 0xB8, 0x30,
                          0x06, 0x0E, 0x0C, 0x0C, 0x0F, 0x0F, 0x07
};
const char f02_116 [] = {
                          0x45,
                          0x30, 0xFE, 0xFE, 0xFE, 0x30,
                          0x00, 0x07, 0x0F, 0x0F, 0x0C
};
const char f02_117 [] = {
                          0x48,
                          0xF8, 0xF8, 0xF8, 0x00, 0x00, 0xF8, 0xF8, 0xF8,
                          0x03, 0x07, 0x0F, 0x0C, 0x0C, 0x0F, 0x0F, 0x07
};
const char f02_118 [] = {
                          0x48,
                          0x38, 0xF8, 0xF8, 0x80, 0x80, 0xF8, 0xF8, 0x38,
                          0x00, 0x01, 0x07, 0x0F, 0x0F, 0x07, 0x01, 0x00
};
const char f02_119 [] = {
                          0x4B,
                          0x38, 0xF8, 0xF8, 0x00, 0xF8, 0x78, 0xF8, 0x00, 0xF8, 0xF8, 0x38,
                          0x00, 0x03, 0x0F, 0x0F, 0x0F, 0x00, 0x0F, 0x0F, 0x0F, 0x03, 0x00
};
const char f02_120 [] = {
                          0x47,
                          0x18, 0x78, 0xF8, 0xE0, 0xF8, 0x78, 0x18,
                          0x0C, 0x0F, 0x0F, 0x03, 0x0F, 0x0F, 0x0C
};
const char f02_121 [] = {
                          0x48,
                          0x38, 0xF8, 0xF8, 0x00, 0x80, 0xF8, 0xF8, 0x38,
                          0x00, 0x63, 0x7F, 0x7F, 0x3F, 0x0F, 0x01, 0x00
};
const char f02_122 [] = {
                          0x48,
                          0x18, 0x18, 0x98, 0xD8, 0xF8, 0xF8, 0x78, 0x38,
                          0x0E, 0x0F, 0x0F, 0x0F, 0x0D, 0x0C, 0x0C, 0x0C
};
const char f02_123 [] = {
                          0x46,
                          0xC0, 0xC0, 0xFC, 0xFE, 0x3E, 0x02,
                          0x00, 0x00, 0x1F, 0x3F, 0x3E, 0x20
};
const char f02_124 [] = {
                          0x42,
                          0xFE, 0xFE,
                          0x7F, 0x7F
};
const char f02_125 [] = {
                          0x46,
                          0x02, 0x3E, 0xFE, 0xFC, 0xC0, 0xC0,
                          0x20, 0x3E, 0x3F, 0x1F, 0x00, 0x00
};
const char f02_126 [] = {
                          0x49,
                          0x00, 0x80, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0xC0, 0x40,
                          0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00
};
/* Font Index Table */

const int Font2 [] = {
          (int) &f02_default,           // 00
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 10
          (int) &f02_default,           // 11
          (int) &f02_default,           // 12
          (int) &f02_default,           // 13
          (int) &f02_default,           // 14
          (int) &f02_default,           // 15
          (int) &f02_default,           // 16
          (int) &f02_default,           // 17
          (int) &f02_default,           // 18
          (int) &f02_default,           // 19
          (int) &f02_default,           // 20
          (int) &f02_default,           // 21
          (int) &f02_default,           // 22
          (int) &f02_default,           // 23
          (int) &f02_default,           // 24
          (int) &f02_default,           // 25
          (int) &f02_default,           // 26
          (int) &f02_default,           // 27
          (int) &f02_default,           // 28
          (int) &f02_29,                // 29
          (int) &f02_30,                // 30
          (int) &f02_31,                // 31
          (int) &f02_32,                // 32
          (int) &f02_33,                // 33
          (int) &f02_34,                // 34
          (int) &f02_35,                // 35
          (int) &f02_36,
          (int) &f02_37,
          (int) &f02_38,
          (int) &f02_39,
          (int) &f02_40,
          (int) &f02_41,
          (int) &f02_42,
          (int) &f02_43,
          (int) &f02_44,
          (int) &f02_45,
          (int) &f02_46,
          (int) &f02_47,
          (int) &f02_48,
          (int) &f02_49,
          (int) &f02_50,
          (int) &f02_51,
          (int) &f02_52,
          (int) &f02_53,
          (int) &f02_54,
          (int) &f02_55,
          (int) &f02_56,
          (int) &f02_57,
          (int) &f02_58,
          (int) &f02_59,
          (int) &f02_60,
          (int) &f02_61,
          (int) &f02_62,
          (int) &f02_63,
          (int) &f02_64,
          (int) &f02_65,
          (int) &f02_66,
          (int) &f02_67,
          (int) &f02_68,
          (int) &f02_69,
          (int) &f02_70,
          (int) &f02_71,
          (int) &f02_72,
          (int) &f02_73,
          (int) &f02_74,
          (int) &f02_75,
          (int) &f02_76,
          (int) &f02_77,
          (int) &f02_78,
          (int) &f02_79,
          (int) &f02_80,
          (int) &f02_81,
          (int) &f02_82,
          (int) &f02_83,
          (int) &f02_84,
          (int) &f02_85,
          (int) &f02_86,
          (int) &f02_87,
          (int) &f02_88,
          (int) &f02_89,
          (int) &f02_90,
          (int) &f02_91,
          (int) &f02_92,
          (int) &f02_93,
          (int) &f02_94,
          (int) &f02_95,
          (int) &f02_96,
          (int) &f02_97,
          (int) &f02_98,
          (int) &f02_99,
          (int) &f02_100,
          (int) &f02_101,
          (int) &f02_102,
          (int) &f02_103,
          (int) &f02_104,
          (int) &f02_105,
          (int) &f02_106,
          (int) &f02_107,
          (int) &f02_108,
          (int) &f02_109,
          (int) &f02_110,
          (int) &f02_111,
          (int) &f02_112,
          (int) &f02_113,
          (int) &f02_114,
          (int) &f02_115,
          (int) &f02_116,
          (int) &f02_117,
          (int) &f02_118,
          (int) &f02_119,
          (int) &f02_120,
          (int) &f02_121,
          (int) &f02_122,
          (int) &f02_123,
          (int) &f02_124,
          (int) &f02_125,
          (int) &f02_126,
          (int) &f02_default,           // 127
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 137
          (int) &f02_default,           // 138
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 148
          (int) &f02_default,           // 149
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 159
          (int) &f02_default,           // 160
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 170
          (int) &f02_default,           // 171
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 181
          (int) &f02_default,           // 182
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 192
          (int) &f02_default,           // 193
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 203
          (int) &f02_default,           // 204
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 214
          (int) &f02_default,           // 215
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 225
          (int) &f02_default,           // 226
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 236
          (int) &f02_default,           // 237
          (int) &f02_default,           // 01
          (int) &f02_default,           // 02
          (int) &f02_default,           // 03
          (int) &f02_default,           // 04
          (int) &f02_default,           // 05
          (int) &f02_default,           // 06
          (int) &f02_default,           // 07
          (int) &f02_default,           // 08
          (int) &f02_default,           // 09
          (int) &f02_default,           // 247
          (int) &f02_default,           // 248
          (int) &f02_default,           // 249
          (int) &f02_default,           // 250
          (int) &f02_default,           // 251
          (int) &f02_default,           // 252
          (int) &f02_default,           // 253
          (int) &f02_default,           // 254
          (int) &f02_default           // 255
};

//----------------------------------------------------------------------
// Font 3 - NSE-1 from Nokia NSE-1
//----------------------------------------------------------------------

const char f03_00 [] = {
                        0x05,
                        0x55, 0xAA, 0x55, 0xAA, 0x55
};
const char f03_01 [] = {
                         0x05,
                         0x7F, 0x7F, 0x7F, 0x7F, 0x7F
};
const char f03_02 [] = {
                         0x05,
                         0x7F, 0x41, 0x41, 0x41, 0x7F
};
const char f03_32 [] = {
                         0x05,
                         0x00, 0x00, 0x00, 0x00, 0x00
};
const char f03_33 [] = {
                         0x02,
                         0x5F, 0x5F
};
const char f03_34 [] = {
                         0x03,
                         0x03, 0x00, 0x03
};
const char f03_35 [] = {
                         0x05,
                         0x36, 0x7F, 0x36, 0x7F, 0x36
};
const char f03_36 [] = {
                         0x05,
                         0x4C, 0xFF, 0x5A, 0xFF, 0x32
};
const char f03_37 [] = {
                         0x06,
                         0x03, 0x63, 0x38, 0x0E, 0x63, 0x60
};
const char f03_38 [] = {
						0x06,
						0x3A, 0x7F, 0x4D, 0x7F, 0x32, 0x78
};
const char f03_39 [] = {
                         0x01,
                         0x03
};
const char f03_40 [] = {
                         0x03,
                         0x3C, 0x7E, 0x81
};
const char f03_41 [] = {
                         0x03,
                         0x81, 0x7E, 0x3C
};
const char f03_42 [] = {
                         0x05,
                         0x36, 0x1C, 0x7F, 0x1C, 0x36
};
const char f03_43 [] = {
                         0x05,
                         0x08, 0x08, 0x3E, 0x08, 0x08
};
const char f03_44 [] = {
                         0x02,
                         0xC0, 0x60
};
const char f03_45 [] = {
                         0x04,
                         0x08, 0x08, 0x08, 0x08, 0x08
};
const char f03_46 [] = {
                         0x02,
                         0x60, 0x60
};
const char f03_47 [] = {
                         0x03,
                         0x70, 0x1C, 0x07
};
const char f03_48 [] = {
                         0x05,
                         0x3E, 0x7F, 0x41, 0x7F, 0x3E
};
const char f03_49 [] = {
                         0x03,
                         0x02, 0x7F, 0x7F
};
const char f03_50 [] = {
                         0x05,
                         0x71, 0x79, 0x49, 0x4F, 0x46
};
const char f03_51 [] = {
                         0x05,
                         0x41, 0x49, 0x49, 0x7F, 0x36
};
const char f03_52 [] = {
                         0x05,
                         0x18, 0x14, 0x12, 0x7F, 0x7F
};
const char f03_53 [] = {
                         0x05,
                         0x47, 0x45, 0x45, 0x7D, 0x38
};
const char f03_54 [] = {
                         0x05,
                         0x3E, 0x7F, 0x45, 0x7D, 0x38
};
const char f03_55 [] = {
                         0x05,
                         0x01, 0x79, 0x7D, 0x0F, 0x03
};
const char f03_56 [] = {
                         0x05,
                         0x36, 0x7F, 0x49, 0x7F, 0x36
};
const char f03_57 [] = {
                         0x05,
                         0x0E, 0x5F, 0x51, 0x7F, 0x3E
};
const char f03_58 [] = {
                         0x02,
                         0x6C, 0x6C
};
const char f03_59 [] = {
                         0x02,
                         0xCC, 0x6C
};
const char f03_60 [] = {
                         0x04,
                         0x08, 0x1C, 0x36, 0x63
};
const char f03_61 [] = {
                         0x04,
                         0x28, 0x28, 0x28, 0x28
};
const char f03_62 [] = {
                         0x04,
                         0x63, 0x36, 0x1C, 0x08
};
const char f03_63 [] = {
                         0x05,
                         0x01, 0x59, 0x5D, 0x07, 0x02
};
const char f03_64 [] = {
                         0x06,
                         0x7C, 0xFE, 0xAA, 0xBA, 0xBE, 0x3C
};
const char f03_65 [] = {
                         0x05,
                         0x7E, 0x7F, 0x11, 0x7F, 0x7E
};
const char f03_66 [] = {
                         0x05,
                         0x7F, 0x7F, 0x45, 0x7F, 0x3A
};
const char f03_67 [] = {
                         0x05,
                         0x3E, 0x7F, 0x41, 0x41, 0x41
};
const char f03_68 [] = {
                         0x05,
                         0x7F, 0x7F, 0x41, 0x7F, 0x3E
};
const char f03_69 [] = {
                         0x05,
                         0x7F, 0x7F, 0x45, 0x45, 0x41
};
const char f03_70 [] = {
                         0x05,
                         0x7F, 0x7F, 0x05, 0x05, 0x01
};
const char f03_71 [] = {
                         0x05,
                         0x3E, 0x7F, 0x41, 0x79, 0x78
};
const char f03_72 [] = {
                         0x05,
                         0x7F, 0x7F, 0x04, 0x7F, 0x7F
};
const char f03_73 [] = {
                         0x02,
                         0x7F, 0x7F
};
const char f03_74 [] = {
                         0x04,
                         0x40, 0x40, 0x7F, 0x3F
};
const char f03_75 [] = {
                         0x06,
                         0x7F, 0x7F, 0x1C, 0x36, 0x63, 0x41
};
const char f03_76 [] = {
                         0x04,
                         0x7F, 0x7F, 0x40, 0x40
};
const char f03_77 [] = {
                         0x07,
                         0x7F, 0x7E, 0x0C, 0x18, 0x0C, 0x7E, 0x7F
};
const char f03_78 [] = {
                         0x06,
                         0x7F, 0x7E, 0x0C, 0x18, 0x3F, 0x7F
};
const char f03_79 [] = {
                         0x06,
                         0x3E, 0x7F, 0x41, 0x41, 0x7F, 0x3E
};
const char f03_80 [] = {
                         0x05,
                         0x7F, 0x7F, 0x11, 0x1F, 0x0E
};
const char f03_81 [] = {
                         0x06,
                         0x3E, 0x7F, 0x41, 0x61, 0xFF, 0xBE
};
const char f03_82 [] = {
                         0x05,
                         0x7F, 0x7F, 0x11, 0x7F, 0x4E
};
const char f03_83 [] = {
                         0x04,
                         0x46, 0x4F, 0x79, 0x31
};
const char f03_84 [] = {
                         0x06,
                         0x01, 0x01, 0x7F, 0x7F, 0x01, 0x01
};
const char f03_85 [] = {
                         0x05,
                         0x3F, 0x7F, 0x40, 0x7F, 0x3F
};
const char f03_86 [] = {
                         0x06,
                         0x07, 0x1F, 0x78, 0x78, 0x1F, 0x07
};
const char f03_87 [] = {
                         0x07,
                         0x0F, 0x7F, 0x78, 0x3C, 0x78, 0x7F, 0x1F
};
const char f03_88 [] = {
                         0x06,
                         0x63, 0x77, 0x1C, 0x1C, 0x77, 0x63
};
const char f03_89 [] = {
                         0x06,
                         0x03, 0x07, 0x7C, 0x7C, 0x07, 0x03
};
const char f03_90 [] = {
                         0x05,
                         0x71, 0x79, 0x5D, 0x4F, 0x47
};
const char f03_91 [] = {
                         0x05,
                         0x00, 0x7F, 0x41, 0x41, 0x00
};
const char f03_92 [] = {
                         0x05,
                         0x02, 0x04, 0x08, 0x10, 0x20
};
const char f03_93 [] = {
                         0x05,
                         0x00, 0x41, 0x41, 0x7F, 0x00
};
const char f03_94 [] = {
                         0x05,
                         0x04, 0x02, 0x01, 0x02, 0x04
};
const char f03_95 [] = {
                         0x05,
                         0x40, 0x40, 0x40, 0x40, 0x40
};
const char f03_96 [] = {
                         0x05,
                         0x00, 0x01, 0x02, 0x04, 0x00
};
const char f03_97 [] = {
                         0x05,
                         0x20, 0x54, 0x54, 0x54, 0x78
};
const char f03_98 [] = {
                         0x05,
                         0x7F, 0x48, 0x44, 0x44, 0x38
};
const char f03_99 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x44, 0x20
};
const char f03_100 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x48, 0x7F
};
const char f03_101 [] = {
                         0x05,
                         0x38, 0x54, 0x54, 0x54, 0x18
};
const char f03_102 [] = {
                         0x05,
                         0x08, 0x7E, 0x09, 0x09, 0x02
};
const char f03_103 [] = {
                         0x05,
                         0x08, 0x54, 0x54, 0x54, 0x3C
};
const char f03_104 [] = {
                         0x05,
                         0x7F, 0x08, 0x04, 0x04, 0x78
};
const char f03_105 [] = {
                         0x05,
                         0x00, 0x48, 0x7D, 0x40, 0x00
};
const char f03_106 [] = {
                         0x05,
                         0x20, 0x40, 0x44, 0x3D, 0x00
};
const char f03_107 [] = {
                         0x05,
                         0x7F, 0x10, 0x28, 0x44, 0x00
};
const char f03_108 [] = {
                         0x05,
                         0x00, 0x41, 0x7F, 0x40, 0x00
};
const char f03_109 [] = {
                         0x05,
                         0x7C, 0x04, 0x78, 0x04, 0x78
};
const char f03_110 [] = {
                         0x05,
                         0x7C, 0x08, 0x04, 0x04, 0x78
};
const char f03_111 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x44, 0x38
};
const char f03_112 [] = {
                         0x05,
                         0x7C, 0x14, 0x14, 0x14, 0x08
};
const char f03_113 [] = {
                         0x05,
                         0x08, 0x14, 0x14, 0x18, 0x7C
};
const char f03_114 [] = {
                         0x05,
                         0x7C, 0x08, 0x04, 0x04, 0x08
};
const char f03_115 [] = {
                         0x05,
                         0x48, 0x54, 0x54, 0x54, 0x20,
};
const char f03_116 [] = {
                         0x05,
                         0x04, 0x3F, 0x44, 0x40, 0x20
};
const char f03_117 [] = {
                         0x05,
                         0x3C, 0x40, 0x40, 0x20, 0x7C
};
const char f03_118 [] = {
                         0x05,
                         0x1C, 0x20, 0x40, 0x20, 0x1C
};
const char f03_119 [] = {
                         0x05,
                         0x3C, 0x40, 0x30, 0x40, 0x3C
};

const char f03_120 [] = {
                         0x05,
                         0x44, 0x28, 0x10, 0x28, 0x44
};
const char f03_121 [] = {
                         0x05,
                         0x0C, 0x50, 0x50, 0x50, 0x3C
};
const char f03_122 [] = {
                         0x05,
                         0x44, 0x64, 0x54, 0x4C, 0x44
};
const char f03_123 [] = {
                         0x05,
                         0x00, 0x08, 0x36, 0x41, 0x00
};
const char f03_124 [] = {
                         0x05,
                         0x00, 0x00, 0x7F, 0x00, 0x00
};
const char f03_125 [] = {
                         0x05,
                         0x00, 0x41, 0x36, 0x08, 0x00
};
const char f03_126 [] = {
                         0x05,
                         0x10, 0x08, 0x08, 0x10, 0x08
};
const char f03_127 [] = {
                         0x05,
                         0x3C, 0x22, 0x21, 0x22, 0x3C
};
const char f03_128 [] = {
                         0x05,
                         0x7F, 0x49, 0x49, 0x49, 0x33
};
const char f03_129 [] = {
                         0x05,
                         0x70, 0x29, 0x27, 0x21, 0x7F
};
const char f03_130 [] = {
                         0x05,
                         0x77, 0x08, 0x7F, 0x08, 0x77
};
const char f03_131 [] = {
                         0x05,
                         0x41, 0x41, 0x49, 0x49, 0x36
};
const char f03_132 [] = {
                         0x05,
                         0x7F, 0x10, 0x08, 0x04, 0x7F
};
const char f03_133 [] = {
                         0x05,
                         0x7C, 0x21, 0x12, 0x09, 0x7C
};
const char f03_134 [] = {
                         0x05,
                         0x20, 0x41, 0x3F, 0x01, 0x7F
};
const char f03_135 [] = {
                         0x05,
                         0x7F, 0x01, 0x01, 0x01, 0x7F
};
const char f03_136 [] = {
                         0x05,
                         0x47, 0x28, 0x10, 0x08, 0x07
};
const char f03_137 [] = {
                         0x05,
                         0x3F, 0x20, 0x20, 0x20, 0x7F
};
const char f03_138 [] = {
                         0x05,
                         0x07, 0x08, 0x08, 0x08, 0x7F
};
const char f03_139 [] = {
                         0x05,
                         0x7E, 0x40, 0x7E, 0x40, 0x7E
};
const char f03_140 [] = {
                         0x05,
                         0x3F, 0x20, 0x3F, 0x20, 0x7F
};
const char f03_141 [] = {
                         0x05,
                         0x01, 0x7F, 0x48, 0x48, 0x30
};
const char f03_142 [] = {
                         0x05,
                         0x7F, 0x48, 0x30, 0x00, 0x7F
};
const char f03_143 [] = {
                         0x05,
                         0x22, 0x49, 0x45, 0x49, 0x3E
};
const char f03_144 [] = {
                         0x05,
                         0x38, 0x44, 0x48, 0x30, 0x4C
};
const char f03_145 [] = {
                         0x05,
                         0x60, 0x60, 0x7F, 0x02, 0x0C
};
const char f03_146 [] = {
                         0x05,
                         0x7F, 0x01, 0x01, 0x01, 0x03
};
const char f03_147 [] = {
                         0x05,
                         0x44, 0x3C, 0x04, 0x7C, 0x44
};
const char f03_148 [] = {
                         0x05,
                         0x63, 0x55, 0x49, 0x41, 0x41
};
const char f03_149 [] = {
                         0x05,
                         0x38, 0x44, 0x44, 0x3C, 0x04
};
const char f03_150 [] = {
                         0x05,
                         0x30, 0x30, 0x1F, 0x65, 0x7F
};
const char f03_151 [] = {
                         0x05,
                         0x08, 0x04, 0x3C, 0x44, 0x02
};
const char f03_152 [] = {
                         0x05,
                         0x10, 0x1E, 0x3F, 0x1E, 0x10
};
const char f03_153 [] = {
                         0x05,
                         0x3E, 0x49, 0x49, 0x49, 0x3E
};
const char f03_154 [] = {
                         0x05,
                         0x5C, 0x62, 0x02, 0x62, 0x5C
};
const char f03_155 [] = {
                         0x05,
                         0x30, 0x4A, 0x45, 0x49, 0x32
};
const char f03_156 [] = {
                         0x05,
                         0x18, 0x14, 0x08, 0x14, 0x0C
};
const char f03_157 [] = {
                         0x05,
                         0x1C, 0x3E, 0x7C, 0x3E, 0x1C
};
const char f03_158 [] = {
                         0x05,
                         0x28, 0x54, 0x54, 0x44, 0x20
};
const char f03_159 [] = {
                         0x05,
                         0x7E, 0x01, 0x01, 0x01, 0x7E
};
const char f03_160 [] = {
                         0x05,
                         0x7F, 0x7F, 0x00, 0x7F, 0x7F
};
const char f03_161 [] = {
                         0x05,
                         0x00, 0x00, 0x79, 0x00, 0x00
};
const char f03_162 [] = {
                         0x05,
                         0x1C, 0x22, 0x7F, 0x22, 0x10
};
const char f03_163 [] = {
                         0x05,
                         0x48, 0x3E, 0x49, 0x41, 0x20
};
const char f03_164 [] = {
                         0x05,
                         0x22, 0x1C, 0x14, 0x1C, 0x22
};
const char f03_165 [] = {
                         0x05,
                         0x15, 0x16, 0x7C, 0x16, 0x15
};
const char f03_166 [] = {
                         0x05,
                         0x00, 0x00, 0x77, 0x00, 0x00
};
const char f03_167 [] = {
                         0x05,
                         0x20, 0x4A, 0x55, 0x29, 0x02
};
const char f03_168 [] = {
                         0x05,
                         0x28, 0x48, 0x3E, 0x09, 0x0A
};
const char f03_169 [] = {
                         0x05,
                         0x7F, 0x41, 0x5D, 0x49, 0x7F
};
const char f03_170 [] = {
                         0x05,
                         0x48, 0x55, 0x55, 0x55, 0x5E
};
const char f03_171 [] = {
                         0x05,
                         0x08, 0x14, 0x2A, 0x14, 0x22
};
const char f03_172 [] = {
                         0x05,
                         0x7F, 0x08, 0x3E, 0x41, 0x3E
};
const char f03_173 [] = {
                         0x05,
                         0x46, 0x29, 0x19, 0x09, 0x7F
};
const char f03_174 [] = {
                         0x05,
                         0x7F, 0x41, 0x65, 0x51, 0x7F
};
const char f03_175 [] = {
                         0x05,
                         0x00, 0x06, 0x05, 0x00, 0x00
};
const char f03_176 [] = {
                         0x05,
                         0x0E, 0x11, 0x11, 0x0E, 0x00
};
const char f03_177 [] = {
                         0x05,
                         0x44, 0x44, 0x5F, 0x44, 0x44
};
const char f03_178 [] = {
                         0x05,
                         0x12, 0x19, 0x15, 0x12, 0x00
};
const char f03_179 [] = {
                         0x05,
                         0x11, 0x15, 0x15, 0x0A, 0x00
};
const char f03_180 [] = {
                         0x05,
                         0x7F, 0x05, 0x15, 0x7A, 0x50
};
const char f03_181 [] = {
                         0x05,
                         0x7F, 0x10, 0x10, 0x08, 0x1F
};
const char f03_182 [] = {
                         0x05,
                         0x06, 0x09, 0x09, 0x7F, 0x7F
};
const char f03_183 [] = {
                         0x05,
                         0x00, 0x18, 0x18, 0x00, 0x00
};
const char f03_184 [] = {
                         0x05,
                         0x38, 0x44, 0x30, 0x44, 0x38
};
const char f03_185 [] = {
                         0x05,
                         0x12, 0x1F, 0x10, 0x00, 0x00
};
const char f03_186 [] = {
                         0x05,
                         0x4E, 0x51, 0x51, 0x51, 0x4E
};
const char f03_187 [] = {
                         0x05,
                         0x22, 0x14, 0x2A, 0x14, 0x08
};
const char f03_188 [] = {
                         0x05,
                         0x17, 0x68, 0x54, 0xFA, 0x41
};
const char f03_189 [] = {
                         0x05,
                         0x17, 0x08, 0x94, 0xCA, 0xB1
};
const char f03_190 [] = {
                         0x05,
                         0x15, 0x1F, 0x60, 0x50, 0xF8
};
const char f03_191 [] = {
                         0x05,
                         0x30, 0x48, 0x45, 0x40, 0x20
};
const char f03_192 [] = {
                         0x05,
                         0x70, 0x29, 0x26, 0x28, 0x70
};
const char f03_193 [] = {
                         0x05,
                         0x70, 0x28, 0x26, 0x29, 0x70
};
const char f03_194 [] = {
                         0x05,
                         0x70, 0x2A, 0x29, 0x2A, 0x70
};
const char f03_195 [] = {
                         0x05,
                         0x72, 0x29, 0x29, 0x2A, 0x71
};
const char f03_196 [] = {
                         0x05,
                         0x70, 0x29, 0x24, 0x29, 0x70
};
const char f03_197 [] = {
                         0x05,
                         0x70, 0x2A, 0x2D, 0x2A, 0x70
};
const char f03_198 [] = {
                         0x05,
                         0x7C, 0x12, 0x7F, 0x49, 0x49
};
const char f03_199 [] = {
                         0x05,
                         0x0E, 0x51, 0x51, 0x71, 0x0A
};
const char f03_200 [] = {
                         0x05,
                         0x7C, 0x55, 0x56, 0x54, 0x44
};
const char f03_201 [] = {
                         0x05,
                         0x7C, 0x54, 0x56, 0x55, 0x44
};
const char f03_202 [] = {
                         0x05,
                         0x7C, 0x56, 0x55, 0x56, 0x44
};
const char f03_203 [] = {
                         0x05,
                         0x7C, 0x55, 0x54, 0x55, 0x44
};
const char f03_204 [] = {
                         0x05,
                         0x00, 0x49, 0x7A, 0x48, 0x00
};
const char f03_205 [] = {
                         0x05,
                         0x00, 0x48, 0x7A, 0x49, 0x00
};
const char f03_206 [] = {
                         0x05,
                         0x00, 0x4A, 0x79, 0x4A, 0x00
};
const char f03_207 [] = {
                         0x05,
                         0x00, 0x45, 0x7C, 0x45, 0x00
};
const char f03_208 [] = {
                         0x05,
                         0x08, 0x7F, 0x49, 0x41, 0x3E
};
const char f03_209 [] = {
                         0x05,
                         0x7A, 0x09, 0x11, 0x22, 0x79
};
const char f03_210 [] = {
                         0x05,
                         0x38, 0x45, 0x46, 0x44, 0x38
};
const char f03_211 [] = {
                         0x05,
                         0x38, 0x44, 0x46, 0x45, 0x38
};
const char f03_212 [] = {
                         0x05,
                         0x38, 0x46, 0x45, 0x46, 0x38
};
const char f03_213 [] = {
                         0x05,
                         0x72, 0x89, 0x89, 0x8A, 0x71
};
const char f03_214 [] = {
                         0x05,
                         0x38, 0x45, 0x44, 0x45, 0x38
};
const char f03_215 [] = {
                         0x05,
                         0x22, 0x14, 0x08, 0x14, 0x22
};
const char f03_216 [] = {
                         0x05,
                         0x08, 0x55, 0x7F, 0x55, 0x08
};
const char f03_217 [] = {
                         0x05,
                         0x3C, 0x41, 0x42, 0x40, 0x3C
};
const char f03_218 [] = {
                         0x05,
                         0x3C, 0x40, 0x42, 0x41, 0x3C
};
const char f03_219 [] = {
                         0x05,
                         0x38, 0x42, 0x41, 0x42, 0x38
};
const char f03_220 [] = {
                         0x05,
                         0x3C, 0x41, 0x40, 0x41, 0x3C
};
const char f03_221 [] = {
                         0x05,
                         0x04, 0x08, 0x72, 0x09, 0x04
};
const char f03_222 [] = {
                         0x05,
                         0x41, 0x7F, 0x52, 0x12, 0x0C
};
const char f03_223 [] = {
                         0x05,
                         0x40, 0x3E, 0x49, 0x49, 0x36
};
const char f03_224 [] = {
                         0x05,
                         0x40, 0xA9, 0xAA, 0xA8, 0xF0
};
const char f03_225 [] = {
                         0x05,
                         0x20, 0x54, 0x56, 0x55, 0x78
};
const char f03_226 [] = {
                         0x05,
                         0x20, 0x56, 0x55, 0x56, 0x78
};
const char f03_227 [] = {
                         0x05,
                         0x42, 0xA9, 0xA9, 0xAA, 0xF1
};
const char f03_228 [] = {
                         0x05,
                         0x20, 0x55, 0x54, 0x55, 0x78
};
const char f03_229 [] = {
                         0x05,
                         0x40, 0xAA, 0xAD, 0xAA, 0xF0
};
const char f03_230 [] = {
                         0x05,
                         0x32, 0x4A, 0x3C, 0x4A, 0x2C
};
const char f03_231 [] = {
                         0x05,
                         0x0C, 0x52, 0x72, 0x12, 0x08
};
const char f03_232 [] = {
                         0x05,
                         0x38, 0x55, 0x56, 0x54, 0x18
};
const char f03_233 [] = {
                         0x05,
                         0x38, 0x54, 0x56, 0x55, 0x18
};
const char f03_234 [] = {
                         0x05,
                         0x38, 0x56, 0x55, 0x56, 0x18
};
const char f03_235 [] = {
                         0x05,
                         0x38, 0x55, 0x54, 0x55, 0x18
};
const char f03_236 [] = {
                         0x05,
                         0x00, 0x51, 0x7A, 0x40, 0x00
};
const char f03_237 [] = {
                         0x05,
                         0x00, 0x50, 0x7A, 0x41, 0x00
};
const char f03_238 [] = {
                         0x05,
                         0x00, 0x92, 0xF9, 0x82, 0x00
};
const char f03_239 [] = {
                         0x05,
                         0x00, 0x49, 0x7C, 0x41, 0x00
};
const char f03_240 [] = {
                         0x05,
                         0x25, 0x52, 0x55, 0x58, 0x30
};
const char f03_241 [] = {
                         0x05,
                         0x7A, 0x11, 0x09, 0x0A, 0x71
};
const char f03_242 [] = {
                         0x05,
                         0x38, 0x45, 0x46, 0x44, 0x38
};
const char f03_243 [] = {
                         0x05,
                         0x38, 0x44, 0x46, 0x45, 0x38
};
const char f03_244 [] = {
                         0x05,
                         0x30, 0x4A, 0x49, 0x4A, 0x30
};
const char f03_245 [] = {
                         0x05,
                         0x32, 0x49, 0x49, 0x4A, 0x31
};
const char f03_246 [] = {
                         0x05,
                         0x38, 0x45, 0x44, 0x45, 0x38
};
const char f03_247 [] = {
                         0x05,
                         0x08, 0x08, 0x2A, 0x08, 0x08
};
const char f03_248 [] = {
                         0x05,
                         0x08, 0x54, 0x3E, 0x15, 0x08
};
const char f03_249 [] = {
                         0x05,
                         0x3C, 0x41, 0x42, 0x20, 0x7C
};
const char f03_250 [] = {
                         0x05,
                         0x38, 0x40, 0x42, 0x21, 0x78
};
const char f03_251 [] = {
                         0x05,
                         0x38, 0x42, 0x41, 0x22, 0x78
};
const char f03_252 [] = {
                         0x05,
                         0x3C, 0x41, 0x40, 0x21, 0x7C
};
const char f03_253 [] = {
                         0x06,
                         0x1E, 0x3F, 0x3F, 0x3F, 0x3F, 0x1E
};
const char f03_254 [] = {
                         0x06,
                         0x1E, 0x21, 0x21, 0x21, 0x21, 0x1E
};
const char f03_255 [] = {
                         0x05,
                         0x0C, 0x51, 0x50, 0x51, 0x3C
};

/* Font indexing table */
const int Font3 [] = {
          (int) &f03_00,
          (int) &f03_01,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_02,
          (int) &f03_32,
          (int) &f03_33,
          (int) &f03_34,
          (int) &f03_35,
          (int) &f03_36,
          (int) &f03_37,
          (int) &f03_38,
          (int) &f03_39,
          (int) &f03_40,
          (int) &f03_41,
          (int) &f03_42,
          (int) &f03_43,
          (int) &f03_44,
          (int) &f03_45,
          (int) &f03_46,
          (int) &f03_47,
          (int) &f03_48,
          (int) &f03_49,
          (int) &f03_50,
          (int) &f03_51,
          (int) &f03_52,
          (int) &f03_53,
          (int) &f03_54,
          (int) &f03_55,
          (int) &f03_56,
          (int) &f03_57,
          (int) &f03_58,
          (int) &f03_59,
          (int) &f03_60,
          (int) &f03_61,
          (int) &f03_62,
          (int) &f03_63,
          (int) &f03_64,
          (int) &f03_65,
          (int) &f03_66,
          (int) &f03_67,
          (int) &f03_68,
          (int) &f03_69,
          (int) &f03_70,
          (int) &f03_71,
          (int) &f03_72,
          (int) &f03_73,
          (int) &f03_74,
          (int) &f03_75,
          (int) &f03_76,
          (int) &f03_77,
          (int) &f03_78,
          (int) &f03_79,
          (int) &f03_80,
          (int) &f03_81,
          (int) &f03_82,
          (int) &f03_83,
          (int) &f03_84,
          (int) &f03_85,
          (int) &f03_86,
          (int) &f03_87,
          (int) &f03_88,
          (int) &f03_89,
          (int) &f03_90,
          (int) &f03_91,
          (int) &f03_92,
          (int) &f03_93,
          (int) &f03_94,
          (int) &f03_95,
          (int) &f03_96,
          (int) &f03_97,
          (int) &f03_98,
          (int) &f03_99,
          (int) &f03_100,
          (int) &f03_101,
          (int) &f03_102,
          (int) &f03_103,
          (int) &f03_104,
          (int) &f03_105,
          (int) &f03_106,
          (int) &f03_107,
          (int) &f03_108,
          (int) &f03_109,
          (int) &f03_110,
          (int) &f03_111,
          (int) &f03_112,
          (int) &f03_113,
          (int) &f03_114,
          (int) &f03_115,
          (int) &f03_116,
          (int) &f03_117,
          (int) &f03_118,
          (int) &f03_119,
          (int) &f03_120,
          (int) &f03_121,
          (int) &f03_122,
          (int) &f03_123,
          (int) &f03_124,
          (int) &f03_125,
          (int) &f03_126,
          (int) &f03_127,
          (int) &f03_128,
          (int) &f03_129,
          (int) &f03_130,
          (int) &f03_131,
          (int) &f03_132,
          (int) &f03_133,
          (int) &f03_134,
          (int) &f03_135,
          (int) &f03_136,
          (int) &f03_137,
          (int) &f03_138,
          (int) &f03_139,
          (int) &f03_140,
          (int) &f03_141,
          (int) &f03_142,
          (int) &f03_143,
          (int) &f03_144,
          (int) &f03_145,
          (int) &f03_146,
          (int) &f03_147,
          (int) &f03_148,
          (int) &f03_149,
          (int) &f03_150,
          (int) &f03_151,
          (int) &f03_152,
          (int) &f03_153,
          (int) &f03_154,
          (int) &f03_155,
          (int) &f03_156,
          (int) &f03_157,
          (int) &f03_158,
          (int) &f03_159,
          (int) &f03_160,
          (int) &f03_161,
          (int) &f03_162,
          (int) &f03_163,
          (int) &f03_164,
          (int) &f03_165,
          (int) &f03_166,
          (int) &f03_167,
          (int) &f03_168,
          (int) &f03_169,
          (int) &f03_170,
          (int) &f03_171,
          (int) &f03_172,
          (int) &f03_173,
          (int) &f03_174,
          (int) &f03_175,
          (int) &f03_176,
          (int) &f03_177,
          (int) &f03_178,
          (int) &f03_179,
          (int) &f03_180,
          (int) &f03_181,
          (int) &f03_182,
          (int) &f03_183,
          (int) &f03_184,
          (int) &f03_185,
          (int) &f03_186,
          (int) &f03_187,
          (int) &f03_188,
          (int) &f03_189,
          (int) &f03_190,
          (int) &f03_191,
          (int) &f03_192,
          (int) &f03_193,
          (int) &f03_194,
          (int) &f03_195,
          (int) &f03_196,
          (int) &f03_197,
          (int) &f03_198,
          (int) &f03_199,
          (int) &f03_200,
          (int) &f03_201,
          (int) &f03_202,
          (int) &f03_203,
          (int) &f03_204,
          (int) &f03_205,
          (int) &f03_206,
          (int) &f03_207,
          (int) &f03_208,
          (int) &f03_209,
          (int) &f03_210,
          (int) &f03_211,
          (int) &f03_212,
          (int) &f03_213,
          (int) &f03_214,
          (int) &f03_215,
          (int) &f03_216,
          (int) &f03_217,
          (int) &f03_218,
          (int) &f03_219,
          (int) &f03_220,
          (int) &f03_221,
          (int) &f03_222,
          (int) &f03_223,
          (int) &f03_224,
          (int) &f03_225,
          (int) &f03_226,
          (int) &f03_227,
          (int) &f03_228,
          (int) &f03_229,
          (int) &f03_230,
          (int) &f03_231,
          (int) &f03_232,
          (int) &f03_233,
          (int) &f03_234,
          (int) &f03_235,
          (int) &f03_236,
          (int) &f03_237,
          (int) &f03_238,
          (int) &f03_239,
          (int) &f03_240,
          (int) &f03_241,
          (int) &f03_242,
          (int) &f03_243,
          (int) &f03_244,
          (int) &f03_245,
          (int) &f03_246,
          (int) &f03_247,
          (int) &f03_248,
          (int) &f03_249,
          (int) &f03_250,
          (int) &f03_251,
          (int) &f03_252,
          (int) &f03_253,
          (int) &f03_254,
          (int) &f03_255

};

//--------------------------------------------------------------------------
// Font 4: Original Trebuchet MS rendition done in March/April 2004
//--------------------------------------------------------------------------

const char f04_32 [] = {
                               0x44, 0x00, 0x00, 0x00, 0x00,
                               000, 0x00, 0x00, 0x00
};


const char f04_33 [] =  {
                               0x42, 0x7F, 0x7F,
                               0x03, 0x03
};

const char f04_34 [] = {       0x45, 0x07, 0x07, 0x00, 0x07, 0x07,
                               0x00, 0x00, 0x00, 0x00, 0x00
};


const char f04_35 [] = {
                               0x47, 0x40, 0xE4, 0x5C, 0x4B, 0xE8, 0x5C, 0x0B,
                               0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
};

const char f04_36 [] =  {
                               0x46, 0x1C, 0x3E, 0x73, 0xE2, 0xC2, 0x84,
                               0x02, 0x04, 0x0C, 0x04, 0x07, 0x03
};

const char f04_37 [] =  {
                               0x49, 0x0E, 0x11, 0x81, 0xCE, 0x30, 0xCC, 0x26, 0x21, 0xC0,
                               0x00, 0x02, 0x01, 0x00, 0x00, 0x01, 0x02, 0x02, 0x01
};

const char f04_38 [] =  {
                               0x48, 0xEE, 0xFF, 0x11, 0x11, 0xF9, 0xFE, 0x10, 0x10,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x03, 0x02, 0x02
};

const char f04_39 [] = {
                               0x42, 0x07, 0x07,
                               0x00, 0x00
};

const char f04_40 [] = {
                               0x43, 0xF8, 0xFE, 0x03,
                               0x03, 0x0F, 0x18
};

const char f04_41 [] = {
                               0x43, 0x03, 0xFE, 0xFC,
                               0x18, 0x0F, 0x03
};

const char f04_42 [] =  {
                               0x46, 0x02, 0x1E, 0x0F, 0x0F, 0x1E, 0x02,
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const char f04_43 [] = {
                               0x45, 0x20, 0x20, 0xF8, 0x20, 0x20,
                               0x00, 0x00, 0x00, 0x00, 0x00
};

const char f04_44 [] = {       0x42, 0x00, 0x00,
                               0x0B, 0x07
};

const char f04_45 [] =  {
                               0x43, 0x40, 0x40, 0x40,
                               0x00, 0x00, 0x00
};

const char f04_46 [] =  {
                               0x42, 0x00, 0x00,
                               0x03, 0x03
};

const char f04_47 [] = {       0x45, 0x00, 0xE0, 0xFC, 0x1F, 0x01,
                               0x03, 0x03, 0x00, 0x00, 0x00
};

const char f04_48 [] = {
                               0x47, 0xFC, 0xFE, 0x03, 0x01, 0x03, 0xFE, 0xFC,
                               0x00, 0x01, 0x03, 0x02, 0x03, 0x01, 0x00
};

const char f04_49 [] = {
                               0x44, 0x0C, 0x06, 0xFF, 0xFF,
                               0x00, 0x00, 0x03, 0x03
};

const char f04_50 [] = {
                               0x46, 0x02, 0x83, 0xC1, 0xF1, 0x3F, 0x1E,
                               0x02, 0x03, 0x03, 0x02, 0x02, 0x02
};

const char f04_51 [] = {
                               0x46, 0x02, 0x03, 0x11, 0x31, 0xFF, 0xEE,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_52 [] = {
                               0x47, 0x60, 0x70, 0x58, 0x4C, 0xFE, 0xFF, 0x40,
                               0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00
};

const char f04_53 [] = {
                               0x46, 0x1F, 0x0F, 0x09, 0x09, 0xF9, 0xF1,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_54 [] = {
                               0x46, 0xF0, 0xFC, 0x1E, 0x13, 0xF1, 0xE0,
                               0x00, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_55 [] = {
                               0x46, 0x01, 0x01, 0xE1, 0xFD, 0x1F, 0x03,
                               0x00, 0x03, 0x03, 0x00, 0x00, 0x00
};

const char f04_56 [] = {
                               0x46, 0xEE, 0xFF, 0x11, 0x11, 0xFF, 0xEE,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_57 [] = {
                               0x46, 0x1E, 0x3F, 0x21, 0xE1, 0xFF, 0x3C,
                               0x00, 0x02, 0x03, 0x01, 0x00, 0x00
};

const char f04_58 [] = {       0x42, 0x18, 0x18,
                               0x03, 0x03
};

const char f04_59 [] = {        0x4B, 0xF8, 0x04, 0x42, 0xE2, 0xF2, 0x42, 0x42, 0x7A, 0x04, 0xF8, 0x00,
                                0x01, 0x02, 0x04, 0x04, 0x05, 0x04, 0x04, 0x04, 0x02, 0x01, 0x00
};

const char f04_60 [] =  {
                               0x45, 0x20, 0x70, 0x50, 0xD8, 0x88,
                               0x00, 0x00, 0x00, 0x00, 0x00
};

const char f04_61 [] =  {
                               0x46, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0,
                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const char f04_62 [] =  {
                               0x45, 0x88, 0xD8, 0x50, 0x70, 0x20,
                               0x00, 0x00, 0x00, 0x00, 0x00
};

const char f04_63 [] =  {
                               0x45, 0x03, 0x71, 0x79, 0x1F, 0x0E,
                               0x00, 0x03, 0x03, 0x00, 0x00
};

const char f04_64 [] = {       0x48, 0xF0, 0x08, 0x84, 0x54, 0xE4, 0x04, 0x08, 0xF0,
                               0x01, 0x02, 0x04, 0x05, 0x05, 0x05, 0x01, 0x00
};

const char f04_65 [] = {
                               0x47, 0x00, 0xF0, 0xFE, 0x87, 0xFE, 0xF0, 0x00,
                               0x03, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03
};

const char f04_66 [] = {
                               0x47, 0xFF, 0xFF, 0x11, 0x11, 0x11, 0xFF, 0xEE,
                               0x03, 0x03, 0x02, 0x02, 0x02, 0x03, 0x01
};

const char f04_67 [] = {
                               0x47, 0xFC, 0xFE, 0x03, 0x01, 0x01, 0x03, 0x02,
                               0x00, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_68 [] = {
                               0x47, 0xFF, 0xFF, 0x01, 0x01, 0x03, 0xFE, 0xFC,
                               0x03, 0x03, 0x02, 0x02, 0x03, 0x01, 0x00
};

const char f04_69 [] = {
                               0x45, 0xFF, 0xFF, 0x11, 0x11, 0x01,
                               0x03, 0x03, 0x02, 0x02, 0x02
};

const char f04_70 [] = {
                               0x46, 0xFF, 0xFF, 0x11, 0x11, 0x11, 0x01,
                               0x03, 0x03, 0x00, 0x00, 0x00, 0x00
};

const char f04_71 [] = {
                               0x48, 0xFC, 0xFE, 0x03, 0x01, 0x01, 0x21, 0xE3, 0xE2,
                               0x00, 0x01, 0x03, 0x02, 0x02, 0x02, 0x03, 0x01
};

const char f04_72 [] = {
                               0x48, 0xFF, 0xFF, 0x10, 0x10, 0x10, 0x10, 0xFF, 0xFF,
                               0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03
};

const char f04_73 [] = {
                               0x42, 0xFF, 0xFF,
                               0x03, 0x03
};

const char f04_74 [] = {
                               0x46, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_75 [] = {
                               0x48, 0xFF, 0xFF, 0x70, 0x3C, 0xEE, 0xC3, 0x01, 0x00,
                               0x03, 0x03, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02
};

const char f04_76 [] = {
                               0x46, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
                               0x03, 0x03, 0x02, 0x02, 0x02, 0x02
};

const char f04_77 [] = {
                               0x49, 0xC0, 0xFF, 0x3E, 0xF0, 0x80, 0xF0, 0x3E, 0xFF, 0xC0,
                               0x03, 0x03, 0x00, 0x01, 0x03, 0x01, 0x00, 0x03, 0x03
};

const char f04_78 [] = {
                               0x48, 0xFF, 0xFF, 0x0C, 0x18, 0x30, 0x60, 0xFF, 0xFF,
                               0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03
};

const char f04_79 [] = {
                               0x48, 0xFC, 0xFE, 0x03, 0x01, 0x01, 0x03, 0xFE, 0xFC,
                               0x00, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01, 0x00
};

const char f04_80 [] = {
                               0x47, 0xFF, 0xFF, 0x41, 0x41, 0x63, 0x3E, 0x1C,
                               0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
};

const char f04_81 [] = {
                               0x49, 0xFC, 0xFE, 0x03, 0x01, 0x01, 0x03, 0xFE, 0xFC, 0x00,
                               0x00, 0x01, 0x03, 0x02, 0x02, 0x07, 0x09, 0x08, 0x08
};

const char f04_82 [] = {
                               0x48, 0xFF, 0xFF, 0x21, 0x21, 0xE1, 0xDF, 0x1E, 0x00,
                               0x03, 0x03, 0x00, 0x00, 0x00, 0x01, 0x03, 0x02
};

const char f04_83 [] = {
                               0x46, 0x0E, 0x1F, 0x39, 0x71, 0xE3, 0xC2,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_84 [] = {
                               0x48, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0x01, 0x01, 0x01,
                               0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00
};

const char f04_85 [] = {
                               0x48, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF,
                               0x00, 0x01, 0x03, 0x02, 0x02, 0x03, 0x01, 0x00
};

const char f04_86 [] = {
                               0x47, 0x03, 0x3F, 0xFC, 0x80, 0xFC, 0x3F, 0x03,
                               0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00
};

const char f04_87 [] = {
                               0x4B, 0x03, 0x3F, 0xFC, 0x80, 0xFC, 0x0F, 0xFC, 0x80, 0xFC, 0x3F, 0x03,
                               0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00
};

const char f04_88 [] = {
                               0x48, 0x01, 0x87, 0xCE, 0x78, 0x78, 0xCE, 0x87, 0x01,
                               0x02, 0x03, 0x01, 0x00, 0x00, 0x01, 0x03, 0x02
};

const char f04_89 [] = {
                               0x48, 0x01, 0x07, 0x1E, 0xF8, 0xF8, 0x1E, 0x07, 0x01,
                               0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00
};

const char f04_90 [] = {
                               0x46, 0x01, 0xC1, 0xF1, 0x3D, 0x0F, 0x03,
                               0x03, 0x03, 0x02, 0x02, 0x02, 0x02
};

const char f04_91 [] =  {
                               0x44, 0xFF, 0xFF, 0x01, 0x01,
                               0x1F, 0x1F, 0x10, 0x10
};

const char f04_92 [] = {       0x45, 0x01, 0x1F, 0xFC, 0xE0, 0x00,
                               0x00, 0x00, 0x00, 0x03, 0x03
};

const char f04_93 [] =  {
                               0x44, 0x01, 0x01, 0xFF, 0xFF,
                               0x10, 0x10, 0x1F, 0x1F
};

const char f04_94 [] =  {
                               0x45, 0x08, 0x06, 0x01, 0x06, 0x08,
                               0x00, 0x00, 0x00, 0x00, 0x00
};

const char f04_95 [] =  {
                               0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                               0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08
};

const char f04_96 [] =  {
                               0x43, 0x01, 0x03, 0x02,
                               0x00, 0x00, 0x00
};

const char f04_97 [] = {
                               0x46, 0xC0, 0xE8, 0x28, 0x28, 0xF8, 0xF0,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x03
};

const char f04_98 [] = {
                               0x46, 0xFF, 0xFF, 0x08, 0x08, 0xF8, 0xF0,
                               0x03, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_99 [] = {
                               0x46, 0xF0, 0xF8, 0x08, 0x08, 0x18, 0x10,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_100 [] = {
                               0x46, 0xF0, 0xF8, 0x08, 0x08, 0xFF, 0xFF,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x03
};

const char f04_101 [] = {
                               0x46, 0xF0, 0xF8, 0x48, 0x48, 0x78, 0x70,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_102 [] = {
                               0x45, 0x08, 0xFE, 0xFF, 0x09, 0x01,
                               0x00, 0x03, 0x03, 0x00, 0x00
};

const char f04_103 [] = {
                               0x47, 0x70, 0xF8, 0x88, 0x88, 0xF8, 0x78, 0x00,
                               0x0F, 0x1B, 0x12, 0x12, 0x12, 0x1E, 0x0C
};

const char f04_104 [] = {
                               0x46, 0xFF, 0xFF, 0x08, 0x08, 0xF8, 0xF0,
                               0x03, 0x03, 0x00, 0x00, 0x03, 0x03
};

const char f04_105 [] = {
                               0x43, 0x08, 0xFB, 0xFB,
                               0x00, 0x03, 0x03
};

const char f04_106 [] = {
                               0x44, 0x00, 0x08, 0xFB, 0xFB,
                               0x10, 0x10, 0x1F, 0x0F
};

const char f04_107 [] = {
                               0x47, 0xFF, 0xFF, 0x60, 0xF0, 0xD8, 0x08, 0x00,
                               0x03, 0x03, 0x00, 0x00, 0x01, 0x03, 0x02
};

const char f04_108 [] = {
                               0x43, 0xFF, 0xFF, 0x00,
                               0x01, 0x03, 0x02
};

const char f04_109 [] = {
                               0x4A, 0xF8, 0xF0, 0x08, 0x08, 0xF8, 0xF0, 0x08, 0x08, 0xF8, 0xF0,
                               0x03, 0x03, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x03, 0x03
};

const char f04_110 [] = {
                               0x46, 0xF8, 0xF0, 0x08, 0x08, 0xF8, 0xF0,
                               0x03, 0x03, 0x00, 0x00, 0x03, 0x03
};

const char f04_111 [] = {
                               0x46, 0xF0, 0xF8, 0x08, 0x08, 0xF8, 0xF0,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x01
};

const char f04_112 [] = {
                               0x46, 0xF8, 0xF8, 0x08, 0x08, 0xF8, 0xF0,
                               0x1F, 0x1F, 0x02, 0x02, 0x03, 0x01
};

const char f04_113 [] = {
                               0x46, 0xF0, 0xF8, 0x08, 0x08, 0xF8, 0xF8,
                               0x01, 0x03, 0x02, 0x02, 0x1F, 0x1F
};

const char f04_114 [] = {
                               0x44, 0xF8, 0xF8, 0x08, 0x18,
                               0x03, 0x03, 0x00, 0x00
};

const char f04_115 [] = {
                               0x45, 0x30, 0x78, 0x48, 0xD8, 0x90,
                               0x01, 0x03, 0x02, 0x03, 0x01
};

const char f04_116 [] = {
                               0x44, 0x04, 0xFF, 0xFF, 0x04,
                               0x00, 0x01, 0x03, 0x02
};

const char f04_117 [] = {
                               0x46, 0xF8, 0xF8, 0x00, 0x00, 0xF8, 0xF8,
                               0x01, 0x03, 0x02, 0x02, 0x03, 0x03
};

const char f04_118 [] = {
                               0x47, 0x08, 0x78, 0xF0, 0x80, 0xF0, 0x78, 0x08,
                               0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00
};

const char f04_119 [] = {
                               0x4B, 0x08, 0x78, 0xF0, 0x80, 0xF0, 0x38, 0xF0, 0x80, 0xF0, 0x78, 0x08,
                               0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00
};

const char f04_120 [] = {
                               0x47, 0x08, 0x18, 0xF0, 0xE0, 0xF0, 0x18, 0x08,
                               0x02, 0x03, 0x01, 0x00, 0x01, 0x03, 0x02
};

const char f04_121 [] = {
                               0x47, 0x08, 0x38, 0xF0, 0x80, 0xF0, 0x78, 0x08,
                               0x00, 0x18, 0x18, 0x0F, 0x03, 0x00, 0x00
};

const char f04_122 [] = {
                               0x46, 0x08, 0x88, 0xC8, 0x68, 0x38, 0x18,
                               0x03, 0x03, 0x02, 0x02, 0x02, 0x02
};

const char f04_123 [] = {      0x4B, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80,
                               0x00, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00

};

const char f04_124 [] =  {
                               0x4B, 0x20, 0x30, 0x38, 0xFC, 0xFE, 0xFF, 0xFE, 0xFC, 0x38, 0x30, 0x20,
                               0x04, 0x0C, 0x1C, 0x3F, 0x7F, 0xFF, 0x7F, 0x3F, 0x1C, 0x0C, 0x04

};

const char f04_125 [] = {
                                0x4B, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x00, 0x00,
                                0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01

};

const char f04_126 [] =  {
                               0x4A, 0x07, 0x3F, 0x65, 0xC5, 0xA5, 0x15, 0xC5, 0x65, 0x3F, 0x07,
                               0xE0, 0xFE, 0xB3, 0xA9, 0xB4, 0xA8, 0xB1, 0xA3, 0xFE, 0xE0

};

const char f04_DEFAULT [] = {       0x47, 0x55, 0xAA, 0x55, 0xAA, 0x55, 0xAA, 0x55,
                                    0x15, 0x0A, 0x15, 0x0A, 0x15, 0x0A, 0x15
};

// Font Indexing Table
const int Font4 [] = {
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_32,
          (int) &f04_33,
          (int) &f04_34,
          (int) &f04_35,
          (int) &f04_36,
          (int) &f04_37,
          (int) &f04_38,
          (int) &f04_39,
          (int) &f04_40,
          (int) &f04_41,
          (int) &f04_42,
          (int) &f04_43,
          (int) &f04_44,
          (int) &f04_45,
          (int) &f04_46,
          (int) &f04_47,
          (int) &f04_48,
          (int) &f04_49,
          (int) &f04_50,
          (int) &f04_51,
          (int) &f04_52,
          (int) &f04_53,
          (int) &f04_54,
          (int) &f04_55,
          (int) &f04_56,
          (int) &f04_57,
          (int) &f04_58,
          (int) &f04_59,
          (int) &f04_60,
          (int) &f04_61,
          (int) &f04_62,
          (int) &f04_63,
          (int) &f04_64,
          (int) &f04_65,
          (int) &f04_66,
          (int) &f04_67,
          (int) &f04_68,
          (int) &f04_69,
          (int) &f04_70,
          (int) &f04_71,
          (int) &f04_72,
          (int) &f04_73,
          (int) &f04_74,
          (int) &f04_75,
          (int) &f04_76,
          (int) &f04_77,
          (int) &f04_78,
          (int) &f04_79,
          (int) &f04_80,
          (int) &f04_81,
          (int) &f04_82,
          (int) &f04_83,
          (int) &f04_84,
          (int) &f04_85,
          (int) &f04_86,
          (int) &f04_87,
          (int) &f04_88,
          (int) &f04_89,
          (int) &f04_90,
          (int) &f04_91,
          (int) &f04_92,
          (int) &f04_93,
          (int) &f04_94,
          (int) &f04_95,
          (int) &f04_96,
          (int) &f04_97,
          (int) &f04_98,
          (int) &f04_99,
          (int) &f04_100,
          (int) &f04_101,
          (int) &f04_102,
          (int) &f04_103,
          (int) &f04_104,
          (int) &f04_105,
          (int) &f04_106,
          (int) &f04_107,
          (int) &f04_108,
          (int) &f04_109,
          (int) &f04_110,
          (int) &f04_111,
          (int) &f04_112,
          (int) &f04_113,
          (int) &f04_114,
          (int) &f04_115,
          (int) &f04_116,
          (int) &f04_117,
          (int) &f04_118,
          (int) &f04_119,
          (int) &f04_120,
          (int) &f04_121,
          (int) &f04_122,
          (int) &f04_123,
          (int) &f04_124,
          (int) &f04_125,
          (int) &f04_126,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT,
          (int) &f04_DEFAULT

};

/*
// Font 5 - Micro 5 var
//-------------------------------------------------
const char f05_DEFAULT [] = {
                              0x03,
                              0x1F, 0x11, 0x1F
};
const char f05_sym1 [] = {
                              0x03,
                              0x1F, 0x11, 0x1F
};

const char f05_32 [] = {
                              0x02,
                              0x00, 0x00
};

const char f05_33 [] = {
                              0x02,
                              0x00, 0x17
};

const char f05_34 [] = {
                              0x04,
                              0x00, 0x03, 0x00, 0x03
};

const char f05_35 [] = {
                              0x05,
                              0x0A, 0x1F, 0x0A, 0x1F, 0x0A
};

const char f05_36 [] = {
                              0x05,
                              0x24, 0x2A, 0x3F, 0x2A, 0x12
};

const char f05_37 [] = {
                              0x04,
                              0x09, 0x04, 0x02, 0x09
};

const char f05_38 [] = {
                              0x05,
                              0x0A, 0x15, 0x1D, 0x14, 0x10
};

const char f05_39 [] = {
                              0x01,
                              0x03
};

const char f05_40 [] = {
                              0x03,
                              0x0C, 0x12, 0x21
};

const char f05_41 [] = {
                              0x03,
                              0x21, 0x12, 0x0C
};

const char f05_42 [] = {
                              0x04,
                              0x00, 0x0A, 0x04, 0x0A
};

// Font Indexing Table
const int Font5 [] = {
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_sym1,
          (int) &f05_DEFAULT,
          (int) &f05_32,
          (int) &f05_33,
          (int) &f05_34,
          (int) &f05_35,
          (int) &f05_36,
          (int) &f05_37,
          (int) &f05_38,
          (int) &f05_39,
          (int) &f05_40,
          (int) &f05_41,
          /*(int) &f05_42,
          (int) &f05_43,
          (int) &f05_44,
          (int) &f05_45,
          (int) &f05_46,
          (int) &f05_47,
          (int) &f05_48,
          (int) &f05_49,
          (int) &f05_50,
          (int) &f05_51,
          (int) &f05_52,
          (int) &f05_53,
          (int) &f05_54,
          (int) &f05_55,
          (int) &f05_56,
          (int) &f05_57,
          (int) &f05_58,
          (int) &f05_59,
          (int) &f05_60,
          (int) &f05_61,
          (int) &f05_62,
          (int) &f05_63,
          (int) &f05_64,
          (int) &f05_65,
          (int) &f05_66,
          (int) &f05_67,
          (int) &f05_68,
          (int) &f05_69,
          (int) &f05_70,
          (int) &f05_71,
          (int) &f05_72,
          (int) &f05_73,
          (int) &f05_74,
          (int) &f05_75,
          (int) &f05_76,
          (int) &f05_77,
          (int) &f05_78,
          (int) &f05_79,
          (int) &f05_80,
          (int) &f05_81,
          (int) &f05_82,
          (int) &f05_83,
          (int) &f05_84,
          (int) &f05_85,
          (int) &f05_86,
          (int) &f05_87,
          (int) &f05_88,
          (int) &f05_89,
          (int) &f05_90,
          (int) &f05_91,
          (int) &f05_92,
          (int) &f05_93,
          (int) &f05_94,
          (int) &f05_95,
          (int) &f05_96,
          (int) &f05_97,
          (int) &f05_98,
          (int) &f05_99,
          (int) &f05_100,
          (int) &f05_101,
          (int) &f05_102,
          (int) &f05_103,
          (int) &f05_104,
          (int) &f05_105,
          (int) &f05_106,
          (int) &f05_107,
          (int) &f05_108,
          (int) &f05_109,
          (int) &f05_110,
          (int) &f05_111,
          (int) &f05_112,
          (int) &f05_113,
          (int) &f05_114,
          (int) &f05_115,
          (int) &f05_116,
          (int) &f05_117,
          (int) &f05_118,
          (int) &f05_119,
          (int) &f05_120,
          (int) &f05_121,
          (int) &f05_122,
          (int) &f05_123,
          (int) &f05_124,
          (int) &f05_125,
          (int) &f05_126,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT,
          (int) &f05_DEFAULT

};

*/
#endif // __STDFONTS_H_
