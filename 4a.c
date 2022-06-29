#include<lpc214x.h>
pwm_init(){
	PINSEL0=0x2;
	PWMPR=0x2;
	PWMPCR=0x200;
	PWMMR0=0xC37F;
	PWMMCR=0x2;
	PWMTCR=0x9;
}

int main(){
	int x;
	pwm_init();
	while(1){
		for(x=0;x<10;x++){
			PWMMR1=0xfff+(0xff5*x);
			PWMLER=0x2;
		}
	}
}