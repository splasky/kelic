#include "..\AT89X52.H"

sfr Data=0x80; //P0 Bus for data output
sbit SLED0=0x90;
sbit SLED1=0x91;
sbit SLED2=0x92;
sbit SLED3=0x93;

unsigned char code Table[]={
0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};

void display(unsigned char scan);
unsigned char sec=30,min=59;

int main(void){
	
	unsigned scan=80;
	
	while(1){
		display(scan);
		sec++;
 		if(sec>59){
			sec=0;
			min+=1;
		}

		if(min>59){
			min=0;
		}
		
	}

}

void display(unsigned char scan){
	unsigned char j=0;
	unsigned char i=0;
	for(j=0;j<scan;++j){
		SLED0=SLED1=SLED2=SLED3=1; //disable
		i=sec %10;
		Data=~Table[i];
		SLED0=0;
		Delay_ms(4);

		SLED0=SLED1=SLED2=SLED3=1; //disable
		i=sec/10;
		Data=~Table[i];
		SLED1=0;
		Delay_ms(4);

		SLED0=SLED1=SLED2=SLED3=1; //disable
		i=min%10;
		Data=~Table[i];
		SLED2=0;
		Delay_ms(4);

		SLED0=SLED1=SLED2=SLED3=1; //disable
		i=min/10;
		Data=~Table[i];
		SLED3=0;
		Delay_ms(4);
	}

}