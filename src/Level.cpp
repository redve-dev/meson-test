#include "include/Level.hpp"
#include <fstream>

Level::Level(){
	logger.Log("Level created", LogLevel::INFO);
}

Level::~Level(){
	logger.Log("Level destroyed", LogLevel::INFO);
}

void Level::Update(double dt){
	for (auto& object : objects){
		object->Update(dt);
	}
}

void Level::Draw(SDL_Renderer* renderer){
	for (auto& object : objects){
		object->Draw(renderer);
	}
}

void Level::ReadLevelFile(const char* path){
	logger.Log("Reading level file", LogLevel::INFO);
	std::fstream file;
	file.open(path, std::ios::in);
	// read csv file
	if (file.is_open()){
		std::string line;
		logger.ClearLogs();
		logger.Log("Reading level file", LogLevel::INFO);
		while (std::getline(file, line)){
			// read line
			logger.Log(line, LogLevel::INFO);
		}
		logger.Log("Finished reading level file", LogLevel::INFO);
		logger.DumpLogsToStdout();
	}
	file.close();
}
