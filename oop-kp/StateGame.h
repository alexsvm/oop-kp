#pragma once


#include "State.h"
#include "World.h"
//#include <Book/Player.hpp>

//#include <SFML/Graphics/Sprite.hpp>
//#include <SFML/Graphics/Text.hpp>


class StateGame : public State
{
public:
	StateGame(StateStack& stack, Context context);

	virtual void		draw();
	virtual bool		update(sf::Time dt);
	virtual bool		handleEvent(const sf::Event& event);


private:
	World				mWorld;
	//Player&				mPlayer;
};