//Klopov Aleksei - LabWork1 - st130153@student.spbu.ru

/**
 * @file rotation.h
 * @brief Image rotation operations
 */

#ifndef ROTATION_H
#define ROTATION_H

#include "main.h"

/**
 * @brief Rotates image 90° clockwise
 * @param rgbInfo 2D pixel array (input image)
 * @param width Image width
 * @param height Image height
 * @return Pointer to new rotated pixel array
 */
RGBQUAD **rotate90Clockwise(RGBQUAD **rgbInfo, unsigned int width, unsigned int height);

/**
 * @brief Rotates image 90° counter-clockwise
 * @param rgbInfo 2D pixel array (input image)
 * @param width Image width
 * @param height Image height
 * @return Pointer to new rotated pixel array
 */
RGBQUAD **rotate90CounterClockwise(RGBQUAD **rgbInfo, unsigned int width, unsigned int height);

#endif