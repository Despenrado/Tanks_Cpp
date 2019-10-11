#include "stdafx.h"
#include <glut.h>
#include <soil.h>
#include <time.h>
#include <iostream>
#include "Bot.h"
#include "Image.h"
#include "display.h"

////////////////////////////////////////////////////////////////////          KONSTRUKTOR          ////////////////////////////////////////

Bot::Bot(int timer, int x, int y) :Tank(x, y)
{
	Bot::timer = timer;
	Bot::set_input();
}

////////////////////////////////////////////////////////////////////          GETTERS           ////////////////////////////////////////

int Bot::get_timer()
{
	return Bot::timer;
}

////////////////////////////////////////////////////////////////////          SETTERS / CONTROLS          /////////////////////////////////////

void Bot::set_input()
{
	Tank::set_delta(rand() % 4 + 1);
}


////////////////////////////////////////////////////////////////////          DRAW PLAYER          ////////////////////////////////////////

void Bot::draw_bot()
{
	if (checkFunc(Tank::get_x(), Tank::get_y(), Tank::get_delta(), Tank::get_size()) == Tank::get_delta()
		|| checkFunc2(Tank::get_x(), Tank::get_y(), Tank::get_delta(), Tank::get_size()) == Tank::get_delta())
	{
		Bot::set_input();
	}
	else
	{
		Tank::controls();
	}
		
		bind_tank_bot();
		switch (get_delta())
		{
		case 1:
		{   //UP
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 1.0);
			glVertex2f(Tank::get_x() - Tank::get_size(), Tank::get_y() - Tank::get_size());
			glTexCoord2f(1.0, 1.0);
			glVertex2f(Tank::get_x() + Tank::get_size(), Tank::get_y() - Tank::get_size());
			glTexCoord2f(1.0, 0.0);
			glVertex2f(Tank::get_x() + Tank::get_size(), Tank::get_y() + Tank::get_size());
			glTexCoord2f(0.0, 0.0);
			glVertex2f(Tank::get_x() - Tank::get_size(), Tank::get_y() + Tank::get_size());
			glEnd();
			break;
		}
		case 3:
		{	//LEFT
			glBegin(GL_QUADS);
			glTexCoord2f(1.0, 1.0);
			glVertex2f(Tank::get_x() - Tank::get_size(), Tank::get_y() - Tank::get_size());
			glTexCoord2f(1.0, 0.0);
			glVertex2f(Tank::get_x() + Tank::get_size(), Tank::get_y() - Tank::get_size());
			glTexCoord2f(0.0, 0.0);
			glVertex2f(Tank::get_x() + Tank::get_size(), Tank::get_y() + Tank::get_size());
			glTexCoord2f(0.0, 1.0);
			glVertex2f(Tank::get_x() - Tank::get_size(), Tank::get_y() + Tank::get_size());
			glEnd();
			break;
		}
		case 2:
		{	//RIGHT
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(Tank::get_x() - Tank::get_size(), Tank::get_y() - Tank::get_size());
			glTexCoord2f(0.0, 1.0);
			glVertex2f(Tank::get_x() + Tank::get_size(), Tank::get_y() - Tank::get_size());
			glTexCoord2f(1.0, 1.0);
			glVertex2f(Tank::get_x() + Tank::get_size(), Tank::get_y() + Tank::get_size());
			glTexCoord2f(1.0, 0.0);
			glVertex2f(Tank::get_x() - Tank::get_size(), Tank::get_y() + Tank::get_size());
			glEnd();
			break;
		}
		case 4:
		{	//DOWN
			glBegin(GL_QUADS);
			glTexCoord2f(1.0, 0.0);
			glVertex2f(Tank::get_x() - Tank::get_size(), Tank::get_y() - Tank::get_size());
			glTexCoord2f(0.0, 0.0);
			glVertex2f(Tank::get_x() + Tank::get_size(), Tank::get_y() - Tank::get_size());
			glTexCoord2f(0.0, 1.0);
			glVertex2f(Tank::get_x() + Tank::get_size(), Tank::get_y() + Tank::get_size());
			glTexCoord2f(1.0, 1.0);
			glVertex2f(Tank::get_x() - Tank::get_size(), Tank::get_y() + Tank::get_size());
			glEnd();
			break;
		}
		}
		glDisable(GL_TEXTURE_2D);
	
	
}

////////////////////////////////////////////////////////////////////          DESTRUKTOR          ////////////////////////////////////////

Bot::~Bot()
{
	// запуск таймера перезапуска объекта (возможно)
}
