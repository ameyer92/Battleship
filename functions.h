#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void init_MCU( void );
//bool buttonDelay(float delay, bool buttonPress);
unsigned char getInput( screen green_grid, screen red_grid );
void reset_locations( bool locations[4][4] );
void clearGreen( void );
void clearRed( void );

#endif