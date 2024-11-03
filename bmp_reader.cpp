#include "bmp_reader.h"
#include <iostream>

unsigned char bitextract(const unsigned int byte, const unsigned int mask) {
    if (mask == 0) {
        return 0;
    }
    int maskBufer = mask, maskPadding = 0;
    while (!(maskBufer & 1)) {
        maskBufer >>= 1;
        maskPadding++;
    }
    return (byte & mask) >> maskPadding;
}

bool loadBMP(const char *fileName, BITMAPFILEHEADER &fileHeader, BITMAPINFOHEADER &fileInfoHeader, RGBQUAD **&rgbInfo) {
    std::ifstream fileStream(fileName, std::ifstream::binary);
    if (!fileStream) {
        std::cerr << "Error opening file '" << fileName << "'." << std::endl;
        return false;
    }

    read(fileStream, fileHeader.bfType, sizeof(fileHeader.bfType));
    if (fileHeader.bfType != 0x4D42) {
        std::cerr << "Error: '" << fileName << "' is not a BMP file." << std::endl;
        return false;
    }

    read(fileStream, fileHeader.bfSize, sizeof(fileHeader.bfSize));
    read(fileStream, fileHeader.bfReserved1, sizeof(fileHeader.bfReserved1));
    read(fileStream, fileHeader.bfReserved2, sizeof(fileHeader.bfReserved2));
    read(fileStream, fileHeader.bfOffBits, sizeof(fileHeader.bfOffBits));

    read(fileStream, fileInfoHeader.biSize, sizeof(fileInfoHeader.biSize));
    read(fileStream, fileInfoHeader.biWidth, sizeof(fileInfoHeader.biWidth));
    read(fileStream, fileInfoHeader.biHeight, sizeof(fileInfoHeader.biHeight));
    read(fileStream, fileInfoHeader.biPlanes, sizeof(fileInfoHeader.biPlanes));
    read(fileStream, fileInfoHeader.biBitCount, sizeof(fileInfoHeader.biBitCount));

    int colorsCount = fileInfoHeader.biBitCount >> 3;
    if (colorsCount < 3) colorsCount = 3;
    int bitsOnColor = fileInfoHeader.biBitCount / colorsCount;
    int maskValue = (1 << bitsOnColor) - 1;

    fileInfoHeader.biRedMask = maskValue << (bitsOnColor * 2);
    fileInfoHeader.biGreenMask = maskValue << bitsOnColor;
    fileInfoHeader.biBlueMask = maskValue;
    fileInfoHeader.biAlphaMask = maskValue << (bitsOnColor * 3);

    unsigned int imageSize = fileHeader.bfSize - fileHeader.bfOffBits;
    std::cout << "Allocated memory for image: " << imageSize << " bytes" << std::endl;

    rgbInfo = new RGBQUAD*[fileInfoHeader.biHeight];
    for (unsigned int i = 0; i < fileInfoHeader.biHeight; i++) {
        rgbInfo[i] = new RGBQUAD[fileInfoHeader.biWidth];
    }

    fileStream.seekg(fileHeader.bfOffBits, std::ios::beg);
    unsigned int buffer;
    int linePadding = ((fileInfoHeader.biWidth * colorsCount) % 4) & 3;

    for (unsigned int i = 0; i < fileInfoHeader.biHeight; i++) {
        for (unsigned int j = 0; j < fileInfoHeader.biWidth; j++) {
            read(fileStream, buffer, fileInfoHeader.biBitCount / 8);
            rgbInfo[i][j].rgbRed = bitextract(buffer, fileInfoHeader.biRedMask);
            rgbInfo[i][j].rgbGreen = bitextract(buffer, fileInfoHeader.biGreenMask);
            rgbInfo[i][j].rgbBlue = bitextract(buffer, fileInfoHeader.biBlueMask);
            rgbInfo[i][j].rgbReserved = bitextract(buffer, fileInfoHeader.biAlphaMask);
        }
        fileStream.seekg(linePadding, std::ios_base::cur);
    }

    return true;
}

void cleanupRGBInfo(RGBQUAD **&rgbInfo, unsigned int height) {
    for (unsigned int i = 0; i < height; i++) {
        delete[] rgbInfo[i];
    }
    delete[] rgbInfo;
    rgbInfo = nullptr;
}
