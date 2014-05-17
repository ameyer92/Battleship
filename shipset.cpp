#include <avr/io.h>
#include "screen.h"
#include "wegotthefunk.h"
#include "shipset.h"

void setDingy( screen current_screen ) {
	unsigned char input_direction;				//var used to move ship on board
	unsigned char x_pos, y_pos;					//coordinate variables
	x_pos = 0;
	y_pos = 0;
	current_screen.addLight( x_pos, y_pos );	//lights up coordinate ( 1, A ) 
	
	while ( 1 ) {
		input_direction = getInput( current_screen );
		if ( input_direction == 0 && y_pos != 0 ) {
			current_screen.subLight( x_pos, y_pos );
			y_pos--;
		}
		else if ( input_direction == 1 && y_pos != 3 ) {
			current_screen.subLight( x_pos, y_pos );
			y_pos++;
		}
		else if ( input_direction == 2 && x_pos != 0 ) {
			current_screen.subLight( x_pos, y_pos );
			x_pos--;
		}
		else if ( input_direction == 3 && x_pos != 3 ) {
			current_screen.subLight( x_pos, y_pos );
			x_pos++;
		}
		else if ( input_directino == 4 ) {
			break;
		}
		current_screen.addLight( x_pos, y_pos );
		current_screen.flicker();
	}
}

void setDualDingy( screen current_screen ) {
	unsigned char input_direction;					//var used to move ship on board
	unsigned char x_pos, y_pos;						//coordinate variables
	x_pos = 0;
	y_pos = 0;
	current_screen.addLight( x_pos, y_pos );		//lights up coordinate ( 1, 1 )
	current_screen.addLight( x_pos, y_pos + 1 );	//lights up coordinate ( 1, 2 )
	current_screen.addLight( x_pos, y_pos + 2 );	//lights up coordinate ( 1, 3 )
	
	while ( 1 ) {
		input_direction = getInput( current_screen );
		if ( input_direction == 0 && y_pos != 0 ) {
			current_screen.subLight( x_pos, y_pos );
			current_screen.subLight( x_pos + 1, y_pos );
			current_screen.subLight( x_pos + 2, y_pos );
			y_pos--;
			current_screen.subLight( x_pos, y_pos );
			current_screen.subLight( x_pos + 1, y_pos );
			current_screen.subLight( x_pos + 2, y_pos );
		}
		else if ( input_direction == 1 && y_pos != 3 ) {
			current_screen.subLight( x_pos, y_pos );
			current_screen.subLight( x_pos + 1, y_pos );
			current_screen.subLight( x_pos + 2, y_pos );
			y_pos++;
			current_screen.subLight( x_pos, y_pos );
			current_screen.subLight( x_pos + 1, y_pos );
			current_screen.subLight( x_pos + 2, y_pos );
		}
		else if ( input_direction == 2 && x_pos != 0 ) {
			current_screen.subLight( x_pos + 2, y_pos );
			x_pos--;
			current_screen.addLight( x_pos , y_pos );
		}
		else if ( input_direction == 3 && x_pos != 1 ) {
			current_screen.subLight( x_pos, y_pos );
			x_pos++;
			current_screen.addLight( x_pos + 2, y_pos );
		}
		else if ( input_direction == 4 ) {
			if ( current_screen.collisionCheck( 3 ) == false ) {
				break;
			}
		}
		current_screen.flicker();
	}
}

void setTriDingy( screen current_screen ) {
	unsigned char input_direction;				//var used to move ship on board
	unsigned char x_pos, y_pos;					//coordinate variables
	x_pos = 0;
	y_pos = 0;
	current_screen.addLight( x_pos, y_pos );		//lights up coordinate ( 1, 1 )
	x_pos++;
	current_screen.addLight( x_pos, y_pos + 1 );	//lights up coordinate ( 2, 1 )
	x_pos++;
	current_screen.addLight( x_pos, y_pos + 2 );
	
	while ( 1 ) { 
		input_direction = getInput( current_screen );
		if ( input_direction == 0 && y_pos != 1 ) {
			current_screen.subLight( x_pos, y_pos + 1 );
			y_pos--;
			current_screen.addLight( x_pos, y_pos );
		}
		else if ( input_direction == 1 && y_pos != 2 ) {
			current_screen.subLight( x_pos, y_pos );
			y_pos++;
			current_screen.addLight( x_pos, y_pos );
		}
		else if ( input_direction == 2 && x_pos != 0 ) {
			current_screen.subLight( x_pos, y_pos );
			current_screen.subLight( x_pos, y_pos + 1 );
			x_pos--;
			current_screen.addLight( x_pos, y_pos );
			current_screen.addLight( x_pos, y_pos + 1 );
		}
		else if ( input_direction == 3 && x_pos != 3 ) {
			current_screen.subLight( x_pos, y_pos );
			current_screen.subLight( x_pos, y_pos + 1 );
			x_pos++;
			current_screen.addLight( x_pos, y_pos );
			current_screen.addLight( x_pos, y_pos + 1 );
		}
		else if ( input_direction == 5 ) {
			if ( current_screen.collisionCheck( 6 ) == false ) {
				break;
			}
		}
		current_screen.flicker();
	}
}

