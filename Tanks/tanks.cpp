#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include <stdlib.h>
#include <time.h>
#include <glut.h>
#include <soil.h>
#include <iostream>
#include "display.h"
#include "menu.h"
#include "Image.h"


using namespace std;

////////////////////////////////////////////////////////////////////          MAIN          ////////////////////////////////////////

int main(int argc, char **argv)
{
	srand(time(0));
	cout << endl << endl 
		<< endl << "                         ===================================================================="
		<< endl << "                         = Produced by Despenrado (Nikita Stepanenko) and Dmytro Matviichuk ="
		<< endl << "                         ===================================================================="
		<< endl << endl << endl << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("TANKS");
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 800, 0, 600);
	get_dir();
	menu();
	tank_bot();
	tank();
	pause();
	draw_bullet();
	game_over();
	player1_win();
	player2_win();
	you_win();
	draw_map();
	glutMouseFunc(mouse_buttom);
	glutSpecialFunc(keyboard);
	glutKeyboardFunc(keyboard);
	glutSpecialUpFunc(keyboardUP);
	glutKeyboardUpFunc(keyboardUP);
	glutDisplayFunc(display);
	glutTimerFunc(16, ticks, 0);
	
	glutMainLoop();
    return 0;
}

// 1) сделать остановку така в keyboard_UP по-человечески