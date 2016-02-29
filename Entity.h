#pragma once
#include "MoveDirection.h"
#include <SDL.h>
#include <vector>
struct Laser;
class Entity
{
public:
	Entity();
	~Entity();

	virtual void movement(const MoveDirection dir) = 0;
	virtual void shoot(std::vector<Laser>& lasers) = 0;
	SDL_Rect getPosition() const { return m_pos; }

protected:
	
	SDL_Rect m_pos;
	int m_movementSpeed = 0;
};

