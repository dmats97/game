#include <citro2d.h>

class sprite{
  private:
    C2D_Sprite spr;
    C2D_SpriteSheet* sheet;
    bool hide;
    int  index;
    float px, py, pz, sx, sy, ox, oy;

  public:
    sprite();
    sprite(C2D_SpriteSheet*, int, float, float, float);

    void setSprite(C2D_SpriteSheet*, int);
    void setPos(float, float, float);
    void setPos(float, float);
    void setScale(float, float);
    void setHide(bool);
    void draw();
};
