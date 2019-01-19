#include "Graphic.hpp"

Graphic::Graphic() :
	_screen(sf::VideoMode(800, 600), "My window"),
	_y(0)
{
	_screen.clear(sf::Color::Black);
	_screen.display();
}

Graphic::~Graphic()
{
	_screen.close();
}

char Graphic::getInput()
{
	sf::Event event;
	while (_screen.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			_screen.close();
	}
	return 'a';
}

void Graphic::putInfo(std::string str)
{
	sf::Font font;
	font.loadFromFile("Menlo.ttc");

	sf::Text text(str, font, 12);
	text.setFillColor(sf::Color::White);
	text.setPosition(15, _y);
	_screen.draw(text);

	_y += 60;
}

void Graphic::render()
{
	_screen.display();
	_screen.clear(sf::Color::Black);
	_y = 0;
}