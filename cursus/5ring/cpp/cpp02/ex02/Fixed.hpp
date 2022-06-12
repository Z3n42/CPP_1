/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:43:52 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/12 19:48:08 by ingonzal         ###   ########.fr       */
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

	bool operator>(Fixed const & rhs)const;
	bool operator<(Fixed const & rhs)const;
	bool operator>=(Fixed const & rhs)const;
	bool operator<=(Fixed const & rhs)const;
	bool operator==(Fixed const & rhs)const;
	bool operator!=(Fixed const & rhs)const;


	Fixed operator+(const Fixed &rhs);
	Fixed operator-(const Fixed &rhs);
	Fixed operator*(const Fixed &rhs);
	Fixed operator/(const Fixed &rhs);

	Fixed & operator++(void);
	Fixed & operator--(void);
	Fixed  operator++(int);
	Fixed  operator--(int);
	
	float toFloat (void) const;
	int toInt (void) const;

	int getRawBits(void) const;
	void setRawBits(int const raw);

	static Fixed & min(Fixed & a, Fixed & b);
	static Fixed & max(Fixed & a, Fixed & b);
	static const Fixed & min(const Fixed & a, const Fixed & b);
	static const Fixed & max(const Fixed & a, const Fixed & b);

private:
	int _in;
	static const int _fracbit = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
