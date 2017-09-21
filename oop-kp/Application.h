#pragma once

// TODO: �������� �� �������� 800x600??
// TODO: options menu??
// TODO: ����������� �� �������� ���� � �������� ������
// TODO: ����� ���� ���������� � ����������� ����������

//#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>

#include "ResourceManager.h"
#include "StateStack.h"
#include "StateMenu.h"
#include "StateGame.h"
#include "StateScore.h"
#include "GUI.h"
//#include "sfGUI.h"
//#include "items.h"
//#include "nomads.h"
#include "ColorConsole.h"
#include "HUD.h"
#include "Player.h"

using namespace std;

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

	GUI	mGUI;


	//sfGUI sfgui;
	//Shapes shapes;
	//nomad nomad1;

	//float _mx, _my;
	
	HUD *mHUD;
	bool showHUD;

	Player mPlayer;

	StateStack mStateStack;


};