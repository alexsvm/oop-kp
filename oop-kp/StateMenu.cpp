#include "StateMenu.h"
#include <SFML/Graphics/Font.hpp>
#include "ResourceManager.h"
#include <SFML/Graphics/RenderWindow.hpp>

StateMenu::StateMenu(StateStack & stack, Context context) : State(stack, context) {

	btnPlay = sfg::Button::Create(" P L A Y ");
	btnPlay->GetSignal(sfg::Widget::OnLeftClick).Connect([this] { requestStackPop();  requestStackPush(States::Game); });
	btnPlay->SetRequisition(sf::Vector2f(0.f, 64.f));


	btnExit = sfg::Button::Create(" E X I T ");
	btnExit->GetSignal(sfg::Widget::OnLeftClick).Connect([this] { requestStackPop(); });

	btnReloadTheme = sfg::Button::Create(" reload theme ");
	btnReloadTheme->GetSignal(sfg::Widget::OnLeftClick).Connect(
		[this] { 
		if (std::ifstream("sfgui.theme")) 
			getContext().gui->sfgDesktop.LoadThemeFromFile("sfgui.theme"); 
	});

	menuBox = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	menuBox->SetSpacing(20.f);
	menuBox->Pack(btnPlay, false);
	menuBox->Pack(btnExit, false);
	menuBox->Pack(sfg::Separator::Create());
	menuBox->Pack(btnReloadTheme, false);

	sfgWindow = sfg::Window::Create();
	sfgWindow->SetTitle("Menu");
	sfgWindow->SetStyle(sfg::Window::BACKGROUND);

	sfgWindow->Add(menuBox);
	// 800/3=260 600/3=200
	auto wSize = sf::Vector2f(getContext().window->getSize()) / 2.f; // делим на долю экрана, которую занимает меню
	auto wPos = (sf::Vector2f(getContext().window->getSize()) - wSize) / 2.f;
	sfgWindow->SetAllocation(sf::FloatRect(wPos, wSize));
	
	
	sfgWindow->SetId("main_window");
	menuBox->SetId("menu_box");
	btnPlay->SetId("btn_play");
	btnExit->SetId("btn_exit");
	btnReloadTheme->SetId("btn_reloadtheme");
	
	//getContext().gui->sfgDesktop.Add(sfgWindow);

}

void StateMenu::draw() {
	sf::RenderWindow& window = *getContext().window;
	getContext().gui->sfGUI.Display(window);
}

bool StateMenu::update(sf::Time dt) {
	getContext().gui->sfgDesktop.Update(dt.asSeconds());
	return false;
}

bool StateMenu::handleEvent(const sf::Event & event) {
	getContext().gui->sfgDesktop.HandleEvent(event);
	return false;
}

void StateMenu::beforeStackPop() {
	getContext().gui->sfgDesktop.Remove(sfgWindow);
}

void StateMenu::afterStackPush() {
	getContext().gui->sfgDesktop.Add(sfgWindow);
}
