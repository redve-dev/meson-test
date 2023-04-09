#pragma once
#include <SDL2/SDL.h>
#include "include/Logger.hpp"

class Game
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	bool isRunning;
	Logger logger;
public:
	Game(int, int);
	~Game();
	void HandleEvents();
	void Update(double);
	void MainLoop();
};
