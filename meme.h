#ifndef __MEME_H__
#define __MEME_H__ 

#include <Magick++.h>

class Meme {
  public:
  Meme(const std::string& filename, const std::string& text1, const std::string& text2);
  Magick::Image render();

  private:
  std::string filename;
  std::string text1;  
  std::string text2;
};

#endif
