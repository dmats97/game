#include <iostream>
#include <citro2d.h>
#include <unistd.h>

void sceneInit(){
  gfxInitDefault();
  cfguInit();
  C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
  C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
  C2D_Prepare();
  romfsInit();
}

void sceneExit(){
  C2D_Fini();
  C3D_Fini();
  romfsExit();
  gfxExit();
}
