#include "../AT89X52.h"
#include "font.h"

sfr Data=0x80;
sfr Scan=0x90;

void main(void){
 	unsigned char i=0;
	unsigned char shift=0;
	unsigned char repeat=0;
	unsigned char scan=0x80;
	

	while(1){
		for(shift=7;shift>0;shift--){
		 	
			//for(repeat=0;repeat<10;repeat++){
			 for(i=0;i<8;i++){
			  	Data=font[i];
				Delay_ms(1);
				Data=0xFF;
				scan=RR8(scan);
				Scan=~(scan>>shift);
			 //}
			}
		}
		
		for(shift=0;shift<8;shift++){
		 	for(repeat=0;repeat<10;repeat++){
			 for(i=0;i<8;i++){
			  	Data=font[i];
				Delay_ms(1);
				Data=0xFF;
				scan=RR8(scan);
				Scan=~(scan<<shift);
			 }
			}
		}	 

	}

}