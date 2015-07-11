#include "tableState.hpp"
#include "Ball_Class.hpp"
#include "Hole.hpp"
#include <cmath>
bool TableState::collisionWall (Ball b)
{
	
	for(int i=0;i<15;i++)
	{
		if (b.position.y >= gc.Length())
			return true;
		if (b.position.x >= gc.Width())
			return true; 
	}
	return false; 
}
bool TableState::collisionBall (int v)
{
	int r = balls[v].getRadius();
	for(int i=0; i <v; i++)
	{
		if (abs(balls[i].position.x - balls[v].position.x) <= 2*r)
			if (abs(balls[i].position.y - balls[v].position.y) <= 2*r)
				return true;
	}
	for(int i =15; i>v;i--)
	{
		if (abs(balls[i].position.x - balls[v].position.x) <= 2*r)
			if (abs(balls[i].position.y - balls[v].position.y) <= 2*r)
				return true;
	}
}
Ball TableState::whoHit (int v)
{
	int r = balls[v].getRadius();
	for(int i=0; i <v; i++)
	{
		if (abs(balls[i].position.x - balls[v].position.x) <= 2*r)
			if (abs(balls[i].position.y - balls[v].position.y) <= 2*r)
				return balls[i];
		
	}
	for(int i =15; i>v;i--)
	{
		if (abs(balls[i].position.x - balls[v].position.x) <= 2*r)
			if (abs(balls[i].position.y - balls[v].position.y) <= 2*r)
				return balls[i];
	}
}

TableState TableState::update (int ms)
{	
	TableState temp = (*this);
	
	for(int cms=0; cms<ms; cms++)
	{
		for(int i=0;i<15;i++)
		{
			balls[i].position.x += balls[i].x_speed;
			balls[i].position.y += balls[i].y_speed;
			if (collisionWall(balls[i]))
			{
				balls[i].tableCollision();	
			}
			else if (collisionBall(i))
			{
				balls[i].ballCollision(whoHit(i));
			}
		}
	}
	return temp;
}

TableState::TableState() {
	holes = new Hole[6];
	balls = new Ball[16];
}
