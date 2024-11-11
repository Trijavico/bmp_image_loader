/*
 *    BMP Loader written by Raydelto Hernandez  (raydelto@yahoo.com)
 */

#include <cstdio>
#include <iostream>
#include <string>

#include "bmp_reader.h"
using namespace std;

int main(void) {
    unsigned char *rgbData;
    unsigned char *header;
    unsigned int imageSize;
    unsigned int headerSize;
    cout << "Reading the BMP file ... " << endl;
    ReadBMP("img/test.bmp", header, rgbData, headerSize, imageSize);
    ApplyGrayFilter(header, rgbData);
    // FlipVertically(header, rgbData);
	FlipHorizontally(header, rgbData);

    cout << "Writing a new BMP file based on data read from a BMP in the " "previous step ..." << endl;
    WriteBMP("img/test2.bmp", header, rgbData, headerSize, imageSize);
    cout << "Freeing resources..." << endl;
    delete[] rgbData;
    delete[] header;
    cout << "This application has ended its execution." << endl;
    return 0;
}
