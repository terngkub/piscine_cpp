#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <string>

class Enemy
{
public:
	Enemy();
	Enemy(int hp, std::string const & type);
	Enemy(Enemy const & src);
	virtual ~Enemy();
	Enemy & operator=(Enemy const & rhs);

	int getHp() const;
	std::string getType() const;

	void setHp(int hp);

	virtual void takeDamage(int damage) = 0;

private:
	int	_hp;
	std::string _type;
};

#endif