#include "LCD.h"

void LCD_Enable() {
    EN = 1;
    __delay_us(5);
    EN = 0;
    __delay_us(100);
}

void LCD_Command(unsigned char cmd){
    RS = 0;
    D4 = (cmd >> 4) & 1;
    D5 = (cmd >> 5) & 1;
    D6 = (cmd >> 6) & 1;
    D7 = (cmd >> 7) & 1;
    LCD_Enable();

    D4 = (cmd >> 0) & 1;
    D5 = (cmd >> 1) & 1;
    D6 = (cmd >> 2) & 1;
    D7 = (cmd >> 3) & 1;
    LCD_Enable();

    if (cmd == 0x01 || cmd == 0x02) {
        __delay_ms(2);
    }
}

void LCD_Char(unsigned char data) {
    RS = 1;
    D4 = (data >> 4) & 1;
    D5 = (data >> 5) & 1;
    D6 = (data >> 6) & 1;
    D7 = (data >> 7) & 1;
    LCD_Enable();

    D4 = (data >> 0) & 1;
    D5 = (data >> 1) & 1;
    D6 = (data >> 2) & 1;
    D7 = (data >> 3) & 1;
    LCD_Enable();
}

void LCD_Clear() {
    LCD_Command(0x01);
    __delay_ms(2);
}

void LCD_Init() {
    TRISC = 0x00;
    __delay_ms(20);

    RS = 0;
    D4 = 1; D5 = 0; D6 = 0; D7 = 0;
    LCD_Enable();
    __delay_ms(5);

    LCD_Enable();
    __delay_us(150);

    LCD_Enable();

    D4 = 0;
    LCD_Enable();

    LCD_Command(0x28);
    LCD_Command(0x0C);
    LCD_Command(0x06);
    LCD_Clear();
}

void LCD_String(const char *str) {
    while (*str) {
        LCD_Char(*str++);
    }
}

void LCD_SetCursor(unsigned char row, unsigned char col) {
    if (row == 1) LCD_Command(0x80 + col);
    else LCD_Command(0xC0 + col);
}