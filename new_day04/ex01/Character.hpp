#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:
	Character();
	Character(std::string const & name);
	Character(Character const & src);
	~Character();
	Character & operator=(Character const & rhs);

	std::string getName() const;
	int getAp() const;
	AWeapon * getWeapon() const;

	void recoverAP();
	void equip(AWeapon * weapon);
	void attack(Enemy * enemy);

private:
	std::string _name;
	int _ap;
	AWeapon * _weapon;
};

std::ostream & operator<<(std::ostream & o, Character const & rhs);

#endif