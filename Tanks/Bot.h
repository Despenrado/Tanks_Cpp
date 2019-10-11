#pragma once
#include "Tank.h"
class Bot :
	public Tank
{
private:
	int timer;
public:
	Bot(int timer, int x, int y);

	int get_timer();
	

	void set_input();	//zmiana kierunku

	void draw_bot();	//rysomanie

	~Bot();
};
