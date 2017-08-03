#pragma once

#include <list>
#include <SFML/Graphics.hpp>

using namespace std;

class Shapes {
private:
	list<sf::Shape*> shapes;
	sf::Shape *_selected = nullptr;
	sf::RectangleShape _frame;

	float _dx, _dy; // 
	bool _is_move; //

	void SelectNearest(int x, int y);
	void Shapes::Selected_Resize(float delta);

public:
	Shapes();
	~Shapes();
	void Clear();
	void Create_Shapes(int count);
	sf::Shape *Add(sf::Shape *shape);
	sf::Shape *Selected();
	void Update(sf::Time delta_time);
	void Render(sf::RenderWindow &target_window);
	void HandleEvent(sf::Event event, sf::RenderWindow &target_window);
};



