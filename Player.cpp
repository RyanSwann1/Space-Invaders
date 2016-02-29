#include "Player.h"
#include "MoveDirection.h"
#include "Laser.h"
#include <iostream>
#include <vector>


Player::Player()
{
	m_pos = { START_XPOS, START_YPOS, SIZE_WIDTH, SIZE_HEIGHT };
	m_movementSpeed = 10;
}


Player::~Player()
{
}

void Player::movement(const MoveDirection dir)
{
	switch (dir)
	{
	case MoveDirection::RIGHT: m_pos.x += m_movementSpeed;
		break;

	case MoveDirection::LEFT: m_pos.x -= m_movementSpeed;
		break;
	}
}

void Player::shoot(std::vector<Laser>& lasers)
{
	//Laser size, spawn pos & movementSpeed
	int spawnXPos = m_pos.x;
	int spawnYOffset = 30;
	int spawnYPos = m_pos.y + spawnYOffset;
	int laserSizeWidth = 30;
	int laserSizeHeight = 40;
	int movementSpeed = 6;

	lasers.push_back(Laser({ spawnXPos, spawnYPos, laserSizeWidth, laserSizeHeight }, movementSpeed, MoveDirection::UP));
}