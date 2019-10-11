#pragma once
void show_multi_player();
void keyboard_player_multi(int key_of_push, int a, int b);	//korzystanie z klawiatury
void keyboard_player_UP_multi(int key_of_push, int a, int b);	//korzystanie z klawiatury
void keyboard_player_multi(unsigned char key_of_push, int a, int b);	//korzystanie z klawiatury
void keyboard_player_UP_multi(unsigned char key_of_push, int a, int b);	//korzystanie z klawiatury
void bullet1();	//kula dla 1 gracza
void bullet2();	//kula dla 2 gracza
void stats_on_0_multi();	//zerowa defiicja obiektow
void Clear_Objects_multi();	//usuniecie obiektow
int check_player_multi(int x1, int y1, int delta1, int size);	//sprawdzanie obecnosci czolga
int check_bullet_multi(int x1, int y1, int delta1, int size, int n);