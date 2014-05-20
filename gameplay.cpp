#include <avr/io.h>
#include "screen.h"
#include "functions.h"
#include "gameplay.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void playGame( screen &green_grid, screen &red_grid, bool ship_locations[4][4] ) {
	unsigned char turn = 1, row = 0, col = 0;
	bool attack_locations[4][4];
	reset_locations( attack_locations );
	while ( 1 ) {
		row = getInput( green_grid, red_grid );
		col = getInput( green_grid, red_grid );
		if ( attack_locations[row][col] == false ) {
			//valid attack
			if ( ship_locations[row][col] == true ) {
				attack_locations[row][col] = true;
				green_grid.subLight( row, col );
				red_grid.addLight( row, col );
			}
			else {
				green_grid.addLight( row, col );
			}
			turn++;
			if ( red_grid.collisionCheck( 6 ) == false ) {
				//utilizing collision check to see if you hit all six
				//opponents ships
				break;
			}
		}
		red_grid.flicker();
		green_grid.flicker();
	}
}