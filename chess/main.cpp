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

#ifndef CLASSIC_GAME
#include"classic_game.h"
#define CLASSIC_GAME
#endif // !CLASSIC_GAME

//#ifndef CHESS_MENU
//#include"chess_menu.h"
//#define CHESS_MENU
//#endif



int main()
{
    try {
        int select = -1;
        while (select == -1)
        {
            select = chess_menu();
        }

        switch (select)
        {
        case(0):
            break;
        case(1):
            //chess_classic_game();
        default:
            break;
        }
        return 0;
    }
    catch (std::exception ex) {
        std::cout << ex.what();
    }

}