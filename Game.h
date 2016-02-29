#pragma once

#include <SDL.h>
#include <vector>
struct Laser;
class Media;
class Display;
class Entity;
class Enemy;
class Game
{
public:
	Game();
	~Game();

	void inputManager(const SDL_Event& e, Entity& player);
	void addEnemies();
	void update();	
	void render(const Entity& player, const Media& media);
	bool createRenderer(const Display& display);
	SDL_Renderer* getRenderer() const { return m_renderer; }

private:
	SDL_Renderer* m_renderer = nullptr;

	std::vector<Laser> m_playerLasers;
	std::vector<Entity> m_enemies;

	const int NUMB_OF_ENEMIES = 6;
	int m_enemyMovementSpeed = 6;

	void moveLasers();

};

