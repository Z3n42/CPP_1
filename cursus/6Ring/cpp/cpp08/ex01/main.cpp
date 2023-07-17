/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 14:24:30 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/17 19:00:02 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void){
	Span a(6);

	try{
		a.addNumber(2);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{
		a.addNumber(3);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{
		a.addNumber(4);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{
		a.addNumber(5);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{
		a.addNumber(6);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{
		a.addNumber(7);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	try{
		a.addNumber(8);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
	Span b(a);
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	return (0);
}
