#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie
{
public:
	Zombie();
	Zombie(std::string type, std::string name);
	~Zombie();

	void setType(std::string type);
	void setName(std::string name);
	void announce() const;

private:
	std::string _type;
	std::string _name;
};

#endif