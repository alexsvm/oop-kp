#pragma once

#include <list>
#include <SFML/Graphics.hpp>

class nomad {
private:
	sf::RectangleShape *shape;
	sf::Vector2f dir; // moving direction
	//sf::Clock clock;
	float dir_rnd_factor;
	float speed; // pixel/s ?
	float accel; // pixel/s^2 ?
	float move_period; // mks
	float accel_change_period; // ms
	float dir_change_period; // ms

	float time_change;
	float time_change_speed;
	float time_change_accel;
	float time_change_dir;
	enum State { stopped, running };
	State state;
public:
	nomad(float x, float y, float size): dir_rnd_factor(0.5), speed(80.f), accel(0.f), 
			accel_change_period(2000.f), dir_change_period(2000.f), state(stopped), 
			time_change(0.f), time_change_speed(0.f), time_change_accel(0.f), time_change_dir(0.f)
	{
		dir.x = 100; dir.y = 0;		
		shape = new sf::RectangleShape(sf::Vector2f(size, size));
		shape->setPosition(sf::Vector2f(x, y));
		shape->setOutlineThickness(3.f);
		shape->setOutlineColor(sf::Color::Blue);
		shape->setFillColor(sf::Color::Transparent);
		move_period = 1000000.f / speed;
	}

	~nomad() {
		delete shape;
	}

	void Update(sf::Time delta_time) {
		if (state == State::stopped) return;
		if (time_change < move_period) {
			time_change += delta_time.asMicroseconds();
		} else {
			float distance = speed * time_change / 1000000.f + accel * (time_change* time_change) /2000000.f; // in px
			float k = distance / sqrtf(dir.x*dir.x + dir.y*dir.y);
			float delta_x = dir.x * k;
			float delta_y = dir.y * k;
			shape->move(delta_x, delta_y);
			time_change = 0;
		}
		if (time_change_dir < dir_change_period) { // Время менять направление?
			time_change_dir += delta_time.asMilliseconds();
		}
		else {
			sf::Transform rotation;
			rotation.rotate(rand() % 180 - 90);
			dir = rotation.transformPoint(dir);
			time_change_dir = 0;
		}

		
	}

	void Render(sf::RenderWindow &target_window) {
		target_window.draw(*shape);
	}

	void HandleEvent(sf::Event event) {

	}

	State GetState() { return state; };
	void SetState(State s) { state = s; };
	void Stop() { state = State::stopped; };
	void Start() { state = State::running; };

};