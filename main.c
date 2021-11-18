#include<reg51.h>
#include"GSM.h"
#include"LCD.h"

#define NUMBER1 "9182328024"   
#define NUMBER2 "9441233636"


sbit vib = P3^2;
sbit buzzer = P0^0;

void main()
{
    unsigned int r;
    GSM_init();
    LCD_init();
    cmdwrt(0x80);
    display("INITIALISING....");
    for(r=0;r<40000;r++);
    cmdwrt(0x80);
    display("DETECTING ACCIDENT");
	  for(r=0;r<20000;r++);
    cmdwrt(0xC0);
    display(" VIBRATION: NO  ");
	  for(r=0;r<20000;r++);
    buzzer=1;
    while(1) {
        if(vib==1) {
            buzzer=0;
            cmdwrt(0x80);
            display("DETECTING VIBRATION");
					  for(r=0;r<20000;r++);
            cmdwrt(0xC0);
            display(" VIBRATION: YES ");
					  for(r=0;r<50000;r++);
					  cmdwrt(0x01);
            cmdwrt(0x80);
            display("SENDING MSG.....");
            sendMSG(NUMBER1,"ACCIDENT DETECTED");
            sendMSG(NUMBER2,"ACCIDENT DETECTED");
            cmdwrt(0xC0);
            display("    MSG SENT    ");
            for(r=0;r<3000;r++);
					  cmdwrt(0x01);
            for(r=0;r<3000;r++);
            cmdwrt(0x80);
            display("CALLING.........");
            call(NUMBER1);
            call(NUMBER2);
            cmdwrt(0x80);
            display("GSM ACCIDENT DET");
        
        }
        else
        {
            buzzer=1;
            cmdwrt(0xC0);
            display(" VIBRATION: NO  ");        
        }
            
    }
}