#include <avr/io.h>
#include "screen.h"
#include "turtles.h"


unsigned char getInput( screen current_screen ) {
	unsigned char i = 0;
	while ( true ) {
		if ( ( PIND & ( 1 << ( i + 4 ) ) ) == ( 1 << ( i + 4 ) ) ) {
			return ( i );
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