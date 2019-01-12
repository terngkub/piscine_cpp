#include "Enemy.hpp"

Enemy::Enemy() :
	_hp(0),
	_type("Default type")
{
}

Enemy::Enemy(int hp, std::string const & type) :
	_hp(hp),
	_type(type)
{
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		_hp = rhs._hp;
		_type = rhs._type;
	}
	return *this;
}

int Enemy::getHp() const
{
	return _hp;
}

std::string Enemy::getType() const
{
	return _type;
}

void Enemy::setHp(int hp)
{
	_hp = hp;
}