#ifndef __DEFINES_H__
#define __DEFINES_H__

#define blit blitAlphaImageToScreen
#define waitvblank sceDisplayWaitVblankStart
#define screenflip flipScreen
#define printf pspDebugScreenPrintf
#define RGB(r, g, b) ((r)|((g)<<8)|((b)<<16))

#endif
