#ifndef SCREEN_H
#define SCREEN_H

class screen {
	public:
		screen();
		void addLight( unsigned char row, unsigned char col );
		void subLight( unsigned char row, unsigned char col );
		void flicker( void );
		bool collisionCheck( unsigned char unique_ship_tiles );
		void clearGrid( void );
	private:
		unsigned char grid[4];
};

#endif