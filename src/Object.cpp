#include "include/Object.hpp"

Object::Object(glm::vec2 pos, glm::vec2 vel, glm::vec2 size):
	position(pos),
	velocity(vel),
	size(size)
{
	rect = SDL_Rect{
		static_cast<int>(pos.x),
		static_cast<int>(pos.y),
		static_cast<int>(size.x),
		static_cast<int>(size.y)
	};
}

void Object::Update(double dt){
	position.x += velocity.x * dt;
	position.y += velocity.y * dt;
}

void Object::Draw(SDL_Renderer* renderer){
	rect.x = position.x;
	rect.y = position.y;
	rect.w = size.x;
	rect.h = size.y;
	SDL_RenderFillRect(renderer, &rect);
}
