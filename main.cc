#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <Magick++.h>

#include "meme.h"

using namespace std;
using namespace Magick;

int main(int argc, char* argv[]) {
  string memetype("");
  string text1("");
  string text2("");

  if (argc < 4) {
    cout << "Usage: gmeme {-fry|-ariel} top_text bottom_text" << endl;
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
    Meme fry("templates/fry.png", text1, text2);
    Image fryImage = fry.render();
    fryImage.write("fry.png");
  } else if (memetype == "ariel") {
    Meme ariel("templates/ariel.jpg", text1, text2);
    Image arielImage = ariel.render();
    arielImage.write("ariel.png");
  }

  return 1;
}

