/**
 * name : Position.h;
 * date : 18/4/28;
 * g++ version : 7.3.1;
 * g++ options : -O2;
 * */

#include "Position.h"

Position::Position():
	posi{0}
{/* Nothing to do; */}
Position::Position(int x,int y):
	posi{x,y}
{/* Nothing to do; */}
Position::~Position()
{/* Nothing to do; */}

int Position::get_x()
{return posi[0];}
int Position::get_y()
{return posi[1];}

void Position::set_x(int x)
{posi[0] = x;}
void Position::set_y(int y)
{posi[1] = y;}

bool Position::operator==(Position position)
{
	return (
		posi[0] == position.posi[0] && 
		posi[1] == position.posi[1]
	);
}

bool Position::operator!=(Position position)
{return !this->operator==(position);}
