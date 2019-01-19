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

	_screen = newwin(30, 20, 0, 0);
}

Shell::~Shell()
{
	endwin();
}

char Shell::getInput()
{
	char c = getch();
	return c;
}

void Shell::putInfo(std::string str)
{
	mvwprintw(_screen, _y, 0, str.c_str());
	_y += 5;
}

void Shell::render()
{
	wrefresh(_screen);
	wclear(_screen);
	_y = 0;
}