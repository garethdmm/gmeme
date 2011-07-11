#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <Magick++.h>

#include "meme.h"

using namespace std; using namespace Magick; 
int main(int argc, char* argv[]) {
  string memetype("");
  string filetype("png");
  string text1("");
  string text2("");

  if (argc < 4) {
    cout << "Usage: gmeme {-fry|-ariel|-philosoraptor|-yuno|-wife|-ming(yao)|-calm(keep)} top_text bottom_text" << endl;
    return 1;
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
      } else if (argv[i][1] == 'm') {
        memetype = "yaoming";
      } else if (argv[i][1] == 'c') {
        memetype = "keepcalm";
      }
    } else { // handle text strings in here
      text1 = argv[i];
      if (i + 1 < argc) {
        i++;
        text2 = argv[i];
      }
    }
  }

  Meme * imageMeme;

  if (memetype == "fry") {
    imageMeme = &(FryMeme(text1, text2));
  } else if (memetype == "ariel") {
    imageMeme = &(ArielMeme(text1, text2));
  } else if (memetype == "philosoraptor") {
    imageMeme = &(PhilosoraptorMeme(text1, text2));
  } else if (memetype == "yuno") {
    imageMeme = &(YUNOMeme(text1, text2));
  } else if (memetype == "anonwife") {
    imageMeme = &(AnonWifeMeme(text1, text2));
  } else if (memetype == "yaoming") {
    imageMeme = &(YaoMeme(text1, text2));
  } else if (memetype == "keepcalm") {
    imageMeme = &(KeepCalmMeme(text1, text2));
  }

  Image memeImage = imageMeme->render();
  memeImage.write(imageMeme->getName() + "." + filetype);

  return 1;
}
