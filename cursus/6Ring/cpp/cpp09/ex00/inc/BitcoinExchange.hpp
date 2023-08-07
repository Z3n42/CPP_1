/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:50:41 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/07 19:28:13 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <exception>
#include <algorithm>
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
			std::map<std::string, double> _data;
			std::map<std::string, std::string> _input;

	public:
			BitcoinExchange(void);
			BitcoinExchange(std::string input);
			BitcoinExchange(BitcoinExchange const & src);
			~BitcoinExchange(void);

			const std::map<std::string, double> & getData(void) const;
			const std::map<std::string, std::string> & getInput(void) const;

			void addData(std::string file);
			void addInput(std::string file);
			std::string const checkDate(std::string date, bool isData);
			std::string trim(const std::string &s);
			std::pair<std::string, double> ClKeyVal(std::string &line);

			template<typename T, typename U>
			void printMap(std::map<T, U> map){
				for(typename std::map<T, U>::const_iterator it = map.begin();
				it != map.end(); ++it){
				/* std::cout << (*it) << "\n"; */
					std::cout << (*it).first << ":" << std::setprecision(std::numeric_limits<U>::digits10 + 1)  << (*it).second << std::endl;
				/* std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n"; */
				}
			}
};
#endif
