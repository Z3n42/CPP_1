/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:26:56 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/09 17:52:23 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	std::cout << std::endl;
	std::cout << "++++++++++++++++++++" << std::endl;
	Array<int>	empty;
	try{

		std::cout << "   [0] : " << empty[0] << std::endl;
	}
	catch (std::exception &e){

		std::cout << e.what() << std::endl << std::endl;
	}
	try{

		std::cout << "   [1] : " << empty[1] << std::endl;
	}
	catch (std::exception &e){

		std::cout << e.what() << std::endl;
	}
	try{

		empty[3] = 3;
	}
	catch (std::exception &e){

		std::cout << "   [3] = " << e.what() << std::endl;
	}
	std::cout << "++++++++++++++++++++" << std::endl;
	std::cout << std::endl;
	std::cout << "       EMPTY" << std::endl;
	std::cout << empty << std::endl;
	std::cout << "++++++++++++++++++++" << std::endl;

	std::cout << std::endl;
	std::cout << "      STRING" << std::endl;
	Array<std::string> strings(4);
	strings[0] = "zero";
	strings[2] = "Second";
	std::cout << strings << std::endl;
	std::cout << "++++++++++++++++++++" << std::endl;
	std::cout << std::endl;

	std::cout << "       INT" << std::endl;
	Array<int> ints(4);
	ints[1] = 42;
	ints[3] = -42;
	std::cout << ints << std::endl;
	std::cout << "++++++++++++++++++++" << std::endl;

	std::cout << std::endl;
	std::cout << "       CHAR" << std::endl;
	Array<char> chars(4);
	chars[0] = 'a';
	chars[2] = 'c';
	std::cout << chars << std::endl;
	std::cout << "++++++++++++++++++++" << std::endl;

	std::cout << std::endl;
	std::cout << "       FLOAT" << std::endl;
	Array<float> floats(4);
	floats[1] = -42.42f;
	floats[3] = 42.42f;
	std::cout << floats << std::endl;
	std::cout << "++++++++++++++++++++" << std::endl;
	std::cout << std::endl;

	system("leaks Array_ex02");
	return (0);
}

