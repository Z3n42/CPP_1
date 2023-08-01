/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:50:41 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/01 18:58:47 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <map>

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

class BitcoinExchange{

	private:
			std::string _input;
			std::map<std::string, std::string> _map;

	public:
			BitcoinExchange(void);
			BitcoinExchange(std::string input);
			BitcoinExchange(BitcoinExchange const & src);
			~BitcoinExchange(void);

			void getData(std::string file);
			void printMap(void);


			
};

#endif
