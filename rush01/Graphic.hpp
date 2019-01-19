#ifndef GRAPHIC_HPP
# define GRAPHIC_HPP

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "IMonitorDisplay.hpp"

class Graphic : public IMonitorDisplay
{
public:
	Graphic();
	~Graphic();
	char getInput();
	void putInfo(std::string str);
	void render();

private:
	sf::RenderWindow 	_screen;
	int					_y;
};

#endif