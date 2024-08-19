
#ifndef CHESS_MENU
#include"chess_menu.h"
#define CHESS_MENU
#endif



/// Play_button
int Play_button::click(std::pair<double, double> mouse_pos)  {
    if (mouse_on(mouse_pos)) return 1; 
    return -1;
}

Play_button::Play_button(std::pair<double, double> pos , sf::Rect<int> rectangle, std::string texture_file) : ClickbleEntity(pos, rectangle,texture_file) {}





/// Exit_button

int Exit_button::click(std::pair<double, double> mouse_pos) {
    if (mouse_on(mouse_pos)) {
        return 0;
    }
    return -1;
}

Exit_button::Exit_button(std::pair<double, double> pos, sf::Rect<int> rectangle, std::string texture_file): ClickbleEntity(pos, rectangle, texture_file) {

}

/// Settings_button

int Settings_button::click(std::pair<double, double> mouse_pos) {
    if (mouse_on(mouse_pos)) {
        draw_settings();
    }
    return -1;
}
Settings_button::Settings_button(std::pair<double, double> pos, sf::Rect<int> rectangle, std::string texture_file,sf::RenderWindow& window): ClickbleEntity(pos, rectangle, texture_file), window(window) {

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

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Chess_menu");
    Object background({ 1,1 }, { 0,0,200,200 }, "textures/background.png");
    Play_button play({ 50,50 }, { 0,0,50,100 }, "textures/background.png");
    Exit_button exit({ 150,150 }, { 0,0,45,45 }, "textures/background.png");
    Settings_button settings({ 5,150 }, { 0,0,45,45 }, "textures/background.png", window);

    Chess_menu menu(background, play, exit, settings);

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
        menu.draw(window);
        window.display();
    }


    return 0;
}