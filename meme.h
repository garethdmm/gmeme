#ifndef __MEME_H__
#define __MEME_H__ 

#include <Magick++.h>

class Meme {
  public:
    Meme(const std::string& name, const std::string& filename, const std::string& text1, const std::string& text2);
    Magick::Image render();
    std::string getName();

  private:
    std::string name;
    std::string filename;
    std::string text1;  
    std::string text2;
};

class FryMeme : public Meme {
  public:
    FryMeme(const std::string& text1, const std::string& text2);
  private:
    static std::string name;
    static std::string filename; 
};

class ArielMeme : public Meme {
  public:
    ArielMeme(const std::string& text1, const std::string& text2);
  private:
    static std::string name;
    static std::string filename; 
};


class PhilosoraptorMeme : public Meme {
  public:
    PhilosoraptorMeme(const std::string& text1, const std::string& text2);
  private:
    static std::string name;
    static std::string filename; 
};

class YUNOMeme : public Meme {
  public:
    YUNOMeme(const std::string& text1, const std::string& text2);
  private:
    static std::string name;
    static std::string filename; 
};

class AnonWifeMeme : public Meme {
  public:
    AnonWifeMeme(const std::string& text1, const std::string& text2);
  private:
    static std::string name;
    static std::string filename; 
};

class YaoMeme : public Meme {
  public:
    YaoMeme(const std::string& text1, const std::string& text2);
  private:
    static std::string name;
    static std::string filename; 
};

class KeepCalmMeme : public Meme {
  public:
    KeepCalmMeme(const std::string& text1, const std::string& text2);
  private:
    static std::string name;
    static std::string filename; 
};

#endif
