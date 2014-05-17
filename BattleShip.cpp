//Code written by Anthony Meyer - 5/14/14 
#include <avr/io.h>
#include "game.h"
#include "screen.h"
#include "wegotthefunk.h"
#include "shipset.h"
#define F_CPU 16000000UL
#include <util/delay.h>

int main( void ) {
	game BattleShip( 1 );	
	screen defense_board;
	while ( 1 ) {								
		setDingy( defense_board );
		setDualDingy( defense_board );
		setTriDingy( defense_board );
		/*pseudo code
		send through UART that you are ready for the game to begin.
		when the oponent also sends that information through UART, turn one will begin.
		
		waitforOponent();
		while ( turn < 16 ) {
			playgame
		}
		*/
	}
}

