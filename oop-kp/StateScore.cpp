#include "StateScore.h"
#include <SFML/Graphics/RenderWindow.hpp>

StateScore::StateScore(StateStack & stack, Context context) : State(stack, context) {

	//btnPlay = sfg::Button::Create(" P L A Y ");
	//btnPlay->GetSignal(sfg::Widget::OnLeftClick).Connect([this] { requestStackPop();  requestStackPush(States::Game); });
	//btnPlay->SetRequisition(sf::Vector2f(0.f, 64.f));


	//btnExit = sfg::Button::Create(" E X I T ");
	//btnExit->GetSignal(sfg::Widget::OnLeftClick).Connect([this] { requestStackPop(); });

	auto Label1 = sfg::Label::Create("Your final score is : ");
	auto Label2 = sfg::Label::Create("Your best score is : ");

	sfg::Box::Ptr box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box->SetSpacing(20.f);
	box->Pack(Label1);
	box->Pack(Label2);
	//box->Pack(btnPlay, false);
	//box->Pack(btnExit, false);

	sfgWindow = sfg::Window::Create();
	sfgWindow->SetTitle("Score");
	sfgWindow->SetStyle(sfg::Window::BACKGROUND);

	sfgWindow->Add(box);

	auto wSize = sf::Vector2f(getContext().window->getSize()) / 2.f; // делим на долю экрана, которую занимает меню
	auto wPos = (sf::Vector2f(getContext().window->getSize()) - wSize) / 2.f;
	sfgWindow->SetAllocation(sf::FloatRect(wPos, wSize));

	sfgWindow->SetId("score_window");
	Label1->SetId("score_label");
	Label1->SetId("score_label");

	//getContext().gui->sfgDesktop.Add(sfgWindow);

}

void StateScore::draw() {
	sf::RenderWindow& window = *getContext().window;
	getContext().gui->sfGUI.Display(window);
}

bool StateScore::update(sf::Time dt) {
	getContext().gui->sfgDesktop.Update(dt.asSeconds());
	return true;
}

bool StateScore::handleEvent(const sf::Event & event) {
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
		requestStackPop();
		requestStackPop();
		requestStackPush(States::Menu);
	}

	getContext().gui->sfgDesktop.HandleEvent(event);
	
	return true;
}

void StateScore::beforeStackPop() {
	getContext().gui->sfgDesktop.Remove(sfgWindow);
}

void StateScore::afterStackPush() {
	getContext().gui->sfgDesktop.Add(sfgWindow);
}
