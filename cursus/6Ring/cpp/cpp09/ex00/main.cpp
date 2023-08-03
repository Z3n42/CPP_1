/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:44:48 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/03 19:23:48 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(void){
	BitcoinExchange btc;
	btc.addData("Data.csv");
	btc.addInput("input.txt");
	btc.printMap(btc.getData());
	btc.printMap(btc.getInput());

  return 0;
}
