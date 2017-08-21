#include "Entity.h"


void Entity::setVelocity(sf::Vector2f velocity) {
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy) {
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const {
	return mVelocity;
}

float Entity::getAccelleration() {
	return mAcceleration;
}

void Entity::setAccelleraion(float accelleration) {
	mAcceleration = accelleration;
}

void Entity::accelerate(sf::Vector2f velocity) {
	mVelocity += velocity;
}

void Entity::accelerate(float vx, float vy) {
	mVelocity.x += vx;
	mVelocity.y += vy;
}

void Entity::updateCurrent(sf::Time dt) {
	
}