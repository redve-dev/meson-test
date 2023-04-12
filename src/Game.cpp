#include "include/Game.hpp"
#include "SDL_video.h"
#include <iostream>
#include <chrono>

Game::Game(int w, int h){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		char* message = nullptr;
		sprintf(message, "SDL_Init Error: %s", SDL_GetError());
		logger.Log(message, LogLevel::ERROR);
	}
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (window == nullptr || renderer == nullptr){
		logger.Log("Could not create window or renderer", LogLevel::ERROR);
		throw std::runtime_error("Could not create window or renderer");
	}
	isRunning = true;
}

Game::~Game(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::HandleEvents(){
	while (SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT){
			isRunning = false;
		}
	}
}

void Game::Update(double dt){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	for (auto& object : objects){
		object->Update(dt);
		object->Draw(renderer);
	}
	SDL_RenderPresent(renderer);
}

static void PushObject(std::vector<std::shared_ptr<Object>>& objects, std::shared_ptr<Object> object){
	objects.push_back(std::move(object));
}

void Game::MainLoop(){
	using namespace std::chrono;
	auto stop = high_resolution_clock::now();
	auto start = high_resolution_clock::now();
	auto object = std::make_shared<Object>(glm::vec2(0, 0), glm::vec2(100, 0), glm::vec2(100, 100));
	PushObject(objects, object);
	object->Update(2);
	while (isRunning){
		HandleEvents();
		stop = high_resolution_clock::now();
		auto elapsed_ms = duration_cast<milliseconds>(stop - start).count();
		const auto dt = elapsed_ms / 1000.0;
		start = high_resolution_clock::now();
		Update(dt);
	}
}
