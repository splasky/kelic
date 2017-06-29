#include "AT89X52.h"

sbit SPEAK=P2^6;
sbit LED=0x80^2; 
sbit KEY=P3^2;
void beep(unsigned char i);

int main(void){
	int i=0;
	char j=0;
	LED=0;
	
	while(1){
	while(KEY==1);
		beep(1);
		LED=0x01;
		Delay_ms(1000);
	while(KEY==1);
		beep(2);
		LED=0x02;
		Delay_ms(1000);
	}
}

void beep(unsigned char i){
	unsigned int j;
		while(i--){
	for(j=0;j<200;j++){
		SPEAK=!SPEAK;
		Delay_ms(1);
		}
		Delay_ms(1000);
   		}	

}