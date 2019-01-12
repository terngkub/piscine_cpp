#ifndef ASSULTTERMINATOR_HPP
# define ASSULTTERMINATOR_HPP

# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	~AssaultTerminator();
	AssaultTerminator(AssaultTerminator const & src);
	AssaultTerminator & operator=(AssaultTerminator const & rhs);

	ISpaceMarine * clone() const;
	void battleCry() const;
	void rangedAttack() const;
	void meleeAttack() const;

private:

};

#endif