#pragma once
#include <string>

class Weapon
{
public:
	Weapon(std::string type);
	std::string const & getType() const;
	void setType(std::string type);

private:
	std::string type;
};