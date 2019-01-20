#include "Shell.hpp"

Shell::Shell() :
	_y(0)
{
	initscr();
	timeout(0);
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	refresh();

	_screen = newwin(100, 200, 0, 0);
}

Shell::~Shell()
{
	endwin();
}

Shell::Shell(Shell const & src)
{
	static_cast<void>(src);
}

Shell & Shell::operator=(Shell const & rhs)
{
	static_cast<void>(rhs);
	return *this;
}

bool Shell::isClose()
{
	if (getch() == 'q')
		return true;
	return false;
}

void Shell::putInfo(std::string str)
{
	mvwprintw(_screen, _y, 0, str.c_str());
	_y += 1;
}

void Shell::editY(int y)
{
	_y += y;
}

void Shell::render()
{
	wrefresh(_screen);
	wclear(_screen);
	_y = 0;
}