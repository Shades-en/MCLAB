#include<lpc214x.h>
unsigned int x=0;
__irq void Timer0_ISR(){
	x^=1;
	if(x)
		IOSET0=1<<20;
	else
		IOCLR0=1<<20;
	T0IR=0x1;
	VICVectAddr=0;
}

int main(){
	IODIR0=0xffffffff;
	T0MCR=0x3;
	T0MR0=0x3456ff;
	VICVectAddr4=(unsigned) Timer0_ISR;
	VICVectCntl4=0x24;
	VICIntEnable=0x10;
	T0TCR=1;
	for(;;);
}