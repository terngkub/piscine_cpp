#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string name, std::string title);
	Sorcerer(Sorcerer const & src);
	~Sorcerer();
	Sorcerer & operator=(Sorcerer const & rhs);

	std::string getName() const;
	std::string getTitle() const;

	void polymorph(Victim const & victim) const;

private:
	std::string _name;
	std::string _title;

	Sorcerer();
};

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs);

#endif