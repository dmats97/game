#include "font.hpp"

gtext::gtext(){
  txBuf  = C2D_TextBufNew(200);
  fontp  = NULL;
  color  = C2D_Color32(0, 0, 0, 255);
  change = true;
  str = "";
  px  = 0.0f;
  py  = 0.0f;
  pz  = 0.0f;
  sx  = 1.0f;
  sy  = 1.0f;
}

gtext::gtext(std::string _str, C2D_Font* _fontp, float _px, float _py, float _pz){
  txBuf  = C2D_TextBufNew(200);
  fontp  = _fontp;
  color  = C2D_Color32(0, 0, 0, 255);
  change = true;
  str = _str;
  px  = _px;
  py  = _py;
  pz  = _pz;
  sx  = 1.0f;
  sy  = 1.0f;
}

void gtext::setString(std::string _str){
  str = _str;
  change = true;
}

void gtext::setScale(float _sx, float _sy){
  sx = _sx;
  sy = _sy;
}

void gtext::setPos(float _px, float _py, float _pz){
  px = _px;
  py = _py;
  pz = _pz;
}

void gtext::setPos(float _px, float _py){
  px = _px;
  py = _py;
}

void gtext::setColor(int _r, int _g, int _b, int _a){
  color = C2D_Color32(_r, _g, _b, _a);
  change = true;
}

void gtext::setColor(int _r, int _g, int _b){
  color = C2D_Color32(_r, _g, _b, _a);
  change = true;
}

void gtext::setFont(C2D_Font* _fontp){
  fontp = _fontp;
  change = true;
}

void gtext::parse(void){
  C2D_TextBufClear(txBuf);
  C2D_TextFontParse(&tx, *fontp, txBuf, str.c_str());
  C2D_TextOptimize(&tx);
}

void gtext::draw(void){
  if (change) parse();
  C2D_DrawText(&tx, C2D_WithColor, px, py, pz, sx, sy, color);
}
