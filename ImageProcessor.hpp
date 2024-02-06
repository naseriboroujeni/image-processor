#ifndef IMAGE_PROCESSOR_HPP
#define IMAGE_PROCESSOR_HPP

#include <vector>

#include "Pixel.hpp"

using namespace std;

/**
 * @brief A class for image processing operations.
 */
class ImageProcessor {

public:
   /**
    * @brief Process a section of image data.
    * @param imageData The vector containing pixel data.
    * @param start The starting index for processing.
    * @param step The step size to process every nth pixel.
    * @param width The width of the image.
    * @param height The height of the image.
    */
   static void processSection(vector<Pixel> &imageData, int start, int step, int width, int height);

   /**
    * @brief Process the entire image using multiple threads.
    * @param imageData The vector containing pixel data.
    * @param numThreads The number of threads to use for processing.
    * @param width The width of the image.
    * @param height The height of the image.
    */
   static void processImage(vector<Pixel> &imageData, int numThreads, int width, int height);
};

#endif // IMAGE_PROCESSOR_HPP
