#include "include/includes.h"
#include "include/callbacks.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//					**			MODULE INFO	**							//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*-----Define the main thread's attribute value----*/
PSP_MODULE_INFO("LUA2C", 0, 1, 0);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);
PSP_HEAP_SIZE_MAX();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//					**			CALLBACKS		**							//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void dump_threadstatus(void);

/*------ Exit callback ------*/
int exit_callback(int arg1, int arg2, void *common) {
          sceKernelExitGame();
          return 0;
}

/*----- Callback thread ------*/
int CallbackThread(SceSize args, void *argp) {
          int cbid;

          cbid = sceKernelCreateCallback("Exit Callback", exit_callback, NULL);
          sceKernelRegisterExitCallback(cbid);

          sceKernelSleepThreadCB();

          return 0;
}

/*------Sets up the callback thread and returns its thread id -----*/
int SetupCallbacks(void) {
          int thid = 0;

          thid = sceKernelCreateThread("update_thread", CallbackThread, 0x11, 0xFA0, 0, 0);
          if(thid >= 0) {
                    sceKernelStartThread(thid, 0, 0);
          }

          return thid;
}
