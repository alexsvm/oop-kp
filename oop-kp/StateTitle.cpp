#include "StateTitle.h"
#include "Utility.h"
#include "ResourceManager.h"
#include <SFML/Graphics/RenderWindow.hpp>


StateTitle::StateTitle(StateStack& stack, Context context) : State(stack, context), mText(), mShowText(true), mTextEffectTime(sf::Time::Zero ) {
	mBackgroundSprite.setTexture(context.textures->get(Textures::TitleScreen));
	mText.setFont(context.fonts->get(Fonts::Main));
	mText.setString("Press any key to start");
	centerOrigin(mText);
	mText.setPosition(sf::Vector2f(context.window->getSize() / 2u));
}

void StateTitle::draw() {
	sf::RenderWindow& window = *getContext().window;
	window.draw(mBackgroundSprite);
	if (mShowText)
		window.draw(mText);
}

bool StateTitle::update(sf::Time dt) {
	mTextEffectTime += dt;
	if (mTextEffectTime >= sf::seconds(0.5f)) {
		mShowText = !mShowText;
		mTextEffectTime = sf::Time::Zero;
	}
	return true;
}

bool StateTitle::handleEvent(const sf::Event& event) { 	// If any key is pressed, trigger the next screen
	if (event.type == sf::Event::KeyReleased) {
		requestStackPop();
		requestStackPush(States::Menu);
	}
	if (event.type == sf::Event::MouseButtonPressed) {
		requestStackPop();
		requestStackPush(States::Menu);
	} // <= MouseButtonPressed

	return true;
}