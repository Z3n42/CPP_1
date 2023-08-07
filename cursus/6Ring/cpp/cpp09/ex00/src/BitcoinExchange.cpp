/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:10:37 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/07 19:28:15 by ingonzal         ###   ########.fr       */
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

const std::map<std::string, double> & BitcoinExchange::getData(void) const{
	return(this->_data);
}

const std::map<std::string, std::string> & BitcoinExchange::getInput(void) const{
	return(this->_input);
}

std::string const BitcoinExchange::checkDate(std::string date, bool isData = false){

	struct tm tm = {};

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		throw std::runtime_error("Invalid Date format");

	int year;
	int mon;
	int day;
	bool leap;

	year = tm.tm_year + 1900;
	mon = tm.tm_mon + 1;
	day = tm.tm_mday;
	leap = false;

	if (year%400 == 0 or (year%100 != 0 and year%4 == 0))
		leap = true;
	if (year < 2009 or year >= 2024){
		if (isData)
			throw std::runtime_error("Invalid year");
		return ("Invalid year");
	}
	if (day == 31 and ((mon < 12 and mon%2 == 0) and (mon != 8 and mon != 10))){
		if (isData)
			throw std::runtime_error("Invalid month days");
		return ("Invalid month days");
	}
	if (mon == 2 and (day > 29 or (day == 29 and leap == false))){
		if (isData)
			throw std::runtime_error("Invalid February days");
		return ("Invalid February days");
	}
	return ("");
}

std::pair<std::string, double> BitcoinExchange::ClKeyVal(std::string &line){
		std::string key;
		double value;

		if (count(line.begin(), line.end(), ',') > 1 or
				count(line.begin(), line.end(), '.') > 1)
			throw std::runtime_error("Invalid Data format");
		key = trim(line.substr(0, line.find(',')));
		value = atof(trim(line.substr(line.find(',')+1, line.find('\n'))).data());
		checkDate(key, true);

		return (std::make_pair(key, value));
}

void BitcoinExchange::addData(std::string file){
	if (file.substr(file.find_last_of(".") + 1) == "csv"){
		std::string line;

		std::ifstream myfile(file);

		if (myfile.is_open()){
			while (std::getline(myfile,line)){
				if (line == "date,exchange_rate")
					continue;
				this->_data.insert(ClKeyVal(line));
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
		/* size_t pos; */
		/* size_t endpos; */
		std::string line;
		std::ifstream myfile(file);
		if (myfile.is_open()){
			while (std::getline(myfile,line, ' ')){
				/* if (line == "date" or line = "|" or line = "value") */
				/* 	continue; */
				/* pos = line.find('|'); */
				/* endpos = line.find('\n'); */
				/* this->_input.insert(std::make_pair(line.substr(0, pos), line.substr(pos + 1, endpos))); */
				/* std::cout << line << std::endl; */
			}
			myfile.close();
		  }
		  else std::cout << "Unable to open file" << std::endl; 
		}
	  else 
		throw std::runtime_error("Invalid Input extension");
}


std::string ltrim(const std::string &s){
	const std::string WHITESPACE = " \n\r\t\f\v";
	size_t start = s.find_first_not_of(WHITESPACE);
	return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string &s){
	const std::string WHITESPACE = " \n\r\t\f\v";
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string BitcoinExchange::trim(const std::string &s) {
	return rtrim(ltrim(s));
}
