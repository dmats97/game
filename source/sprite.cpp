#include "sprite.hpp"

sprite::sprite(){
  hide = true;
  index = 0;
  px = py = pz = ox = oy = 0.0f;
  sx = sy = 1.0f;
}

sprite::sprite(C2D_SpriteSheet* _sheet, int _index, float _px, float _py, float _pz){
  hide = false;
  setSprite(_sheet, _index);
  setPos(_px, _py, _pz);
}

void sprite::setSprite(C2D_SpriteSheet* _sheet, int _index){
  C2D_SpriteFromSheet(&spr, *_sheet, _index);
}

void sprite::setPos(float _px, float _py){
  C2D_SpriteSetPos(&spr, _px, _py);
}

void sprite::setPos(float _px, float _py, float _pz){
  C2D_SpriteSetPos(&spr, _px, _py);
  C2D_SpriteSetDepth(&spr, _pz);
}

void sprite::setScale(float _sx, float _sy){
  C2D_SpriteSetScale(&spr, _sx, _sy);
}

void sprite::setHide(bool _hide){
  hide = _hide;
}

void sprite::draw(){
  if (!hide) C2D_DrawSprite(&spr);
}
