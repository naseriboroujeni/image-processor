#include "PpmImageFileIo.hpp"
#include <fstream>
#include <iostream>

void PpmImageFileIo::readPpmImage(const string &inputPath, int &width, int &height, vector<Pixel> &imageData) {

   ifstream inputFile(inputPath, ios::binary);
   if (!inputFile) {
      cerr << "Error opening input file.\n";
      return;
   }

   string format;
   inputFile >> format >> width >> height;
   inputFile >> ws;

   imageData.resize(width * height);
   inputFile.read(reinterpret_cast<char *>(imageData.data()), sizeof(Pixel) * width * height);

   inputFile.close();
}

void PpmImageFileIo::writePpmImage(const string &outputPath, int width, int height, const vector<Pixel> &imageData) {

   ofstream outputFile(outputPath, ios::binary);
   if (!outputFile) {
      cerr << "Error opening output file.\n";
      return;
   }

   // Write PPM header
   outputFile << "P6\n"
              << width << " " << height << "\n255\n";

   // Write pixel data
   outputFile.write(reinterpret_cast<const char *>(imageData.data()), sizeof(Pixel) * width * height);

   outputFile.close();
}
