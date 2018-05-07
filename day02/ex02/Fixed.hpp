/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:43:45 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/07 19:07:22 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	public:

		// Constructors & Destructor
		Fixed(void);
		Fixed(int value);
		Fixed(float value);
		Fixed(Fixed const & src);
		~Fixed(void);

		// Assignation Operator
		Fixed &			operator=(Fixed const & rhs);

		// Comparison Operators
		bool			operator>(Fixed const & rhs) const;
		bool			operator<(Fixed const & rhs) const;
		bool			operator>=(Fixed const & rhs) const;
		bool			operator<=(Fixed const & rhs) const;
		bool			operator==(Fixed const & rhs) const;
		bool			operator!=(Fixed const & rhs) const;

		// Arithmetic Operators
		Fixed			operator+(Fixed const & rhs) const;
		Fixed			operator-(Fixed const & rhs) const;
		Fixed			operator*(Fixed const & rhs) const;
		Fixed			operator/(Fixed const & rhs) const;

		// Functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

	private:
		int					rawBits;
		static const int	fractionalBits = 8;
};

std::ostream &	operator<<(std::ostream & o, Fixed const & rhs);

Fixed const &	min(Fixed const & lhs, Fixed const & rhs);
Fixed const &	max(Fixed const & lhs, Fixed const & rhs);

#endif
