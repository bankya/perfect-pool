#include <iostream>
#include "shot.h"

using namespace std;

void output (ostream &out, Shot* shots, int length)
{
	for(int i = 0; i < length; i++) {
		Shot s = shots[i];
		out << "[" 
		<< s.xVel << ", " 
		<< s.yVel << ", " 
		<< s.resetPosition.x 
		<< ", " << s.resetPosition.y << "]\n";
	}
}

struct holes
{
	holes (Position in, int r1);
	Position i;
	int r;
};

holes::holes (Position in, int r1)
{
	i = in; 
	r = r1; 
}
