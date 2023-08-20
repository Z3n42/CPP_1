/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:44:48 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/20 15:24:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void initRpn(char **argv){

	Rpn a(argv[1]);
	a.calculus();
}

int main(int argc, char** argv){
	if (argc == 2){
		try{
			initRpn(argv);
		}
		catch(std::runtime_error &e){
			std::cout << RED << e.what() << RESET << std::endl;
		}
	}
	else
		std::cout << RED << "Error" << RESET << std::endl;
  return 0;
}
