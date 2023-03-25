/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:43:52 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/10 13:11:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{

public:
	Fixed(void);
	~Fixed(void);
	Fixed(Fixed const & src);
	

	Fixed(int const n);
	Fixed(float const n);

	Fixed & operator=(Fixed const & rhs);
	
	float toFloat (void) const;
	int toInt (void) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _in;
	static const int _fracbit = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
