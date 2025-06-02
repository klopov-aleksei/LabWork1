//Klopov Aleksei - LabWork1 - st130153@student.spbu.ru

/**
 * @file filters.h
 * @brief Image filter operations
 */

#ifndef FILTERS_H
#define FILTERS_H

#include "main.h"

/**
 * @brief Applies Gaussian blur filter to image
 * @param rgbInfo 2D pixel array (input/output image)
 * @param width Image width
 * @param height Image height
 * @note Uses 5x5 kernel with fixed coefficients
 */
void applyGaussianFilter(RGBQUAD **rgbInfo, unsigned int width, unsigned int height);

#endif