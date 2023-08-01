/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:44:48 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/01 18:58:42 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(void){
	BitcoinExchange btc;
	btc.getData("Data.csv");
	btc.printMap();

  return 0;
}
