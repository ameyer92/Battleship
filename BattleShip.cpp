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
	
	//Hello, Anthony was here;
	while( 1 ) {
		setDingy( defense_board );
	}
	

	
}

