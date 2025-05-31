#pragma config FOSC = INTIO67
#pragma config PRICLKEN = ON
#pragma config PLLCFG = ON
#pragma config PWRTEN = ON
#pragma config WDTEN = OFF    
#pragma config LVP = OFF

#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "LCD.h"
#include "ultrasonico.h"
#include "i2c.h"

#define _XTAL_FREQ 16000000UL

void main(void) {
    OSCCON = 0X70;

    LCD_Init();
    Init_HCSR04();
    I2C_init(); // Incluido por si se necesita comunicación I2C más adelante

    __delay_ms(1000);
    LCD_Clear();
    LCD_SetCursor(1,0);
    LCD_String("Distancia (cm): ");

    char buffer[16];

    while(1){
        uint16_t distancia = Get_Distance_cm();
        sprintf(buffer,"    %3ucm      ", distancia);

        LCD_SetCursor(2,0);
        LCD_String(buffer);

        __delay_ms(400);
    }
}
