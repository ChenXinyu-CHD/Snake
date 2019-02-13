/**
 * name : Types.h;
 * date : Feb 14,2019;
 * g++ version : 8.2.1;
 * g++ options : -O2;
 * */

#ifndef TYPES_H
#define TYPES_H

struct Position
{
	int X;
	int Y;

	inline bool operator==(const Position & posi) const
	{
		return (X == posi.X) && (Y == posi.Y);
	}

	inline bool operator!=(const Position & posi) const
	{
		return !(*this == posi);
	}
};

class Direct
{
public:
	enum direct
	{
		left=3,up=2,down=1,right=0
	};
private:
	direct d;
public:
	Direct(){}
	Direct(direct di){d = di;}

	void operator=(direct dir)
	{
		if(3 != dir + d)
			d = dir;
	}

	operator int()const
	{
		return d;
	}
};

#endif //TYPES_H
