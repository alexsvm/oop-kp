#include <typeinfo>
#include <iostream>
#include "items.h"


//list<sf::Shape*> shapes;
//sf::Shape *_selected = nullptr;
//sf::RectangleShape _frame;

//float _dx, _dy; // 
//bool _is_move; //

/*
void shapes_init()
{
	
	_frame.setFillColor(sf::Color::Transparent);
	_frame.setOutlineThickness(1);
	_frame.setOutlineColor(sf::Color::Red);
}
*/

Shapes::Shapes() {
	_selected = nullptr;
	_frame.setFillColor(sf::Color::Transparent);
	_frame.setOutlineThickness(1);
	_frame.setOutlineColor(sf::Color::Red);
}

Shapes::~Shapes() {
	Clear();
}

void Shapes::Clear() {
	for (size_t i = shapes.size(); i > 0; i--) {
		shapes.pop_front();
	}
}

void Shapes::Create_Shapes(int count) {

	sf::CircleShape *c;
	for (; count > 0; count--) {
		c = new sf::CircleShape(100);
		c->setOutlineColor(sf::Color::Green);
		c->setFillColor(sf::Color::Transparent);
		c->setOutlineThickness(3);
		c->setPosition(rand() % 600, rand() % 600);
		shapes.push_back(c);
	}
}



sf::Shape *Shapes::Add(sf::Shape *shape) {
	shapes.push_back(shape);
	return shape;
}

sf::Shape *Shapes::Selected()
{
	return _selected;
}

void Shapes::Update(sf::Time delta_time) {
	
}

void Shapes::Render(sf::RenderWindow &target_window) {
	list<sf::Shape*>::iterator it = shapes.begin();
	for (; it != shapes.end(); ++it) {
		target_window.draw(**it); // Draw shape
		if (*it == _selected) {
			if (typeid(**it) == typeid(sf::CircleShape)) {
				sf::CircleShape *c = dynamic_cast<sf::CircleShape *> (*it);
				float w = (c->getRadius()) * 2;
				_frame.setSize(sf::Vector2f(w, w));
				_frame.setOrigin(w / 2, w / 2);
				_frame.setPosition(c->getPosition());
			}
			if (typeid(**it) == typeid(sf::RectangleShape)) {
				sf::RectangleShape *r = dynamic_cast<sf::RectangleShape *> (*it);
				sf::Vector2f v = r->getSize();
				v.x += 10;
				v.y += 10;
				_frame.setSize(v);
				_frame.setOrigin(v.x / 2, v.x / 2);
				_frame.setPosition(r->getPosition());
			}
			target_window.draw(_frame);
		}
	}
}

void Shapes::SelectNearest(int x, int y) {
	list<sf::Shape*>::reverse_iterator it = shapes.rbegin();
	sf::Vector2f v;
	float r2, d2;
	//cout << "x=" << x << ", y=" << y << endl;
	for (; it != shapes.rend(); ++it) {
		if (typeid(**it) == typeid(sf::CircleShape)) {
			sf::CircleShape *c = dynamic_cast<sf::CircleShape *> (*it);
			v = c->getPosition();
			r2 = c->getRadius() * c->getRadius();
		}
		if (typeid(**it) == typeid(sf::RectangleShape)) {
			sf::RectangleShape *r = dynamic_cast<sf::RectangleShape *> (*it);
			v = r->getPosition();
			r2 = sqrt(r->getSize().x * r->getSize().x + r->getSize().y *  r->getSize().y);
			r2 *= r2;
		}
		d2 = (v.x - x)*(v.x - x) + (v.y - y)*(v.y - y);
		//cout << "    v.x=" << v.x << ", v.y=" << v.y << endl;
		if (r2 > d2) {
			_selected = *it;
			return;
		}
	} // for
	_selected = nullptr;
}

void Shapes::Selected_Resize(float delta) {
	if (_selected) {
		if (typeid(*_selected) == typeid(sf::CircleShape)) {
			sf::CircleShape *c = dynamic_cast<sf::CircleShape *> (_selected);
			c->setRadius(c->getRadius()+delta);
			//c->move(-delta, -delta);
			c->setOrigin(c->getRadius(), c->getRadius());
		}
		if (typeid(*_selected) == typeid(sf::RectangleShape)) {
			sf::RectangleShape *r = dynamic_cast<sf::RectangleShape *> (_selected);
			sf::Vector2f v = r->getSize();
			v.x += delta;
			v.y += delta;
			r->setSize(v);
			r->setOrigin(v.x / 2, v.x / 2);
		}
	}
}

void Shapes::HandleEvent(sf::Event event, sf::RenderWindow &target_window) {
	if (shapes.empty()) return;
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::View view = target_window.getView();
			sf::Vector2f vc = view.getCenter();
			sf::Vector2f vs = view.getSize();
			cout << vs.x << "x" << vs.y << " - "<< vc.x << "," << vc.y << endl;
			SelectNearest(event.mouseButton.x + vc.x - vs.x/2, event.mouseButton.y + vc.y - vs.y/2);
			if (_selected) {
				sf::Vector2f pos;
				pos = _selected->getPosition();
				_dx = event.mouseButton.x - pos.x;
				_dy = event.mouseButton.y - pos.y;
				_is_move = true;
			}
		}
		if (event.mouseButton.button == sf::Mouse::Right) {
			_selected = nullptr;
		}
	} // MouseButtonPressed
	
	if (event.type == sf::Event::MouseButtonReleased) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			if (_is_move) 
				_is_move = false;
		}
	} // MouseButtonReleased

	if (event.type == sf::Event::MouseMoved) {
		if (_is_move) {
			_selected->setPosition(sf::Vector2f(event.mouseMove.x - _dx, event.mouseMove.y - _dy));
		}
	} // MouseMoved

	if (event.type == sf::Event::MouseWheelScrolled) {
		if (event.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {
				_selected->setRotation(_selected->getRotation() + event.mouseWheelScroll.delta);
			}else {
				Selected_Resize(event.mouseWheelScroll.delta);
			}
			
		}
		
	} // MouseWheelScrolled

	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape) {

		}
	} // KeyPressed
}


