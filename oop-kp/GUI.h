#pragma once

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
		//sfgDesktop.SetProperty("Button", "FontName", "menu_font" );
		//sfgDesktop.SetProperty("Button", "FontSize", 48.f);
		//sfgDesktop.SetProperty("Button", "Color", sf::Color::Yellow);
		//sfgDesktop.SetProperty("#btn_exit", "Color", sf::Color::Red);
		sfgDesktop.SetProperties(
			//	/*"Window#second_window > Box > Label {"
			//	"	FontName: custom_font;"
			//	"	FontSize: 18;"
			//	"}"*/
			"#main_window {"
			" Color: #0F000F0F;"
			"}"
			"Button {"
			" Color: #FF0000FF;"
			" FontName: menu_font;"
			" FontSize: 32;"
			"}"
			"#btn_play {"
			" Color: #FFFF00FF;"
			//"	FontName: \\fonts\\hermes.ttf;"
			" FontSize: 48;"
			"}"
			"Box {"
			" Color: #000F0F0F;"
			"}"
		);
	}

};