#pragma once


class Player {
public:
	float mScoreCurrent;
	float mScoreBest;
	
	Player() : mScoreCurrent(0.f), mScoreBest(0.f) {};
};

//	void handleEvent(const sf::Event& event, CommandQueue& commands);
//	void handleRealtimeInput(CommandQueue& commands);
//
//	void assignKey(Action action, sf::Keyboard::Key key);
//	sf::Keyboard::Key		getAssignedKey(Action action) const;
//
//
//private:
//	void initializeActions();
//	static bool isRealtimeAction(Action action);
//
//
//private:
//	std::map<sf::Keyboard::Key, Action>		mKeyBinding;
//	std::map<Action, Command>				mActionBinding;
