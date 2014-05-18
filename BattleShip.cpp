//Code written by Anthony Meyer - 5/14/14 
#include <avr/io.h>
#include "game.h"
#include "screen.h"
#include "wegotthefunk.h"
#include "shipset.h"
#define F_CPU 16000000UL
#include <util/delay.h>

//Anthony was here anyways..
int main( void ) {
	game BattleShip( 1 );	
	screen defense_board;
	
	
	setDingy( defense_board );
	setDualDingy( defense_board );
	setTriDingy( defense_board );
	while ( 1 ) {
		defense_board.flicker();
	}
}

