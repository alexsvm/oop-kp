#include "State.h"
#include "StateStack.h"

State::Context::Context(sf::RenderWindow& window, TextureHolder& textures, FontHolder& fonts, GUI& gui, Player& player) 
	: window(&window)
	, textures(&textures)
	, fonts(&fonts)
	, gui(&gui)
	, player(&player)
{

}

State::State(StateStack& stack, Context context) : mStack(&stack), mContext(context) {

}

State::~State() {

}

void State::requestStackPush(States::ID stateID) {
	//afterStackPush();
	mStack->pushState(stateID);
}

void State::requestStackPop() {
	//beforeStackPop();
	mStack->popState();
}

void State::requestStateClear() {
	mStack->clearStates();
}

State::Context State::getContext() const {
	return mContext;
}

void State::beforeStackPop() {
}

void State::afterStackPush() {
}

