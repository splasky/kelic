#include "..\AT89X52.h"

sbit SPEAK=P2^6;
sbit KEY=P3^2;
bit check=1;

int main(void){
 while(1){
 	if(KEY==0){
		check=!check;
		Delay_ms(100);
	}

	if(check){
		SPEAK=!SPEAK;
		Delay_ms(10);
	}
}			 
}	
