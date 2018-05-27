/**
 * name : Position.h;
 * date : 18/4/28;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
	int posi[2];
public:
	Position();
	Position(int x,int y);
	~Position();

	int get_x();
	int get_y();

	void set_x(int x);
	void set_y(int y);

	bool operator==(Position position);
	bool operator!=(Position position);
};

#endif /* POSITION_H */
