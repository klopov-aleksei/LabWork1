//Klopov Aleksei - LabWork1 - st130153@student.spbu.ru

/**
 * @file main.h
 * @brief BMP file format structures and definitions
 */

#ifndef MAIN_H
#define MAIN_H

#include <cstdint>

#pragma pack(push, 1) // no padding in structs

/**
 * @struct BITMAPFILEHEADER
 * @brief BMP file header structure
 */
struct BITMAPFILEHEADER {
    uint16_t bfType;      ///< File type (must be "BM")
    uint32_t bfSize;      ///< File size in bytes
    uint16_t bfReserved1; ///< Reserved (must be 0)
    uint16_t bfReserved2; ///< Reserved (must be 0)
    uint32_t bfOffBits;   ///< Offset to pixel data
};

/**
 * @struct BITMAPINFOHEADER
 * @brief BMP information header structure
 */
struct BITMAPINFOHEADER {
    uint32_t biSize;          ///< Size of this header
    int32_t biWidth;          ///< Image width in pixels
    int32_t biHeight;         ///< Image height in pixels (positive = bottom-up)
    uint16_t biPlanes;        ///< Number of color planes (must be 1)
    uint16_t biBitCount;      ///< Bits per pixel (24 for RGB)
    uint32_t biCompression;   ///< Compression type (0 = none)
    uint32_t biSizeImage;     ///< Image size in bytes (0 for uncompressed)
    int32_t biXPelsPerMeter;  ///< Horizontal resolution (pixels/meter)
    int32_t biYPelsPerMeter;  ///< Vertical resolution (pixels/meter)
    uint32_t biClrUsed;       ///< Number of colors in palette
    uint32_t biClrImportant;  ///< Important colors (0 = all)
};

/**
 * @struct RGBQUAD
 * @brief RGB color structure
 * @note For 24-bit BMP format (blue, green, red order)
 */
struct RGBQUAD {
    uint8_t rgbBlue;      ///< Blue component (0-255)
    uint8_t rgbGreen;     ///< Green component (0-255)
    uint8_t rgbRed;       ///< Red component (0-255)
    uint8_t rgbReserved;  ///< Reserved (not used in 24-bit BMP)
};

#pragma pack(pop)

#endif