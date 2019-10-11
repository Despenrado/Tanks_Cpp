#include "stdafx.h"
#include <glut.h>
#include <soil.h>
#include "Tank.h"
#include "single.h"
#include "multi.h"

////////////////////////////////////////////////////////////////////          KONSTRUKTOR          ////////////////////////////////////////

Tank::Tank(int x, int y)
{
	Tank::set_x(x);
	Tank::set_y(y);
	Tank::set_size();
	Tank::set_delta(0);
	Tank::set_delta_shoot(1);
}

////////////////////////////////////////////////////////////////////          SETTERS          ////////////////////////////////////////

void Tank::set_x(int x)
{
	Tank::x = x;
}

void Tank::set_y(int y)
{
	Tank::y = y;
}

void Tank::set_size()
{
	Tank::size = 25;
}

void Tank::set_delta(int delta)
{
	Tank::delta = delta;
}

void Tank::set_delta_shoot(int delta)
{
	Tank::delta_shoot = delta;
}

////////////////////////////////////////////////////////////////////          GETTERS          ////////////////////////////////////////

int Tank::get_x()
{
	return Tank::x;
}

int Tank::get_y()
{
	return Tank::y;
}

int Tank::get_size()
{
	return Tank::size;
}

int Tank::get_delta()
{
	return Tank::delta;
}

int Tank::get_delta_shoot()
{
	return Tank::delta_shoot;
}

////////////////////////////////////////////////////////////////////          CONTROLS          ////////////////////////////////////////

void Tank::controls()
{

	switch (Tank::get_delta())
	{
	case 1:
	{

		Tank::set_y(get_y() + 2);
		break;
	}
	case 2:
	{

		Tank::set_x(get_x() - 2);
		break;
	}
	case 3:
	{
		Tank::set_x(get_x() + 2);

		break;
	}
	case 4:
	{
		Tank::set_y(get_y() - 2);
		break;
	}
	default:
	{
		Tank::set_x(get_x());
		Tank::set_y(get_y());
	}
	}
}

////////////////////////////////////////////////////////////////////          DESTRUKTOR          ////////////////////////////////////////

Tank::~Tank()
{
}
