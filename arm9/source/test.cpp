// libadx-nds test program
// by headshot2017 (Headshotnoby)
// LibADX Dreamcast library (c)2012 Josh PH3NOM Pearson
// Built on top of NDS Helix-MP3 decoder code by sverx (https://adshomebrewersdiary.blogspot.com/2012/06/mp3-streaming-on-arm7.html)

#include <nds.h>
#include <stdio.h>
#include <filesystem.h>

#include "libadx.h"

static void waitAnyKey()
{
	while (1)
	{
		swiWaitForVBlank();
		scanKeys();

		if (keysDown())
			break;
	}
}

int main(void)
{
	videoSetModeSub(MODE_0_2D);
	vramSetBankC(VRAM_C_SUB_BG);
	consoleInit(NULL, 0, BgType_Text4bpp, BgSize_T_256x256, 0, 1, false, true);

	printf("libadx-nds test program\n\n");

	printf("Loading NitroFS...");
	if (!nitroFSInit(0))
	{
		printf("Failed!\nPress any button to exit...\n");
		waitAnyKey();
		return 1;
	}

	printf("Success!\nInit ADX library...");
	if (!adx_init())
	{
		printf("Failed!\nPress any button to exit...\n");
		waitAnyKey();
		return 1;
	}

	printf("Success!\nPlay ADX file...");
    int err = adx_play("nitro:/test.adx", 1);
	if(err <= 0)
	{
		printf("Failed! %d\nPress any button to exit...\n", err);
		waitAnyKey();
		return 1;
	}
	printf("Success!\n\n");

	printf("A: Play\n");
	printf("B: Stop\n");
	printf("Y: Pause/Resume\n");
	printf("X: Restart\n");
	printf("DPad: Volume up/down\n");
	printf("Start: Exit\n");

	int vol = 127;
	bool paused = false;

	while(1) {
		swiWaitForVBlank();
		scanKeys();

		int down = keysDown();
		int held = keysHeld();

		if (!(held & KEY_SELECT)) adx_update();
		if (held & KEY_UP && vol < 127)
		{
			vol++;
			adx_set_volume(vol);
		}
		if (held & KEY_DOWN && vol > 0)
		{
			vol--;
			adx_set_volume(vol);
		}

		if (down & KEY_A) adx_play("nitro:/test.adx", 1);
		if (down & KEY_B) adx_stop();
		if (down & KEY_X) adx_restart();
		if (down & KEY_Y)
		{
			(paused) ? adx_resume() : adx_pause();
			paused ^= 1;
		}
	}
	
	return 0;
}
