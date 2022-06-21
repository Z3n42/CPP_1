/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 17:35:53 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/13 18:47:58 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main(void) {

	Fixed		a;
	Fixed	 	b(Fixed(5.05f) * Fixed(2));


	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a + 1, b) << std::endl;

	/* *Pruebas propias* */
	/* >, < */
	/* if(a > b) */
	/* 	std::cout << "true" << std::endl; */
	/* else */
	/* 	std::cout << "false" << std::endl; */
	/* if(a < b) */
	/* 	std::cout << "true" << std::endl; */
	/* else */
	/* 	std::cout << "false" << std::endl; */

	/* >=, <= */
	/* if(a >= b) */
	/* 	std::cout << "true" << std::endl; */
	/* else */
	/* 	std::cout << "false" << std::endl; */
	/* if(a <= b) */
	/* 	std::cout << "true" << std::endl; */
	/* else */
	/* 	std::cout << "false" << std::endl; */

	/* ==, != */
	/* if(a == b) */
	/* 	std::cout << "true" << std::endl; */
	/* else */
	/* 	std::cout << "false" << std::endl; */
	/* if(a != b) */
	/* 	std::cout << "true" << std::endl; */
	/* else */
	/* 	std::cout << "false" << std::endl; */

	/* +, =, *, / */
	/* std::cout << a + b << std::endl; */
	/* std::cout << a - b << std::endl; */
	/* std::cout << a * b << std::endl; */
	/* std::cout << a / b << std::endl; */


	return 0;
}
