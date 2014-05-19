#include <avr/io.h>
#include "screen.h"
#include "wegotthefunk.h"
#include "getting_attacked.h"
#define F_CPU 16000000UL
#include <util/delay.h>

void playGame( &screen green_grid, &screen red_grid ) {
	unsigned char turn = 1, row = 0, col = 0;
	bool attackLocations[4][4];
	for ( int i = 0; i < 4; i++ ) {
		for ( int j = 0; j < 4; j++ ) {
			attackLocations[i][j] = false;
		}
	}
	while ( 1 ) {
		row = getInput( current_screen );
		col = getInput( current_screen );
		if ( attackLocations[row][col] == false ) {
			if ( current_screen.grid[row] & ( 1 << col ) == ( 1 << col ) ) {
				red_grid.addLight( row, col );
				green_grid.subLight( row, col );
				attackLocations[row][col] = true;
			}
			else {
				green_grid.addLight( row, col );
				attackLocations[row][col] = true;
			}
		}
		turn++;
	}
}