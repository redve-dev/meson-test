#include "../include/Game.hpp"

int main()
{
	try{
	Game game(800, 600);
	}
	catch(std::exception& e){
		return 1;
	}
	return 0;
}
