#ifndef PONY_HPP
# define PONY_HPP

# include <string>

class Pony
{
public:
	Pony(std::string name);
	~Pony();

	void announce() const;

private:
	std::string _name;
};

#endif