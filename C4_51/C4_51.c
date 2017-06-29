#include "../AT89X52.h"
#include "font4.h"

sfr Data=0x80;
sfr Scan=0x90;

void main(void){
 	unsigned char i=0;
	unsigned char j=0;
	unsigned char repeat;
	Scan=0x7F;

	while(1){
	 	j=0;
		while(j<8*4){
		 	for(repeat=0;repeat<50;repeat++){
			 for(i=j;i<j+8;i++){
			  	Data=font4[i];
				Delay_ms(1);
				Data=0xFF;
				Scan=RR8(Scan);
			 }

			}
			j+=8;

		}

	}

}