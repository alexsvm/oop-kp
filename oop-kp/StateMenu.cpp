//#include <memory>
#include "StateMenu.h"
#include <SFML/Graphics/Font.hpp>



StateMenu::StateMenu(StateStack & stack, Context context) : State(stack, context) {

	//std::shared_ptr<const sf::Font> my_font = std::make_shared<const sf::Font>(context.fonts->get(Fonts::Menu));
	//sfgDesktop.GetEngine().GetResourceManager().AddFont("menu_font", my_font);
	//sfgDesktop.SetProperty("Button", "FontName", "menu_font" );
	//sfgDesktop.SetProperty("Button", "FontSize", 48.f);
	//sfgDesktop.SetProperty("Button", "Color", sf::Color::Yellow);
	//sfgDesktop.SetProperty("#btn_exit", "Color", sf::Color::Red);
	//sfgDesktop.SetProperties(
	//	//	/*"Window#second_window > Box > Label {"
	//	//	"	FontName: custom_font;"
	//	//	"	FontSize: 18;"
	//	//	"}"*/
	//	"#main_window {"
	//	" Color: #0F000F0F;"
	//	"}"
	//	"Button {"
	//		" Color: #FF0000FF;"
	//		" FontName: menu_font;"
	//		" FontSize: 32;"
	//		"}"
	//	"#btn_play {"
	//		" Color: #FFFF00FF;"
	//		//"	FontName: \\fonts\\hermes.ttf;"
	//		" FontSize: 48;"
	//		"}"
	//	"Box {"
	//		" Color: #000F0F0F;"
	//	"}"
	//);


	btnPlay = sfg::Button::Create(" P L A Y ");
	btnPlay->GetSignal(sfg::Widget::OnLeftClick).Connect([this] { requestStackPop();  requestStackPush(States::Game); });
	btnPlay->SetRequisition(sf::Vector2f(0.f, 64.f));


	btnExit = sfg::Button::Create(" E X I T ");
	btnExit->GetSignal(sfg::Widget::OnLeftClick).Connect([this] { requestStackPop(); });

	sfg::Box::Ptr box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box->SetSpacing(20.f);
	box->Pack(btnPlay, false);
	box->Pack(btnExit, false);

	sfgWindow = sfg::Window::Create();
	sfgWindow->SetTitle("Menu");
	sfgWindow->SetStyle(sfg::Window::BACKGROUND);

	sfgWindow->Add(box);
	sfgWindow->SetAllocation(sf::FloatRect(320, 256, 1024 - 320 * 2, 768 - 256 * 2));

	sfgWindow->SetId("main_window");
	btnExit->SetId("btn_play");
	btnExit->SetId("btn_exit");
	
	//sfgDesktop.SetProperty("Button#btn_play", "FontSize", 96.f);
	
	getContext().gui->sfgDesktop.Add(sfgWindow);
	//sfgDesktop.Add(sfgWindow);

}

void StateMenu::draw() {
	sf::RenderWindow& window = *getContext().window;
	getContext().gui->sfGUI.Display(window);
	//sfGUI.Display(window);
}

bool StateMenu::update(sf::Time dt) {
	getContext().gui->sfgDesktop.Update(dt.asSeconds());
	//sfgDesktop.Update(dt.asSeconds());
	return false;
}

bool StateMenu::handleEvent(const sf::Event & event) {
	getContext().gui->sfgDesktop.HandleEvent(event);
	//sfgDesktop.HandleEvent(event);
	return false;
}
