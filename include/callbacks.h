#ifndef __CALLBACKS_H__
#define __CALLBACKS_H__

void dump_threadstatus(void);
int exit_callback(int arg1, int arg2, void *common);
int CallbackThread(SceSize args, void *argp);
int SetupCallbacks(void);

#endif
