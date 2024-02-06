#include "ImageProcessor.hpp"

#include <thread>

void ImageProcessor::processSection(vector<Pixel> &imageData, int start, int step, int width, int height) {
   for (int i = start; i < width * height; i += step) {
      imageData[i].red = min(imageData[i].red + 50, 255);
      imageData[i].green = min(imageData[i].green + 20, 255);
      imageData[i].blue = min(imageData[i].blue - 30, 255);
   }
}

void ImageProcessor::processImage(vector<Pixel> &imageData, int numThreads, int width, int height) {
   vector<thread> threads;

   for (int i = 0; i < numThreads; ++i) {
      threads.emplace_back(&ImageProcessor::processSection, ref(imageData), i, numThreads, width, height);
   }

   for (auto &thread : threads) {
      thread.join();
   }
}
