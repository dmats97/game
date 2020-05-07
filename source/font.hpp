#include <string>
#include <citro2d.h>

class gtext{
  private:
    std::string str; 
    bool change;
    float px, py, pz, sx, sy;
    u32 color;
    C2D_Font* fontp;
    C2D_TextBuf txBuf;

    void parse();

  public:
    gtext();
    gtext(std::string, C2D_Font*, float, float, float);

    C2D_Text tx;
    void setString(std::string);
    void setScale (float, float);
    void setPos(float, float, float);
    void setPos(float, float);
    void setColor(int, int, int, int);
    void setColor(int, int, int);
    void setFont(C2D_Font*);
    void draw();
};
