#include "..\AT89X52.H"
#include "font.h"
sfr Data=0x80;
sfr Scan=0x90;

int main(void){
	unsigned char i=0;
	Scan=0x7F;
	while(1){
		for(i=0;i<8;++i){
			Data=font[i];
			Delay_ms(1);
			Data=0xFF; // disable all
			Scan=RR8(Scan);
		}
		
	}

}