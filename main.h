//Klopov Aleksei - LabWork1 - st130153@student.spbu.ru

#ifndef MAIN_H
#define MAIN_H

#include <cstdint>

#pragma pack(push, 1) // no padding in structs

struct BITMAPFILEHEADER {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
};

struct BITMAPINFOHEADER {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
};

// RGBQUAD struct for 24-bit BMP color information
struct RGBQUAD {
    uint8_t rgbBlue;
    uint8_t rgbGreen;
    uint8_t rgbRed;
    uint8_t rgbReserved; // 24-bit BMP doesn't use it, but I did it anyway for compatibility
};

#pragma pack(pop)

#endif
