#include "AT89X52.h"

int main(void){
loop:
P0=0x56;
P0|= 0x80;
P0&= 0xFD;
P0=~P0;
goto loop;
}