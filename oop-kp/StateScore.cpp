#include "StateScore.h"
#include <sstream>
#include <SFML/Graphics/RenderWindow.hpp>

StateScore::StateScore(StateStack & stack, Context context) : State(stack, context) {

	auto Label1 = sfg::Label::Create("Your final score is : ");
	auto Label2 = sfg::Label::Create("Your best score is : ");
	lblCScore = sfg::Label::Create("");
	lblBScore = sfg::Label::Create("");

	auto box = sfg::Box::Create(sfg::Box::Orientation::VERTICAL);
	box->SetSpacing(10.f);
	box->Pack(Label1);
	box->Pack(lblCScore);
	box->Pack(Label2);
	box->Pack(lblBScore);

	sfgWindow = sfg::Window::Create();
	sfgWindow->SetTitle("Score");
	sfgWindow->SetStyle(sfg::Window::BACKGROUND);

	sfgWindow->Add(box);

	auto wSize = sf::Vector2f(getContext().window->getSize()) / 2.f; // делим на долю экрана, которую занимает меню
	auto wPos = (sf::Vector2f(getContext().window->getSize()) - wSize) / 2.f;
	sfgWindow->SetAllocation(sf::FloatRect(wPos, wSize));

	sfgWindow->SetId("score_window");
	Label1->SetId("score_label");
	Label2->SetId("score_label");
	lblCScore->SetId("score_label");
	lblBScore->SetId("score_label");

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

	std::stringstream sc;
	sc << std::fixed << std::setprecision(2) << getContext().player->mScoreCurrent;
	lblCScore->SetText(sc.str());
	
	std::stringstream sb;
	sb << std::fixed << std::setprecision(2) << getContext().player->mScoreBest;
	lblBScore->SetText(sb.str());
}
