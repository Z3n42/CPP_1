/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 17:10:37 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/29 16:43:31 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(void){

}


BitcoinExchange::BitcoinExchange(BitcoinExchange const & src){
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void){

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs){
	this->_data = rhs.getData();
	return (*this);
}

const std::map<std::string, double> & BitcoinExchange::getData(void) const{
	return(this->_data);
}


std::string const BitcoinExchange::checkDate(std::string date, bool isData = false){

	struct tm tm = {};

	if (!strptime(date.c_str(), "%Y-%m-%d", &tm)){
		if (isData)
			throw std::runtime_error("Error: bad data => " + trim(date));
		throw std::runtime_error("Error: bad input => " + trim(date));
	}

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
	if ((year < 2009 or year >= 2024) or (year == 2009 and mon == 1 and day < 2)){
		if (isData)
			throw std::runtime_error("Error: bad data => " + trim(date));
		throw std::runtime_error("Error: bad input => " + trim(date));
	}
	if (day == 31 and ((mon < 12 and mon%2 == 0) and (mon != 8 and mon != 10))){
		if (isData)
			throw std::runtime_error("Error: bad data => " + trim(date));
		throw std::runtime_error("Error: bad input => " + trim(date));
	}
	if (mon == 2 and (day > 29 or (day == 29 and leap == false))){
		if (isData)
			throw std::runtime_error("Error: bad data => " + trim(date));
		throw std::runtime_error("Error: bad input => " + trim(date));
	}
	return ("");
}

std::pair<std::string, double> BitcoinExchange::ClKeyVal(std::string &line, bool isData = false){

		std::string key;
		double value;
		char *endPtr;
		char sep;
		
		sep = '|';
		if (isData)
			sep = ',';
		if (count(line.begin(), line.end(), sep) != 1 or
				count(line.begin(), line.end(), '.') > 1 or
				ispunct(*(--trim(line).end())))
			throw std::runtime_error("Error: bad input => " + trim(line));
		key = trim(line.substr(0, line.find(sep)));
		checkDate(key, isData);
		value = strtod(trim(line.substr(line.find(sep)+1, line.find('\n'))).data(), &endPtr);
		if (*endPtr)
			throw std::runtime_error("Error: bad input => " + trim(line));
		if (value < 0)
			throw std::runtime_error("Error: not a positive number");
		if (value > 1000 and not isData)
			throw std::runtime_error("Error: too large a number.");

		return (std::make_pair(key, value));
}

void BitcoinExchange::addData(std::string file){
	if (file.substr(file.find_last_of(".") + 1) != "csv")
		throw std::runtime_error("Error: bad file => " + file);
	std::string line;
	int lnbr;

	lnbr = 0;
	std::ifstream myfile(file);

	if (myfile.is_open()){
		while (std::getline(myfile,line)){
			if (line == "date,exchange_rate" and lnbr == 0)
				continue;
			this->_data.insert(ClKeyVal(line, true));
			lnbr++;
		}
		myfile.close();
		if (lnbr == 0)
		  throw std::runtime_error("Error: bad file => " + file);
	  }
	  else throw std::runtime_error("Error: bad file => " + file);
}

void BitcoinExchange::addInput(std::string file){
	std::string ext;

	ext = file.substr(file.find_last_of(".") + 1);
	if (ext != "txt" and ext != "csv" )
		throw std::runtime_error("Error: bad file => " + file);
	std::string line;
	int lnbr;

	lnbr = 0;
	std::ifstream myfile(file);

	if (myfile.is_open()){
		while (std::getline(myfile,line)){
			if (line.empty())
				throw std::runtime_error("Error: bad file => " + file);
			if (line == "date | value" and lnbr == 0)
				continue;
			try {
				ClKeyVal(line);
			}
			catch(std::exception &e){
				std::cout << e.what() << std::endl;
				continue;
			}
			printPair(ClKeyVal(line));
			lnbr++;
		}
		myfile.close();
		if (lnbr == 0)
		  throw std::runtime_error("Error: bad file => " + file);
	  }
	  else throw std::runtime_error("Error: bad file => " + file);
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
