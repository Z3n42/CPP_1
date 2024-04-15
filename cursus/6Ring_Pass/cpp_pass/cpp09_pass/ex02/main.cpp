/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:05:20 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/29 16:24:35 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char** argv){
	if (argc >= 2){
		PmergeMe a;
		try{
			a.initPmergeMe(argc, argv);
			a.printContainers();
			a.mergeInsertSort();
		}
		catch(std::runtime_error &e){
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	else
		std::cout << RED << "Error: wrong number of arguments" << RESET << std::endl;
  return 0;
}
