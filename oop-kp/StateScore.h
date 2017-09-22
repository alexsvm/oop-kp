#pragma once

#include "State.h"
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>

class StateScore : public State {
public:
	StateScore(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

private:
	sfg::Window::Ptr sfgWindow;
	sfg::Label::Ptr lblCScore;
	sfg::Label::Ptr lblBScore;

public:
	virtual void beforeStackPop();
	virtual void afterStackPush();
};
