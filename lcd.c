#include <stdio.h>
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "Scankey.h"
#include "LCD_Driver.h"

int32_t main(void){
	int8_t number;
	char TEXT0[16]="Smpl_LCD_KeyPad";
	char TEXT1[16]="KeyPad:        ";
	
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	
	Initial_panel();
	clr_all_panel();
	
	OpenKeyPad();
	print_lcd(0, TEXT0);
	
	while(1){
		number=Scankey();
		sprintf(TEXT1+8, "%d", number);
		print_lcd(1, TEXT1);
		DrvSYS_Delay(5000);
	}
}
