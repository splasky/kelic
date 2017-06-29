#include "AT89X52.H"
sfr Data=0x80;
/* s char 0x6d */
unsigned char is_button=0;

void main(void)
{
	EA=1;
	IT0=1;
	EX0=1;
	
	P1=0xf0;

	while(1){
		if(!is_button){
			Data=~0x6d;
		}else{
			Data=0x6d;
		}
		Delay_ms(50);
	}
}



void EX0_init(void) interrupt 0
{
	
	is_button=!is_button;
}