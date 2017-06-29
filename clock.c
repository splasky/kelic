#include "AT89X52.H"

sfr Data=0x80;
sbit RS=0x96;
sbit RW=0x91;
sbit EN=0x97;

char timer_counter=0;
void LCD_Disp(unsigned int disp);
void LCD_init(void);
void LCD_Cmd(unsigned char Cmd);
void init_timer();
void timer_count();
void clock_display();
void clock_out(char time);

char hour,min,sec;
char is_stopped=0;

void main(void)
{
	TMOD=0x01;
	TL0=65536-46080;
	TH0=(65536-10)>>8;

	EA=1;
	
	ET0=1;
	TR0=1;

	IT0=1;
	EX0=1;

	LCD_init();
	/* timer here */
	init_timer();
	timer_count();
}

void init_timer()
{
 	hour=23;
	min=59;
	sec=59;
	is_stopped=0;
}

void T0_int(void) interrupt 1{
	
	timer_counter++;
 	if(timer_counter==20){
		timer_counter=0;
		sec++;
		TL0=65536-46080;
		TH0=(65536-10)>>8;	
	}
}

void timer_count()
{
	while(1){
		if(!is_stopped){
			if(sec>59){
			sec=0;min++;
			}
			if(min>59){
			min=0;hour++;
			}
			if(hour>23){
			hour=0;min=0;sec=0;
			}
		}
		/* lcd display time */
		clock_display();
		Delay_ms(5);
	}
}

void clock_display(){
	LCD_Cmd(0x80);
 	clock_out(hour);
	LCD_Data(':');
	clock_out(min);
	LCD_Data(':');
	clock_out(sec);	
}

void clock_out(char time){
	LCD_Data(time/10+'0');
	LCD_Data(time%10+'0');
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


void EX0_init(void) interrupt 0
{
	/* stop timer */
	is_stopped=!is_stopped;
}