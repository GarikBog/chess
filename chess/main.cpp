#ifndef GRAPHICS
#include <SFML/Graphics.hpp>
#define GRAPHICS
#endif // !GRAPHICS


#ifndef CHESS_MENU
#include"chess_menu.h"
#define CHESS_MENU
#endif

#ifndef IOSTREAM
#include<iostream>
#define IOSTREAM
#endif

#ifndef VECTOR
#include<vector>
#define VECTOR
#endif



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

}

int main()
{
    

    switch (1)
    {
    case(1):
        chess_classic_game();
    default:
        break;
    }

    return 0;
}