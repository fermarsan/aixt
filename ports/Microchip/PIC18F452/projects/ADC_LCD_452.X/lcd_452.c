#include "lcd_452.h"

void Lcd_Port(char a)
{
    (a & 1) ? (D4 = 1) : (D4 = 0);
    (a & 2) ? (D5 = 1) : (D5 = 0);
    (a & 4) ? (D6 = 1) : (D6 = 0);
    (a & 8) ? (D7 = 1) : (D7 = 0);
}

void Lcd_Cmd(char a)
{
    RS = 0;
    Lcd_Port(a);
    EN = 1;
    __delay_ms(4);
    EN = 0;
}

void Lcd_Clear(void)
{
    Lcd_Cmd(0);
    Lcd_Cmd(1);
}

void Lcd_Set_Cursor(char a, char b)
{
    char temp,z,y;
    if(a == 1)
    {
        temp = 0x80 + b - 1;
        z = temp>>4;
        y = temp & 0x0F;
        Lcd_Cmd(z);
        Lcd_Cmd(y);
    }
    else if(a == 2)
    {
        temp = 0xC0 + b - 1;
        z = temp>>4;
        y = temp & 0x0F;
        Lcd_Cmd(z);
        Lcd_Cmd(y);
    }
    else if(a == 3)
    {
        temp = 0x94 + b - 1;
        z = temp>>4;
        y = temp & 0x0F;
        Lcd_Cmd(z);
        Lcd_Cmd(y);
    }
    else if(a == 4)
    {
        temp = 0xD4 + b - 1;
        z = temp>>4;
        y = temp & 0x0F;
        Lcd_Cmd(z);
        Lcd_Cmd(y);
    }
}

void Lcd_Init(void)
{
	RS_DIR = 0;
	EN_DIR = 0;
	D4_DIR = 0;
	D5_DIR = 0;
	D6_DIR = 0;
	D7_DIR = 0;
    Lcd_Port(0x00);
    __delay_ms(20);
    Lcd_Cmd(0x03);
    __delay_ms(5);
    Lcd_Cmd(0x03);
    __delay_ms(11);
    Lcd_Cmd(0x03);
    Lcd_Cmd(0x02);
    Lcd_Cmd(0x02);
    Lcd_Cmd(0x08);
    Lcd_Cmd(0x00);
    Lcd_Cmd(0x0C);
    Lcd_Cmd(0x00);
    Lcd_Cmd(0x06);
    Lcd_Clear();
}

void Lcd_Write_Char(char a)
{
    char temp,y;
    temp = a&0x0F;
    y = a&0xF0;
    RS = 1;
    Lcd_Port(y>>4);
    EN = 1;
    __delay_us(40);
    EN = 0;
    Lcd_Port(temp);
    EN = 1;
    __delay_us(40);
    EN = 0;
}

void Lcd_Write_String(const char *a)
{
    int i;
    for(i=0;a[i]!='\0';i++)
        Lcd_Write_Char(a[i]);
}

void Lcd_Shift_Right(void)
{
    Lcd_Cmd(0x01);
    Lcd_Cmd(0x0C);
}

void Lcd_Shift_Left(void)
{
    Lcd_Cmd(0x01);
    Lcd_Cmd(0x08);
}

void Lcd_Blink(void)
{
    Lcd_Cmd(0x00);
    Lcd_Cmd(0x0F);
}

void Lcd_NoBlink(void)
{
    Lcd_Cmd(0x00);
    Lcd_Cmd(0x0C);
}

#ifdef USE_CGRAM_LCD
void Lcd_CGRAM_CreateChar(char add, const char* chardata)
{
    switch(add)
    {
        case 0:
            for(char i=0; i<=7; i++)
                Lcd_Write_Char(chardata[i]);
            break;
        case 1:
            for(char i=8; i<=15; i++)
                Lcd_Write_Char(chardata[i-8]);
            break;
        case 2:
            for(char i=16; i<=23; i++)
                Lcd_Write_Char(chardata[i-16]);
            break;
        case 3:
            for(char i=24; i<=31; i++)
                Lcd_Write_Char(chardata[i-24]);
            break;
        case 4:
            for(char i=32; i<=39; i++)
                Lcd_Write_Char(chardata[i-32]);
            break;
        case 5:
            for(char i=40; i<=47; i++)
                Lcd_Write_Char(chardata[i-40]);
            break;
        case 6:
            for(char i=48; i<=55; i++)
                Lcd_Write_Char(chardata[i-48]);
            break;
        case 7:
            for(char i=56; i<=63; i++)
                Lcd_Write_Char(chardata[i-56]);
            break;
    }
}

void Lcd_CGRAM_Init(void)
{
    Lcd_Cmd(0x04);
    Lcd_Cmd(0x00);
}

void Lcd_CGRAM_Close(void)
{
    Lcd_Cmd(0x00);
    Lcd_Cmd(0x02);
}
#endif