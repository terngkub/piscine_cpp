#include "Graphic.hpp"

Graphic::Graphic() :
	_screen(sf::VideoMode(390, 700), "ft_gkrellm"),
	_y(0)
{
	_screen.clear(sf::Color::Black);
	_screen.display();
}

Graphic::~Graphic()
{
	_screen.close();
}

Graphic::Graphic(Graphic const & src)
{
	static_cast<void>(src);
}

Graphic & Graphic::operator=(Graphic const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

bool Graphic::isClose()
{
	sf::Event event;
	while (_screen.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			return true;
		if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			return true;
	}
	return false;
}

void Graphic::putInfo(std::string str)
{
	sf::Font font;
	font.loadFromFile("fonts/Menlo.ttc");

	sf::Text text(str, font, 12);
	text.setFillColor(sf::Color::White);
	text.setPosition(15, _y);
	_screen.draw(text);

	_y += 16;
}

void Graphic::editY(int y)
{
	_y += y;
}

void Graphic::render()
{
	_screen.display();
	_screen.clear(sf::Color::Black);
	_y = 0;
}