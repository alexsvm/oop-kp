#pragma once

#include "ResourceManager.h"
#include "SceneNode.h"
//#include "SpriteNode.h"
#include "BlueBox.h"
#include "RedBox.h"

//#include <Book/CommandQueue.hpp>
//#include <Book/Command.hpp>

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

#include <array>
#include <queue>


// Forward declaration
namespace sf
{
	class RenderWindow;
	class Event;
	class Clock;
}

class World : private sf::NonCopyable
{
public:
	enum State {
		Waiting,
		Playing,
		Stopped
	};

	explicit World(sf::RenderWindow& window);
	void update(sf::Time dt);
	void draw();
	virtual bool handleEvent(const sf::Event& event);
	//CommandQueue&		getCommandQueue();

	State getState();
	void setState(State state);

	float getScoreCurrent() { return mScoreCurrent; };
	float getScoreBest() { return mScoreBest; };

	void reset();

private:
	//void				loadTextures();
	void buildScene();

private:
	enum Layer 	{
		Background,
		Air,
		LayerCount
	};


private:
	State mState;
	float mScoreCurrent;
	float mScoreBest;

	sf::Clock mScoreClock;

	sf::RenderWindow& mWindow;
	sf::View mWorldView;
	TextureHolder mTextures;

	SceneNode mSceneGraph;
	std::array<SceneNode*, LayerCount> mSceneLayers;
	//CommandQueue mCommandQueue;

	sf::FloatRect mWorldBounds;
	sf::RectangleShape boundShape;
	RedBox red;
	std::array<BlueBox*, 4> blues;

};

