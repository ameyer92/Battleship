#include <avr/io.h>
#include "screen.h"
#include "wegotthefunk.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include <time.h>

using namespace std;

bool buttonDelay(float delay, bool buttonPress){
  clock_t clockTime;
  if( buttonPress == false)
    clockTime = clock();
  
  if ( ((float)clockTime/CLOCKS_PER_SEC) >= delay )
    return true;
  
  return false;
}

char getInput( screen current_screen ) {
	char i = ( 0 );
	bool buttonPress = false;
  float delay = .5;
  
  while ( true ) {
    if ( ( PIND & ( 1 << ( i + 4 ) ) ) == ( 1 << ( i + 4 ) )){
      if ( buttonDelay(delay, buttonPress) )
        return i;
      buttonPress = true;
    }
    if ( ( PIND & 0x08 ) == 0x08 ) {
      if ( buttonDelay(delay, buttonPress) )
        return 4;
      buttonPress = true;
    }
    else {
      current_screen.flicker();
      i++;
      if ( i == 4 )
        i = 0;
    }
  }
}

void clearScreen( void ) {
	PORTC = 0xFF;
}