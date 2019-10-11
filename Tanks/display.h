#pragma once
void ticks(int = 0);
void display();
void mouse_buttom(int buttom, int tate, int x, int y);	//korzystanie z myszy
void keyboard(int key_of_push, int a, int b);	//korzystanie z klawiatury
void keyboard(unsigned char key_of_push, int a, int b);	//korzystanie z klawiatury
void keyboardUP(unsigned char key_of_push, int a, int b);	//korzystanie z klawiatury
void keyboardUP(int key_of_push, int a, int b);	//korzystanie z klawiatury
void new_map();	//definiowanie mapy
void del_map();	//usuniecie mapy
int chechFunc_tank(int x1, int y1, int delta1, int size, int x2, int y2);	//sprawdzanie obecnosci czolga
int checkFunc2(int x1, int y1, int delta1, int size);	//sprawdzanie obecnosci czolga
int checkFunc(int x, int y, int delta, int size);	//sprawdzanie obecnosci sciany
int checkFunc3(int x1, int y1, int delta1, int size, int n);	//sprawdzanie obecnosci czolga dla kuli
void set_change_display(int n);
int get_kill_ptr();
void bullet_draw();