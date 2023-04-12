#pragma once
#include "include/Logger.hpp"
#include "include/Object.hpp"
#include <vector>
#include <memory>

class Level
{
	std::vector<std::shared_ptr<Object>> objects;
	Logger logger;
public:
	Level();
	~Level();
	void Update(double dt);
	void Draw(SDL_Renderer* renderer);
	void ReadLevelFile(const char* path);
};
