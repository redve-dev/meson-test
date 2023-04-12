#pragma once
#include <glm/vec2.hpp>
#include <SDL2/SDL.h>

class Object{
	glm::vec2 position;
	glm::vec2 velocity;
	glm::vec2 size;
	SDL_Rect rect;
public:
	Object(glm::vec2 pos, glm::vec2 vel, glm::vec2 size);
	void Update(double dt);
	void Draw(SDL_Renderer* renderer);
};
