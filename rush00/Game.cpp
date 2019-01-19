/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 13:06:06 by                   #+#    #+#             */
/*   Updated: 2019/01/13 21:12:37 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "IInput.hpp"
#include "Input.hpp"
#include "Game.hpp"
#include <cstdlib>
#include <cstddef>
#include <iostream>

Game::Game( int width, int height ) :
	has_input(false),
	map(width, height),
	player(width, height),
	over(false),
	game_objects(new IGameEntity *[10]),
	objects_number(1), // for the player
	storage_space(10),
	frame_rate(10) {

	init();
}

void Game::init( void ) {

	for (size_t i = 1; i < storage_space; i++)
		game_objects[i] = nullptr;
	collision_table = new IGameEntity **[map.width + 3];
	for (int i = 0; i < map.width + 3; i++)
	{
		collision_table[i] = new IGameEntity *[map.height + 3];
		for (int j = 0;j < map.height + 3; j++)
			collision_table[i][j] = nullptr;
	}
	game_objects[0] = &player;
	map.put_object(player);
	map.render();
	gettimeofday(&loop_start, NULL);
}

Game::Game( void ) :
	has_input(false),
	player(map.width, map.height),
	over(false),
	game_objects(new IGameEntity *[10]),
	objects_number(1), // for the player
	storage_space(10),
	collision_table(),
	frame_rate(10) {

	init();
}

Game::~Game( void ) {

	// Player is in first position and has automatic allocation;
	for (size_t	i = 1; i < storage_space; i++)
		delete game_objects[i];
	delete game_objects;
	for (int i = 0; i < map.width + 3; i++)
		delete collision_table[i];
	delete collision_table;
	return;
}

bool	Game::is_over( void ) const {

	return (over || player.is_destroyed());
}

void	Game::cleanup_objects( void ) {

	// Same than the destroyer
	for (size_t i = 1; i < storage_space;i++)
	{
		if (game_objects[i] != nullptr
				&& (game_objects[i]->is_destroyed()
					)) {
			delete game_objects[i];
			game_objects[i] = nullptr;
			objects_number--;
		}
	}
}

void	Game::update( IInput const & input ) {
	if (input.is_exit())
		over = true;
	else
	{
		player.take_command(input);
		if (rand()%100 > 90)
			store_object(new Enemy(map.width, rand() % map.height));
	}
	iter_on_objects(&Game::kill_out_of_map);
	cleanup_objects();
	iter_on_objects(&Game::collision_with);
	iter_on_objects(&Game::clean_collision);
	cleanup_objects();
	iter_on_objects(&Game::update_object);

}

void	Game::kill_out_of_map( IGameEntity & obj ) {

	if (!map.inside(obj.get_position()))
		obj.kill();
}

void	Game::update_object( IGameEntity & obj) {

	IGameEntity * new_object = obj.update();

	if (new_object != nullptr)
		store_object(new_object);
}

void	Game::render_object( IGameEntity const & obj) const {

	map.put_object(obj);
}

void	Game::render( void ) {

	map.put_object(player);
	iter_on_objects(&Game::render_object);
	map.render();
	has_input = false;
	loop_start = loop_stop;
	flushinp();
}

void	Game::resize_storage( void ) {
	IGameEntity **old_storage = game_objects;
	size_t	new_storage_space = storage_space * 2;

	game_objects = new IGameEntity *[new_storage_space];
	for (size_t i = 0; i < storage_space; i++)
		game_objects[i] = old_storage[i];
	for (size_t i = storage_space; i < new_storage_space; i++)
		game_objects[i] = nullptr;
	delete old_storage;
	storage_space = new_storage_space;
}

void	Game::store_object(IGameEntity * object) {

	if (objects_number == storage_space)
		resize_storage();
	size_t	i = 0;
	while (game_objects[i] != nullptr)
		i++;
	game_objects[i] = object;
	objects_number++;
}

void	Game::iter_on_objects( void (Game::*f)( IGameEntity & ) ) {

	for (size_t i = 0; i < storage_space; i++)
	{
		if (game_objects[i] != nullptr)
			(this->*f)(*(game_objects[i]));
	}
}

void	Game::iter_on_objects(
		void (Game::*f)( IGameEntity const & ) const ) const {

	for (size_t i = 0; i < storage_space; i++)
	{
		if (game_objects[i] != nullptr)
			(this->*f)(*(game_objects[i]));
	}
}

void	Game::clean_collision( IGameEntity & object) {

	get_collision_position(object.get_position()) = nullptr;
	get_collision_position(object.get_position(), object.get_move()) = nullptr;
}

IGameEntity	* & Game::get_collision_position(
		Position const & pos,
		Move const & move) {

	return collision_table[(pos.x + move.getX() + 1)][pos.y];
}

void	Game::collision_with( IGameEntity & object) {

	IGameEntity * collider = get_collision_position( object.get_position() );
	if (collider == nullptr)
		collider = get_collision_position(
				object.get_position(), object.get_move());
	if (collider == nullptr)
	{
		get_collision_position(object.get_position()) = &object;
		get_collision_position(object.get_position(), object.get_move()) = &object;
	}
	else
		object.collides_with(*collider);
}

bool Game::should_update()
{
	gettimeofday(&loop_stop, NULL);
	int duration = (loop_stop.tv_sec - loop_start.tv_sec) * 1000000 + loop_stop.tv_usec - loop_start.tv_usec;
	if (duration > (1000000 / frame_rate))
		return true;
	return false;
}
