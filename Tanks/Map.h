#pragma once
class Map
{
private:
	bool wall[601][801];
public:
	Map();

	bool get_wall(int x, int y);

	void set_wall(); // inicjalizacja scian

	int check_wall(int x, int y, int delta, int size);	//sprawdzanie jest/nie barjery(sciany)
	int check_tank(int x1, int y1, int delta1, int size, int x2, int y2);	//sprawdzanie jest/nie barjery(czolgu)

	void draw_pix();

	~Map();
};
