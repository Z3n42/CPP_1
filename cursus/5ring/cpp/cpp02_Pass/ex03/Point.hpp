/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:28:39 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/17 19:34:08 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{

public:
	Point(void); 
	~Point(void);

	Point(Point const  &src);
	Point(float const x, float const y);
	Point(Fixed const x, Fixed const y);

	Point & operator=(Point & rhs);

	Fixed getx(void) const;
	Fixed gety(void) const;

	/* void setx(Fixed const value); */
	/* void sety(Fixed const value); */

private:
	Fixed const _x;
	Fixed const _y;

};

	bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
