#include "AT89X52.H"

void main(){
	unsigned char i=0;
	EA=1;
	EX0=1;
	EX1=1;
	while(1)
	{
		P0=i;
		Delay_ms(50);
		i++;
	}
}

void EX0_init(void) interrupt 0
{
	char i=0;
	for(i=0;i<5;i++)
	{
		P0=0x00; Delay_ms(1000);
		P0=0xff; Delay_ms(1000);
	}
}


void EX1_init(void) interrupt 2
{
	char i=0;
	for(i=0;i<5;i++)
	{
		P0=0x00; Delay_ms(3000);
		P0=0xff; Delay_ms(3000);
	}
}