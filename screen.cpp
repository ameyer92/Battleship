#include <avr/io.h>
#include "screen.h"
#include "wegotthefunk.h"

screen::screen( void ) {
	grid[0] = 0xE0;
	grid[1] = 0xD0;
	grid[2] = 0xB0;
	grid[3] = 0x70;
	grid_color = 0;
}

screen::screen( bool green_or_red ) {
	grid[0] = 0xE0;
	grid[1] = 0xD0;
	grid[2] = 0xB0;
	grid[3] = 0x70;
	grid_color = green_or_red;
}

void screen::addLight( unsigned char row, unsigned char col ) {
	grid[row] |= ( 1 << col );
}

void screen::subLight( unsigned char row, unsigned char col ) {
	grid[row] &= ~( 1 << col );
}

void screen::flicker( void ) {
	if ( grid_color == 0 ) {
		for ( unsigned char i = 0; i < 4; i++ ) {
			PORTC = grid[i];
		}
		clearGreen();
	}
	else if ( grid_color == 1 ) {
		for ( unsigned char i = 0; i < 4; i++ ) {
			PORTA = grid[i];
		}
		clearRed();
	}
}

bool screen::collisionCheck( unsigned char unique_ship_tiles ) {
	unsigned char count = unique_ship_tiles;
	for ( int i = 0; i < 4; i++ ){
		for ( int j = 0; j < 4; j++ ) {
			if ( ( grid[i] & ( 1 << j ) ) == ( 1 << j ) ) {
				count--;
			}
		}
	}
	if ( count == 0 ) {
		return ( false );
	}
	else {
		return ( true );
	}
}	

void screen::clearGrid( void ) {
	grid[0] = 0xE0;
	grid[1] = 0xD0;
	grid[2] = 0xB0;
	grid[3] = 0x70;
}

