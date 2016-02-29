#include "Game.h"
#include "Entity.h"
#include "MoveDirection.h"
#include "Laser.h"
#include "Media.h"
#include "Display.h"
#include "Enemy.h"

#include <iostream>


Game::Game()
{
	
}

Game::~Game()
{
}

void Game::inputManager(const SDL_Event& e, Entity& player )
{
	switch (e.key.keysym.sym)
	{
	case SDLK_d: player.movement(MoveDirection::RIGHT);
		break;
	case SDLK_a: player.movement(MoveDirection::LEFT);
		break;
	case SDLK_SPACE: player.shoot(m_playerLasers);
		break;
	}
}

bool Game::createRenderer(const Display& display)
{
	bool success = true;
	m_renderer = SDL_CreateRenderer(display.getWindow(), -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr)
	{
		success = false;
	}
	return success;
}



void Game::render(const Entity& player, const Media& media)
{
	SDL_RenderClear(m_renderer);

	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 0); //Background

	//Render player
	SDL_RenderCopy(m_renderer, media.getPlayerTexture(), nullptr, &player.getPosition());
	
	//Render player lasers
	for (auto laser : m_playerLasers)
	{
		SDL_RenderCopy(m_renderer, media.getLaserTexture(), nullptr, &laser.m_pos);
	}
	////Render enemies
	//for (auto &enemy : m_enemies)
	//{
	//	SDL_RenderCopy(m_renderer, media.getEnemyTerxture(), nullptr, &enemy.getPosition());
	//}

	//Apply render
	SDL_RenderPresent(m_renderer);
}

void Game::update()
{
	void moveLasers();
}

void Game::addEnemies()
{
	int startXPos = 100;
	int startYPos = 100;
	int newXPos = 100;
	int newYPos = 150; 

	////Spawn all enemies
	//for (int i = 0; i < NUMB_OF_ENEMIES; i++)
	//{
	//	m_enemies.push_back(Enemy({ startXPos, startYPos, Enemy::SIZE_WIDTH, Enemy::SIZE_HEIGHT }, m_enemyMovementSpeed, MoveDirection::LEFT));
	//	startXPos += newXPos; //After every enemy spawned, move along the row
	//}
}


void Game::moveLasers()
{
	for (auto &lasers : m_playerLasers)
	{
		if (lasers.m_dir == MoveDirection::UP) {
			lasers.m_pos.y -= lasers.m_movementSpeed;
		}
	}
}
