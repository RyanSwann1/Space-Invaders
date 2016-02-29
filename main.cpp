#include "Display.h"
#include "Media.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"
#include "MoveDirection.h"
#include "Game.h"

#include <SDL.h>
#include <iostream>


bool init(Display& display, Game& game, Media& media)
{
	bool success = true;

	//Initialize SDL Video
	if (!display.init()) {
		printf("Failed to initialize SDL Video");
		success = false;
	}

	if (!game.createRenderer(display))
	{
		printf("Failed to create the renderer.");
		success = false;
	}

	//Intiailize/Load media
	if (!media.loadMedia(display, game)) {
		printf("Failed to load media");
		success = false;
	}

	return success;
}

int main(int argc, char* args[])
{
	Display display;
	Game game;
	Media media;
	bool gameOngoing = true;

	gameOngoing = init(display, game, media);

	//Game Begin
	if (gameOngoing) 
	{
		printf("Begin game loop");

		bool quit = false;
		SDL_Event e;

		Entity* player = new Player();

		game.addEnemies();

		//Begin game loop
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT) {
					quit = true;
				}
				if (e.type == SDL_KEYDOWN) {
					game.inputManager(e, *player);
				}
				
			}

			game.update();
			game.render(*player, media);
		}

	}
	else
	{
		SDL_Delay(4000);
	}


	return 0;
}