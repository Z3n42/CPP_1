/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:10:37 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/01 18:58:43 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(void){

}

/* BitcoinExchange::BitcoinExchange(std::string input){ */

/* }; */

/* BitcoinExchange::BitcoinExchange(BitcoinExchange const & src){ */

/* }; */

BitcoinExchange::~BitcoinExchange(void){

}

void BitcoinExchange::getData(std::string file){
	size_t pos;
	size_t endpos;
	std::string line;
	std::ifstream myfile(file);
	if (myfile.is_open()){
		while (std::getline(myfile,line)){
			pos = line.find(',');
			endpos = line.find('\n');
			this->_map.insert(std::pair<std::string, std::string>(line.substr(0, pos), line.substr(pos + 1, endpos)));
		}
		myfile.close();
	  }
	  else std::cout << "Unable to open file" << std::endl; 
}

void BitcoinExchange::printMap(void){
	for(std::map<std::string, std::string >::const_iterator it = this->_map.begin();
    it != this->_map.end(); ++it){
    /* std::cout << (*it) << "\n"; */
		std::cout << (*it).first << ":" << (*it).second << std::endl;
    /* std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n"; */
	}
}
