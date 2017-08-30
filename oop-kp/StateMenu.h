#pragma once

#include "State.h"
#include <SFGUI\SFGUI.hpp>
#include <SFGUI\Widgets.hpp>

class StateMenu : public State {
public:
	StateMenu(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(sf::Time dt);
	virtual bool handleEvent(const sf::Event& event);

private:
	//sfg::SFGUI sfGUI;
	sfg::Window::Ptr sfgWindow;
	//sfg::Desktop sfgDesktop;

	sfg::Box::Ptr menuBox;

	sfg::Button::Ptr btnPlay;
	sfg::Button::Ptr btnExit;


};

