#include "stdafx.h"
#include <glut.h>
#include <soil.h>
#include "Tank.h"
#include "Map.h"
#include "Player.h"
#include "Bullet.h"
#include "Image.h"
#include "Map.h"
#include "display.h"


Player *player1;
Player *player2;
Bullet *bullet_pl1;
Bullet *bullet_pl2;
unsigned int i1 = 0;
unsigned int i2 = 0;
int shoot1;
int shoot2;

////////////////////////////////////////////////////////////////////          CHECKING          ////////////////////////////////////////

int check_bullet_multi(int x1, int y1, int delta1, int size, int n)
{
	switch (n)
	{
	case 3:
	{
		return chechFunc_tank(x1, y1, delta1, size, player2->get_x(), player2->get_y());
		break;
	}
	case 4:
	{
		return chechFunc_tank(x1, y1, delta1, size, player1->get_x(), player1->get_y());
		break;
	}
	}

	return 0;
}

int check_player_multi(int x1, int y1, int delta1, int size)
{
	if (x1 == player1->get_x()&& y1 == player1->get_y())
	{
		int a = chechFunc_tank(x1, y1, delta1, size, player2->get_x(), player2->get_y());
		if (a == player1->get_delta())
		{
			return a;
		}
	}
	if (x1 == player2->get_x()&& y1 == player2->get_y())
	{
		int a = chechFunc_tank(x1, y1, delta1, size, player1->get_x(), player1->get_y());
		if (a == player2->get_delta())
		{
			return a;
		}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////          PLAYER'S BULLETS          ////////////////////////////////////////

void bullet1()
{
	if (shoot1 > 0)
	{
		if (i1 == 0)
		{
			bullet_pl1 = new Bullet[1]{ Bullet(player1->get_x(), player1->get_y(), player1->get_input_shoot(), 3) };
		}
		if (i1 > 0)
		{
			Bullet *bullet_temp = new Bullet[i1];
			bullet_temp = bullet_pl1;
			bullet_pl1 = new Bullet[i1 + 1];
			for (unsigned int i3 = 0; i3 < i1; i3++)
			{
				bullet_pl1[i3] = bullet_temp[i3];
			}
			delete[]bullet_temp;
			bullet_pl1[i1].set_x(player1->get_x());
			bullet_pl1[i1].set_y(player1->get_y());
			bullet_pl1[i1].set_delta(player1->get_input_shoot());
			bullet_pl1[i1].set_n(3);
		}
		i1++;
	}
	for (unsigned int i3 = 0; i3 < i1; i3++)
	{
		bullet_pl1[i3].draw_bullet();
		if (i1 == 256)
		{
			i1 = i3 = 0;
		}
	}
}

void bullet2()
{
	if (shoot2 > 0)
	{
		if (i2 == 0)
		{
			bullet_pl2 = new Bullet[1]{ Bullet(player2->get_x(), player2->get_y(), player2->get_input_shoot(), 4) };
		}
		if (i2 > 0)
		{
			Bullet *bullet_temp = new Bullet[i2];
			bullet_temp = bullet_pl2;
			bullet_pl2 = new Bullet[i2 + 1];
			for (unsigned int i3 = 0; i3 < i2; i3++)
			{
				bullet_pl2[i3] = bullet_temp[i3];
			}
			delete[]bullet_temp;
			bullet_pl2[i2].set_x(player2->get_x());
			bullet_pl2[i2].set_y(player2->get_y());
			bullet_pl2[i2].set_delta(player2->get_input_shoot());
			bullet_pl2[i2].set_n(4);
		}
		i2++;
	}
	for (unsigned int i3 = 0; i3 < i2; i3++)
	{
		bullet_pl2[i3].draw_bullet();
		if (i2 == 256)
		{
			i2 = i3 = 0;
		}
	}
}

////////////////////////////////////////////////////////////////////          DRAW MULTI PLAYER          ////////////////////////////////////////

void show_multi_player()
{
	bullet1();
	bullet2();
	bind_tank();
	player1->draw_player();
	bind_tank_bot();
	player2->draw_player();
	glutSwapBuffers();
}

////////////////////////////////////////////////////////////////////          KONTROLS          ////////////////////////////////////////

void keyboard_player_multi(int key_of_push, int a, int b)
{
	player1->set_input(key_of_push);
}

void keyboard_player_UP_multi(int key_of_push, int a, int b)
{
	player1->set_input(-1);

}

void keyboard_player_multi(unsigned char key_of_push, int a, int b)
{
	player2->set_input(key_of_push);
	if (key_of_push == '/')
	{
		shoot1 = 1;
	}
	//player2->set_input(key_of_push);
	if (key_of_push == 'c')
	{
		shoot2 = 1;
	}
}

void keyboard_player_UP_multi(unsigned char key_of_push, int a, int b)
{
	if (key_of_push != '/' && key_of_push != 'c')
	{
		player2->set_input(-1);
	}
	else
	{
		if (key_of_push == '/')
		{
			shoot1 = 0;
		}
		else
		{
			shoot2 = 0;
		}
	}
}

////////////////////////////////////////////////////////////////////          START / DEL OBJECTS          ////////////////////////////////////////

void stats_on_0_multi()
{
	player1 = new Player{ Player(500, 400) };
	player2 = new Player{ Player(200, 200) };
	i1 = 0;
	i2 = 0;
}

void Clear_Objects_multi()
{
	if (i1 > 0)
	{
		delete[]bullet_pl1;
	}
	if (i2 > 0)
	{
		delete[]bullet_pl2;
	}
	delete player1;
	delete player2;
}
