/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <nkamolba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 23:43:45 by nkamolba          #+#    #+#             */
/*   Updated: 2018/05/07 00:22:29 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed &	operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					rawBits;
		static const int	fractionalBits = 8;
};

#endif
