#include <iostream>
#include <sstream>
#include <string>

#include "meme.h"

using namespace std;
using namespace Magick;

Meme::Meme(const string& filename, const string& text1, const string& text2): filename(filename), text1(text1), text2(text2) {}

Image Meme::render() {
  Image image(filename);

  Color white("white");
  Color black("black");

  Geometry imageGeometry = image.size();
  int imageWidth = imageGeometry.width();
  int imageHeight = imageGeometry.height();

  image.font("Impact");
  image.fontPointsize(50);
  image.fillColor(white);
  image.strokeColor(black);

  TypeMetric tm1, tm2;
  image.fontTypeMetrics(text1, &tm1);
  image.fontTypeMetrics(text2, &tm2);

  int mid = imageWidth / 2;
  int top = 0;
  int bottom = imageHeight - 60;
  int left1 = mid - (tm1.textWidth()/2);
  int left2 = mid - (tm2.textWidth()/2);

  left1 = (left1 >= 0 )? left1 : 0;
  left2 = (left2 >= 0 )? left2 : 0;

  stringstream offset1_string;
  stringstream offset2_string;

  offset1_string << "+" << left1 << "+" << top; 
  offset2_string << "+" << left2 << "+" << bottom;

  Geometry text1_offset(offset1_string.str().c_str());
  Geometry text2_offset(offset2_string.str().c_str());

  image.annotate(text1, text1_offset);
  image.annotate(text2, text2_offset); 

  return image;
}
