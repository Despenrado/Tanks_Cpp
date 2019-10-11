#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <string> 
#include <windows.h> 
#include <stdlib.h>
#include <glut.h>
#include <soil.h>



char *dir;


GLuint *menu1;
GLuint *tank1;
GLuint *pause1;
GLuint *tank1_bot;
GLuint *bullet1;
GLuint *map1;
GLuint *you_win1;
GLuint *player1_win1;
GLuint *player2_win1;
GLuint *game_over1;

void get_dir()
{
	char temp_char[MAX_PATH];
	TCHAR temp_dir[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, temp_dir);
	wcstombs(temp_char, temp_dir, MAX_PATH);
	std::string temp_string = std::string(temp_char);
	for (unsigned int i = 0; i < temp_string.length(); i++)
	{
		if (temp_string[i] == '\\')
		{
			temp_string[i] = '/';
		}
	}
	dir = new char[temp_string.length()];
	std::strcpy(dir, temp_string.c_str());
	
}

////////////////////////////////////////////////////////////////////          BINDS          ////////////////////////////////////////

void draw_menu_menu()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *menu1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 0);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 600);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(800, 600);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(800, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void draw_menu_pause()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *pause1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 0);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 600);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(800, 600);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(800, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void bind_tank()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *tank1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void bind_tank_bot()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *tank1_bot);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void bind_bullet()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *bullet1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void draw_game_over()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *game_over1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 0);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 600);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(800, 600);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(800, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void draw_you_win()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *you_win1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 0);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 600);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(800, 600);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(800, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void draw_player1_win()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *player1_win1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 0);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 600);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(800, 600);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(800, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void draw_player2_win()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *player2_win1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 0);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 600);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(800, 600);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(800, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void bind_map()
{
	glEnable(GL_TEXTURE_2D);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glBindTexture(GL_TEXTURE_2D, *map1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 1.0);
	glVertex2f(0, 0);

	glTexCoord2f(0.0, 0.0);
	glVertex2f(0, 600);

	glTexCoord2f(1.0, 0.0);
	glVertex2f(800, 600);

	glTexCoord2f(1.0, 1.0);
	glVertex2f(800, 0);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

////////////////////////////////////////////////////////////////////         LOAD          ////////////////////////////////////////

void menu()
{
	char temp[MAX_PATH+1];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/menu.png");
	menu1 = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*menu1 = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
}

void pause()
{
	char temp[MAX_PATH];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/pause.png");
	pause1 = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*pause1 = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
}

void tank()
{
	char temp[MAX_PATH];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/tank.png");
	tank1 = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*tank1 = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
}
void tank_bot()
{
	char temp[MAX_PATH];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/tank_bot.png");
	tank1_bot = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*tank1_bot = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
}


void draw_bullet()
{
	char temp[MAX_PATH];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/bullet.png");
	bullet1 = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*bullet1 = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
}

void you_win()
{
	char temp[MAX_PATH];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/you_win.png");
	you_win1 = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*you_win1 = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
}

void player1_win()
{
	char temp[MAX_PATH];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/player1.png");
	player1_win1 = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*player1_win1 = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);

}

void player2_win()
{
	char temp[MAX_PATH];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/player2.png");
	player2_win1 = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*player2_win1 = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
}

void game_over()
{
	char temp[MAX_PATH];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/game_over.png");
	game_over1 = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*game_over1 = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
}

void draw_map()
{
	char temp[MAX_PATH];
	strcpy_s(temp, dir);
	strcat_s(temp, "/Images/map.png");
	map1 = new GLuint;
	glClear(GL_COLOR_BUFFER_BIT);
	*map1 = SOIL_load_OGL_texture
	(temp,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
	);
}
