#ifndef ENTITY
#include"Entity.h"
#define ENTITY
#endif

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
	void take(Figure& attacker);

private:
	Figure figure;
	std::string name;
};




class Figure : public ClickbleEntity
{
public:

	/// SETTERS 
	void set_type(Figure& type);

	/// GETTERS 

	virtual std::string get_type();
	/// OTHER
	Figure(std::pair<double, double> pos, std::pair<int, int> size, std::string texture_file, sf::Rect<int> rectangle, Cell cell, bool color);
	void move(Cell& new_cell);
	virtual void calculate_attack();
	virtual int click(std::pair<double, double> mouse_pos);

private:
	Cell& cell;
	bool color;
	std::vector<Cell> attack;

};