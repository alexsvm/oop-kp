#pragma once

#include "SceneNode.h"

class Entity : public SceneNode {
public:
	Entity() : mAcceleration(0) {};
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	void accelerate(sf::Vector2f velocity);
	void accelerate(float vx, float vy);
	sf::Vector2f getVelocity() const;
	float getAccelleration();
	void setAccelleraion(float accelleration);

private:
	virtual void updateCurrent(sf::Time dt);


private:
	sf::Vector2f mVelocity;
	float mAcceleration;
};
