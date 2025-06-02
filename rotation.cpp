//Klopov Aleksei - LabWork1 - st130153@student.spbu.ru

#include "rotation.h"
#include <iostream>

RGBQUAD **rotate90Clockwise(RGBQUAD **rgbInfo, unsigned int width, unsigned int height) {
    RGBQUAD **rotated = new RGBQUAD*[width];
    for (unsigned int i = 0; i < width; ++i) {
        rotated[i] = new RGBQUAD[height];
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < static_cast<int>(height); i++) {
        for (int j = 0; j < static_cast<int>(width); j++) {
            rotated[j][height - i - 1] = rgbInfo[i][j];
        }
    }

    return rotated;
}

RGBQUAD **rotate90CounterClockwise(RGBQUAD **rgbInfo, unsigned int width, unsigned int height) {
    RGBQUAD **rotated = new RGBQUAD*[width];
    for (unsigned int i = 0; i < width; ++i) {
        rotated[i] = new RGBQUAD[height];
    }

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < static_cast<int>(height); i++) {
        for (int j = 0; j < static_cast<int>(width); j++) {
            rotated[width - j - 1][i] = rgbInfo[i][j];
        }
    }

    return rotated;
}
