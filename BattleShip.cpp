//The main .cpp file.
#include <avr/io.h>			//needed for using the avr microcontroller
#include "screen.h"			//used for storing grid information and lighting up arrays
#include "functions.h"		//general functions
#include "shipset.h"		//functions for setting the user's ships
#include "gameplay.h"		//functions for actual gameplay, called after setting ships
#define F_CPU 16000000UL	//Clock speed
#include <util/delay.h>		//contains the delay function _delay_ms( *delay_time_in_ms* );

int main( void ) {
	init_MCU();				//data direction register initiation
	screen green_grid(0);	//screen that stores information about green lights
	screen red_grid(1);		//screen that stores information about red lights 
	bool ship_locations[4][4];
	
	while ( 1 ) {
		setDingy( green_grid, red_grid, ship_locations );					//sets ship one on the user's board
		setDualDingy( green_grid, red_grid, ship_locations );				//sets ship two on the user's board
		setTriDingy( green_grid, red_grid, ship_locations );				//sets ship three on the user's board
		//playGame( green_grid, red_grid );
		//1. Keep ships, as the other user attacks
		//2. This is acheived by getting inputs from him instead.
		
	}
}

 