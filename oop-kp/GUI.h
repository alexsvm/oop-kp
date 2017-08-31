#pragma once

#include <fstream>
#include <SFGUI\SFGUI.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFGUI\Widgets.hpp>
#include "ResourceManager.h"

class GUI {
private:
	FontHolder* fonts;

public:
	GUI(FontHolder &Fonts) : fonts(&Fonts){
		
	}

	sfg::SFGUI sfGUI;
	sfg::Desktop sfgDesktop;

	void init() {
		// Setting up fonts for GUI
		std::shared_ptr<const sf::Font> my_font = std::make_shared<const sf::Font>(fonts->get(Fonts::Menu));
		sfgDesktop.GetEngine().GetResourceManager().AddFont("menu_font", my_font);

		// https://github.com/TankOs/SFGUI/blob/master/src/SFGUI/Engines/BREW.cpp - см. здесь (АВМ)

		if (std::ifstream("sfgui.theme"))
			sfgDesktop.LoadThemeFromFile("sfgui.theme");
		//else
		//	return;

		//sfgDesktop.SetProperties(
		//	//	/*"Window#second_window > Box > Label {"
		//	//	"	FontName: custom_font;"
		//	//	"	FontSize: 18;"
		//	//	"}"*/
		//	"#main_window {"
		//	" BackgroundColor: #00FF0F80;"
		//	" BorderColor: #FF0F0F80;"
		//	" BorderWidth: 4.f;"
		//	" ShadowDistance: 5.f;"
		//	" ShadowAlpha: 200.f;"
		//	"}"

		//	"#score_window {"
		//	" BackgroundColor: #00FF0F80;"
		//	" BorderColor: #FF0F0F80;"
		//	" BorderWidth: 4.f;"
		//	"}"
		//	

		//	"#menu_box {"
		//	" BackgroundColor: #0F000F0F;"
		//	" BorderColor: #00FF0FFF;"
		//	" BorderWidth: 2.f;"
		//	"}"

		//	"Button {"
		//	" Color: #FF00FFFF;"
		//	" BackgroundColor: #800000FF;"
		//	" FontName: menu_font;"
		//	" FontSize: 32;"
		//	"}"
		//
		//	"Button:PRELIGHT {"
		//	" Color: #FAFA00FF;"
		//	" BackgroundColor: #FFFF00FF;"
		//	"}"

		//	"Button:ACTIVE {"
		//	" Color: #FFFF00FF;"
		//	" BackgroundColor: #FF3030FF;"
		//	"}"


		//	"Button#btn_play:PRELIGHT {"
		//	" Color: #FFFFFFFF;"
		//	" BackgroundColor: #0F0F0FFF;"
		//	"}"
		//	/*
		//	"#btn_play {"
		//	" Color: #FFFF00FF;"
		//	" BackgroundColor: #0F000FFF;"
		//	" BorderColor: #00FF0FFF;"
		//	" FontName: menu_font;"
		//	" FontSize: 48;"
		//	"}"*/
		//);
	}

};