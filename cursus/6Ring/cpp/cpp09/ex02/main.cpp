/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:05:20 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/20 20:01:21 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* void initRpn(std::string input){ */
/* 	if (input.compare("T35T") == 0) */
/* 		test(); */
/* 	else{ */
/* 		Rpn a(input); */
/* 		Rpn b(a); */
/* 		b.calculus(); */
/* 	} */
/* } */

/* void test(void){ */
/* 	std::string input[ ] */
/* 		= {"8 9 * 9 - 9 - 9 - 4 - 1 +", "7 7 * 7 -", "1 2 * 2 / 2 * 2 4 - +", "(1 + 1)"}; */

/* 	std::cout << std::endl; */
/* 	std::cout << "=========== Test Start ===========" << std::endl; */
/* 	std::cout << std::endl; */
/* 	for (int i = 0; i < 4; i++){ */
/* 		std::cout  << "\33[39m" << "./PmergeMe " << "\"" << input[i] << "\"" << std::endl; */
/* 		initRpn(input[i]); */
/* 	} */
/* } */

int main(int argc, char** argv){
	if (argc >= 2){
		try{
			initPmegeMe(argc, argv);
		}
		catch(std::runtime_error &e){
			std::cout << RED << e.what() << RESET << std::endl;
			std::cout << std::endl;
			system("leaks PmergeMe");	
			std::cout << std::endl;
		}
	}
	else
		std::cout << RED << "Error" << RESET << std::endl;
  return 0;
}
