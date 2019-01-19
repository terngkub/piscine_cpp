#ifndef SHELL_HPP
# define SHELL_HPP

#include <ncurses.h>
#include <string>
#include "IMonitorDisplay.hpp"

class Shell : public IMonitorDisplay
{
public:
	Shell();
	~Shell();
	char getInput();
	void putInfo(std::string str);
	void render();

private:
	WINDOW *	_screen;
	int			_y;
};

#endif