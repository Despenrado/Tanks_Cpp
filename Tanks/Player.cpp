#include "stdafx.h"
#include <glut.h>
#include <soil.h>
#include "Player.h"
#include "Image.h"
#include "display.h"

////////////////////////////////////////////////////////////////////          KONSTRUKTOR          ////////////////////////////////////////

Player::Player(int x, int y):Tank(x, y)
{
	Player::set_input_shoot(1);
}

////////////////////////////////////////////////////////////////////          SETTERS / CONTROLS          ////////////////////////////////////////

void Player::set_input(int input_int)// dla glutSpecialFunc
{
	
		switch (input_int)
		{
		case 101:
		{
			Tank::set_delta(1);
			Player::set_input_shoot(1);
			break;
		}
		case 100:
		{
			Tank::set_delta(2);
			Player::set_input_shoot(2);
			break;
		}
		case 102:
		{
			Tank::set_delta(3);
			Player::set_input_shoot(3);
			break;
		}
		case 103:
		{
			Tank::set_delta(4);
			Player::set_input_shoot(4);
			break;
		}
		case -1:	Tank::set_delta(0); break;
		}
	
}

void Player::set_input(unsigned char input_char)// dla glutKeyboardFunc
{
	if (input_char == 'w')
	{
		Tank::set_delta(1);
		Player::set_input_shoot(1);
	}
	if (input_char == 'a')
	{
		Tank::set_delta(2);
		Player::set_input_shoot(2);
	}
	if (input_char == 'd')
	{
		Tank::set_delta(3);
		Player::set_input_shoot(3);
	}
	if (input_char == 's')
	{
		Tank::set_delta(4);
		Player::set_input_shoot(4);
	}
	if (input_char == '-1')
		Tank::set_delta(0);
}

void Player::set_input_shoot(int input)
{
	Player::input_shoot = input;
}


////////////////////////////////////////////////////////////////////          GETTERS          ////////////////////////////////////////

int Player::get_input_shoot()
{
	return Player::input_shoot;
}

////////////////////////////////////////////////////////////////////          DRAW PLAYER          ////////////////////////////////////////

void Player::draw_player()
{
	if (checkFunc(Tank::get_x(), Tank::get_y(), Tank::get_delta(), Tank::get_size()) == Tank::get_delta() 
		|| checkFunc2(Tank::get_x(), Tank::get_y(), Tank::get_delta(), Tank::get_size()) == Tank::get_delta())
	{
		Tank::set_delta(0);

	}
	Tank::controls();
	switch (Player::get_input_shoot())
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

Player::~Player()
{
}
