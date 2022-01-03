#include <iostream>

#include "../include/Game.h"

int main()
{
	app::Game game;
	try
	{
		game.Start();
	} catch (const std::exception &ex)
	{
		game.Stop();
		std::cout << ex.what() << std::endl;
	} catch (...)
	{
		std::cout << "Unknown exception caught." << std::endl;
	}

	return 0;
}
