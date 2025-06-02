//Klopov Aleksei - LabWork1 - st130153@student.spbu.ru

#include "bmp_reader.h"
#include "rotation.h"
#include "filters.h"
#include <iostream>
#include <chrono>
#include <iomanip>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " input_file.bmp" << std::endl;
        return 0;
    }

    const char* fileName = argv[1];
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER fileInfoHeader;
    RGBQUAD **rgbInfo = nullptr;

    if (!loadBMP(fileName, fileHeader, fileInfoHeader, rgbInfo)) {
        return 0;
    }

    std::chrono::high_resolution_clock::time_point start, end;
    double duration;
    {
        start = std::chrono::high_resolution_clock::now();
        RGBQUAD **rotatedClockwise = rotate90Clockwise(rgbInfo, fileInfoHeader.biWidth, fileInfoHeader.biHeight);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "Clockwise rotation: " << std::fixed << std::setprecision(3) << duration << " ms" << std::endl;

        std::swap(fileInfoHeader.biWidth, fileInfoHeader.biHeight);
        if (!saveBMP("rotated_90_clockwise.bmp", fileHeader, fileInfoHeader, rotatedClockwise)) {
            std::cerr << "Failed to save rotated_90_clockwise.bmp" << std::endl;
        }
        cleanupRGBInfo(rotatedClockwise, fileInfoHeader.biHeight);
        std::swap(fileInfoHeader.biWidth, fileInfoHeader.biHeight);
    }

    {
        start = std::chrono::high_resolution_clock::now();
        RGBQUAD **rotatedCounterClockwise = rotate90CounterClockwise(rgbInfo, fileInfoHeader.biWidth, fileInfoHeader.biHeight);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "Counter-clockwise rotation: " << std::fixed << std::setprecision(3) << duration << " ms" << std::endl;

        std::swap(fileInfoHeader.biWidth, fileInfoHeader.biHeight);
        if (!saveBMP("rotated_90_counterclockwise.bmp", fileHeader, fileInfoHeader, rotatedCounterClockwise)) {
            std::cerr << "Failed to save rotated_90_counterclockwise.bmp" << std::endl;
        }
        cleanupRGBInfo(rotatedCounterClockwise, fileInfoHeader.biHeight);
        std::swap(fileInfoHeader.biWidth, fileInfoHeader.biHeight);
    }

    {
        start = std::chrono::high_resolution_clock::now();
        applyGaussianFilter(rgbInfo, fileInfoHeader.biWidth, fileInfoHeader.biHeight);
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration<double, std::milli>(end - start).count();
        std::cout << "Gaussian filter: " << std::fixed << std::setprecision(3) << duration << " ms" << std::endl;
        
        if (!saveBMP("gaussian_filtered.bmp", fileHeader, fileInfoHeader, rgbInfo)) {
            std::cerr << "Failed to save gaussian_filtered.bmp" << std::endl;
        }
    }

    cleanupRGBInfo(rgbInfo, fileInfoHeader.biHeight);

    return 0;
}

