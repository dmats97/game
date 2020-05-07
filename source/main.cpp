#include <iostream>
#include <vector>

#include "init.hpp"
#include "font.hpp"
#include "sprite.hpp"

void sceneRender(std::vector<gtext> dtxt, std::vector<sprite> dspr){
  size_t i = 0;
  for(i = 0; i < dtxt.size(); i++) dtxt[i].draw();
  for(i = 0; i < dspr.size(); i++) dspr[i].draw();
}

int main(){
  sceneInit();
  C3D_RenderTarget* top = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
  consoleInit(GFX_BOTTOM, NULL);

  //resource
  C2D_Font Hanazono_font = C2D_FontLoad("romfs:/hnzn.bcfnt");
  C2D_Font Mgenplus_font = C2D_FontLoad("romfs:/mgen+_1ph.bcfnt");
  C2D_SpriteSheet  sheet = C2D_SpriteSheetLoad("romfs:/sprites.t3x"); 

  //font
  std::vector<gtext> drawObj;
  drawObj.push_back(gtext("サンプルテキスト", &Hanazono_font, 40.0f, 164.0f, 0.9f));
  drawObj[0].setColor(255, 255, 255, 255);

  //sprites
  std::vector<sprite> drawSpr;
  drawSpr.push_back(sprite(&sheet, 0, 0.0f,   0.0f, 0.0f));
  drawSpr.push_back(sprite(&sheet, 2, 8.0f, 240.0f, 0.0f));
  
  while(aptMainLoop()){
    hidScanInput();
    u32 key = hidKeysDown();
    if (key & KEY_START) break;

    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
	  C2D_TargetClear(top, C2D_Color32(0x30, 0x30, 0x30, 0xFF));
    C2D_SceneBegin(top);
    sceneRender(drawObj, drawSpr);
    C3D_FrameEnd(0);

  }

  C2D_FontFree(Hanazono_font);

  sceneExit();
  return 0;
}
