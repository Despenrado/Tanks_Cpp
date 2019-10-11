#pragma once
void show_single_player();
void keyboard_player(int key_of_push, int a, int b);	//korzystanie z klawiatury
void keyboard_player_UP(int key_of_push, int a, int b);	//korzystanie z klawiatury
void keyboard_player(unsigned char key_of_push, int a, int b);	//korzystanie z klawiatury
void keyboard_player_UP(unsigned char key_of_push, int a, int b);	//korzystanie z klawiatury
void bullet();	//stworznie i rysowanie kuli
void stats_on_0_single(); //zerowa defiicja obiektow
void Clear_Objects_single();	//usuniecie obiektow
int check_player_single(int x1, int y1, int delta1, int size);	//sprawdzanie obecnosci czolga
void bot_bullet1(int ib);
int check_bullet_single(int x1, int y1, int delta1, int size, int n);
int get_bots();