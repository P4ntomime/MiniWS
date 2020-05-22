#ifndef FONT_BIG_MINIWS_H_
#define FONT_BIG_MINIWS_H_

//TODO: add temperature, humidity and pressure texts (save in one Array for simpler use) plus dot and comma

typedef struct charset_big
{
    const unsigned char character[6][32];
    uint8_t from_last_char;     //may be changed to const
    uint8_t to_next_char;

}s_charset_big;

const s_charset_big _0_bigchar = {
        .character = {
                {54,54,11, 7, 5, 4, 3, 2, 2, 1, 1, 1,00,00,00,00,00,00,00,00,00, 1, 1, 1, 2, 2, 3, 3, 4, 6, 7,11},  //Background
                {00,00,33,40,43,46,48,50,50,52,52,52,54,54,54, 9, 8, 8, 9,54,54,53,52,52,51,50,49,48,46,43,40,33},  //Foreground
                {00,00,10, 7, 6, 4, 3, 2, 2, 1, 1, 1,00,00,00,36,38,38,36,00,00,00, 1, 1, 1, 2, 2, 3, 4, 5, 7,10},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00, 9, 8, 8, 9,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Foreground
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};

const s_charset_big _1_bigchar = {
        .character = {
                { 9, 9, 9, 8, 8, 8, 7, 7, 6, 6, 5, 4, 4, 3, 2, 1, 1, 1, 1, 1, 1, 1,54,54,54,54,54,54,54,54,54,54},  //Background
                { 6, 6, 6, 7, 7, 7, 9,10,47,47,48,49,49,50,51,52,52,52,52,52,52,52,00,00,00,00,00,00,00,00,00,00},  //Foreground
                {39,39,39,39,39,39,38,37, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,00,00,00,00,00,00,00,00,00,00},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Foreground
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};

const s_charset_big _2_bigchar = {
        .character = {
                {54,54,10, 7, 5, 4, 3, 2, 1, 1, 1,00,00,00,00,00,00,00,00,00, 1, 1, 1, 2, 2, 3, 4, 5, 7,10,54,54},  //Background
                {00,00, 9,12,14,15,16,17,18,18,18,19, 9, 8, 8, 8, 9,44,42,40,38,36,34,31,29,26,23,20,15, 9,00,00},  //Foreground
                {00,00,26,25,23,21,19,17,15,13,11, 9,17,16,14,11, 7, 1, 3, 5, 6, 8,10,12,14,16,18,20,23,35,00,00},  //Background
                {00,00, 8, 9,11,13,15,17,19,21,23,25,27,29,31,34,37, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,00,00,00},  //Foreground
                {00,00, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,00,00,00},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};

const s_charset_big _3_bigchar = {
        .character = {
                {54,54, 8, 5, 3, 3, 2, 1, 1, 1,00,00,00,00,00,00,00,00,00,00,00,00, 1, 1, 1, 2, 2, 3, 4, 6, 9,30},  //Background
                {00,00,10,13,15,15,16,17,17,17,18,18,18,18, 9, 8, 8, 9,32,54,54,54,52,52,52,50,21,19,18,14, 9,14},  //Foreground
                {00,00,14,14,14,14,14,14,14,14,14, 3, 3, 3,12,13,12,10,13,00,00,00, 1, 1, 1, 2, 1, 2, 3, 6, 9,10},  //Background
                {00,00,13,16,17,18,19,20,20,21,21, 8, 8, 8, 8, 8,10,11, 9,00,00,00,00,00,00,00,28,27,25,23,20,00},  //Foreground
                {00,00, 9, 6, 5, 4, 3, 2, 2, 1, 1, 3, 3, 3,16,17,16,16,00,00,00,00,00,00,00,00, 2, 3, 4, 5, 7,00},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,21,22,22, 9, 8, 8, 8,00,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};

const s_charset_big _4_bigchar = {
        .character = {
                {33,30,27,23,20,17,13,10, 7, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,35,35,35,35},  //Background
                {11,14,17,21,24,27,31,34,27,27,25,22,18,14,52,52,52,52,52,52,52,52,52,52,52,52,52,52, 9, 9, 9, 9},  //Foreground
                {10,10,10,10,10,10,10,10, 1, 5, 9,12,16,20, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,10,10,10,10},  //Background
                {00,00,00,00,00,00,00,00, 9, 9, 9, 9, 9, 9,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Foreground
                {00,00,00,00,00,00,00,00,10,10,10,10,10,10,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};

const s_charset_big _5_bigchar = {
        .character = {
                {54,54,14, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,18,20,23},  //Background
                {00,00,14,27,27,27,27,27,27,27,27,27,27,27, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,31,28,22},  //Foreground
                {00,00, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 9, 8, 7, 7, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 8, 5, 6, 9},  //Background
                {00,00,10,13,15,16,17,18,18,19,19,19,20,20,10, 7, 7, 7, 9,39,39,39,38,38,38,36,36,35,33,00,00,00},  //Foreground
                {00,00,10, 7, 5, 4, 3, 2, 2, 1, 1, 1,00,00, 6,21,23,23,21,00,00,00, 1, 1, 1, 2, 2, 3, 4,00,00,00},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,20, 9, 8, 8, 9,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};

const s_charset_big _6_bigchar = {
        .character = {
                {54,10, 7, 6, 4, 3, 3, 2, 2, 1, 1, 1,00,00,00,00,00,00,00,00,00,00, 1, 1, 1, 2, 2, 3, 4, 5, 7,10},  //Background
                {00,34,40,43,46,48,48,50,51,52,52,52,54,54, 9, 8, 8, 8, 9,15,15,15,14,14,14,13,13,12,11,10, 8, 5},  //Foreground
                {00,10, 7, 5, 4, 3, 3, 2, 1, 1, 1, 1,00,00,12,12,11,11, 9, 3, 3, 3, 3, 3, 3, 4, 4, 5, 5, 6, 8,11},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00, 6, 6, 7, 7, 9,36,36,36,35,35,35,33,33,31,30,28,24,19},  //Foreground
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,18,20,20,20,18,00,00,00, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00, 9, 8, 8, 8, 9,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};

const s_charset_big _7_bigchar = {
        .character = {
                { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,00,00,00,00,00,00,00},  //Background
                { 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,52,52,52,52,52,52,52,49,43,37,31,25,19,13,00,00,00,00,00,00,00},  //Foreground
                {45,45,45,45,41,35,29,23,17,12, 6, 1, 1, 1, 1, 1, 1, 1, 4,10,16,22,28,34,40,00,00,00,00,00,00,00},  //Background
                {00,00,00,00, 3, 9,15,21,27,32,38,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Foreground
                {00,00,00,00, 1, 1, 1, 1, 1, 1, 1,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};

const s_charset_big _8_bigchar = {
        .character = {
                {54,54, 9, 6, 5, 4, 3, 2, 2, 1, 1, 1,00,00,00,00,00,00,00,00,00,00,00, 1, 1, 1, 2, 2, 3, 5, 6, 9},  //Background
                {00,00, 9,14,17,19,20,50,50,52,52,52,54,54,54, 9, 8, 8, 9,54,54,54,53,52,52,51,21,21,19,16,14, 9},  //Foreground
                {00,00,12, 7, 3, 2, 1, 2, 2, 1, 1, 1,00,00,00,11,13,13,11,00,00,00, 1, 1, 1, 2, 1, 1, 3, 5, 7,12},  //Background
                {00,00,14,21,24,25,27,00,00,00,00,00,00,00,00,10, 8, 8,10,00,00,00,00,00,00,00,28,27,25,23,21,15},  //Foreground
                {00,00,10, 6, 5, 4, 3,00,00,00,00,00,00,00,00,15,17,17,15,00,00,00,00,00,00,00, 2, 3, 4, 5, 6, 9},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00,00, 9, 8, 8, 9,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};

const s_charset_big _9_bigchar = {
        .character = {
                {54, 9, 7, 5, 4, 3, 2, 2, 1, 1, 1,00,00,00,00,00,00,00,00,00,00, 1, 1, 1, 1, 2, 3, 3, 4, 5, 7,10},  //Background
                {00,20,24,28,30,31,33,33,35,35,35,36,36,36, 9, 8, 8, 8, 9,54,54,52,52,52,51,50,48,48,46,43,40,34},  //Foreground
                {00,10, 8, 6, 5, 5, 4, 4, 3, 3, 3, 3, 3, 3,18,20,20,20,18,00,00, 1, 1, 1, 2, 2, 3, 3, 4, 6, 7,10},  //Background
                {00, 5, 8,10,11,12,13,13,14,14,14,15,15,15, 9, 7, 7, 6, 6,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Foreground
                {00, 9, 7, 5, 4, 3, 2, 2, 1, 1, 1,00,00,00, 9,11,11,12,12,00,00,00,00,00,00,00,00,00,00,00,00,00},  //Background
                {00,00,00,00,00,00,00,00,00,00,00,00,00,00, 9, 8, 8, 8, 9,00,00,00,00,00,00,00,00,00,00,00,00,00}   //Foreground
        },
        .from_last_char = 0,
        .to_next_char = 0
};



#endif
