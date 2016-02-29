#pragma once
#include "Entity.h"

class Enemy :
	public Entity
{
public:
	Enemy();
	~Enemy();

	void movement(const MoveDirection dir);
	void shoot(std::vector<Laser>& lasers);
	int getMovementSpeed() const { return m_movementSpeed; }
	

	//Size of enemy
	static const int SIZE_WIDTH = 50;
	static const int SIZE_HEIGHT = 50;
	
private:
	int m_movementSpeed = 4;

};

