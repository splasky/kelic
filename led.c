#include "AT89X52.h"
#include "heart.h"

sfr Data=0x80;
sfr Scan=0x90;
sbit KEY=P3^2; // p32 button

void main(void){
	unsigned char i;
	Scan=0x7F;


	while(1){
		if(KEY==0){
		   for(i=0;i<8;++i){
			Data=~heart[i];
			Scan=RR8(Scan);
		   }
		}
		else{
		   for(i=0;i<8;++i){
			Data=heart[i];
			Scan=RR8(Scan);
			}
		}
	
	}
	
}