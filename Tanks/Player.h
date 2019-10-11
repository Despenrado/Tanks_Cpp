#pragma once
#include "Tank.h"

class Player :
	public Tank
{
private:
	int input_shoot;			 // KEY CODE
public:
	Player(int x, int y);

	void set_input(int input_int);
	void set_input(unsigned char input_char);
	void set_input_shoot(int input);

	int get_input_shoot();

	void draw_player();

	~Player();
};

