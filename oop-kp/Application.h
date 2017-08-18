#pragma once

//#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "ResourceManager.h"
#include "StateStack.h"
#include "StateMenu.h"
#include "StateGame.h"

//#include "sfGUI.h"
#include "items.h"
#include "nomads.h"
#include "ColorConsole.h"
#include "HUD.h"



class Application {

public:
	Application();
	void run();

private:
	void processInput();
	void update(sf::Time dt);
	void render();
	void registerStates();


private:
	static const sf::Time TimePerFrame;
	sf::ContextSettings settings;

	sf::RenderWindow Window;

	TextureHolder Textures;
	FontHolder Fonts;


	//sfGUI sfgui;
	Shapes shapes;
	nomad nomad1;

	//float _mx, _my;
	
	HUD *mHUD;

	//Player					mPlayer;

	StateStack mStateStack;


};