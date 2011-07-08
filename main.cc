#include <iostream>
#include <Magick++.h>

using namespace std;
using namespace Magick;

int main() {
  Image ariel("templates/ariel.jpg");

  Geometry g("100x100+50+50");
  Color c("white");
  ariel.fontPointsize(50);
  ariel.strokeColor(c);
  ariel.fillColor(c);
  ariel.font("Helvetica");
  ariel.annotate("Something", g);

  ariel.write("ariel2.jpg");

  return 1;
}

