#include <sys/time.h>
#include "Map.hpp"
#include "IGameEntity.hpp"
#include "Position.hpp"

Map::Map( void ) :
	width(60),
	height(20),
	place(0)
{
	init_ncurses();
}

Map::Map( int width, int height ) :
	width(width),
	height(height),
	place(0)
{
	init_ncurses();
}

Map::~Map( void )
{
	endwin();
}

void	Map::put_object( IGameEntity const & object ) const {

	int x = object.get_position().x;
	int y = object.get_position().y;

	if (check_place(x - 1, y))
	{
		wattron(game, COLOR_PAIR(2));
		mvwaddch(game, y, x, object.get_char_sign());
		wattroff(game, COLOR_PAIR(2));
	}
	else
		mvwaddch(game, y, x, object.get_char_sign());
}

Map::Map(Map const & src)
{
	*this = src;
}

Map & Map::operator=(Map const & rhs)
{
	if (this != &rhs)
		game = rhs.game;
	return *this;
}

void Map::render()
{
	wrefresh(game);
	wrefresh(info);
	wclear(game);
	wclear(info);
	box(info, 0, 0);

	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			if (check_place(i, j))
			{
				wattron(game, COLOR_PAIR(2));
				mvwaddch(game, j, i, ' ');
				wattroff(game, COLOR_PAIR(2));
			}
		}
	}
	place++;

	struct timeval now;
	gettimeofday(&now, NULL);
	int diff_sec = now.tv_sec - start.tv_sec;
	mvwprintw(info, 2, 2, "time %02d:%02d", diff_sec / 60, diff_sec % 60);
}

bool	Map::inside(Position const & pos) const {

	return (pos.x >= 0 && pos.x <= width
			&& pos.y >= 0 && pos.y <= height);
}

void Map::init_ncurses( void )
{
	initscr();
	start_color();
	timeout(0);
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	refresh();

	init_pair(1, COLOR_BLACK, COLOR_BLUE);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);

	game = newwin(height, width, 0, 0);
	info = newwin(5, width, height, 0);

	wbkgd(game, COLOR_PAIR(1));
	box(game, 0, 0);
	box(info, 0, 0);
	gettimeofday(&start, NULL);
	mvwprintw(info, 2, 2, "time %02d:%02d", 0, 0);
}

bool Map::check_place(int x, int y) const
{
	int bgx = (place + x) % 100;
	int bgy = y % 20;

	if ((bgx >= 5 && bgx < 15 && bgy >= 4 && bgy < 10)
		|| (bgx >= 15 && bgx < 25 && bgy >= 13 && bgy < 18)
		|| (bgx >= 40 && bgx < 65 && bgy >= 2 && bgy < 10)
		|| (bgx >= 45 && bgx < 50 && bgy >= 14 && bgy < 17)
		|| (bgx >= 65 && bgx < 70 && bgy >= 16 && bgy < 19)
		|| (bgx >= 80 && bgx < 90 && bgy >= 9 && bgy < 13))
		return true;
	return false;
}