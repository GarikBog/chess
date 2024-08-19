
#ifndef CHESS_MENU
#include"chess_menu.h"
#define CHESS_MENU
#endif



/// Play_button
int Play_button::click(std::pair<double, double> mouse_pos) {
    if (mouse_on(mouse_pos)) return 1; 
}

Play_button::Play_button(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle) : ClickbleEntity(pos, rectangle,texture_file) {}





/// Exit_button

int Exit_button::click(std::pair<double, double> mouse_pos) {
    if (mouse_on(mouse_pos)) {
        return 0;
    }
}

Exit_button::Exit_button(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle): ClickbleEntity(pos, rectangle, texture_file) {

}

/// Settings_button

int Settings_button::click(std::pair<double, double> mouse_pos) {
    if (mouse_on(mouse_pos)) {
        draw_settings();
    }
}
Settings_button::Settings_button(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle,sf::RenderWindow& window) : ClickbleEntity(pos, rectangle, texture_file), window(window) {

}

void Settings_button::draw_settings() {
    /// SDELAT'
}

/// Chess_menu

void Chess_menu::draw(sf::RenderWindow& window) {
    background.draw(window);
    play.draw(window);
    exit.draw(window);
    settings.draw(window);
}

Chess_menu::Chess_menu(Object bg, Play_button pl, Exit_button ex, Settings_button set) : background(bg),play(pl),exit(ex),settings(set) {
    
}



int chess_menu() {

    sf::RenderWindow window(sf::VideoMode(200, 200), "Chess_menu");
    Object background();

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