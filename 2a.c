#include<lpc214x.h>

void onwait(){
	T0MR0=0x7A11;
	T0PR=0;
	T0TCR=1;
	while(!(T0TC==T0MR0));
	T0TCR=0x3;
}

void offwait(){
	T0MR0=0xB71A;
	T0PR=1;
	T0TCR=1;
	while(!(T0TC==T0MR0));
	T0TCR=0x3;
}

int main(){
	T0MCR=0x4;
	IODIR0=1<<16;
	while(1){
		IOSET0=1<<16;
		onwait();
		IOCLR0=1<<16;
		offwait();
	}
}