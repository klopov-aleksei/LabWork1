#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <fstream>
#include <cstdint>

typedef int FXPT2DOT30;
 
typedef struct {
    FXPT2DOT30 ciexyzX;
    FXPT2DOT30 ciexyzY;
    FXPT2DOT30 ciexyzZ;
} CIEXYZ;
 
typedef struct {
    CIEXYZ  ciexyzRed; 
    CIEXYZ  ciexyzGreen; 
    CIEXYZ  ciexyzBlue; 
} CIEXYZTRIPLE;
 
typedef struct {
    std::uint16_t bfType;
    unsigned int   bfSize;
    std::uint16_t bfReserved1;
    std::uint16_t bfReserved2;
    unsigned int   bfOffBits;
} BITMAPFILEHEADER;
 
typedef struct {
    unsigned int   biSize;
    unsigned int   biWidth;
    unsigned int   biHeight;
    std::uint16_t biPlanes;
    std::uint16_t biBitCount;
    unsigned int   biCompression;
    unsigned int   biSizeImage;
    unsigned int   biXPelsPerMeter;
    unsigned int   biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
    unsigned int   biRedMask;
    unsigned int   biGreenMask;
    unsigned int   biBlueMask;
    unsigned int   biAlphaMask;
    unsigned int   biCSType;
    CIEXYZTRIPLE   biEndpoints;
    unsigned int   biGammaRed;
    unsigned int   biGammaGreen;
    unsigned int   biGammaBlue;
    unsigned int   biIntent;
    unsigned int   biProfileData;
    unsigned int   biProfileSize;
    unsigned int   biReserved;
} BITMAPINFOHEADER;
 
typedef struct {
    unsigned char  rgbBlue;
    unsigned char  rgbGreen;
    unsigned char  rgbRed;
    unsigned char  rgbReserved;
} RGBQUAD;
 
// reading a file sequentially (byte by byte)
template <typename Type>
void read(std::ifstream &fp, Type &result, std::size_t size) {
    fp.read(reinterpret_cast<char*>(&result), size);
}
 
unsigned char bitextract(const unsigned int byte, const unsigned int mask);
 
#endif
