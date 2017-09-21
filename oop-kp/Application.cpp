#include "Application.h"
#include "StateTitle.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application() : /*nomad1(100, 100, 200),*/
	Textures(),
	Fonts(),
	mGUI(Fonts),
	mPlayer(),
	mStateStack(State::Context(Window, Textures, Fonts, mGUI, mPlayer)),
	showHUD(true)
{
	srand(std::time(NULL));

	settings.antialiasingLevel = 8;
	Window.create(sf::VideoMode(800, 600), "Hello world!", sf::Style::Close || sf::Style::Titlebar, settings); // Create SFML's window.
	Window.setVerticalSyncEnabled(false);
	Window.setKeyRepeatEnabled(false);

	Window.resetGLStates();

	// Print window settings:
	settings = Window.getSettings();
	std::cout << "depth bits:" << settings.depthBits << std::endl;
	std::cout << "stencil bits:" << settings.stencilBits << std::endl;
	std::cout << "antialiasing level:" << settings.antialiasingLevel << std::endl;
	std::cout << "version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;
	std::cout << cyan << "cyan " << magenta << "magenta " << yellow << "yellow " << grey << "grey " << std::endl;
	std::cout << light_cyan << "light_cyan " << light_magenta << "light_magenta " << light_yellow << "light_yellow " << white << "white" << std::endl;
	std::cout << light_red << " red " << on_blue << " on blue " << grey << on_black << "back in black " << std::endl;

	// Loading resources:
	Fonts.load(Fonts::Main, "fonts\\Hermes.ttf"); 
	Fonts.load(Fonts::Menu, "fonts\\AvanteTitulInline.ttf");
	Fonts.load(Fonts::HUD, "fonts\\Hermes.ttf");
	Textures.load(Textures::TitleScreen, "textures\\TitleScreen.png");

	mGUI.init();
	mHUD = new HUD(State::Context{ Window, Textures, Fonts, mGUI, mPlayer });

	registerStates();
	mStateStack.pushState(States::Title);
}

void Application::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (Window.isOpen()) {
		if (showHUD) mHUD->begin_update();

		processInput();

		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			update(TimePerFrame);

			if (mStateStack.isEmpty())
				Window.close();
		} // while (timeSinceLastUpdate > TimePerFrame) {

		render();
	} // while (Window.isOpen()) {
}

void Application::processInput() {
	sf::Event event;

	while (Window.pollEvent(event)) { // Event processing.
		mStateStack.handleEvent(event);

		if (event.type == sf::Event::Closed) { // If window is about to be closed, leave program.
			Window.close();
		}

		if (event.type == sf::Event::Resized)
		{
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			Window.setView(sf::View(visibleArea));

		}
		//if (event.type == sf::Event::KeyPressed) {
		//	if (event.key.code == sf::Keyboard::Up) {
		//		sf::View view = Window.getView();
		//		view.move(0, -50);
		//		Window.setView(view);
		//	}
		//	if (event.key.code == sf::Keyboard::Right) {
		//		sf::View view = Window.getView();
		//		view.move(50, 0);
		//		Window.setView(view);
		//	}
		//	if (event.key.code == sf::Keyboard::Down) {
		//		sf::View view = Window.getView();
		//		view.move(0, 50);
		//		Window.setView(view);
		//	}
		//	if (event.key.code == sf::Keyboard::Left) {
		//		sf::View view = Window.getView();
		//		view.move(-50, 0);
		//		Window.setView(view);
		//	}
		//} // KeyPressed
		//if (event.type == sf::Event::MouseButtonPressed) {
		//	if (event.mouseButton.button == sf::Mouse::Left) {
		//		_mx = event.mouseButton.x;
		//		_my = event.mouseButton.y;
		//	}
		//	if (event.mouseButton.button == sf::Mouse::Right) {
		//		;
		//	}
		//} // <= MouseButtonPressed
		//if (event.type == sf::Event::MouseButtonReleased) {
		//	if (event.mouseButton.button == sf::Mouse::Left) {
		//		;
		//	}
		//} // <=MouseButtonReleased
		//if (event.type == sf::Event::MouseMoved) {
		//	if (!shapes.Selected() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		//		sf::Vector2i mc = sf::Mouse::getPosition();
		//		sf::View view = Window.getView();
		//		view.move(_mx - event.mouseMove.x, _my - event.mouseMove.y);
		//		Window.setView(view);
		//		_mx = event.mouseMove.x;
		//		_my = event.mouseMove.y;
		//	}
		//} // <=MouseMoved
	} // while (Window.pollEvent(event)) { // Event processing.

}

void Application::update(sf::Time dt) {
	mStateStack.update(dt);
}

void Application::render() {
	Window.clear();

	mStateStack.draw();

	if (showHUD) mHUD->end_update();
	if (showHUD) mHUD->draw();

	Window.display();
}

void Application::registerStates() {
	mStateStack.registerState<StateTitle>(States::Title);
	mStateStack.registerState<StateMenu>(States::Menu);
	mStateStack.registerState<StateGame>(States::Game);
	mStateStack.registerState<StateScore>(States::Score);
}

