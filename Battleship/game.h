#ifndef GAME_H
#define GAME_H

class game {
	public:
		game();
		game( unsigned char MCU_number );
	private:
		unsigned char turn;
		unsigned char MCU;
};

#endif