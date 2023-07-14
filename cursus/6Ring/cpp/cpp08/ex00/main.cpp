/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:45:17 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/14 18:05:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	try{
		int iarray[] = {2, 3, 4, 2, 45, 3, 4};

		std::vector<int> ivec(iarray, iarray + sizeof(iarray) / sizeof(iarray[0]));
		easyfind(ivec, 4);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}

	try{
		int iarray[] = {2, 3, 4, 2, 45, 3, 4};

		std::vector<int> ivec(iarray, iarray + sizeof(iarray) / sizeof(iarray[0]));
		easyfind(ivec, 7);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}

	try{
		char carray[] = {'a', 'c', 'f', 'g', '*', 'z', 'e', 'f'};

		std::vector<char> cavec(carray, carray + sizeof(carray) / sizeof(carray[0]));
		easyfind(cavec, 42);
	}
	catch(std::runtime_error &e){
		std::cout << e.what() << std::endl;
	}
}
