/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:43:52 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/09 17:49:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{

public:
	Fixed(void);
	~Fixed(void);
	Fixed(Fixed const & src);

	Fixed & operator=(Fixed const & rhs);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:
	int _in;
	static const int bit = 8;
};

#endif
