#ifndef MAP_HPP
# define MAP_HPP

# include <sys/time.h>
# include <ncurses.h>
# include "Player.hpp"
# include "Bullet.hpp"
# include "Enemy.hpp"
# include "Position.hpp"

class Map
{
	public:
		Map( void );
		Map( int width, int height );
		~Map( void );

		int 	width;
		int 	height;

		void	put_object( IGameEntity const & ) const;
		void	render();
		bool	inside(Position const &) const;

	private:
		Map(Map const & src);
		Map & operator=(Map const & rhs);

		WINDOW *		game;
		WINDOW *		info;
		struct timeval	start;
		int				place;

		void	init_ncurses( void );
		bool	check_place(int x, int y) const;
};

#endif
