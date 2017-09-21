#include "HUD.h"

HUD::HUD(State::Context context) : mContext(context) {
	f_clock.setSampleDepth(100); 	// Sample 100 frames for averaging.
	font = mContext.fonts->get(Fonts::Main); //mContext.fonts->get(Fonts::Main);
	hud = new ClockHUD(f_clock, font);
}

void HUD::draw() {
	mContext.window->draw(*hud);
}

void HUD::begin_update() {
	f_clock.beginFrame(); // Start a new frame. #HUD
}

void HUD::end_update() {
	f_clock.endFrame(); // End frame. #HUD
}


