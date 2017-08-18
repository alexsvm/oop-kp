#pragma once

#include "ResourceManager.h"
#include "SceneNode.h"
//#include "SpriteNode.h"
#include "BlueBox.h"
//#include <Book/CommandQueue.hpp>
//#include <Book/Command.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>
#include <queue>


// Forward declaration
namespace sf
{
	class RenderWindow;
}

class World : private sf::NonCopyable
{
public:
	explicit							World(sf::RenderWindow& window);
	void								update(sf::Time dt);
	void								draw();

	//CommandQueue&						getCommandQueue();


private:
	//void								loadTextures();
	void								buildScene();
	//void								adaptPlayerPosition();
	//void								adaptPlayerVelocity();


private:
	enum Layer
	{
		Background,
		Air,
		LayerCount
	};


private:
	sf::RenderWindow&					mWindow;
	sf::View							mWorldView;
	TextureHolder						mTextures;

	SceneNode							mSceneGraph;
	std::array<SceneNode*, LayerCount>	mSceneLayers;
	//CommandQueue						mCommandQueue;

	sf::FloatRect						mWorldBounds;
	//sf::Vector2f						mSpawnPosition;
	//float								mScrollSpeed;
	//Aircraft*							mPlayerAircraft;
};

