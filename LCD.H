#define lcd_data P1

sbit RS = P2^0; 
sbit RW = P2^1;
sbit EN = P2^2; 

void cmdwrt(unsigned char);
void datawrt(unsigned char);
void  LCD_init();
void display(unsigned char *str);


void lcd_delay()
{
    unsigned int lcd_delay;
    for(lcd_delay=0;lcd_delay<=6000;lcd_delay++);
}

void LCD_init()
{ 
	  cmdwrt(0x38);
    cmdwrt(0x0e);
    cmdwrt(0x01);
    cmdwrt(0x06);
    cmdwrt(0x0c);
    cmdwrt(0x80);
}

void cmdwrt(unsigned char a)
{
    unsigned int i;
    lcd_data=a;
    RS = 0; 
    RW = 0;
    EN = 1;
    lcd_delay();
    EN = 0;
}

void datawrt(unsigned char b)
{
    unsigned int i;
    lcd_data=b;
    RS = 1; 
    RW = 0;
    EN = 1;
    lcd_delay();
    EN = 0;
}

void display(unsigned char *str)
{
    while(*str) {
        datawrt(*str++);
    }
		
}