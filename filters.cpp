//Klopov Aleksei - LabWork1 - st130153@student.spbu.ru

#include "filters.h"
#include <cmath>
#include <algorithm>

void applyGaussianFilter(RGBQUAD **rgbInfo, unsigned int width, unsigned int height) {
    const int kernelSize = 5;
    const float kernel[kernelSize][kernelSize] = {
        { 1 / 273.0, 4 / 273.0,  7 / 273.0,  4 / 273.0, 1 / 273.0 },
        { 4 / 273.0, 16 / 273.0, 26 / 273.0, 16 / 273.0, 4 / 273.0 },
        { 7 / 273.0, 26 / 273.0, 41 / 273.0, 26 / 273.0, 7 / 273.0 },
        { 4 / 273.0, 16 / 273.0, 26 / 273.0, 16 / 273.0, 4 / 273.0 },
        { 1 / 273.0, 4 / 273.0,  7 / 273.0,  4 / 273.0, 1 / 273.0 }
    };

    // to store filtered results
    RGBQUAD **temp = new RGBQUAD*[height];
    for (unsigned int i = 0; i < height; ++i) {
        temp[i] = new RGBQUAD[width];
    }

    const int h = static_cast<int>(height);
    const int w = static_cast<int>(width);

    #pragma omp parallel for collapse(2)
    for (int y = 2; y < h - 2; y++) {
        for (int x = 2; x < w - 2; x++) {
            float red = 0, green = 0, blue = 0;
            for (int ky = -2; ky <= 2; ++ky) {
                for (int kx = -2; kx <= 2; ++kx) {
                    RGBQUAD &pixel = rgbInfo[y + ky][x + kx];
                    red += pixel.rgbRed * kernel[ky + 2][kx + 2];
                    green += pixel.rgbGreen * kernel[ky + 2][kx + 2];
                    blue += pixel.rgbBlue * kernel[ky + 2][kx + 2];
                }
            }
            temp[y][x].rgbRed = static_cast<uint8_t>(red);
            temp[y][x].rgbGreen = static_cast<uint8_t>(green);
            temp[y][x].rgbBlue = static_cast<uint8_t>(blue);
        }
    }

    #pragma omp parallel for collapse(2)
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            if (y < 2 || y >= h - 2 || x < 2 || x >= w - 2) {
                temp[y][x] = rgbInfo[y][x];
            }
        }
    }

    #pragma omp parallel for
    for (int y = 0; y < h; y++) {
        std::copy(temp[y], temp[y] + w, rgbInfo[y]);
        delete[] temp[y];
    }
    delete[] temp;
}
