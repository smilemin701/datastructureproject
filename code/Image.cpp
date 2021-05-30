/**
 * @file lab_intro.cpp
 * Implementations of image manipulation functions.
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <stdlib.h>     
#include <vector>
#include <time.h>
#include <stdio.h>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include "Image.h"

using cs225::HSLAPixel;
using cs225::PNG;
/**
 * Returns an image that has been transformed to grayscale.
 *
 * The saturation of every pixel is set to 0, removing any color.
 *
 * @return The grayscale image.
 */
PNG grayscale(PNG image) {
  /// This function is already written for you so you can see how to
  /// interact with our PNG class.
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      // `pixel` is a pointer to the memory stored inside of the PNG `image`,
      // which means you're changing the image directly.  No need to `set`
      // the pixel since you're directly changing the memory of the image.
      pixel.s = 0.5;
      pixel.h = 350;
    }
  }

  return image;
}



/**
 * Returns an image with a spotlight centered at (`centerX`, `centerY`).
 *
 * A spotlight adjusts the luminance of a pixel based on the distance the pixel
 * is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 * distance away from the center.
 *
 * For example, a pixel 3 pixels above and 4 pixels to the right of the center
 * is a total of `sqrt((3 * 3) + (4 * 4)) = sqrt(25) = 5` pixels away and
 * its luminance is decreased by 2.5% (0.975x its original value).  At a
 * distance over 160 pixels away, the luminance will always decreased by 80%.
 * 
 * The modified PNG is then returned.
 *
 * @param image A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 *
 * @return The image with a spotlight.
 */
PNG createSpotlight(PNG image, int centerX, int centerY, int score) {
  for (unsigned x = 0; x < image.width(); x++) {
    for (unsigned y = 0; y < image.height(); y++) {
      HSLAPixel & pixel = image.getPixel(x, y);

      double edist = sqrt(pow(centerX - (int)x,2) + pow(centerY - (int)y,2));
      if (edist < 20*(score + 1)) {
        //pixel.s = 0.6 + pixel.s;
        pixel.h = 90;
        pixel.a = 0.1;
        pixel.l = 0.5;
        pixel.s = 1;

    }
    }
  } 
  return image;
}

PNG connectNode(PNG image, int x1, int y1, int x2, int y2) {
  for (int i = x1; i < x2; i++) {
      double y_val = (((double) (y2 - y1)/ (double) (x2 - x1)) * abs((double) (i - x1))) + y1;
      int rounded = abs(round(y_val));
      unsigned int y_entry = rounded;
      unsigned int x_entry = i;
      if (i < (int) image.width() && rounded < (int) image.height()) {
        for(int i = 0; i < 7; i++) {
          cs225::HSLAPixel & pixel = image.getPixel(x_entry, y_entry+i);
        //changing HSLApixel values to pink.
          pixel.h = 40;
          pixel.s = 1;
          pixel.l = 0.6;
          pixel.a = 1;
        
        }
        

        
      }
    }

    for (int i = x2; i < x1; i++) {
      double y_val = (((double) (y1 - y2)/ (double) (x1 - x2)) * abs((double) (i - x2))) + y2;
      int rounded = abs(round(y_val));
      unsigned int y_entry = rounded;
      unsigned int x_entry = i;
      if (abs(i) < (int) image.width() && abs(rounded) < (int) image.height()) {
        for(int i = 0; i < 7; i++) {
          cs225::HSLAPixel & pixel2 = image.getPixel(x_entry+i, y_entry);
        //changing HSLApixel values to pink.
          pixel2.h = 350;
          pixel2.s = 1;
          pixel2.l = 0.6;
          pixel2.a = 1;
        
        }
      }
    }
  return image;

}

PNG reset_to_ori(PNG ori, PNG cover){
  for (unsigned x = 0; x < ori.width(); x++) {
    for (unsigned y = 0; y < ori.height(); y++) {
      cs225::HSLAPixel & pixel_ori = ori.getPixel(x, y);
      cs225::HSLAPixel & pixel_cover = cover.getPixel(x, y);
      pixel_ori = pixel_cover;
    }
  }
  return ori;
}
