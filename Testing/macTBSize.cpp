#include<cstdint>
#define MAX_MCS_INDEX 28
#define MAX_RESOURCE_BLOCK 100

uint16_t TBSizeArr[MAX_MCS_INDEX + 1][MAX_RESOURCE_BLOCK] =
{
    {
    2,    4,    7,    11,    15,    19,    22,    26,    28,    32,
    36,    41,    43,    47,    49,    53,    57,    61,    63,    67,
    71,    75,    77,    81,    85,    89,    93,    97,    97,    101,
    105,    109,    113,    117,    121,    125,    129,    129,    133,    137,
    141,    145,    149,    153,    157,    157,    161,    165,    169,    173,
    177,    177,    185,    185,    193,    193,    201,    201,    201,    209,
    209,    217,    217,    225,    225,    225,    233,    233,    241,    241,
    249,    249,    253,    261,    261,    261,    269,    269,    277,    277,
    285,    285,    285,    293,    293,    301,    301,    309,    309,    317,
    317,    317,    325,    325,    333,    333,    341,    341,    341,    349,
    }, /* 01 */
    {
    3,    7,    11,    18,    22,    26,    28,    32,    41,    43,
    47,    53,    57,    61,    65,    71,    75,    79,    85,    89,
    93,    97,    101,    109,    113,    117,    121,    125,    129,    133,
    141,    145,    149,    153,    157,    161,    169,    173,    177,    177,
    185,    193,    193,    201,    201,    209,    217,    217,    225,    225,
    233,    233,    241,    249,    249,    253,    261,    261,    269,    269,
    277,    285,    285,    293,    293,    301,    309,    309,    317,    317,
    325,    325,    333,    341,    341,    349,    349,    357,    357,    357,
    373,    373,    373,    389,    389,    389,    405,    405,    405,    405,
    421,    421,    421,    437,    437,    437,    437,    453,    453,    453
    }, /* 02 */
    {
    4,    9,    18,    22,    26,    32,    37,    41,    47,    53,
    59,    65,    71,    77,    81,    87,    93,    97,    105,    109,
    117,    121,    125,    133,    137,    145,    149,    157,    161,    165,
    173,    177,    185,    193,    193,    201,    209,    209,    217,    225,
    225,    233,    241,    249,    253,    261,    261,    269,    277,    277,
    285,    293,    293,    301,    309,    317,    317,    325,    333,    333,
    341,    349,    357,    357,    357,    373,    373,    389,    389,    389,
    405,    405,    405,    421,    421,    421,    437,    437,    437,    453,
    453,    453,    469,    469,    485,    485,    485,    501,    501,    501,
    517,    517,    517,    533,    533,    533,    549,    549,    549,    573,
    }, /* 03 */
    {
    5,    13,    22,    26,    32,    41,    49,    55,    63,    71,
    77,    85,    93,    101,    109,    113,    121,    129,    137,    145,
    153,    157,    165,    173,    177,    185,    193,    201,    209,    217,
    225,    233,    241,    249,    253,    261,    269,    277,    285,    293,
    301,    309,    317,    317,    325,    333,    341,    349,    357,    357,
    373,    373,    389,    389,    405,    405,    421,    421,    437,    437,
    453,    453,    453,    469,    469,    485,    485,    501,    501,    517,
    517,    533,    533,    549,    549,    549,    573,    573,    573,    597,
    597,    597,    597,    621,    621,    621,    645,    645,    645,    669,
    669,    669,    669,    693,    693,    693,    717,    717,    717,    717,
    }, /* 04 */
    {
    7,    15,    26,    32,    41,    51,    61,    69,    79,    87,
    97,    105,    113,    125,    133,    141,    149,    161,    169,    177,
    185,    193,    201,    217,    225,    233,    241,    249,    261,    269,
    277,    285,    293,    301,    309,    325,    333,    341,    349,    357,
    373,    373,    389,    389,    405,    405,    421,    437,    437,    453,
    453,    469,    469,    485,    501,    501,    517,    517,    533,    533,
    549,    549,    573,    573,    573,    597,    597,    621,    621,    621,
    645,    645,    645,    669,    669,    693,    693,    693,    717,    717,
    717,    749,    749,    749,    749,    775,    775,    775,    807,    807,
    807,    807,    839,    839,    839,    871,    871,    871,    871,    903,
    }, /* 05 */
    {
    41,    22,    32,    49,    63,    75,    89,    101,    117,    129,
    141,    153,    169,    185,    193,    209,    217,    233,    249,    261,
    277,    285,    301,    309,    325,    341,    349,    373,    373,    389,
    405,    421,    437,    437,    453,    469,    485,    501,    517,    517,
    533,    549,    573,    573,    597,    597,    621,    621,    645,    645,
    669,    669,    693,    717,    717,    749,    749,    749,    775,    775,
    807,    807,    807,    839,    839,    871,    871,    871,    903,    903,
    935,    935,    967,    967,    967,    999,    999,    1031,    1031,    1031,
    1063,    1063,    1095,    1095,    1095,    1143,    1143,    1143,    1143,    1191,
    1191,    1191,    1191,    1239,    1239,    1239,    1287,    1287,    1287,    1287,
    }, /* 06 */
    {
    13,    28,    41,    59,    73,    89,    105,    121,    137,    153,
    165,    185,    201,    209,    225,    241,    261,    277,    293,    309,
    317,    333,    349,    373,    389,    405,    421,    421,    437,    453,
    469,    485,    501,    517,    533,    549,    573,    573,    597,    621,
    621,    645,    669,    669,    693,    717,    717,    749,    749,    775,
    775,    807,    807,    839,    839,    839,    871,    871,    903,    903,
    935,    935,    967,    967,    999,    999,    1031,    1031,    1063,    1063,
    1095,    1095,    1095,    1143,    1143,    1143,    1191,    1191,    1191,    1239,
    1239,    1239,    1287,    1287,    1287,    1335,    1335,    1335,    1383,    1383,
    1383,    1431,    1431,    1431,    1431,    1479,    1479,    1479,    1527,    1527,
    }, /* 07 */
    {
    15,    32,    49,    67,    85,    101,    121,    137,    157,    173,
    193,    209,    225,    241,    261,    277,    293,    317,    333,    349,
    373,    389,    405,    421,    437,    453,    469,    485,    501,    533,
    549,    573,    573,    597,    621,    621,    645,    669,    693,    693,
    717,    749,    749,    775,    775,    807,    807,    839,    871,    871,
    903,    903,    935,    935,    967,    967,    999,    999,    1031,    1063,
    1063,    1095,    1095,    1143,    1143,    1143,    1191,    1191,    1191,    1239,
    1239,    1239,    1287,    1287,    1335,    1335,    1335,    1383,    1383,    1383,
    1431,    1431,    1431,    1479,    1479,    1527,    1527,    1527,    1572,    1572,
    1572,    1620,    1620,    1620,    1692,    1692,    1692,    1692,    1764,    1764,
    }, /* 08 */
    {
    17,    37,    57,    77,    97,    117,    137,    157,    177,    193,
    217,    233,    253,    277,    293,    317,    333,    357,    373,    389,
    421,    437,    453,    469,    501,    517,    533,    549,    573,    597,
    621,    645,    645,    669,    693,    717,    717,    749,    775,    775,
    807,    839,    839,    871,    871,    903,    935,    935,    967,    999,
    999,    1031,    1031,    1063,    1095,    1095,    1143,    1143,    1143,    1191,
    1191,    1239,    1239,    1287,    1287,    1287,    1335,    1335,    1383,    1383,
    1383,    1431,    1431,    1479,    1479,    1479,    1527,    1527,    1572,    1572,
    1620,    1620,    1620,    1692,    1692,    1692,    1692,    1764,    1764,    1764,
    1764,    1836,    1836,    1836,    1908,    1908,    1908,    1908,    1980,    1980,
    }, /* 09 */
    {
    18,    41,    63,    85,    109,    129,    153,    173,    193,    217,
    241,    261,    285,    309,    333,    349,    373,    389,    421,    437,
    469,    485,    501,    533,    549,    573,    597,    621,    645,    669,
    693,    717,    717,    749,    775,    775,    807,    839,    839,    871,
    903,    935,    935,    967,    999,    999,    1031,    1063,    1063,    1095,
    1143,    1143,    1143,    1191,    1191,    1239,    1239,    1287,    1287,    1335,
    1335,    1383,    1383,    1431,    1431,    1431,    1479,    1479,    1527,    1527,
    1572,    1572,    1620,    1620,    1620,    1692,    1692,    1692,    1764,    1764,
    1764,    1836,    1836,    1836,    1836,    1908,    1908,    1908,    1980,    1980,
    1980,    2052,    2052,    2052,    2124,    2124,    2124,    2124,    2196,    2196,
    }, /* 10 */

    {
    26,    55,    85,    113,    141,    169,    201,    225,    253,    285,
    309,    341,    373,    405,    421,    453,    485,    517,    549,    573,
    597,    621,    669,    693,    717,    749,    775,    807,    839,    839,
    871,    903,    935,    967,    999,    1031,    1063,    1095,    1095,    1143,
    1191,    1191,    1239,    1239,    1287,    1335,    1335,    1383,    1383,    1431,
    1479,    1479,    1527,    1527,    1572,    1572,    1620,    1620,    1692,    1692,
    1764,    1764,    1764,    1836,    1836,    1908,    1908,    1908,    1980,    1980,
    2052,    2052,    2052,    2124,    2124,    2196,    2196,    2196,    2292,    2292,
    2292,    2385,    2385,    2385,    2385,    2481,    2481,    2481,    2577,    2577,
    2577,    2673,    2673,    2673,    2673,    2769,    2769,    2769,    2865,    2865,
    }, /* 11 */
    {
    28,    61,    93,    125,    157,    193,    225,    253,    285,    317,
    357,    389,    421,    453,    485,    517,    549,    573,    621,    645,
    669,    717,    749,    775,    807,    839,    871,    903,    935,    967,
    999,    1031,    1063,    1095,    1143,    1143,    1191,    1239,    1239,    1287,
    1335,    1335,    1383,    1431,    1431,    1479,    1527,    1527,    1572,    1620,
    1620,    1692,    1692,    1764,    1764,    1836,    1836,    1836,    1908,    1908,
    1980,    1980,    2052,    2052,    2124,    2124,    2124,    2196,    2196,    2292,
    2292,    2292,    2385,    2385,    2385,    2481,    2481,    2481,    2577,    2577,
    2577,    2673,    2673,    2673,    2769,    2769,    2769,    2865,    2865,    2865,
    2961,    2961,    2961,    3062,    3062,    3062,    3182,    3182,    3182,    3182
    }, /* 12 */
    {
    32,    69,    105,    141,    177,    217,    249,    285,    325,    357,
    389,    437,    469,    501,    533,    573,    621,    645,    693,    717,
    749,    775,    807,    871,    903,    935,    967,    999,    1031,    1063,
    1095,    1143,    1191,    1239,    1239,    1287,    1335,    1383,    1383,    1431,
    1479,    1527,    1527,    1572,    1620,    1620,    1692,    1692,    1764,    1764,
    1836,    1836,    1908,    1908,    1980,    1980,    2052,    2052,    2124,    2124,
    2196,    2196,    2292,    2292,    2292,    2385,    2385,    2481,    2481,    2481,
    2577,    2577,    2577,    2673,    2673,    2769,    2769,    2769,    2865,    2865,
    2865,    2961,    2961,    3062,    3062,    3062,    3182,    3182,    3182,    3182,
    3302,    3302,    3302,    3422,    3422,    3422,    3542,    3542,    3542,    3542,
    }, /* 13 */
    {
    35,    75,    113,    153,    193,    225,    269,    309,    341,    389,
    421,    453,    501,    533,    573,    621,    645,    693,    717,    775,
    807,    839,    871,    903,    967,    999,    1031,    1063,    1095,    1143,
    1191,    1239,    1287,    1287,    1335,    1383,    1431,    1479,    1479,    1527,
    1572,    1620,    1620,    1692,    1692,    1764,    1836,    1836,    1908,    1908,
    1980,    1980,    2052,    2052,    2124,    2124,    2196,    2196,    2292,    2292,
    2292,    2385,    2385,    2481,    2481,    2577,    2577,    2577,    2673,    2673,
    2769,    2769,    2769,    2865,    2865,    2961,    2961,    2961,    3062,    3062,
    3062,    3182,    3182,    3182,    3302,    3302,    3302,    3422,    3422,    3422,
    3542,    3542,    3542,    3662,    3662,    3662,    3662,    3822,    3822,    3822
    }, /* 14 */
    {
    41,    79,    121,    161,    201,    241,    285,    325,    373,    405,
    453,    485,    533,    573,    621,    645,    693,    749,    775,    807,
    839,    903,    935,    967,    999,    1063,    1095,    1143,    1191,    1239,
    1239,    1287,    1335,    1383,    1431,    1479,    1527,    1527,    1572,    1620,
    1692,    1692,    1764,    1764,    1836,    1836,    1908,    1980,    1980,    2052,
    2052,    2124,    2124,    2196,    2196,    2292,    2292,    2385,    2385,    2481,
    2481,    2481,    2577,    2577,    2673,    2673,    2769,    2769,    2769,    2865,
    2865,    2961,    2961,    3062,    3062,    3062,    3182,    3182,    3182,    3302,
    3302,    3302,    3422,    3422,    3422,    3542,    3542,    3542,    3662,    3662,
    3662,    3822,    3822,    3822,    3822,    3963,    3963,    3963,    3963,    4107
    }, /* 15 */

    {
    47,    97,    145,    193,    249,    293,    349,    389,    453,    501,
    549,    597,    645,    693,    749,    775,    839,    903,    935,    999,
    1031,    1095,    1143,    1191,    1239,    1287,    1335,    1383,    1431,    1479,
    1527,    1572,    1620,    1692,    1764,    1764,    1836,    1908,    1908,    1980,
    2052,    2052,    2124,    2196,    2196,    2292,    2292,    2385,    2385,    2481,
    2481,    2577,    2673,    2673,    2769,    2769,    2865,    2865,    2961,    2961,
    3062,    3062,    3062,    3182,    3182,    3302,    3302,    3422,    3422,    3422,
    3542,    3542,    3662,    3662,    3662,    3822,    3822,    3822,    3963,    3963,
    3963,    4107,    4107,    4107,    4251,    4251,    4251,    4395,    4395,    4395,
    4587,    4587,    4587,    4736,    4736,    4736,    4736,    4904,    4904,    4904
    }, /* 16 */
    {
    51,    105,    161,    217,    269,    325,    373,    437,    485,    533,
    597,    645,    693,    749,    807,    871,    903,    967,    1031,    1063,
    1143,    1191,    1239,    1287,    1335,    1383,    1431,    1527,    1572,    1620,
    1692,    1692,    1764,    1836,    1908,    1908,    1980,    2052,    2124,    2124,
    2196,    2292,    2292,    2385,    2385,    2481,    2577,    2577,    2673,    2673,
    2769,    2769,    2865,    2865,    2961,    3062,    3062,    3182,    3182,    3182,
    3302,    3302,    3422,    3422,    3542,    3542,    3662,    3662,    3662,    3822,
    3822,    3822,    3963,    3963,    4107,    4107,    4107,    4251,    4251,    4251,
    4395,    4395,    4395,    4587,    4587,    4587,    4736,    4736,    4736,    4904,
    4904,    4904,    5072,    5072,    5072,    5072,    5296,    5296,    5296,    5477
    }, /* 17 */
    {
    55,    113,    173,    233,    293,    349,    405,    469,    517,    573,
    645,    693,    749,    807,    871,    935,    999,    1031,    1095,    1143,
    1239,    1287,    1335,    1383,    1431,    1527,    1572,    1620,    1692,    1764,
    1836,    1836,    1908,    1980,    2052,    2124,    2124,    2196,    2292,    2292,
    2385,    2481,    2481,    2577,    2577,    2673,    2769,    2769,    2865,    2865,
    2961,    3062,    3062,    3182,    3182,    3302,    3302,    3422,    3422,    3542,
    3542,    3662,    3662,    3662,    3822,    3822,    3963,    3963,    3963,    4107,
    4107,    4251,    4251,    4251,    4395,    4395,    4395,    4587,    4587,    4587,
    4736,    4736,    4904,    4904,    4904,    5072,    5072,    5072,    5296,    5296,
    5296,    5296,    5477,    5477,    5477,    5669,    5669,    5669,    5861,    5861
    }, /* 18 */
    {
    61,    125,    185,    249,    309,    373,    437,    501,    573,    621,
    693,    749,    807,    871,    935,    999,    1063,    1143,    1191,    1239,
    1335,    1383,    1431,    1527,    1572,    1620,    1692,    1764,    1836,    1908,
    1980,    1980,    2052,    2124,    2196,    2292,    2292,    2385,    2481,    2481,
    2577,    2673,    2673,    2769,    2865,    2865,    2961,    3062,    3062,    3182,
    3182,    3302,    3302,    3422,    3422,    3542,    3542,    3662,    3662,    3822,
    3822,    3963,    3963,    3963,    4107,    4107,    4251,    4251,    4395,    4395,
    4395,    4587,    4587,    4587,    4736,    4736,    4904,    4904,    4904,    5072,
    5072,    5072,    5296,    5296,    5296,    5477,    5477,    5477,    5669,    5669,
    5669,    5861,    5861,    5861,    5861,    6117,    6117,    6117,    6117,    6378
    }, /* 19 */
    {
    65,    133,    201,    269,    333,    405,    469,    533,    597,    669,
    749,    807,    871,    935,    999,    1063,    1143,    1191,    1287,    1335,
    1431,    1479,    1572,    1620,    1692,    1764,    1836,    1908,    1980,    2052,
    2124,    2124,    2196,    2292,    2385,    2385,    2481,    2577,    2673,    2673,
    2769,    2865,    2865,    2961,    3062,    3062,    3182,    3182,    3302,    3422,
    3422,    3542,    3542,    3662,    3662,    3822,    3822,    3963,    3963,    4107,
    4107,    4251,    4251,    4251,    4395,    4395,    4587,    4587,    4587,    4736,
    4736,    4904,    4904,    5072,    5072,    5072,    5296,    5296,    5296,    5477,
    5477,    5477,    5669,    5669,    5669,    5861,    5861,    5861,    6117,    6117,
    6117,    6117,    6378,    6378,    6378,    6378,    6594,    6594,    6594,    6882
    }, /* 20 */

    {
    73,    149,    225,    301,    373,    453,    533,    621,    693,    749,
    839,    903,    999,    1063,    1143,    1239,    1287,    1383,    1431,    1527,
    1620,    1692,    1764,    1836,    1908,    1980,    2052,    2124,    2196,    2292,
    2385,    2481,    2481,    2577,    2673,    2769,    2865,    2865,    2961,    3062,
    3182,    3182,    3302,    3302,    3422,    3542,    3542,    3662,    3662,    3822,
    3963,    3963,    4107,    4107,    4251,    4251,    4395,    4395,    4587,    4587,
    4587,    4736,    4736,    4904,    4904,    5072,    5072,    5296,    5296,    5296,
    5477,    5477,    5669,    5669,    5669,    5861,    5861,    5861,    6117,    6117,
    6117,    6378,    6378,    6378,    6594,    6594,    6594,    6594,    6882,    6882,
    6882,    7167,    7167,    7167,    7167,    7407,    7407,    7407,    7708,    7708
    },/* 21 */
    {
    77,    157,    233,    317,    389,    469,    549,    645,    717,    775,
    871,    935,    1031,    1095,    1191,    1287,    1335,    1431,    1527,    1572,
    1692,    1764,    1836,    1908,    1980,    2052,    2124,    2196,    2292,    2385,
    2481,    2577,    2577,    2673,    2769,    2865,    2961,    3062,    3062,    3182,
    3302,    3302,    3422,    3542,    3542,    3662,    3662,    3822,    3963,    3963,
    4107,    4107,    4251,    4251,    4395,    4395,    4587,    4587,    4736,    4736,
    4904,    4904,    5072,    5072,    5072,    5296,    5296,    5477,    5477,    5477,
    5669,    5669,    5861,    5861,    5861,    6117,    6117,    6117,    6378,    6378,
    6378,    6594,    6594,    6594,    6882,    6882,    6882,    6882,    7167,    7167,
    7167,    7407,    7407,    7407,    7708,    7708,    7708,    7708,    7972,    7972
    },/* 22 */
    {
    89,    185,    277,    373,    469,    549,    645,    749,    839,    935,
    1031,    1095,    1191,    1287,    1383,    1479,    1572,    1692,    1764,    1836,
    1908,    2052,    2124,    2196,    2292,    2385,    2481,    2577,    2673,    2769,
    2865,    2961,    3062,    3182,    3182,    3302,    3422,    3542,    3662,    3662,
    3822,    3822,    3963,    4107,    4107,    4251,    4395,    4395,    4587,    4587,
    4736,    4736,    4904,    5072,    5072,    5072,    5296,    5296,    5477,    5477,
    5669,    5669,    5861,    5861,    6117,    6117,    6117,    6378,    6378,    6594,
    6594,    6594,    6882,    6882,    6882,    6882,    7167,    7167,    7167,    7407,
    7407,    7407,    7708,    7708,    7708,    7972,    7972,    7972,    8324,    8324,
    8324,    8601,    8601,    8601,    8889,    8889,    8889,    9214,    9214,    9422
    },/* 23 */
    {
    81,     165,     249,       333,    421,    501,    573,    669,    749,    839,
    903,    999,    1063,       1143,   1239,   1335,   1431,   1479,   1572,   1620,
    1764,   1836,   1908,       1980,   2052,   2124,   2196,   2292,   2385,   2481,
    2577,   2673,   2769,       2865,   2865,   2961,   3062,   3182,   3182,   3302,
    3422,   3422,   3542,       3662,   3662,   3822,   3963,   3963,   4107,   4107,
    4251,   4251,   4395,       4395,   4587,   4587,   4736,   4736,   4904,   4904,
    5072,   5072,   5296,       5296,   5477,   5477,   5477,   5669,   5669,   5861,   
    5861,   5861,   6117,       6117,   6117,   6378,   6378,   6378,   6594,   6594,   
    6594,   6882,   6882,       6882,   7167,   7167,   7167,   7407,   7407,   7407,
    7407,   7708,   7708,       7708,   7972,   7972,   7972,   7972,   8324,   8324
    },/* 24 */
    {
    85,     173,    261,    349,    437,    533,    621,    693,    775,    871,    
    967,    1063,   1143,   1239,   1335,   1383,   1479,   1572,   1692,   1764,
    1836,   1908,   2052,   2124,   2196,   2292,   2385    ,2481,  2577,   2673,
    2769,   2769,   2865,   2961,   3062,   3182,   3302,   3302,   3422,   3542,
    3662,   3662,   3822,   3822,   3963,   4107,   4107,   4251,   4251,   4395,
    4395,   4587,   4587,   4736,   4904,   4904,   5072,   5072,   5296,   5296,
    5296,   5477,   5477,   5669,   5669,   5861,   5861,   5861,   6117,   6117,
    6117,   6378,   6378,   6594,   6594,   6594,   6882,   6882,   6882,   7167,
    7167,   7167,   7407,   7407,   7407,   7708,   7708,   7708,   7708,   7972,
    7972,   7972,   8324,   8324,   8324,   8324,   8601,   8601,   8601,   8889    
    },/* 25 */
    {
    101,    201,    309,    405,    517,    621,    717,    807,    935,    1031,
    1143,   1239,   1335,   1431,   1527,   1620,   1764,   1836,   1980,   2052,
    2196,   2292,   2385,   2481,   2577,   2673,   2769,   2865,   2961,   3062,
    3182,   3302,   3422,   3542,   3662,   3662,   3822,   3963,   3963,   4107,
    4251,   4395,   4395,   4587,   4587,   4736,   4904,   4904,   5072,   5072,
    5296,   5296,   5477,   5669,   5669,   5861,   5861,   5861,   6117,   6117,
    6378,   6378,   6594,   6594,   6594,   6882,   6882,   6882,   7167,   7167,   
    7407,   7407,   7407,   7708,   7708,   7972,   7972,   7972,   8324,   8324,
    8324,   8601,   8601,   8601,   8889,   8889,   8889,   9214,   9214,   9214,
    9422,   9526,   9526,   9838,   9838,   9838,   10147,  10147,  10147,  10147    
    },/* 26 */
    {
    121,    249,    373,    501,    621,    749,    871,    999,    1095,   1239,
    1335,   1479,   1620,   1692,   1836,   1980,   2124,   2196,   2385,   2481,
    2577,   2673,   2865,   2961,   3062,   3182,   3302,   3422,   3542,   3662,
    3822,   3963,   4107,   4251,   4395,   4395,   4587,   4736,   4904,   4904,
    5072,   5072,   5296,   5477,   5477,   5669,   5861,   5861,   6117,   6117,
    6378,   6378,   6594,   6594,   6882,   6882,   7167,   7167,   7407,   7407,
    7407,   7708,   7708,   7972,   7972,   7972,   8324,   8324,   8601,   8601,
    8889,   8889,   8889,   9214,   9422,   9526,   9526,   9526,   9838,   9838,
    10147,  10147,  10147,  10147,  10595,  10595,  10595,  10992,  10992,  10992,
    11352,  11352,  11352,  11725,  11725,  11725,  11725,  12237,  12237,  12237    
    },/* 27 */
    {
    129,    261,    390,    533,    645,    775,    903,    1063,   1191,   1287,
    1431,   1572,   1692,   1836,   1980,   2124,   2196,   2385,   2481,   2577,
    2769,   2865,   3062,   3182,   3302,   3422,   3542,   3662,   3822,   3963,
    4107,   4251,   4395,   4395,   4587,   4736,   4904,   4904,   5072,   5296,
    5296,   5477,   5669,   5861,   5861,   6117,   6117,   6378,   6378,   6594,
    6594,   6882,   6882,   7167,   7167,   7407,   7407,   7708,   7708,   7972,
    7972,   7972,   8324,   8324,   8601,   8601,   8889,   8889,   8889,   9214,
    9422,   9526,   9526,   9838,   9838,   9838,   10147,  10147,  10147,  10595,  
    10595,  10595,  10992,  10992,  10992,  11352,  11352,  11725,  11725,  11725,
    11725,  12237,  12237,  12237,  12237,  12730,  12730,  12730,  13191,  13191    
    }/* 28 */
};
