/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:50:41 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/06 19:26:35 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

class BitcoinExchange{

	private:
			/* std::string _input; */
			std::map<std::string, std::string> _data;
			std::map<std::string, std::string> _input;

	public:
			BitcoinExchange(void);
			BitcoinExchange(std::string input);
			BitcoinExchange(BitcoinExchange const & src);
			~BitcoinExchange(void);

			const std::map<std::string, std::string> & getData(void) const;
			const std::map<std::string, std::string> & getInput(void) const;

			void addData(std::string file);
			void addInput(std::string file);
			std::string const checkDate(std::string date, bool isData);
			void printMap(std::map<std::string, std::string> map);


			
};

#endif
