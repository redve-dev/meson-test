#pragma once
#include <SDL2/SDL.h>
#include "include/Logger.hpp"
#include "include/Object.hpp"
#include <vector>
#include <memory>

class Game
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	bool isRunning;
	Logger logger;
	std::vector<std::shared_ptr<Object>> objects;
	void HandleEvents();
	void Update(double);
public:
	Game(int, int);
	~Game();
	void MainLoop();
};
