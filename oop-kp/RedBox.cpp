#include "RedBox.h"
#include "Utility.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


RedBox::RedBox(sf::Vector2f size) {
	centerOrigin(mShape);
	setOrigin(std::floor(size.x / 2.f), std::floor(size.y / 2.f));
	mShape.setSize(size);
	mShape.setOutlineThickness(3.f);
	mShape.setOutlineColor(sf::Color::Red);
	mShape.setFillColor(sf::Color::Red);
}

void RedBox::drawCurrent(sf::RenderTarget & target, sf::RenderStates states) const {
	target.draw(mShape);
}

void RedBox::updateCurrent(sf::Time dt) {
	sf::Vector2f pos = getPosition() - mShape.getSize() / 2.f;
	mShape.setPosition(pos);
}
