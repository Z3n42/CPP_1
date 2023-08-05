/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:44:48 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/05 20:03:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void initBtc(char **argv){

	(void) argv;
	BitcoinExchange btc;

	btc.addData("Data.csv");
	/* btc.addInput(argv[1]); */
	btc.printMap(btc.getData());
	/* btc.printMap(btc.getInput()); */
}

int main(int argc, char** argv){
	if (argc == 2){
		try{
			initBtc(argv);
		}
		catch(std::runtime_error &e){
			std::cout << e.what() << std::endl << std::endl;
		}
	}
	else
		std::cout << "invalid arguments" << std::endl;
  return 0;
}
