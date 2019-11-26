#include "stdafx.h"
#include <stdlib.h>
#include "Bullet.h"
#include <time.h>
#include <glut.h>
#include <soil.h>
#include <iostream>
#include "Image.h"
#include "display.h"

////////////////////////////////////////////////////////////////////          KONSTRUKTOR          //////////////////////////////////////

Bullet::Bullet()
{
	Bullet::x = 0;
	Bullet::y = 0;
	Bullet::delta = 1;
	Bullet::set_size();
}

Bullet::Bullet(int x, int y, int delta, int n)
{
	Bullet::x = x;
	Bullet::y = y;
	Bullet::delta = delta;
	Bullet::set_size();
	Bullet::n = n;
}

////////////////////////////////////////////////////////////////////          SETTERS          ////////////////////////////////////////

void Bullet::set_x(int x)
{
	Bullet::x = x;
}

void Bullet::set_y(int y)
{
	Bullet::y = y;
}

void Bullet::set_delta(int delta)
{
	Bullet::delta = delta;
}

void Bullet::set_size()
{
	Bullet::size = 5;
}

void Bullet::set_n(int n)
{
	Bullet::n = n;
}

////////////////////////////////////////////////////////////////////          GETTERS          ///////////////////////////////////////


int Bullet::get_y()
{
	return Bullet::y;
}

int Bullet::get_delta()
{
	return Bullet::delta;
}

int Bullet::get_x()
{
	return Bullet::x;
}

int Bullet::get_size()
{
	return Bullet::size;
}

int Bullet::get_n()
{
	return Bullet::n;
}

////////////////////////////////////////////////////////////////////          CONTROLS          ///////////////////////////////////////

void Bullet::contrls()
{
	switch (get_delta())
	{
	case 1:
	{
		Bullet::set_y(get_y() + 4);
		break;
	}
	case 2:
	{
		Bullet::set_x(get_x() - 4);
		break;
	}
	case 3:
	{
		Bullet::set_x(get_x() + 4);
		break;
	}
	case 4:
	{
		Bullet::set_y(get_y() - 4);
		break;
	}
	case 10:
	{
		Bullet::set_y(10);
		Bullet::set_x(10);
		break;
	}
	}
}
////////////////////////////////////////////////////////////////////          DRAW PLAYER          ////////////////////////////////////

void Bullet::draw_bullet()
{
	int a = checkFunc3(Bullet::get_x(), Bullet::get_y(), Bullet::get_delta(), Bullet::get_size(), Bullet::get_n());
	if (checkFunc(Bullet::get_x(), Bullet::get_y(), Bullet::get_delta(), Bullet::get_size()) == Bullet::get_delta() 
		|| a == Bullet::get_delta())
	{
		if (a == Bullet::get_delta())
		{
			switch (n)
			{
			case 1:
			{
				if (get_kill_ptr() == 0)
				{
					set_change_display(4);
				}
				break;
			}
			case 2:
			{
				set_change_display(5);
				break;
			}
			case 3:
			{
				set_change_display(6);
				break;
			}
			case 4:
			{
				set_change_display(7);
				break;
			}
			}
		}
		Bullet::set_delta(10);
		Bullet::contrls();
	}
	else
	{
		if (Bullet::get_delta() != 10)
		{
			Bullet::contrls();
			bind_bullet();
			glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0);
			glVertex2f(Bullet::get_x() - Bullet::get_size(), Bullet::get_y() - Bullet::get_size());
			glTexCoord2f(1.0, 0.0);
			glVertex2f(Bullet::get_x() + Bullet::get_size(), Bullet::get_y() - Bullet::get_size());
			glTexCoord2f(1.0, 1.0);
			glVertex2f(Bullet::get_x() + Bullet::get_size(), Bullet::get_y() + Bullet::get_size());
			glTexCoord2f(0.0, 1.0);
			glVertex2f(Bullet::get_x() - Bullet::get_size(), Bullet::get_y() + Bullet::get_size());
			glEnd();
			glDisable(GL_TEXTURE_2D);
		}
	}
}

////////////////////////////////////////////////////////////////////          DESTRUKTOR          ////////////////////////////////////          

Bullet::~Bullet()
{
}
