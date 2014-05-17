#include <avr/io.h>
#include "screen.h"
#include "wegotthefunk.h"
#define F_CPU 16000000UL
#include <util/delay.h>



char getInput( screen current_screen ) {
	char i = ( 0 );
	while ( true ) {
		if ( ( PIND & ( 1 << ( i + 4 ) ) ) == ( 1 << ( i + 4 ) ) ) {
			_delay_ms( 500 );
			return ( i );
		}
		if ( ( PIND & 0x08 ) == 0x08 ) {
			_delay_ms( 500 );
			return ( 4 );
		}
		else {
			current_screen.flicker();
			i++;
			if ( i == 4 ) {
				i = 0;
			}
		}
	}
}

void clearScreen( void ) {
	PORTC = 0xFF;
}