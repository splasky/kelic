#include "AT89X52.H"

sfr Data=0x80;
sbit RS=0x96;
sbit RW=0x91;
sbit EN=0x97;


void LCD_Disp(unsigned int disp);

void main(void)
{
	char *line1="1110134037";
	char *line2="20170606";

	char i;
	LCD_init();

	LCD_Cmd(0x81);
	for(i=0;i<10;++i){
		LCD_Data(line1[i]);
		Delay_ms(1);
	}

	LCD_Cmd(0xC1);
	for(i=0;i<8;i++){
		LCD_Data(line2[i]);
		Delay_ms(1);
	}

	while(1);

}


void LCD_Data(char dat)
{
	Data=dat;
	/* write into lcd */
	RS=1;
	RW=0;
	EN=1;
	Delay_ms(1);
	/* clear lcd */
	EN=0;
}

void LCD_Cmd(unsigned char Cmd){
	Data=Cmd;
	RS=0;
	RW=0;
	EN=1;
	Delay_ms(1);
	EN=0;
}

void LCD_init(void){
	LCD_Cmd(0x38);
	LCD_Cmd(0x0c);
	LCD_Cmd(0x06);
	LCD_Cmd(0x01);
	LCD_Cmd(0x02);
}
