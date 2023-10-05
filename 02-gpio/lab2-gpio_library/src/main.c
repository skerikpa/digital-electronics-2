/***********************************************************************
 * 
 * Blink a LED in Arduino-style and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2022 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB5   // PB5 is AVR pin where green on-board LED 
#define LED_GREEN_BOARD PB0 
#define BUTTON PD2
                        // is connected
#define SHORT_DELAY 500 // Delay in milliseconds
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops
#include <gpio.h>

// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
//#include "Arduino.h"
//#define PB5 13          // In Arduino world, PB5 is called "13"
//#define PB0 8
// -----


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    uint8_t led_value = 0;  // Local variable to keep LED status

    // Set pin where on-board LED is connected as output
    //arduino style
    //pinMode(LED_GREEN, OUTPUT);
    //pinMode(LED_GREEN_BOARD, OUTPUT);

    //register style
    //DDRB = DDRB | (1<<LED_GREEN); 
    //DDRB = DDRB | (1<<LED_GREEN_BOARD); 

    //using libraries
    GPIO_mode_output(&DDRB, LED_GREEN);
    GPIO_mode_output(&DDRB, LED_GREEN_BOARD);

    GPIO_mode_input_pullup(&DDRD, BUTTON);
    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        _delay_ms(SHORT_DELAY);
        if(GPIO_read(&PIND, BUTTON)==0)
        {
            // Change LED value
            if (led_value == 0) {
                led_value = 1;
                // Set pin to HIGH
                //digitalWrite(LED_GREEN, HIGH);
                //digitalWrite(LED_GREEN_BOARD, HIGH);

                //PORTB = PORTB | (1<<LED_GREEN);
                //PORTB = PORTB | (1<<LED_GREEN_BOARD);

                GPIO_write_high(&PORTB, LED_GREEN);
                GPIO_write_high(&PORTB, LED_GREEN_BOARD);
            }
            else {
                led_value = 0;
                // Clear pin to LOW
                //digitalWrite(LED_GREEN, LOW);
                //digitalWrite(LED_GREEN_BOARD, LOW);

                //PORTB = PORTB & ~(1<<LED_GREEN);
                //PORTB = PORTB & ~(1<<LED_GREEN_BOARD);

                GPIO_write_low(&PORTB, LED_GREEN);
                GPIO_write_low(&PORTB, LED_GREEN_BOARD);
            }
        }
    }

    // Will never reach this
    return 0;
}