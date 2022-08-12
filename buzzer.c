#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvADC.h"

int main(){
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG();
	
	DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT);
	DrvGPIO_SetBit(E_GPB, 11);
	
	while(1){
		DrvGPIO_ClrBit(E_GPB, 11);
		DrvSYS_Delay(10000);
		DrvGPIO_SetBit(E_GPB, 11);
		DrvSYS_Delay(20000);
		DrvGPIO_ClrBit(E_GPB, 11);
		DrvSYS_Delay(30000);
		DrvGPIO_SetBit(E_GPB, 11);
		DrvSYS_Delay(40000);
		DrvGPIO_SetBit(E_GPB, 11);
		DrvSYS_Delay(70000);
		DrvGPIO_ClrBit(E_GPB, 11);
		DrvSYS_Delay(60000);
		DrvGPIO_SetBit(E_GPB, 11);
		DrvSYS_Delay(70000);
	}
}
