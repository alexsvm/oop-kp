#include "StateGame.h"
#include "ResourceManager.h"
#include <SFML/Graphics/RenderWindow.hpp>


StateGame::StateGame(StateStack& stack, Context context)
	: State(stack, context)
	, mWorld(*context.window)
	//, mPlayer(*context.player)
{
	sf::RenderWindow& window = *getContext().window;
	mScoreText.setFont(context.fonts->get(Fonts::Main));
	mScoreText.setColor({ 0, 200, 200, 200 });
	mScoreText.setString("42");
	mScoreText.setPosition(sf::Vector2f(10, window.getSize().y - mScoreText.getLocalBounds().height * 2 ));
	;
}

void StateGame::draw() {
	sf::RenderWindow& window = *getContext().window;
	mWorld.draw();
	window.draw(mScoreText);
}

bool StateGame::update(sf::Time dt) {
	mWorld.update(dt);
	mScoreText.setString(std::to_string(mWorld.getScoreCurrent()));
	//CommandQueue& commands = mWorld.getCommandQueue();
	//mPlayer.handleRealtimeInput(commands);
	
	return true;
}

bool StateGame::handleEvent(const sf::Event& event) {
	// Game input handling
	//CommandQueue& commands = mWorld.getCommandQueue();
	//mPlayer.handleEvent(event, commands);

	// Escape pressed, trigger the pause screen
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		requestStackPop();
		requestStackPush(States::Menu);
	}

	mWorld.handleEvent(event);

	if (mWorld.getState() == World::Over) {
		//requestStackPop();
		requestStackPush(States::Score);
	}

	return true;
}