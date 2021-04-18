TARGET = LUA2C
#PSP_EBOOT_ICON = ICON0.png // uncomment to add icon0 to your eboot
#PSP_EBOOT_PIC1 = PIC1.png // uncomment to add pic1 to your eboot
#PSP_EBOOT_SND0 = SND0.AT3 // uncomment to add snd0.at3 to your eboot
OBJS = main.o graphics.o framebuffer.o callbacks.o debug.o mp3.o wav.o

CFLAGS = -O2 -G0 -Wall -g
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
ASFLAGS = $(CFLAGS)

LIBDIR =
LIBS = -lpsprtc -lpsppower -lpsputility -lpspgu -lpng -lz -lmikmod -lmmio -lpspaudiolib -lpspaudio -lm -lmad 
LDFLAGS =

EXTRA_TARGETS = EBOOT.PBP
PSP_EBOOT_TITLE = LUA2C

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
