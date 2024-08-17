
#ifndef CHESS_MENU
#include"chess_menu.h"
#define CHESS_MENU
#endif




int chess_menu() {

    sf::RenderWindow window(sf::VideoMode(200, 200), "Chess_menu");

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