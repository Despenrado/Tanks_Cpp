#include "stdafx.h"
#include <glut.h>
#include <soil.h>
#include "Map.h"
#include "Image.h"

////////////////////////////////////////////////////////////////////          KONSTRUKTOR          ////////////////////////////////////////

Map::Map()
{
	set_wall();
}

////////////////////////////////////////////////////////////////////          SETTERS          ////////////////////////////////////////

void Map::set_wall()
{
	for (int i = 0; i < 601; i++)
	{
		for (int i2 = 100; i2 < 701; i2++)
		{
			Map::wall[i][i2] = 0;
		}
	}

	for (int i = 0; i < 800; i++)
	{
		Map::wall[1][i] = 1;
		Map::wall[2][i] = 1;
		Map::wall[3][i] = 1;
		Map::wall[4][i] = 1;
		Map::wall[5][i] = 1;
		Map::wall[6][i] = 1;

		Map::wall[596][i] = 1;
		Map::wall[597][i] = 1;
		Map::wall[598][i] = 1;
		Map::wall[599][i] = 1;
		Map::wall[600][i] = 1;
	}
	
	for (int i = 250; i < 351; i++)
	{
		for (int i2 = 200; i2 < 601; i2++)
		{
			Map::wall[i][i2] = 1;
		}
	}

	for (int i = 100; i < 501; i++) 
	{
		for (int i2 = 350; i2 < 451; i2++)
		{
			Map::wall[i][i2] = 1;
		}
	}
	for (int i = 0; i < 600; i++)
		for (int i2 = 0, i3 = 696; i2 < 104 && i3 < 801; i2++, i3++)
		{
			Map::wall[i][i2] = 1;
			Map::wall[i][i3] = 1;
		}
}

////////////////////////////////////////////////////////////////////          GETTERS          ////////////////////////////////////////

bool Map::get_wall(int x, int y)
{
	return Map::wall[y][x];
}

////////////////////////////////////////////////////////////////////          CHECKING          ////////////////////////////////////////

int Map::check_wall(int x, int y, int delta, int size)
{
		switch (delta)
		{
		case 1:
		{
			if (Map::get_wall(x - size, y + size + 2) == 1 || Map::get_wall(x + size, y + size + 2) == 1)
			{
				return 1;
			}
			break;
		}
		case 2:
		{
			if (Map::get_wall(x - size - 2, y - size) == 1 || Map::get_wall(x - size - 2, y + size) == 1)
			{
				return 2;
			}
			break;
		}
		case 3:
		{
			if (Map::get_wall(x + size + 2, y - size) == 1 || Map::get_wall(x + size + 2, y + size) == 1)
			{
				return 3;
			}
			break;
		}
		case 4:
		{
			if (Map::get_wall(x + size, y - size - 2) == 1 || Map::get_wall(x - size, y - size - 2) == 1)
			{
				return 4;
			}
			break;
		}
		}
		return 0;
}

int  Map::check_tank(int x1, int y1, int delta1, int size, int x2, int y2)
{
	int size2 = 25;
	switch (delta1)
	{
	case 1:
	{
		if ((x1 - size >= x2 - size2 && x1 - size <= x2 + size2 && y1 + size + 1 >= y2 - size2 && y1 + size + 1 <= y2 + size2) 
			|| (x1 + size >= x2 - size2 && x1 + size <= x2 + size2 && y1 + size + 1 >= y2 - size2 && y1 + size + 1 <= y2 + size2))
		{
			return 1;
		}
		break;
	}
	case 2:
	{
		if ((y1 - size >= y2 - size2 && y1 - size <= y2 + size2 && x1 - size - 1 >= x2 - size2 && x1 - size - 1 <= x2 + size2)
			|| (y1 + size >= y2 - size2 && y1 + size <= y2 + size2 && x1 - size - 1 >= x2 - size2 && x1 - size - 1 <= x2 + size2))
		{
			return 2;
		}
		break;
	}
	case 3:
	{
		if ((y1 - size >= y2 - size2 && y1 - size <= y2 + size2 && x1 + size + 1 >= x2 - size2 && x1 + size + 1 <= x2 + size2)
			|| (y1 + size >= y2 - size2 && y1 + size <= y2 + size2 && x1 + size + 1 >= x2 - size2 && x1 + size + 1 <= x2 + size2))
		{
			return 3;
		}
		break;
	}
	case 4:
	{
		if ((x1 - size >= x2 - size2 && x1 - size <= x2 + size2 && y1 - size - 1 <= y2 + size2 && y1 - size - 1 >= y2 - size2)
			|| (x1 + size >= x2 - size2 && x1 + size <= x2 + size2 && y1 - size - 1 <= y2 + size2 && y1 - size - 1 >= y2 - size2))
		{
			return 4;
		}
		break;
	}
	}
	return 0;
}

////////////////////////////////////////////////////////////////////          DRAW          ////////////////////////////////////////

void Map::draw_pix()
{
	bind_map();
}

////////////////////////////////////////////////////////////////////          DESTRUKTOR          ////////////////////////////////////////

Map::~Map()
{
}
