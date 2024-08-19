#ifndef ENTITY
#include"Entity.h"
#define ENTITY
#endif


/// Object

void Object::set_rect(sf::Rect<int> new_rect) {
	sprite.setTextureRect(new_rect);
}

std::pair<int, int> Object::get_pos() const {
	return pos;
}

sf::Rect<int> Object::get_rect() const {
	return rectangle;
}

std::string Object::get_texture() const {
	return texture_file;
}

Object::Object(std::pair<double, double> pos, sf::IntRect rectangle, std::string texture_file): pos(pos),rectangle(rectangle) {
	if (!texture.loadFromFile(texture_file)) {
		throw std::exception("Texture file is not found!");
	}
	this->texture_file = texture_file;

	sprite.setPosition(pos.first, pos.second);
	sprite.setTextureRect(rectangle);

}

void Object::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

/// ENTITY

void Entity::set_pos(std::pair<double, double> new_pos)
{
	sprite.setPosition(new_pos.first, new_pos.second);
	pos = new_pos;
}

void Entity::set_size(std::pair<int, int> new_size)
{
	sf::Vector2i texture_pos = rectangle.getPosition();
	sprite.setTextureRect({ texture_pos.x,texture_pos.y,new_size.first,new_size.second });

	rectangle = { texture_pos.x,texture_pos.y,new_size.first,new_size.second };
}

void Entity::set_texture(std::string new_texture_file)
{
	if (!texture.loadFromFile(new_texture_file)) throw std::exception("New texture file is not found!");

	texture_file = new_texture_file;
}

void Entity::set_speed(double new_speed)
{
	speed = new_speed;
}

void Entity::set_finale_pos(std::pair<double, double> new_pos)
{
	finale_pos = new_pos;
}

double Entity::get_speed() const
{
	return speed;
}

std::pair<double, double> Entity::get_finale_pos() const
{
	return finale_pos;
}

Entity::Entity(std::pair<double, double> pos, sf::Rect<int> rectangle, std::string texture_file): Object(pos,rectangle,texture_file)
{
}

void Entity::move_to_pos(double tick) {
	if (pos != finale_pos && speed) {
		double dx = finale_pos.first - pos.first / speed;
		double dy = finale_pos.second - pos.second / speed;
		set_pos({ pos.first + dx * tick,pos.second + dy * tick });
	}
}

/// Clckable Entity

ClickbleEntity::ClickbleEntity(std::pair<double, double> pos, sf::Rect<int> rectangle, std::string texture_file) : Entity(pos, rectangle, texture_file)
{

}

bool ClickbleEntity::mouse_on(std::pair<double, double> mouse_pos)
{
	double mx = mouse_pos.first, my = mouse_pos.second, bx = pos.first, by = pos.second,bdx = bx + rectangle.getSize().x, bdy = by + rectangle.getSize().y;

	if (mx >= bx && mx <= bdx && my >= by && my <= bdy) {
		return true;
	}
	return false;
}