#include "BlueBox.h"
#include "ResourceManager.h"
#include "Utility.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


//Textures::ID toTextureID(Aircraft::Type type)
//{
//	switch (type)
//	{
//	case Aircraft::Eagle:
//		return Textures::Eagle;
//
//	case Aircraft::Raptor:
//		return Textures::Raptor;
//	}
//}

BlueBox::BlueBox(const TextureHolder& textures, sf::Vector2f size) { // mSprite(textures.get(Textures::BlueBox)) {
	centerOrigin(mShape);
	//shape->setPosition(sf::Vector2f(x, y));
	mShape.setSize(size);
	mShape.setOutlineThickness(3.f);
	mShape.setOutlineColor(sf::Color::Blue);
	mShape.setFillColor(sf::Color::Magenta);
}

void BlueBox::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	//target.draw(mSprite, states);
	//shape = new sf::RectangleShape(sf::Vector2f(size, size));
	target.draw(mShape);
}

void BlueBox::updateCurrent(sf::Time dt) {
	mShape.setPosition(this->getPosition());
}

//unsigned int BlueBox::getCategory() const
//{
//	switch (mType)
//	{
//	case Eagle:
//		return Category::PlayerAircraft;
//
//	default:
//		return Category::EnemyAircraft;
//	}
//}
