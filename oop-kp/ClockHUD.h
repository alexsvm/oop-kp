#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

#include <SFML/Graphics.hpp>
#include "FrameClock.h"

class ClockHUD : public sf::Drawable
{
	struct Stat
	{
		sf::Color color;
		std::string str;
	};

	typedef std::vector<Stat> Stats_t;

public:

	ClockHUD(const sfx::FrameClock& clock, const sf::Font& font)
		: m_clock(&clock)
		, m_font(&font)
	{}

private:

	void draw(sf::RenderTarget& rt, sf::RenderStates states) const
	{
		// Gather the available frame time statistics.
		const Stats_t stats = build();

		sf::Text elem;
		elem.setFont(*m_font);
		elem.setCharacterSize(16);
		elem.setPosition(5.0f, 400.0f);

		// Draw the available frame time statistics.
		for (std::size_t i = 0; i < stats.size(); ++i)
		{
			elem.setString(stats[i].str);
			elem.setColor(stats[i].color);

			rt.draw(elem, states);

			// Next line.
			elem.move(0.0f, 16.0f);
		}
	}

private:

	template<typename T>
	static std::string format(std::string name, std::string resolution, T value)
	{
		std::ostringstream os;
		os.precision(4);
		os << std::left << std::setw(5);
		os << name << " : ";
		os << std::setw(5);
		os << value << " " << resolution;
		return os.str();
	}


	Stats_t build() const
	{
		const int count = 10;
		const Stat stats[count] = {
			{ sf::Color{ 255,255,  0,128 }, format("Time",  "(sec)", m_clock->getTotalFrameTime().asSeconds()) },	// Yellow
			{ sf::Color{ 255,255,255,128 },  format("Frame", "",      m_clock->getTotalFrameCount()) },				// White
			{ sf::Color{ 255,  0,  0,128 },  format("FPS",   "",      m_clock->getFramesPerSecond()) },				// Green
			{ sf::Color{ 255,  0,  0,128 },  format("min.",  "",      m_clock->getMinFramesPerSecond()) },			// Green
			{ sf::Color{ 255,  0,  0,128 },  format("avg.",  "",      m_clock->getAverageFramesPerSecond()) },					// Green
			{ sf::Color{ 255,  0,  0,128 },  format("max.",  "",      m_clock->getMaxFramesPerSecond()) },						// Cyan
			{ sf::Color{   0,255,255,128 },   format("Delta", "(ms)",  m_clock->getLastFrameTime().asMilliseconds()) },			// Cyan
			{ sf::Color{   0,255,255,128 },   format("min.",  "(ms)",  m_clock->getMinFrameTime().asMilliseconds()) },			// Cyan
			{ sf::Color{   0,255,255,128 },   format("avg.",  "(ms)",  m_clock->getAverageFrameTime().asMilliseconds()) },		// Cyan
			{ sf::Color{   0,255,255,128 },   format("max.",  "(ms)",  m_clock->getMaxtFrameTime().asMilliseconds()) }			// Cyan
		};
		return Stats_t(&stats[0], &stats[0] + count);
	}

private:

	const sf::Font* m_font;
	const sfx::FrameClock* m_clock;
};
