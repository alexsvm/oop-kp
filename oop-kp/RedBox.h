#pragma once

#include "SceneNode.h"

#include <SFML/Graphics/RectangleShape.hpp>


class RedBox : public SceneNode {
public:
	RedBox(sf::Vector2f size);

	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void updateCurrent(sf::Time dt);
	virtual sf::FloatRect getBounds() const;

private:
	sf::RectangleShape		mShape;
};