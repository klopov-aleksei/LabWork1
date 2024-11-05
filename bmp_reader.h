#ifndef BMP_READER_H
#define BMP_READER_H

#include "main.h"
#include <fstream>

bool loadBMP(const char *fileName, BITMAPFILEHEADER &fileHeader, BITMAPINFOHEADER &fileInfoHeader, RGBQUAD **&rgbInfo);
bool saveBMP(const char *fileName, const BITMAPFILEHEADER &fileHeader, const BITMAPINFOHEADER &fileInfoHeader, RGBQUAD **rgbInfo);
void cleanupRGBInfo(RGBQUAD **&rgbInfo, unsigned int height);

#endif

