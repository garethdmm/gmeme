#include <iostream>
#include <sstream>
#include <string.h>
#include <Magick++.h>

using namespace std;
using namespace Magick;

Image ariel(const string& text1, const string& text2) {
  cout << "Ariel?" << endl;
  Image arielmeme("templates/ariel.jpg");

  Color white("white");
  Color black("black");

  arielmeme.font("Helvetica-Bold");
  arielmeme.fontPointsize(50);
  arielmeme.fillColor(white);
  arielmeme.strokeColor(black);

  TypeMetric tm1, tm2;
  arielmeme.fontTypeMetrics(text1, &tm1);
  arielmeme.fontTypeMetrics(text2, &tm2);

  cout << "Text1: " << text1 << endl;
  cout << "Width: " << tm1.textWidth() << endl;

  cout << "Text2: " << text2 << endl;
  cout << "Width: " << tm2.textWidth() << endl;

  int mid = 200;
  int left1 = mid - (tm1.textWidth()/2);
  int left2 = mid - (tm2.textWidth()/2);

  left1 = (left1 >= 0 )? left1 : 0;
  left2 = (left2 >= 0 )? left2 : 0;

  stringstream offset1_string;
  stringstream offset2_string;

  offset1_string << "+" << left1 << "+10";
  offset2_string << "+" << left2 << "+365";

  cout << "Offset1: " << offset1_string.str() << endl;
  cout << "Offset2: " << offset2_string.str() << endl;

  Geometry text1_offset(offset1_string.str().c_str());
  Geometry text2_offset(offset2_string.str().c_str());

  arielmeme.annotate(text1, text1_offset);
  arielmeme.annotate(text2, text2_offset); 

  return arielmeme;
}

Image fry(const string& text1, const string& text2) {
  Image frymeme("templates/fry.png");

  Color white("white");
  Color black("black");

  frymeme.font("Helvetica-Bold");
  frymeme.fontPointsize(50);
  frymeme.fillColor(white);
  frymeme.strokeColor(black);

  TypeMetric tm1, tm2;
  frymeme.fontTypeMetrics(text1, &tm1);
  frymeme.fontTypeMetrics(text2, &tm2);

  cout << "Text1: " << text1 << endl;
  cout << "Width: " << tm1.textWidth() << endl;

  cout << "Text2: " << text2 << endl;
  cout << "Width: " << tm2.textWidth() << endl;

  int mid = 301;
  int left1 = mid - (tm1.textWidth()/2);
  int left2 = mid - (tm2.textWidth()/2);

  stringstream offset1_string;
  stringstream offset2_string;

  offset1_string << "+" << left1 << "+10";
  offset2_string << "+" << left2 << "+400";

  cout << "Offset1: " << offset1_string.str() << endl;
  cout << "Offset2: " << offset2_string.str() << endl;

  Geometry text1_offset(offset1_string.str().c_str());
  Geometry text2_offset(offset2_string.str().c_str());

  frymeme.annotate(text1, text1_offset);
  frymeme.annotate(text2, text2_offset); 

  return frymeme;
}

int main(int argc, char* argv[]) {

  string memetype("");
  string text1("");
  string text2("");

  if (argc < 4) {
    cout << "Usage: gmeme -fry top_text bottom_text" << endl;
  }

  for (int i = 1; i < argc; i++) {
    cout << "Argv[ " << i << "]:" << argv[i] << endl;

    if (argv[i][0] == '-') { // handle all the control flags here
      cout << "Control: " << argv[i] << endl;

      if (argv[i][1] == 'f') { // fry
        memetype = "fry";
        cout << "Frymeme!" << endl;
      } else if (argv[i][1] == 'a') {
        memetype = "ariel";
        cout << "Arielmeme!" << endl;
      }
    } else { // handle text strings in here
      text1 = argv[i];
      cout << "text1: " << text1 << endl;
      if (i + 1 < argc) {
        i++;
        text2 = argv[i];
        cout << "text2: " << text2 << endl;
      }
    }
  }

  if (memetype == "fry") {
    cout << "text1: " << text1 << endl;
    cout << "text2: " << text2 << endl;

    Image fryImage = fry(text1, text2);    
    fryImage.write("fry.png");
  } else if (memetype == "ariel") {
    Image arielImage = ariel(text1, text2);
    arielImage.write("ariel.png");
  }

  return 1;
}

