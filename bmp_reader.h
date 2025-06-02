//Klopov Aleksei - LabWork1 - st130153@student.spbu.ru

/**
 * @file bmp_reader.h
 * @brief BMP file I/O operations
 */

#ifndef BMP_READER_H
#define BMP_READER_H

#include "main.h"
#include <fstream>

/**
 * @brief Loads BMP file into memory
 * @param fileName Path to BMP file
 * @param fileHeader Reference to file header structure
 * @param fileInfoHeader Reference to info header structure
 * @param rgbInfo Reference to 2D pixel array
 * @return true if successful, false otherwise
 */
bool loadBMP(const char *fileName, BITMAPFILEHEADER &fileHeader, 
             BITMAPINFOHEADER &fileInfoHeader, RGBQUAD **&rgbInfo);

/**
 * @brief Saves BMP file from memory
 * @param fileName Output file path
 * @param fileHeader File header structure
 * @param fileInfoHeader Info header structure
 * @param rgbInfo 2D pixel array
 * @return true if successful, false otherwise
 */
bool saveBMP(const char *fileName, const BITMAPFILEHEADER &fileHeader, 
             const BITMAPINFOHEADER &fileInfoHeader, RGBQUAD **rgbInfo);

/**
 * @brief Deallocates memory for pixel array
 * @param rgbInfo Reference to 2D pixel array
 * @param height Image height (number of rows)
 */
void cleanupRGBInfo(RGBQUAD **&rgbInfo, unsigned int height);

#endif