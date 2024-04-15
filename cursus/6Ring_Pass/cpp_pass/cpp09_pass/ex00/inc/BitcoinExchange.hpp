/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:50:41 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/29 16:43:10 by ingonzal         ###   ########.fr       */
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
			std::map<std::string, double> _data;

	public:
			BitcoinExchange(void);
			BitcoinExchange(BitcoinExchange const & src);
			~BitcoinExchange(void);

			BitcoinExchange& operator=(const BitcoinExchange &rhs);

			const std::map<std::string, double> & getData(void) const;
			const std::map<std::string, double> & getInput(void) const;

			void addData(std::string file);
			void addInput(std::string file);
			std::string const checkDate(std::string date, bool isData);
			std::string trim(const std::string &s);
			std::pair<std::string, double> ClKeyVal(std::string &line, bool isData);


			template<typename T, typename U>
			void printMap(std::map<T, U> map){
				for(typename std::map<T, U>::const_iterator it = map.begin();
				it != map.end(); ++it)
					std::cout << (*it).first << ":" << std::setprecision(std::numeric_limits<U>::digits10) << (*it).second << std::endl;
			}

			template<typename T, typename U>
			void printPair(std::pair<T, U> pair){
			typename std::map<T,U>::iterator itlow;
			itlow = this->_data.upper_bound(pair.first);
				std::cout << pair.first << " => " << std::setprecision(std::numeric_limits<U>::digits10) << pair.second << " = " << this->_data[(*--itlow).first] * pair.second  << std::endl;
			}
};
#endif
