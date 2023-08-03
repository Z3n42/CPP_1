/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:10:37 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/03 19:23:41 by ingonzal         ###   ########.fr       */
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

const std::map<std::string, std::string> & BitcoinExchange::getData(void) const{
	return(this->_data);
}

const std::map<std::string, std::string> & BitcoinExchange::getInput(void) const{
	return(this->_input);
}

void BitcoinExchange::addData(std::string file){
	if (file.substr(file.find_last_of(".") + 1) == "csv"){
		size_t pos;
		size_t endpos;
		std::string line;
		std::ifstream myfile(file);
		if (myfile.is_open()){
			while (std::getline(myfile,line)){
				pos = line.find(',');
				endpos = line.find('\n');
				this->_data.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1, endpos)));
			}
			myfile.close();
		  }
		  else std::cout << "Unable to open file" << std::endl; 
		}
	  else std::cout << "Bad data_file extension" << std::endl; 
}

void BitcoinExchange::addInput(std::string file){
	if (file.substr(file.find_last_of(".") + 1) == "txt"){
		size_t pos;
		size_t endpos;
		std::string line;
		std::ifstream myfile(file);
		if (myfile.is_open()){
			while (std::getline(myfile,line)){
				pos = line.find('|');
				endpos = line.find('\n');
				this->_input.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1, endpos)));
			}
			myfile.close();
		  }
		  else std::cout << "Unable to open file" << std::endl; 
		}
	  else std::cout << "Bad data_file extension" << std::endl; 
}

void BitcoinExchange::printMap(std::map<std::string, std::string> map){;
	for(std::map<std::string, std::string >::const_iterator it = map.begin();
    it != map.end(); ++it){
    /* std::cout << (*it) << "\n"; */
		std::cout << (*it).first << ":" << (*it).second << std::endl;
    /* std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n"; */
	}
}
