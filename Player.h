#pragma once
#include <SDL.h>
#include "Entity.h"


struct Laser;
class Player :
	public Entity
{
public:
	Player();
	~Player();

	void movement(const MoveDirection dir);
	void shoot(std::vector<Laser>& lasers);
private:
	static const int START_XPOS = 370;
	static const int START_YPOS = 650;
	static const int SIZE_WIDTH = 70;
	static const int SIZE_HEIGHT = 70;

};

