#include "AT89X52.H"

sfr Data=0x80;
sbit RS=0x96;
sbit RW=0x91;
sbit EN=0x97;

char code Table[]={
	0x10,0x1f,0x02,0x0f,0x0a,0xff,0x02,0x00, /* year*/
	0x0f,0x09,0x0f,0x09,0x0f,0x09,0x13,0x00, /* month */
	0x0f,0x09,0x09,0x0f,0x09,0x09,0x0f,0x00
};

char hour=0,min=0,sec=0,month=0,day=0;
int year;

void LCD_Disp(unsigned int disp);
void LCD_Clock(char hour,char min,char sec);
void Print_Time_TO_LCD(char dat);

int main(void)
{
	char i=0;
	year=2017;month=6;day=6;

	LCD_init();
	
	for(i=0;i<=24;i++){
		LCD_Cmd(0x40+i);
		LCD_Data(Table[i]);
	}

	while(1){
		LCD_Cmd(0x80);
		LCD_Clock(hour,min,sec);
		Delay_ms(5);
		sec++;
		if(sec>60){
			sec=0;min++;
		}

		if(min>60){
			min=0;hour++;
		}

		if(hour>23){
			hour=0;sec=0;min=0;
		}
		/* print date */
		LCD_Cmd(0xC0);
		Delay_ms(5);
		LCD_Data(year/1000+'0');
		LCD_Data(year%1000/100+'0');
		LCD_Data(year%100/10+'0');
		LCD_Data(year%10+'0');

		LCD_Data(0);
		LCD_Data(month/10+'0');
		LCD_Data(month%10+'0');
		LCD_Data(1);
		LCD_Data(day/10+'0');
		LCD_Data(day%10+'0');
		LCD_Data(2);
	

	}

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


void LCD_Disp(unsigned int disp)
{
	LCD_Data(disp /10000+'0');
	LCD_Data(disp %10000/1000+'0');
	LCD_Data(disp %1000/100+'0');
	LCD_Data(disp %100/10+'0');
	LCD_Data(disp %10+'0');
}

void LCD_Clock(char hour,char min,char sec){
	LCD_Cmd(0x80);

	Print_Time_TO_LCD(hour);
	LCD_Data(':');
	Print_Time_TO_LCD(min);
	LCD_Data(':');
	Print_Time_TO_LCD(sec);
}

	
void Print_Time_TO_LCD(char dat){
	LCD_Data(dat/10+'0');
	LCD_Data(dat%10+'0');
}

