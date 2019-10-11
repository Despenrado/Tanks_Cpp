#pragma once
class Tank
{
private:
	int x;             // COORDINATE OX
	int y;             // COORDINATE OY
	int size;		   // SUZE_OF_TANK/2
	int delta;		   // DIRECTION OF THE OF MOVEMENT 
	int delta_shoot;   // USE IN SHOOTS
public:
	Tank(int x, int y);

	void set_x(int x);
	void set_y(int y);
	void set_delta(int delta);
	void set_delta_shoot(int delta);
	void set_size();

	int get_y();
	int get_x();
	int get_delta();
	int get_delta_shoot();
	int get_size();
	
	void controls(); //zmiana wspolrzednych

	~Tank();
};
