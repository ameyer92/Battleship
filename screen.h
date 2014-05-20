#ifndef SCREEN_H
#define SCREEN_H

class screen {
	public:
		screen();
		screen( bool is_green_or_red );
		void addLight( unsigned char row, unsigned char col );
		void subLight( unsigned char row, unsigned char col );
		void flicker( void );
		bool collisionCheck( unsigned char unique_ship_tiles );
		void clearGrid( void );
	private:
		unsigned char grid[4];
		bool grid_color;			//0 for green, 1 for red
};

#endif