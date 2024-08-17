#ifndef ENTITY
#include"Entity.h"
#define ENTITY
#endif


#ifndef GRAPHICS
#include <SFML/Graphics.hpp>
#define GRAPHICS
#endif // !GRAPHICS


class Play_button : ClickbleEntity {

public:
	void click();
	Play_button(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle);
};

class Exit_button : ClickbleEntity {
public:
	void click();
	Exit_button(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle);
};

class Settings_button : ClickbleEntity {
public:
	void click();
	Settings_button(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle);
};

class Chess_menu {

public:
	void draw(sf::RenderWindow& window);

private:
	Object background;
	Play_button play;
	Exit_button exit;
	Settings_button settings;

};
