#include "ultrasonico.h"
#include <xc.h>
#define _XTAL_FREQ 16000000UL

void Init_HCSR04(void) {
    TRIG_DIR = 0;
    ECHO_DIR = 1;
    TRIG = 0;
}

uint16_t Get_Distance_cm(void) {
    uint16_t time = 0;
    float distancia;

    // Pulso de trigger
    TRIG = 1;
    __delay_us(10);
    TRIG = 0;

    // Esperar hasta que ECHO suba
    while(!ECHO);

    // Medir duración del pulso
    while(ECHO){
        __delay_us(1);
        time++;
        if(time > 30000) break; // Timeout de 30ms
    }

    // Cálculo de distancia (cm)
    distancia = (time * 0.0343) / 2.0;
    return (uint16_t)distancia;
}

