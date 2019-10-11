#include "stdafx.h"
#include <stdlib.h>
#include <glut.h>
#include <soil.h>
#include "menu.h"
#include "single.h"
#include "multi.h"
#include "Map.h"
#include "Image.h"

Map *map;
int change_display = 0;
int old_display = 0;

void set_change_display(int n)
{
	change_display = n;
}

int get_kill_ptr()
{
	return get_bots();
}

////////////////////////////////////////////////////////////////////          CHECKING         ////////////////////////////////////////

int checkFunc(int x, int y, int delta, int size)
{
	return map->check_wall(x, y, delta, size);
}

int checkFunc2(int x1, int y1, int delta1, int size)
{
	switch (change_display)
	{
	case 1:
	{
		return check_player_single(x1, y1, delta1, size);
		break;
	}
	case 2:
	{
		return check_player_multi(x1, y1, delta1, size);
		break;
	}
	}
	return 0;
}

int checkFunc3(int x1, int y1, int delta1, int size, int n)
{
	switch (change_display)
	{
	case 1:
	{
		return check_bullet_single(x1, y1, delta1, size, n);
		break;
	}
	case 2:
	{
		return check_bullet_multi(x1, y1, delta1, size, n);
		break;
	}
	}
	return 0;
}

int chechFunc_tank(int x1, int y1, int delta1, int size, int x2, int y2)
{
	return map->check_tank(x1, y1, delta1, size, x2, y2);
}

////////////////////////////////////////////////////////////////////       MAP       ////////////////////////////////////////
void new_map()
{
	map = new Map;
}

void del_map()
{
	delete map;
}

////////////////////////////////////////////////////////////////////       UPRAVLENIE       ////////////////////////////////////////
void mouse_buttom(int buttom, int state, int x, int y)
{
	if (buttom == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			switch (change_display)
			{
			case 0:
			{
				if (y < 200 && y >175 && x < 550 && x > 250)
				{
					stats_on_0_single();
					new_map();
					old_display = 1;
					set_change_display(1);
				}
				if (y < 325 && y > 300 && x < 525 && x > 275)
				{
					stats_on_0_multi();
					new_map();
					old_display = 2;
					set_change_display(2);
				}
				if (y < 450 && y > 425 && x < 450 && x > 350)
				{
					exit(0);
				}
				break;
			}
			case 3:
			{
				if (y < 200 && y > 175 && x < 562 && x > 237)
				{
					change_display = old_display;
				}
				if (y < 450 && y > 425 && x < 637 && x > 187)
				{
					switch (old_display)
					{
					case 1:	Clear_Objects_single(); break;
					case 2:	Clear_Objects_multi(); break;
					}
					
					del_map();
					set_change_display(0);
				}
				break;
			}
			case 4:
			{
				if (y < 425 && y > 400 && x < 637 && x > 187)
				{
					Clear_Objects_single();
					del_map();
					set_change_display(0);
				}
				break;
			}
			case 5:
			{
				if (y < 425 && y > 400 && x < 637 && x > 187)
				{
					Clear_Objects_single();
					del_map();
					set_change_display(0);
				}
				break;
			}
			case 6:
			{
				if (y < 425 && y > 400 && x < 637 && x > 187)
				{
					Clear_Objects_multi();
					del_map();
					set_change_display(0);
				}
				break;
			}
			case 7:
			{
				if (y < 425 && y > 400 && x < 637 && x > 187)
				{
					Clear_Objects_multi();
					del_map();
					set_change_display(0);
				}
				break;
			}
			}
		}
	}
}

void keyboard(int key_of_push, int a, int b)
{
	if (change_display == 1)
	{
		keyboard_player(key_of_push, a, b);
	}
	if (change_display == 2)
	{
		keyboard_player_multi(key_of_push, a, b);
	}
}

void keyboardUP(int key_of_push, int a, int b)
{
	if (change_display == 1)
	{
		keyboard_player_UP(key_of_push, a, b);
	}
	if (change_display == 2)
	{
		keyboard_player_UP_multi(key_of_push, a, b);
	}
}

void keyboard(unsigned char key_of_push, int a, int b)
{
	if (key_of_push == 27 && (change_display == 1 || change_display == 2))
	{
		set_change_display(3);
	}
	else
	{
		if (change_display == 1)
		{
			keyboard_player(key_of_push, a, b);
		}
		if (change_display == 2)
		{
			keyboard_player_multi(key_of_push, a, b);
		}
	}
}

void keyboardUP(unsigned char key_of_push, int a, int b)
{
	if (old_display == 1)
	{
		keyboard_player_UP(key_of_push, a, b);
	}
	if (old_display == 2)
	{
		keyboard_player_UP_multi(key_of_push, a, b);
	}
}

////////////////////////////////////////////////////////////////////       DISPLAY       ////////////////////////////////////////

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	switch (change_display)
	{
	case 0:
	{
		draw_menu();
		break;
	}
	case 1:
	{
		map->draw_pix();
		show_single_player();
		
		break;
	}
	case 2:
	{
		map->draw_pix();
		show_multi_player();
		
		break;
	}
	case 3:
	{
		show_pause();
		break;
	}
	case 4://win
	{
		draw_you_win();
		break;
	}
	case 5://lose
	{
		draw_game_over(); 
		break;
	}
	case 6://win1
	{
		draw_player2_win();
		break;
	}
	case 7://win2
	{
		draw_player1_win();
		break;
	}
	}
	glFlush();
}

////////////////////////////////////////////////////////////////////       TIMER       ////////////////////////////////////////

void ticks(int = 0)
{
	display();
	
	glutTimerFunc(16, ticks, 0);
}


