#include<lpc214x.h>

void init(){
	PINSEL0=0x5;
	U0FCR=0x7;
	U0LCR=0x03;
	U0DLL=0x5D;
	U0DLM=0x00;
}

void delay(){
	int i;
	for(i=0;i<=2000000;i++);
}

int main(){
	unsigned char p[]="Hello world";
	int z;
	init();
	for(z=0;z<11;z++){
		U0THR=p[z];
		while(!(U0LSR && 0x20));
		delay();
	}
	while(1);
}