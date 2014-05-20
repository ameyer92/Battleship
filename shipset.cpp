#include <avr/io.h>
#include "screen.h"
#include "wegotthefunk.h"
#include "shipset.h"

void setDingy( screen &green_grid, screen &red_grid, bool ship_locations[4][4] ) {
	reset_locations( ship_locations );
	green_grid.clearGrid();
	unsigned char input_direction;					//var used to move ship on board
	unsigned char row, col;							//coordinate variables
	row = 0;
	col = 0;
	green_grid.addLight( row, col );		//lights up coordinate ( 1, A ) 
	while (  1 ) {
		input_direction = getInput( green_grid, red_grid );
		if ( input_direction == 0 && row != 0 ) {
			green_grid.subLight( row, col );
			row--;
		}
		else if ( input_direction == 1 && row != 3 ) {
			green_grid.subLight( row, col );
			row++;
		}
		else if ( input_direction == 2 && col != 0 ) {
			green_grid.subLight( row, col );
			col--;
		}
		else if ( input_direction == 3 && col != 3 ) {
			green_grid.subLight( row, col );
			col++;
		}
		if ( input_direction == 4 ) {
			ship_locations[row][col] = true;
			break;
		}
		green_grid.addLight( row, col );
		green_grid.flicker();
	}
}

void setDualDingy( screen &green_grid, screen &red_grid, bool ship_locations[4][4] ) {
	unsigned char input_direction;						//var used to move ship on board
	unsigned char row, col;								//coordinate variables
	row = 0;
	col = 0;
	green_grid.addLight( row, col );					//lights up coordinate ( 0, 0 )
	green_grid.addLight( row + 1, col );				//lights up coordinate ( 1, 0 )
	
	
	while ( 1 ) {
		input_direction = getInput( green_grid, red_grid );
		if ( input_direction == 0 && row != 0 ) {
			green_grid.subLight( row + 1, col );
			row--;
			green_grid.addLight( row, col );
		}
		else if ( input_direction == 1 && row != 2 ) {
			green_grid.subLight( row, col );
			row++;
			green_grid.addLight( row + 1, col );
		}
		else if ( input_direction == 2 && col != 0 ) {
			green_grid.subLight( row, col );
			green_grid.subLight( row + 1, col );
			col--;
			green_grid.addLight( row, col );
			green_grid.addLight( row + 1, col );
		}
		else if ( input_direction == 3 && col != 3 ) {
			green_grid.subLight( row, col );
			green_grid.subLight( row + 1, col );
			col++;
			green_grid.addLight( row, col );
			green_grid.addLight( row + 1, col );
		}
		else if ( input_direction == 4 ) {
			if ( green_grid.collisionCheck( 3 ) == false ) {
				ship_locations[row][col] = true;
				ship_locations[row][col + 1] = true;
				break;
			}
			else {
				setDingy( green_grid, red_grid, ship_locations );
				row = 0;
				col = 0;
				green_grid.addLight( row, col );		//lights up coordinate ( 0, 0 )
				green_grid.addLight( row + 1, col );	
			}
		}
		green_grid.flicker();
	}
}

void setTriDingy( screen &green_grid, screen &red_grid, bool ship_locations[4][4] ) {
	unsigned char input_direction;							//var used to move ship on board
	unsigned char row, col;  								//coordinate variables
	row = 0;
	col = 0;
	green_grid.addLight( row, col );				//lights up coordinate ( 1, 1 )
	green_grid.addLight( row, col + 1 );			//lights up coordinate ( 2, 1 )
	green_grid.addLight( row, col + 2 );
	
	while ( 1 ) { 
		input_direction = getInput( green_grid, red_grid );
		if ( input_direction == 0 && row != 0 ) {
			green_grid.subLight( row, col );
			green_grid.subLight( row, col + 1 );
			green_grid.subLight( row, col + 2 );
			row--;
			green_grid.addLight( row, col );
			green_grid.addLight( row, col + 1 );
			green_grid.addLight( row, col + 2 );
		}
		else if ( input_direction == 1 && row != 3 ) {
			green_grid.subLight( row, col );
			green_grid.subLight( row, col + 1 );
			green_grid.subLight( row, col + 2 );
			row++;
			green_grid.addLight( row, col );
			green_grid.addLight( row, col + 1 );
			green_grid.addLight( row, col + 2 );
		}
		else if ( input_direction == 2 && col != 0 ) {
			green_grid.subLight( row, col + 2);
			col--;
			green_grid.addLight( row, col );
		}
		else if ( input_direction == 3 && col != 1 ) {
			green_grid.subLight( row, col );
			col++;
			green_grid.addLight( row, col + 2 );
		}
		else if ( input_direction == 4 ) {
			if ( green_grid.collisionCheck( 6 ) == false ) {
				ship_locations[row][col] = true;
				ship_locations[row][col + 1] = true;
				ship_locations[row][col + 2] = true;
				break;
			}
			else {
				setDingy( green_grid, red_grid, ship_locations );
				setDualDingy( green_grid, red_grid, ship_locations );
				row = 0;
				col = 0;
				green_grid.addLight( row, col );			//lights up coordinate ( 1, 1 )
				green_grid.addLight( row, col + 1 );		//lights up coordinate ( 2, 1 )
				green_grid.addLight( row, col + 2 );		//lights up coordinate ( 3, 1 )
			}
		}
		green_grid.flicker();
	}
}