#ifndef PPM_IMAGE_FILE_IO_HPP
#define PPM_IMAGE_FILE_IO_HPP

#include <string>
#include <vector>

#include "Pixel.hpp"

using namespace std;

/**
 * @brief A class for reading and writing PPM image files.
*/
class PpmImageFileIo {

public:
   /**
    * @brief Read a PPM image file.
    * @param inputPath The path to the input PPM file.
    * @param width The width of the image (output).
    * @param height The height of the image (output).
    * @param imageData The vector to store pixel data (output).
   */
   static void readPpmImage(const string &inputPath, int &width, int &height, vector<Pixel> &imageData);

   /**
    * @brief Write a PPM image file.
    * @param outputPath The path to the output PPM file.
    * @param width The width of the image.
    * @param height The height of the image.
    * @param imageData The vector containing pixel data.
   */
   static void writePpmImage(const string &outputPath, int width, int height, const vector<Pixel> &imageData);
};

#endif // PPM_IMAGE_FILE_IO_HPP
