#include <stdint.h>
#include <stdarg.h>

#include "../include/types.h"
#include "../include/imports.h"
#include "../include/utility.h"
#include "../include/syscall.h"
#include "../include/detour.h"
#include "../include/Vars.h"
#include "../include/sparse.h"
#include "../include/AdvancedWarfare.h"
#include "../include/Huds.h"
#include "../include/Menu.h"
#include "../include/Helpers.h"
#include "../include/Functions.h"
#include "../include/Buttons.h"


typedef void (*AW_DrawStub_t)(uint64_t);
AW_DrawStub_t AW_DrawStub_s;
void Draw_Hook(uint64_t p1)
{
    AW_DrawStub_s(p1);
	
	if(Dvar_GetBool("cl_ingame") == true){
		ButtonMonitoring();
	}
}

extern "C" void _main(void) {
	initImports();
	char restoreDrawingHook[16] = {0x55, 0x48, 0x89, 0xE5, 0x41, 0x57, 0x41, 0x56, 0x53, 0x48, 0x83, 0xEC, 0x18, 0x48, 0x89, 0xFB};
	memcpy((void *)0x90DFE0, restoreDrawingHook, 16 );
	HudElem_DestroyAll();//Clear everything before spawning huds in again
	WelcomeMessage[0] = SetText(0, "Dont Change", 210, 10, 0, 1.3f, 6, 255, 255, 255, 255, 0, 255, 0, 255);
	TypeWriterText(WelcomeMessage[0], "Welcome to MenuBase\nMade By CMTFrosty", 15, 1.0f);
	AW_DrawStub_s = (AW_DrawStub_t)DetourFunction(0x90DFE0, (void *)Draw_Hook, 16);
	sceSysUtilSendSystemNotificationWithText(222, "Menu Base Loaded!");
}