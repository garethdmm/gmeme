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
  string filetype("png");
  string text1("");
  string text2("");

  if (argc < 4) {
    cout << "Usage: gmeme {-fry|-ariel|-philosoraptor|-yuno} top_text bottom_text" << endl;
  }

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') { // handle all the control flags here
      if (argv[i][1] == 't') { // filetype
        i++;
        if (i < argc) {
          filetype = string(argv[i]);
        }
      } else if (argv[i][1] == 'f') { // fry
        memetype = "fry";
      } else if (argv[i][1] == 'a') {
        memetype = "ariel";
      } else if (argv[i][1] == 'p') {
        memetype = "philosoraptor";
      } else if (argv[i][1] == 'y') {
        memetype = "yuno";
      } else if (argv[i][1] == 'w') {
        memetype = "anonwife";
      }
    } else { // handle text strings in here
      text1 = argv[i];
      if (i + 1 < argc) {
        i++;
        text2 = argv[i];
      }
    }
  }

  if (memetype == "fry") {
    Meme fry("templates/fry.png", text1, text2);
    Image fryImage = fry.render();
    fryImage.write("fry." + filetype);
  } else if (memetype == "ariel") {
    Meme ariel("templates/ariel.jpg", text1, text2);
    Image arielImage = ariel.render();
    arielImage.write("ariel." + filetype);
  } else if (memetype == "philosoraptor") {
    Meme philo("templates/philosoraptor.jpg", text1, text2);
    Image philoImage = philo.render();
    philoImage.write("philosoraptor." + filetype);
  } else if (memetype == "yuno") {
    Meme yuno("templates/yuno.png", text1, text2);
    Image yunoImage = yuno.render();
    yunoImage.write("yuno." + filetype);
  } else if (memetype == "anonwife") {
    Meme wife("templates/anonwife.jpg", text1, text2);
    Image wifeImage = wife.render();
    wifeImage.write("wife." + filetype); 
  }

  return 1;
}

