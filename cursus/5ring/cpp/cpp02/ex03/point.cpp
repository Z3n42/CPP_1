/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:39:04 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/18 18:39:47 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0){
}


Point::~Point(void){
}

Point::Point(Point const & src): _x(src.getx()), _y(src.gety()){
}

Point::Point(float const x, float const y): _x(x), _y(y){
}

Point::Point(Fixed const x, Fixed const y): _x(x), _y(y){
}

/* Posible copy constructor ** Doesn't work */ 
/* Point::Point(Point &src) { */
/* 	std::cout << "Copy" << std::endl; */
/* 	*this = src; */
/* } */

Point &Point::operator=(Point & rhs){
	return (rhs);
}


Fixed Point::getx(void) const{
	return(this->_x);
}

Fixed Point::gety(void) const{
	return(this->_y);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){

	Fixed a_x = a.getx();
	Fixed a_y = a.gety();
	Fixed b_x = b.getx();
	Fixed b_y = b.gety();
	Fixed c_x = c.getx();
	Fixed c_y = c.gety();
	Fixed p_x = point.getx();
	Fixed p_y = point.gety();

	Fixed d_x = b_x - a_x;
	Fixed d_y = b_y - a_y;
	Fixed e_x = c_x - a_y;
	Fixed e_y = c_y - a_y;

	Fixed w1((e_x * (a_y - p_y) + e_y * (p_x - a_x)) / (d_x * e_y - d_y * e_x));
	Fixed w2((p_y - a_y - w1 * d_y) / e_y);

	if ((w1 > 0) && (w2 > 0) && ((w1 + w2) < 1))
		return (true);
	return (false);
}

/* Other way */
	/* Fixed *w1 = new Fixed((e_x * (a_y - p_y) + e_y * (p_x - a_x)) / (d_x * e_y - d_y * e_x)); */
	/* Fixed *w2 = new Fixed((p_y - a_y - *w1 * d_y) / e_y); */
