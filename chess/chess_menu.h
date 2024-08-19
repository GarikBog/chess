#ifndef ENTITY
#include"Entity.h"
#define ENTITY
#endif


#ifndef GRAPHICS
#include <SFML/Graphics.hpp>
#define GRAPHICS
#endif // !GRAPHICS






class Play_button : public ClickbleEntity {

public:
	int click(std::pair<double, double> mouse_pos);
	Play_button(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle);
};

class Exit_button : public ClickbleEntity {
public:
	int click(std::pair<double, double> mouse_pos);
	Exit_button(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle);
};

class Settings_button : public ClickbleEntity {
public:
	int click(std::pair<double, double> mouse_pos);
	Settings_button(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle,sf::RenderWindow& window);
private:
	void draw_settings();
	sf::RenderWindow& window;
};

class Chess_menu {

public:
	void draw(sf::RenderWindow& window);
	Chess_menu(Object bg, Play_button pl, Exit_button ex, Settings_button set);

private:
	Object background;
	Play_button play;
	Exit_button exit;
	Settings_button settings;

};

int chess_menu();