#include <chrono>
#include <filesystem>
#include <iostream>
#include <thread>

#include "ImageProcessor.hpp"
#include "PpmImageFileIo.hpp"

using namespace std;


int main() {

   const string inputDirectory = "./";
   const string outputDirectory = "output/";

   // Create the output directory if it doesn't exist
   filesystem::create_directory(outputDirectory);

   for (const auto &entry : filesystem::directory_iterator(inputDirectory)) {
      if (entry.is_regular_file() && entry.path().extension() == ".ppm") {
         string inputPath = entry.path().string();

         // Extract the filename (without extension) from the path
         string filename = entry.path().stem().string();

         string outputPath = outputDirectory + filename + "_converted.ppm";

         int width, height;
         vector<Pixel> imageData;

         PpmImageFileIo::readPpmImage(inputPath, width, height, imageData);

         // Process with multiple threads
         int numThreads = thread::hardware_concurrency();
         auto startMultiThreaded = chrono::high_resolution_clock::now();
         ImageProcessor::processImage(imageData, numThreads, width, height);
         auto endMultiThreaded = chrono::high_resolution_clock::now();

         // Process with a single thread
         auto startSingleThreaded = chrono::high_resolution_clock::now();
         ImageProcessor::processImage(imageData, 1, width, height); // Pass numThreads = 1 for single-threaded
         auto endSingleThreaded = chrono::high_resolution_clock::now();

         // Output processing times
         cout << numThreads << "-threaded processing time for " << filename << ": " << chrono::duration_cast<chrono::milliseconds>(endMultiThreaded - startMultiThreaded).count() << " ms\n";
         cout << "Single-threaded processing time for " << filename << ": " << chrono::duration_cast<chrono::milliseconds>(endSingleThreaded - startSingleThreaded).count() << " ms\n";

         // Write result to output files
         PpmImageFileIo::writePpmImage(outputPath, width, height, imageData);
      }
   }

   return 0;
}
