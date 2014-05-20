#include <avr/io.h>
#include "screen.h"
#include "wegotthefunk.h"
#define F_CPU 16000000UL
#include <util/delay.h>
//#include <time.h>		not in use, does not compile

using namespace std;

void init_MCU( void ) {
	DDRA = 0xFF;		//sets PORT A to outputs
	//DDRB = 0x0F;		//sets 0-3 as outputs, 4-7 as inputs ( not needed yet )
	DDRC = 0xFF;		//sets PORT C to outputs
	DDRD = 0x00;		//sets PORT D to outputs
}

/*		--not in use, does not compile--
bool buttonDelay(float delay, bool buttonPress){
  clock_t clockTime;
  if( buttonPress == false)
    clockTime = clock();
  
  if ( ((float)clockTime/CLOCKS_PER_SEC) >= delay )
    return true;
  
  return false;
}*/

unsigned char getInput( screen green_grid, screen red_grid ) {
	unsigned char i = 0 ;
	//bool buttonPress = false;
	//float delay = .5;
  
  while ( true ) {
    if ( ( PIND & ( 1 << ( i + 4 ) ) ) == ( 1 << ( i + 4 ) )){
		//if ( buttonDelay(delay, buttonPress) )
			//return i;
		//buttonPress = true;
		return ( i );
    }
    if ( ( PIND & 0x08 ) == 0x08 ) {
		//if ( buttonDelay(delay, buttonPress) )
		//  return 4;
		//buttonPress = true;
		return ( 4 );
    }
    else {
      green_grid.flicker();
	  red_grid.flicker();
      i++;
      if ( i == 4 )
        i = 0;
    }
  }
}

void reset_locations( bool locations[4][4] ) {
	for ( unsigned char i = 0; i < 4; i++ ) {
		for( unsigned char j = 0; j < 4; j++ ) {
			locations[i][j] = false;
		}
	}
}


void clearGreen( void ) {
	PORTC = 0xFF;
}

void clearRed( void ) {
	PORTA = 0xFF;
}