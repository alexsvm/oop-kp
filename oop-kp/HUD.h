#pragma once

#include "State.h"
#include "FrameClock.h"
#include "ClockHUD.h"

class HUD {
public:
	HUD(State::Context context);

	void draw();
	void begin_update();
	void end_update();

private:
	State::Context mContext;
	sfx::FrameClock f_clock;
	sf::Font font;
	ClockHUD *hud;
};