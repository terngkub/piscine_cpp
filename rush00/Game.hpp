/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:02:59 by                   #+#    #+#             */
/*   Updated: 2019/01/13 15:51:32 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP
# include <sys/time.h>
# include "Map.hpp"
# include "Player.hpp"
# include "Enemy.hpp"
# include "Move.hpp"

class Game {

	public:

		Game( void );
		~Game( void );
		Game( int width, int height );

		void	update( IInput const & input );
		void	render( void );
		bool	is_over( void ) const;

		bool	should_update();

		bool has_input;

	private:

		Game( Game const & );
		Game & operator=( Game const & );
		void	init( void );

		void	resize_storage( void );
		void	store_object(IGameEntity * object);

		void	iter_on_objects( void (Game::*f)( IGameEntity & ) );
		void	iter_on_objects(
				void (Game::*f)( IGameEntity const & ) const ) const;
		void	collision_with( IGameEntity & object);
		void	render_object( IGameEntity const & object) const;
		void	update_object( IGameEntity & object);
		void	cleanup_objects( void );
		void	clean_collision( IGameEntity & object );
		void	kill_out_of_map( IGameEntity & object );


		Map		map;
		Player	player;
		bool	over;

		IGameEntity	**game_objects;
		size_t		objects_number;
		size_t		storage_space;
		size_t		first_free_space;

		IGameEntity ***	collision_table;
		IGameEntity * &	get_collision_position(
				Position const &,
				Move const & = Move(0, 0)
				);

		int frame_rate;
		struct timeval loop_start;
		struct timeval loop_stop;
};

#endif // GAME_HPP
