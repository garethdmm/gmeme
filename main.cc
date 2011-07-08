#include <iostream>
#include <Magick++.h>

using namespace std;
using namespace Magick;

Image fry(const string& text1, const string& text2) {
  Image frymeme("templates/fry.png");

  Geometry text1_offset("+120+10");
  Geometry text2_offset("+120+400");
  Color white("white");
  Color black("black");

  frymeme.font("Helvetica-Bold");
  frymeme.fontPointsize(50);
  frymeme.fillColor(white);
  frymeme.strokeColor(black);

  frymeme.annotate(text1, text1_offset);
  frymeme.annotate(text2, text2_offset); 

  return frymeme;
}

int main(int argc, char* argv[]) {

  Image frymeme = fry("Not sure if troll", "or just stupid");
  frymeme.write("fry.png");

  return 1;
}

