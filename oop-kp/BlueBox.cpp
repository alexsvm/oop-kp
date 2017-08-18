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
	mShape.setSize(size);
	mShape.setOutlineThickness(0.f);
	mShape.setOutlineColor(sf::Color::Blue);
	mShape.setFillColor(sf::Color::Blue);
}

void BlueBox::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
	//target.draw(mSprite, states);
	//shape = new sf::RectangleShape(sf::Vector2f(size, size));
	target.draw(mShape);
}

void BlueBox::updateCurrent(sf::Time dt) {
	mShape.setPosition(this->getPosition());
}

sf::FloatRect BlueBox::getBounds() const {
	return sf::FloatRect(mShape.getPosition(), mShape.getSize());
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
