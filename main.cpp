#include "bmp_reader.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " file_name" << std::endl;
        return 0;
    }

    char *fileName = argv[1];
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER fileInfoHeader;
    RGBQUAD **rgbInfo = nullptr;

    if (!loadBMP(fileName, fileHeader, fileInfoHeader, rgbInfo)) {
        return 0;
    }

    // Clean up memory
    cleanupRGBInfo(rgbInfo, fileInfoHeader.biHeight);
    return 1;
}
