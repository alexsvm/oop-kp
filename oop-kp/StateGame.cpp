#include "StateGame.h"


StateGame::StateGame(StateStack& stack, Context context)
	: State(stack, context)
	, mWorld(*context.window)
	//, mPlayer(*context.player)
{
	;
}

void StateGame::draw() {
	mWorld.draw();
}

bool StateGame::update(sf::Time dt) {
	mWorld.update(dt);

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

	return true;
}