#ifndef ULTRASONICO_H
#define ULTRASONICO_H

#include <xc.h>
#include <stdint.h>

#define TRIG LATBbits.LATB0
#define ECHO PORTBbits.RB1
#define TRIG_DIR TRISBbits.TRISB0
#define ECHO_DIR TRISBbits.TRISB1

void Init_HCSR04(void);
uint16_t Get_Distance_cm(void);

#endif