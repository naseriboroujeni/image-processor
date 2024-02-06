#ifndef PPM_IMAGE_FILE_IO_HPP
#define PPM_IMAGE_FILE_IO_HPP

#include <string>
#include <vector>
#include "Pixel.hpp"

using namespace std;

class PpmImageFileIo {
public:
   static void readPpmImage(const string &inputPath, int &width, int &height, vector<Pixel> &imageData);
   static void writePpmImage(const string &outputPath, int width, int height, const vector<Pixel> &imageData);
};

#endif // PPM_IMAGE_FILE_IO_HPP
