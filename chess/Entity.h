
#ifndef GRAPHICS
#include <SFML/Graphics.hpp>
#define GRAPHICS
#endif // !GRAPHICS

#ifndef VECTOR
#include<vector>
#define VECTOR
#endif



class Object
{
public:

	/// SETTERS
	void set_rect(sf::Rect<int> new_rect);


	/// GETTERS
	std::pair<int, int> get_pos() const;
	std::pair<double, double> get_size() const;
	sf::Rect<int> get_rect() const;
	std::string get_texture() const;

	/// OTHER
	Object(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file,sf::Rect<int> rectangle);
	~Object();
	void draw(sf::RenderWindow& window);

protected:
	std::pair<double, double> pos;
	std::pair<int, int> size;
	sf::Rect<int> rectangle;
	std::string texture_file;
	sf::Texture texture;
	sf::Sprite sprite;

};


class Figure;



class Cell : public Object 
{
public:
	/// SETTERS
	void set_figure(Figure& figure);

	/// GETTERS
	std::string figure_on();
	std::string get_name();


	/// OTHER
	Cell(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle, std::string name, Figure& figure);
	void eat(Figure& attacker);

private:
	Figure figure;
	std::string name;
};



class Entity : public Object 
{
public:
	/// SETTERS
	void set_pos(std::pair<double, double> new_pos);
	void set_size(std::pair<int, int> new_size);
	void set_texture(std::string new_texture_file);
	void set_speed(double new_speed);
	void set_finale_pos(std::pair<double, double> new_pos);

	/// GETTERS
	double get_speed() const;
	std::pair<double, double> get_finale_pos() const;

	/// OTHER
	Entity(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle);
	void move_to_pos(double tick);

protected:
	double speed;
	std::pair<double, double> finale_pos;
};



class ClickbleEntity : public Entity {

public:
	ClickbleEntity(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle);
	bool mouse_on(std::pair<double, double> mouse_pos);
	virtual void click(std::pair<double, double> mouse_pos);


};



class Figure : public ClickbleEntity
{
public:

	/// SETTERS 
	void set_type(Figure& type);

	/// OTHER
	Figure(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle, Cell cell, bool color);
	void move(Cell& new_cell);
	virtual void calculate_attack();
	virtual void click(std::pair<double, double> mouse_pos);

private:
	Cell& cell;
	bool color;
	std::vector<Cell> attack;

};

