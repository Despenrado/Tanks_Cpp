#pragma once
class Bullet
{
private:
	int x;
	int y;
	int delta;
	int size;
	int n;

public:
	Bullet(int x, int y, int delta, int n);
	Bullet();

	void set_x(int x);
	void set_y(int y);
	void set_size();
	void set_delta(int x);
	void set_n(int n);

	Bullet &operator = (const Bullet &temp)
	{
		this->x = temp.x;
		this->y = temp.y;
		this->delta = temp.delta;
		this->n = temp.n;
		return *this;
	}
	
	int get_y();
	int get_delta();
	int get_x();
	int get_size();
	int get_n();

	void contrls();	//przesuniecie

	void draw_bullet();	//rysowanie kuli

	virtual ~Bullet();
};
