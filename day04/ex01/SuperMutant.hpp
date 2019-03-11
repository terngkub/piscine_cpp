#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	SuperMutant(SuperMutant const & src);
	~SuperMutant();
	SuperMutant & operator=(SuperMutant const & rhs);

	void takeDamage(int damage);
};

#endif