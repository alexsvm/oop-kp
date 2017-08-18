#pragma once

#include "Entity.h"
#include "ResourceManager.h"

//#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


class BlueBox : public Entity {

public:
	BlueBox(const TextureHolder& textures, sf::Vector2f size);

	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void updateCurrent(sf::Time dt);
	virtual sf::FloatRect getBounds() const;
	//virtual unsigned int	getCategory() const;

private:
	//Type					mType;
	//sf::Sprite				mSprite;
	sf::RectangleShape		mShape;
};
