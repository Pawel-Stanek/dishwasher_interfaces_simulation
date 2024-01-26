/*
 * main.c    ATmega328p    F_CPU = 16000000 Hz
 *
 * Created on: 25.01.2024
 *     Author: Paweł Stanek
*/
#include <avr/io.h>
#include <util/delay.h>








int main( void ) {

	DDRD = (1<<PD1)|(1<<PD0);	//  PD0 , PD1
	PORTD = (1<<PD1)|(1<<PD0);  //  PD0 , PD1 - OFF

	DDRD |= (1<<PD5)|(1<<PD4)|(1<<PD3)|(1<<PD2);
    PORTD |= 0x3C;


	DDRC = 0xFF;
	PORTC = 0xFF;

	_delay_ms(1200);


	uint16_t fx = 0;

    while ( 1 ) {


    	fx = (fx<<1) | (fx>>9);
    	if( !fx ) fx = 1;

    	PORTC = ~fx;
    	PORTD = (PORTD & 0xC3) | ( ~(fx>>4) & 0x3C );




    	_delay_ms(500);
    }
}


