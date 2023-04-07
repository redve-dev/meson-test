#include <SDL2/SDL.h>

class Game
{
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event event;
	bool isRunning;
public:
	Game(int, int);
	~Game();
};
