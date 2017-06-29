#include "..\AT89X52.h"

sfr Data=0x80;
sfr Scan=0x90;

#include "font.h"

void main(void){
    unsigned char i=0;
	unsigned char mask=0;
	unsigned char boo=0;
	unsigned char repeat=0;
	Scan=0x7F;


	while(1){
		mask=0x7F;
		for(boo=0;boo<8;boo++){
		
			for(repeat=0;repeat<10;repeat++){
			 for(i=0;i<8;i++){
			  	Data=font[i]|mask;
				Delay_ms(1);
				Data=0xFF;
				Scan=RR8(Scan);
			 }
			}
		mask=mask>>1;
		}

	   for(boo=0;boo<8;boo++){
			for(repeat=0;repeat<10;repeat++){
			 for(i=0;i<8;i++){
			  	Data=font[i]|mask;
				Delay_ms(1);
				Data=0xFF;
				Scan=RR8(Scan);
			 }
			}
		mask=mask<<1;
		}
		
	}
}
