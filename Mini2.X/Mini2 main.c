//-------------------------Configuracion inicial--------------------------------
#pragma config FOSC = INTRC_CLKOUT
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config MCLRE = OFF
#pragma config CP = OFF
#pragma config CPD = OFF
#pragma config BOREN = OFF
#pragma config IESO = OFF
#pragma config FCMEN = OFF
#pragma config LVP = OFF
#pragma config BOR4V = BOR40V
#pragma config WRT = OFF

//-------------------------Librerias--------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "I2C.h"
#include "USART.h"
#include "MPU6050.h"

void main(void) {
    
    UART_TX_Init();
    ANSELH = 0;
    TRISB = 0; // LED Indicator
    MPU6050_Init();
    while(1)
	{
	    MPU6050_Read();
        __delay_ms(50);
    }
    return;
}
