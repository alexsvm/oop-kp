#include "Application.h"
#include "StateTitle.h"

const sf::Time Application::TimePerFrame = sf::seconds(1.f / 60.f);

Application::Application() : nomad1(100, 100, 200), Textures(), Fonts(), mStateStack(State::Context(Window, Textures, Fonts))
{
	srand(std::time(NULL));

	settings.antialiasingLevel = 8;
	Window.create(sf::VideoMode(800, 800), "Hello world!", sf::Style::Default, settings); // Create SFML's window.
	Window.setKeyRepeatEnabled(false);

	sfgui._shapes = &shapes;
	nomad1.Start();

	Window.resetGLStates();

	// Print window settings:
	settings = Window.getSettings();
	std::cout << "depth bits:" << settings.depthBits << std::endl;
	std::cout << "stencil bits:" << settings.stencilBits << std::endl;
	std::cout << "antialiasing level:" << settings.antialiasingLevel << std::endl;
	std::cout << "version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;
	std::cout << cyan << "cyan " << magenta << "magenta " << yellow << "yellow " << grey << "grey " << endl;
	std::cout << light_cyan << "light_cyan " << light_magenta << "light_magenta " << light_yellow << "light_yellow " << white << "white" << endl;
	std::cout << light_red << " red " << on_blue << " on blue " << grey << on_black << "back in black " << endl;

	// Loading resources:
	Fonts.load(Fonts::Main, "fonts\\hermes.ttf"); 
	Fonts.load(Fonts::HUD, "fonts\\hermes.ttf");
	Textures.load(Textures::TitleScreen, "textures\\TitleScreen.png");

	mHUD = new HUD(State::Context{ Window, Textures, Fonts });

	registerStates();
	mStateStack.pushState(States::Title);
}

void Application::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (Window.isOpen()) {
		mHUD->begin_update();

		processInput();

		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			update(TimePerFrame);

			//if (mStateStack.isEmpty())
			//	Window.close();
		}
		render();
	}
}

void Application::processInput() {
	sf::Event event;

	while (Window.pollEvent(event)) { // Event processing.
		mStateStack.handleEvent(event);

		sfgui.HandleEvent(event);
		shapes.HandleEvent(event, Window);
		nomad1.HandleEvent(event);
		//
		if (event.type == sf::Event::Closed) { // If window is about to be closed, leave program.
			Window.close();
		}
		//
		if (event.type == sf::Event::Resized)
		{
			sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			Window.setView(sf::View(visibleArea));

		}
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Up) {
				sf::View view = Window.getView();
				view.move(0, -50);
				Window.setView(view);
			}
			if (event.key.code == sf::Keyboard::Right) {
				sf::View view = Window.getView();
				view.move(50, 0);
				Window.setView(view);
			}
			if (event.key.code == sf::Keyboard::Down) {
				sf::View view = Window.getView();
				view.move(0, 50);
				Window.setView(view);
			}
			if (event.key.code == sf::Keyboard::Left) {
				sf::View view = Window.getView();
				view.move(-50, 0);
				Window.setView(view);
			}
		} // KeyPressed
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				_mx = event.mouseButton.x;
				_my = event.mouseButton.y;
			}
			if (event.mouseButton.button == sf::Mouse::Right) {
				;
			}
		} // <= MouseButtonPressed
		if (event.type == sf::Event::MouseButtonReleased) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				;
			}
		} // <=MouseButtonReleased
		if (event.type == sf::Event::MouseMoved) {
			if (!shapes.Selected() && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i mc = sf::Mouse::getPosition();
				sf::View view = Window.getView();
				view.move(_mx - event.mouseMove.x, _my - event.mouseMove.y);
				Window.setView(view);
				_mx = event.mouseMove.x;
				_my = event.mouseMove.y;
			}
		} // <=MouseMoved
	} // <= Event processing

}

void Application::update(sf::Time dt) {
	mStateStack.update(dt);

	sfgui.Update(dt);
	shapes.Update(dt);
	nomad1.Update(dt);
}

void Application::render() {
	Window.clear();

	mStateStack.draw();

	shapes.Render(Window);
	nomad1.Render(Window);
	sfgui.Render(Window);

	mHUD->end_update();
	mHUD->draw();

	Window.display();
}

void Application::registerStates() {
	mStateStack.registerState<StateTitle>(States::Title);

}

