#include "include/includes.h" //All needed header files are placed in the "Includes.h" file. This A) Makes them global to any c code that includes the file and B) keeps the main code smaller.
#include "include/defines.h" //All the used defines are here. Look in the defines file for a few examples of how to use a alias for a function. i.e waitvblank(); instead of sceDisplayWaitVblankStart();.

#define MAX_IMG 2 //Tells the code that the maxiumum amount of images for the particular set is 2

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//					**			VARIABLES		**							//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int bx = 0; //background X
int done = 0; // 0 = keep program running while true

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//					**			FUNCTIONS		**						//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void scroll() //Scrolling code example in c....  Simple yet effective 
{
	if (bx != - 480) // Keep scrolling whilst bx isn't equal to - 480.
	{
		bx -= 1;
	} else {
		bx = 0; // Reset bx (i.e image 1 to 0 after it reaches - 480.
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//					**			MAIN       		**							//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
					
int main()
{
	SetupCallbacks();
	initGraphics();
	pspDebugScreenInit();
	scePowerSetClockFrequency(333, 333, 166); //choose what speed you want to run your game/app at.
		
	SceCtrlData pad, lastpad; //setup pointer for last pad. You will know it as oldpad.
	sceCtrlReadBufferPositive(&lastpad, 1);
	
	/////////////////////// ********** MENU IMAGES ********** ///////////////////////////
	Image *menu[MAX_IMG]; 
		menu[0] = loadImage("./bk.png");
		menu[1] = menu[0];
		
	/////////////////////// ********** MENU SOUNDS & MUSIC ********** ///////////////////////////
	//Load Sounds	
	WAV_Init(); //Init the wav loader. Must be done or you will hear no sound :p
	WAV* ACHTUNG = WAV_Load("./ACHTUNG.wav"); //Load the wav file

	//Load Music 
	MP3_Init(1); //Init the mp3 loader. Must be done or you will hear no music.
	MP3_Load("./Motorcycle_Emptiness.mp3"); //load the mp3.
	MP3_Play();	//Play the mp3. Note MP3 playing is done outside the main loop.
	
	//////////////// WHILE LOOP /////////////////
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//					**			MENU       		**						   			   //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
while(done == 0)
{
	sceCtrlReadBufferPositive(&pad, 1); //Same as Pad = Controls.read()
			
	if (pad.Buttons != lastpad.Buttons)
	{
		if (pad.Buttons & PSP_CTRL_CROSS)  /*----Plays Sound If "Left" Button is Pressed And Changes the Start Value to "1"----*/
		{
			WAV_Play(ACHTUNG); //play the wav file upon pressing cross
		}
	
		if (pad.Buttons & PSP_CTRL_START) /*-----Plays Sound If "Left" Button is Pressed And Changes the Start Value to "0"----*/
		{
			sceKernelExitGame(); //quit the game
			return 0;
		}
	}	

	scroll(); // Call the scroll function
		  
    blit(0, 0 , 480, 272, menu[0], bx, 0); //blit image to screen
	blit(0, 0 , 480, 272, menu[1], bx + 480, 0); //blit image to screen
    waitvblank(); //wait for vblank
	FPS_CHECK(); //See what fps the app is running at
    screenflip(); //flip buffers
	lastpad = pad; 
}
    sceKernelSleepThread();
    return 0;
}
