/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:24:30 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/23 17:43:44 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void){
	Span a(5);
	Span c(50000);

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
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	c.generator();
	std::cout << "c.generator: " << std::endl; 
	std::cout << c << std::endl;

	try{
		std::cout << "a.short: " << a.shortestSpan() << std::endl;
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		std::cout << "a.long: " <<  a.longestSpan() << std::endl;
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		std::cout << "c.short: " << c.shortestSpan() << std::endl;
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	try{
		std::cout << "c.long: " << c.longestSpan() << std::endl;
	}
	catch(std::runtime_error &e){
		std::cout << RED << e.what() << RESET << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Leaks Summary :" << std::endl;
	system ("leaks Span");
	return (0);
}
