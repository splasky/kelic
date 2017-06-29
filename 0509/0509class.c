#include "AT89X52.h"
sfr LED=0x80;
int main(void){

	unsigned char j;

	while(1){
		j=0x01;
		do{
		
			LED=j;
			Delay_ms(100);
			j<<=1;
		} while (j<0x80);
		j=0x80;
		do{
		
			LED=j;
			Delay_ms(100);
			j>>=1;
		} while (j>0x01);

		while(i>7){
			if(i%2==0) {
			++i;
			continue;
			}
			LED=j;
			Delay_ms(100);
			j<<=i;
			++i;
		}
	}
	return 0;
}