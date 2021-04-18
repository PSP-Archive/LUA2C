#include <pspkernel.h>
#include <pspdisplay.h>
#include <stdlib.h>
#include <string.h>
#include <pspdebug.h>
#include <psprtc.h>

//Check What FPS It Is Running At
void FPS_CHECK()
{
	static u64 tick,lasttick;
	static int drawBuffer=0;
	drawBuffer=0x88000-drawBuffer; 
	pspDebugScreenSetOffset((int)drawBuffer);
	pspDebugScreenSetXY(0,0);
	sceRtcGetCurrentTick(&tick);
	int elapsed=tick-lasttick;
	lasttick=tick;
	if(elapsed<1) elapsed=1;
	pspDebugScreenPrintf("FPS %.2f (%d usec)",1000000.0f/elapsed,elapsed);
}
