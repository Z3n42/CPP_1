/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:44:48 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/04 18:50:22 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char** argv){
	if (argc != 2){
		initBtc(argv);
	}
	else
		std::cout << "invalid arguments" << std::endl;

	BitcoinExchange btc;
	btc.addData("Data.csv");
	btc.addInput("input.txt");
	btc.printMap(btc.getData());
	btc.printMap(btc.getInput());

  return 0;
}
