/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:10:37 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/05 20:03:20 by ingonzal         ###   ########.fr       */
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

void BitcoinExchange::checkDate(std::string date){
	struct tm tm = {};

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm)){
		if (tm.tm_year < 2009 && tm_year > 2024){
			if (tm.tm_day == 31 && (tm.tm_mon < 10 && tm.tm_mon%2 == 0 || tm.tm_mon == 11))
				throw std::runtime_error("Invalid Date format");
			if (tm.tm)
	}
	else

}


void BitcoinExchange::addData(std::string file){
	if (file.substr(file.find_last_of(".") + 1) == "csv"){
		size_t pos;
		size_t endpos;
		std::string date;
		std::string line;

		std::ifstream myfile(file);

		if (myfile.is_open()){
			while (std::getline(myfile,line)){
				if (line == "date,exchange_rate")
					continue;
				pos = line.find(',');
				endpos = line.find('\n');
				date = line.substr(0, pos);
				checkDate(date);
				/* std::cout << "date => " << date << std::endl; */
				this->_data.insert(std::make_pair(date, line.substr(pos + 1, endpos)));
			}
			myfile.close();
		  }
		  else std::cout << "Unable to open file" << std::endl; 
		}
	  else 
		throw std::runtime_error("Invalid Data extension");
}

void BitcoinExchange::addInput(std::string file){
	std::string ext;

	ext = file.substr(file.find_last_of(".") + 1);
	if (ext == "txt" || ext == "csv" ){
		size_t pos;
		size_t endpos;
		std::string line;
		std::ifstream myfile(file);
		if (myfile.is_open()){
			while (std::getline(myfile,line)){
				if (line == "date | value")
					continue;
				pos = line.find('|');
				endpos = line.find('\n');
				this->_input.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1, endpos)));
			}
			myfile.close();
		  }
		  else std::cout << "Unable to open file" << std::endl; 
		}
	  else 
		throw std::runtime_error("Invalid Input extension");
}

void BitcoinExchange::printMap(std::map<std::string, std::string> map){;
	for(std::map<std::string, std::string >::const_iterator it = map.begin();
    it != map.end(); ++it){
    /* std::cout << (*it) << "\n"; */
		std::cout << (*it).first << ":" << (*it).second << std::endl;
    /* std::cout << it->first << " " << it->second.first << " " << it->second.second << "\n"; */
	}
}
