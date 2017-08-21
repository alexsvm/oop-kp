#include "World.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>

#include <algorithm>
#include <cmath>


World::World(sf::RenderWindow& window)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(50.f, 50.f, mWorldView.getSize().x - 100, mWorldView.getSize().y - 100)
	, red(sf::Vector2f(68.f, 68.f))
{
	boundShape.setSize(sf::Vector2f(mWorldBounds.width, mWorldBounds.height));
	boundShape.setPosition(50.f, 50.f);
	boundShape.setOutlineColor(sf::Color::Yellow);
	boundShape.setOutlineThickness(4.f);
	boundShape.setFillColor(sf::Color::Transparent);

	buildScene();
}

void World::update(sf::Time dt) {

	// Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
	//while (!mCommandQueue.isEmpty())
	//	mSceneGraph.onCommand(mCommandQueue.pop(), dt);
	//adaptPlayerVelocity();

	mSceneGraph.update(dt);
	sf::Vector2f mouse_pos{ sf::Mouse::getPosition(mWindow) }; // -mWindow.getPosition() };
	red.setPosition(mouse_pos);
	red.update(dt);
	// check red collision!
	
	// update blues and check theirs collisions with world bounds!
	for (auto &it : blues) {
		auto itemVelocity = it->getVelocity();
		auto deltaX = itemVelocity.x * dt.asSeconds();
		auto deltaY = itemVelocity.y * dt.asSeconds();
		auto itemBounds = it->getBounds();
		auto worldBounds = sf::FloatRect(boundShape.getPosition(), boundShape.getSize());
		if (worldBounds.left >= (itemBounds.left + deltaX) || (worldBounds.left + worldBounds.width) <= (itemBounds.left + itemBounds.width + deltaX)) { // left or right intersection
			deltaX = -deltaX;
			itemVelocity.x = - itemVelocity.x;
		}
		if (worldBounds.top >= (itemBounds.top + deltaY) || (worldBounds.top + worldBounds.height) <= (itemBounds.top + itemBounds.height + deltaY)) { // top or bottom intersection
			deltaY = -deltaY;
			itemVelocity.y = -itemVelocity.y;
		}

		itemVelocity.x >= 0 ? itemVelocity.x += it->getAccelleration() * dt.asSeconds() : itemVelocity.x -= it->getAccelleration() * dt.asSeconds();
		itemVelocity.y >= 0 ? itemVelocity.y += it->getAccelleration() * dt.asSeconds() : itemVelocity.y -= it->getAccelleration() * dt.asSeconds();
		it->setVelocity(itemVelocity);
		it->move(deltaX, deltaY);
	}
}

void World::draw() {
	mWindow.draw(boundShape);
	mWindow.draw(mSceneGraph);
	mWindow.draw(red);
}

//CommandQueue& World::getCommandQueue()
//{
//	return mCommandQueue;
//}

//void World::loadTextures()
//{
//	mTextures.load(Textures::Eagle, "Media/Textures/Eagle.png");
//	mTextures.load(Textures::Raptor, "Media/Textures/Raptor.png");
//	mTextures.load(Textures::Desert, "Media/Textures/Desert.png");
//}

void World::buildScene() {
	for (std::size_t i = 0; i < LayerCount; ++i) {
		SceneNode::Ptr layer(new SceneNode());
		mSceneLayers[i] = layer.get();
		mSceneGraph.attachChild(std::move(layer));
	}

	// Prepare the tiled background
	//sf::Texture& texture = mTextures.get(Textures::Desert);
	//sf::IntRect textureRect(mWorldBounds);
	//texture.setRepeated(true);

	// Add the background sprite to the scene
	//std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
	//backgroundSprite->setPosition(mWorldBounds.left, mWorldBounds.top);
	//mSceneLayers[Background]->attachChild(std::move(backgroundSprite));

	red.setPosition(sf::Vector2f(100.f, 100.f));
	blues[0] = new BlueBox(mTextures, sf::Vector2f(100.f, 100.f));
	blues[0]->setPosition(100.f, 100.f);
	blues[1] = new BlueBox(mTextures, sf::Vector2f(100.f, 80.f));
	blues[1]->setPosition(500.f, 100.f);
	blues[2] = new BlueBox(mTextures, sf::Vector2f(50.f, 100.f));
	blues[2]->setPosition(100.f, 500.f);
	blues[3] = new BlueBox(mTextures, sf::Vector2f(170.f, 34.f));
	blues[3]->setPosition(500.f, 500.f);
	for (auto& it : blues) {
		it->setVelocity(100 - std::rand() % 200, 100 - std::rand() % 200);
		it->setAccelleraion(100);
		std::unique_ptr<BlueBox> box(it);
		mSceneGraph.attachChild(std::move(box));
	};
}

//void World::adaptPlayerPosition()
//{
//	// Keep player's position inside the screen bounds, at least borderDistance units from the border
//	sf::FloatRect viewBounds(mWorldView.getCenter() - mWorldView.getSize() / 2.f, mWorldView.getSize());
//	const float borderDistance = 40.f;
//
//	sf::Vector2f position = mPlayerAircraft->getPosition();
//	position.x = std::max(position.x, viewBounds.left + borderDistance);
//	position.x = std::min(position.x, viewBounds.left + viewBounds.width - borderDistance);
//	position.y = std::max(position.y, viewBounds.top + borderDistance);
//	position.y = std::min(position.y, viewBounds.top + viewBounds.height - borderDistance);
//	mPlayerAircraft->setPosition(position);
//}
//
//void World::adaptPlayerVelocity()
//{
//	sf::Vector2f velocity = mPlayerAircraft->getVelocity();
//
//	// If moving diagonally, reduce velocity (to have always same velocity)
//	if (velocity.x != 0.f && velocity.y != 0.f)
//		mPlayerAircraft->setVelocity(velocity / std::sqrt(2.f));
//
//	// Add scrolling velocity
//	mPlayerAircraft->accelerate(0.f, mScrollSpeed);
//}
