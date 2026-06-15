#include "uart0.h"
#include "delay.h"
#include "lcd.h"
#include "esp01.h"
#include "rtc.h"

extern char buff[100],dummy;
extern unsigned char ch,r_flag;

void initadc(void);
void read_adc(u32,f32 *,u32 *);

#define MQ2        11
#define BUZZER     15

f32 temp_voltage;
u8 gas,g_flag,min;
u32 adc_val;
u8 temperature;
#include <LPC214X.H>


int main()
{
	int j=0;
  	InitUART0();//inirilize uart0 communication
	LCD_Init();//initilize LCD
	initadc();//initilize ADC
	RTC_Init();//initilize RTC
	IODIR0|=1<<BUZZER;//Configure buzzer pin as output
	Write_CMD_LCD(0x80);
	Write_str_LCD("ESP01 Interface");
	delay_ms(1000);
	esp01_connectAP();//connect ESP01 to WIFI Access point
	setrtctimeinfo(16,7,0);//set RTC time
	min=MIN;
	delay_ms(1000);
	g_flag=1;
	while(1)
  	{
		Write_CMD_LCD(0x80);
		read_adc(1,&temp_voltage,&adc_val);//Read ADC value from temperature sensor channel 1
		temperature = temp_voltage * 100;//Convert sensor output voltage to temperature (°C) by multipling with 100
		Write_str_LCD("TEMP: ");//Display Temperature on LCD
		Write_int_LCD(temperature);
		Write_DAT_LCD(223);
		Write_DAT_LCD('C');
		Write_CMD_LCD(0xC0);		
		Write_str_LCD("SMOKE: ");
		if(g_flag==1) //Smoke not detected
		{
			Write_CMD_LCD(0xC0+7);
			Write_str_LCD("NDETECTED");			
		}
		if(g_flag==0)//Smoke detected
		{
			Write_CMD_LCD(0xC0+7);
			Write_str_LCD("DETECTED ");			
		}
		if((((IOPIN0>>MQ2)&1)==0) && (j==0))
		{
			Write_CMD_LCD(0xC0+7);
			Write_str_LCD("DETECTED ");
			IOSET0=1<<BUZZER;//Turn on Buzzer
			esp01_sendToThingspeak(1,2);//Send Smoke alert to thingspeak
			IOCLR0=1<<BUZZER;//Turn of buzzer
			delay_ms(1000);
			j++;
			g_flag=0;	
		}
		if(j<30)
			j++;
		else
			j=0;
		//else
		//	g_flag=0;
		if(min==MIN)//Every 3 Minutes
		{
			esp01_sendToThingspeak(temperature,1);//Send temperature data to thingspeak
			min+=3;
		}
		if(MIN==59)
			min=0;
		delay_ms(1000);
  }
}

