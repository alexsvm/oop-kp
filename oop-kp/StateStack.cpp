#include "Foreach.h"
#include "StateStack.h"
#include <cassert>


StateStack::StateStack(State::Context context) : mStack(), mPendingList(), mContext(context), mFactories() {
}

void StateStack::update(sf::Time dt) { 
	// Iterate from top to bottom, stop as soon as update() returns false
	
	/*for (auto &it : mStack) {
		if (!it->update(dt))
			break;
	}*/

	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if (!(*itr)->update(dt))
			break;
	}
	applyPendingChanges();
}

void StateStack::draw() {
	/*for (auto &state : mStack)
		state->draw();*/

	// Draw all active states from bottom to top
	FOREACH(State::Ptr& state, mStack)
		state->draw();
}

void StateStack::handleEvent(const sf::Event& event) { 	// Iterate from top to bottom, stop as soon as handleEvent() returns false
	/*for (auto &it : mStack)
		if (!it->handleEvent(event))
			break;*/
	for (auto itr = mStack.rbegin(); itr != mStack.rend(); ++itr)
	{
		if (!(*itr)->handleEvent(event))
			break;
	}
	applyPendingChanges();
}

void StateStack::pushState(States::ID stateID) {
	mPendingList.push_back(PendingChange(Push, stateID));
}

void StateStack::popState() {
	mPendingList.push_back(PendingChange(Pop));
}

void StateStack::clearStates() {
	mPendingList.push_back(PendingChange(Clear));
}

bool StateStack::isEmpty() const {
	return mStack.empty();
}

State::Ptr StateStack::createState(States::ID stateID) {
	auto found = mFactories.find(stateID);
	assert(found != mFactories.end());
	return found->second();
}

void StateStack::applyPendingChanges() {
	//FOREACH(PendingChange change, mPendingList)
	for (auto &change : mPendingList) {
		switch (change.action) {
		case Push:
		{
			auto mState = createState(change.stateID);
			mState->afterStackPush();
			mStack.push_back(std::move(mState));
		}
			break;

		case Pop:
		{
			auto mState = mStack.back().get();
			mState->beforeStackPop();
			mStack.pop_back();
		}
			break;

		case Clear:
			mStack.clear();
			break;
		} // switch
	} // for 
	mPendingList.clear();
}

StateStack::PendingChange::PendingChange(Action action, States::ID stateID) : action(action) , stateID(stateID) {

}
