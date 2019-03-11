#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include <string>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(std::string name);
	NinjaTrap(NinjaTrap const & src);
	~NinjaTrap();
	NinjaTrap & operator=(NinjaTrap const & rhs);

	void ninjaShoebox(ClapTrap const & trap) const;
	void ninjaShoebox(FragTrap const & trap) const;
	void ninjaShoebox(ScavTrap const & trap) const;
	void ninjaShoebox(NinjaTrap const & trap) const;
};

#endif