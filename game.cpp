#include <avr/io.h>
#include "game.h"

//Anthony was here (7:34)
game::game( void ) {
	DDRC = 0xFF;		//sets PORT C to outputs
	DDRD = 0x07;		//sets pins 4-7 as inputs and 0-3 as outputs
	MCU = 1;			//by default sets the player to one
	turn = 0;
}

game::game( unsigned char MCU_number ) {
	DDRC = 0xFF;
	DDRD = 0x07;
	MCU = MCU_number;
	turn = 0;
}