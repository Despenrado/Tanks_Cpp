#include "stdafx.h"
#include <algorithm>
#include <iostream>
#include <glut.h>
#include <soil.h>
#include <vector>
#include "Tank.h"
#include "Bot.h"
#include "Map.h"
#include "Player.h"
#include "Bullet.h"
#include "Image.h"
#include "display.h"


Player *player; 
std::vector<Bot> bot1;
Bullet *bullet_pl;
Bullet *bullet_bot[3];

unsigned int i = 0;
int shoot = 0;

int shoot_timer[3] = { 0, 0, 0 };
unsigned int bot_shoot[3] = {0,0,0};
int bots = 3;


int get_bots()
{
	return bots;
}

////////////////////////////////////////////////////////////////////          CHECKING          ////////////////////////////////////////

int check_player_single(int x1, int y1, int delta1, int size)
{
	if (x1 == player->get_x() && y1 == player->get_y())
	{
		for (int i3 = 0; i3 < bots; i3++)
		{
			int a = chechFunc_tank(x1, y1, delta1, size, bot1[i3].get_x(), bot1[i3].get_y());
			if (a == player->get_delta())
			{
				return a;
			}
		}
	}
	else
	{
		for (int i3 = 0; i3 < bots; i3++)
		{
			if (x1 != bot1[i3].get_x() && y1 != bot1[i3].get_y())
			{
				int a = chechFunc_tank(x1, y1, delta1, size, bot1[i3].get_x(), bot1[i3].get_y());
				if (a == delta1)
				{
					return a;
				}
			}
		}
		int a = chechFunc_tank(x1, y1, delta1, size, player->get_x(), player->get_y());
		if (a == delta1)
		{
			return a;
		}
	}
	return 0;
}

int check_bullet_single(int x1, int y1, int delta1, int size, int n)
{
	switch (n)
	{
	case 2:
	{
		return chechFunc_tank(x1, y1, delta1, size, player->get_x(), player->get_y());
		break;
	}
	case 1:
	{
		for (int i3 = 0; i3 < bots; i3++)
		{
			int a = chechFunc_tank(x1, y1, delta1, size, bot1[i3].get_x(), bot1[i3].get_y());
			if (a == delta1)
			{
				bots--;
				bot1.erase(bot1.begin()+i3);
				return a;
			}
		}
	}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////          PLAYER'S BULLETS           ////////////////////////////////////////

void bullet()
{
	if (shoot > 0)
	{
		if (i == 0)
		{
			bullet_pl = new Bullet[1]{ Bullet(player->get_x(), player->get_y(), player->get_input_shoot(), 1) };
		}
		if (i > 0)
		{
			Bullet *bullet_temp = new Bullet[i];
			bullet_temp = bullet_pl;
			bullet_pl = new Bullet[i + 1];
			for (unsigned int i3 = 0; i3 < i; i3++)
			{
				bullet_pl[i3] = bullet_temp[i3];
			}
			delete[]bullet_temp;
			bullet_pl[i].set_x(player->get_x());
			bullet_pl[i].set_y(player->get_y());
			bullet_pl[i].set_delta(player->get_input_shoot());
			bullet_pl[i].set_n(1);
		}
		i++;
	}
	for (unsigned int i3 = 0; i3 < i; i3++)
	{
		bullet_pl[i3].draw_bullet();
		if (i == 256)
		{
			i = i3 = 0;
		}
	}
}

void bot_bullet1(int ib)
{
	shoot_timer[ib]++;
		if (shoot_timer[ib] % bot1[ib].get_timer() == 0)
		{
			if (bot_shoot[ib] == 0)
			{
				bullet_bot[ib] = new Bullet[1]{ Bullet(bot1[ib].get_x(), bot1[ib].get_y(), bot1[ib].get_delta(), 2) };
			}
			if (bot_shoot[ib] > 0)
			{
				Bullet *bullet_temp = new Bullet[bot_shoot[ib]];
				bullet_temp = bullet_bot[ib];
				bullet_bot[ib] = new Bullet[bot_shoot[ib] + 1];
				for (unsigned int i3 = 0; i3 < bot_shoot[ib]; i3++)
				{
					bullet_bot[ib][i3] = bullet_temp[i3];
				}
				delete[]bullet_temp;
				bullet_bot[ib][bot_shoot[ib]].set_x(bot1[ib].get_x());
				bullet_bot[ib][bot_shoot[ib]].set_y(bot1[ib].get_y());
				bullet_bot[ib][bot_shoot[ib]].set_delta(bot1[ib].get_delta());
				bullet_bot[ib][bot_shoot[ib]].set_n(2);
			}
			bot_shoot[ib]++;
		}
		if (rand()%128 == 3)
		{
			bot1[ib].set_input();
		}
}

void bullet_draw()
{
	for (int i4 = 0; i4 < 3; i4++)
	{
		for (unsigned int i3 = 0; i3 < bot_shoot[i4]; i3++)
		{
			bullet_bot[i4][i3].draw_bullet();
		}
		if (bot_shoot[i4] == 128)
		{
			bot_shoot[i4] = 0;
		}
		if (shoot_timer[i4] == 1024)
		{
			shoot_timer[i4] = 0;
		}
	}
}

////////////////////////////////////////////////////////////////////          DRAW SINGLE PALYER          ////////////////////////////////////////

void show_single_player()
{
	bullet();
	for (int i3 = 0; i3 < bots; i3++)
	{
		bot_bullet1(i3);
	}
	bullet_draw();
	bind_tank();
	player->draw_player();
	for (int i4 = 0; i4 < bots; i4++)
	{

		bot1[i4].draw_bot();
	}
	glutSwapBuffers();
}

////////////////////////////////////////////////////////////////////          KONTROLS          ////////////////////////////////////////


void keyboard_player(int key_of_push, int a, int b)
{
	player->set_input(key_of_push);
}

void keyboard_player_UP(int key_of_push, int a, int b)
{
	player->set_input(-1);
}

void keyboard_player(unsigned char key_of_push, int a, int b)
{
	player->set_input(key_of_push);
	if (key_of_push == '/')
	{
		shoot = 1;
	}
	player->set_input(key_of_push);
	if (key_of_push == 'c')
	{
		shoot = 1;
	}
}

void keyboard_player_UP(unsigned char key_of_push, int a, int b)
{
	if (key_of_push != '/' && key_of_push != 'c')
	{
		player->set_input(-1);
	}
	else
	{
		if (key_of_push == '/')
		{
			shoot = 0;
		}
		else
		{
			shoot = 0;
		}
	}
}

////////////////////////////////////////////////////////////////////          START / DEL OBJECTS          ////////////////////////////////////////

void stats_on_0_single()
{
	player = new Player{ Player(300, 100) };
	bot1.push_back(Bot(70, 200, 200));
	bot1.push_back(Bot(30, 500, 200));
	bot1.push_back(Bot(50, 500, 500));
	bots = 3;
	for (int i3 = 0; i3 < bots; i3++)
	{
		shoot_timer[i3] = 0;
		bot_shoot[i3] = 0;
	}
	i = 0;
	shoot = 0;
}

void Clear_Objects_single()
{
	if (i > 0)
	{
		delete[]bullet_pl;
	}
	for (int i3 = 0; i3 < 3; i3++)
	{
		if (bot_shoot[i3] > 0)
		{
			delete[]bullet_bot[i3];
		}
	}
	delete player;
	bot1.clear();
}

