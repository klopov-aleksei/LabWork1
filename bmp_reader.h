#ifndef BMP_READER_H_INCLUDED
#define BMP_READER_H_INCLUDED

#include "main.h"
#include <fstream>

bool loadBMP(const char *fileName, BITMAPFILEHEADER &fileHeader, BITMAPINFOHEADER &fileInfoHeader, RGBQUAD **&rgbInfo);
void cleanupRGBInfo(RGBQUAD **&rgbInfo, unsigned int height);

#endif
