#include "PNG.h"
#include "HSLAPixel.h"
#include <cmath>
#include <iostream>
#include "image.h"


using cs225::HSLAPixel;
using cs225::PNG;


PNG createNode(PNG image, int centerX, int centerY) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      double edist = sqrt(pow(centerX - (int)x,2) + pow(centerY - (int)y,2));
      if (edist > 50) {
        pixel.h = 360;
        pixel.s = pixel.s + 0.6;
      } 
    }
  } 
  return image;
  
}