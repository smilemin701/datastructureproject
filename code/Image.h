/**
 * @file lab_intro.h
 * Declarations of image manipulation functions.
 */

#pragma once

#include "cs225/PNG.h"

cs225::PNG grayscale(cs225::PNG image);  
cs225::PNG createSpotlight(cs225::PNG image, int centerX, int centerY, int score);
cs225::PNG illinify(cs225::PNG image);
cs225::PNG watermark(cs225::PNG firstImage, cs225::PNG secondImage);
cs225::PNG connectNode(cs225::PNG image, int x1, int y1, int x2, int y2);
cs225::PNG reset_to_ori(cs225::PNG ori, cs225::PNG cover);