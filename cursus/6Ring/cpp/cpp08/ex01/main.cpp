/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:24:30 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/20 19:03:17 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void){
	Span a(5);

	try{
		a.addNumber(6);
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		a.addNumber(3);
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		a.addNumber(17);
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		a.addNumber(9);
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		a.addNumber(11);
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		a.addNumber(16);
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		a.addNumber(19);
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}

	Span b(a);
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try{
		std::cout << a.shortestSpan() << std::endl;
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		std::cout << a.longestSpan() << std::endl;
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
