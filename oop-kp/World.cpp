#include "World.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>

#include <algorithm>
#include <cmath>


World::World(sf::RenderWindow& window)
	: mWindow(window)
	, mWorldView(window.getDefaultView())
	//, mTextures()
	, mSceneGraph()
	, mSceneLayers()
	, mWorldBounds(0.f, 0.f, mWorldView.getSize().x, 2000.f)
	//, mSpawnPosition(mWorldView.getSize().x / 2.f, mWorldBounds.height - mWorldView.getSize().y / 2.f)
	//, mScrollSpeed(-50.f)
	//, mPlayerAircraft(nullptr)
	, red(sf::Vector2f(100, 100))
{
	//loadTextures();
	buildScene();

	// Prepare the view
	//mWorldView.setCenter(mSpawnPosition);
}

void World::update(sf::Time dt)
{
	// Scroll the world, reset player velocity
	//mWorldView.move(0.f, mScrollSpeed * dt.asSeconds());
	//mPlayerAircraft->setVelocity(0.f, 0.f);

	// Forward commands to scene graph, adapt velocity (scrolling, diagonal correction)
	//while (!mCommandQueue.isEmpty())
	//	mSceneGraph.onCommand(mCommandQueue.pop(), dt);
	//adaptPlayerVelocity();

	// Regular update step, adapt position (correct if outside view)
	mSceneGraph.update(dt);
	sf::Vector2f mouse_pos{ sf::Mouse::getPosition(mWindow) }; // -mWindow.getPosition() };
	red.setPosition(mouse_pos);
	red.update(dt);
	//adaptPlayerPosition();
}

void World::draw()
{
//	mWindow.setView(mWorldView);
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

void World::buildScene()
{
	// Initialize the different layers
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

	// Add player's aircraft
	//std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Eagle, mTextures));
	//mPlayerAircraft = leader.get();
	//mPlayerAircraft->setPosition(mSpawnPosition);
	//mSceneLayers[Air]->attachChild(std::move(leader));
	std::unique_ptr<BlueBox> box1(new BlueBox(mTextures, sf::Vector2f(200.f, 200.f)));
	box1->setPosition(500.f, 500.f);
	mSceneLayers[Air]->attachChild(std::move(box1));

	std::unique_ptr<BlueBox> box2(new BlueBox(mTextures, sf::Vector2f(200.f, 200.f)));
	box2->setPosition(400.f, 400.f);
	mSceneLayers[Air]->attachChild(std::move(box2));

	red.setPosition(sf::Vector2f(100.f, 100.f));
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
