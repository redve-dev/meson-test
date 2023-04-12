#include <iostream>
#include "include/Game.hpp"

int main(){
	try{
	Game game(800, 600);
	game.MainLoop();
	}
	catch (std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}
