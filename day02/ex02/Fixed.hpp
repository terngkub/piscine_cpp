#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	// Constructors & destructor
	Fixed();
	Fixed(int const value);
	Fixed(float const value);
	Fixed(Fixed const & src);
	~Fixed();

	// Assignment operator
	Fixed & operator=(Fixed const &rhs);

	// Comparison operators
	bool operator>(Fixed const &rhs) const;
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;

	// Arithmetic operators
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;

	// Increment & decrement operators
	Fixed & operator++();
	Fixed operator++(int);
	Fixed & operator--();
	Fixed operator--(int);

	// Member functions
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	// Non-member functions
	static Fixed & min(Fixed & a, Fixed & b);
	static Fixed & max(Fixed & a, Fixed & b);
	static Fixed const & min(Fixed const & a, Fixed const & b);
	static Fixed const & max(Fixed const & a, Fixed const & b);

private:
	int _rawBits;
	static const int _fractionalBits = 8;
};

// Stream operator
std::ostream & operator<<(std::ostream & o, Fixed const &rhs);


#endif