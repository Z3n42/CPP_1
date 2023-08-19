/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:44:48 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/19 20:45:05 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RNP.hpp"

void initRnp(char **argv){

	Rnp a(argv[1]);
	std::cout << a << std::endl;
}

int main(int argc, char** argv){
	if (argc == 2){
		try{
			initRnp(argv);
		}
		catch(std::runtime_error &e){
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	else
		std::cout << RED << "Error" << RESET << std::endl;
  return 0;
}
