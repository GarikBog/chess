#ifndef CLASSIC_GAME
#include"classic_game.h"
#define CLASSIC_GAME
#endif // !CLASSIC_GAME


int chess_classic_game() {

	sf::RenderWindow window(sf::VideoMode(200, 200), "Chess_classic");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
				return 0;
			}
		}

		window.clear();
		window.display();
	}
	return 0;
}