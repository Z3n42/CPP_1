/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:20:01 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/19 20:44:56 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RNP.hpp"


Rnp::Rnp(void){

}

Rnp::Rnp(std::string input){
	for(std::string::iterator it = input.begin(); it != input.end(); it++){
		if (!checkInput(*it)){
			std::string c(1, *it);
			throw std::runtime_error("Error: bad input => " + c);
		}
		if (!isspace(*it))
			this->_stack.push(*it);
	}
}

Rnp::Rnp(Rnp const & src){
	*this = src;
}

Rnp::~Rnp(void){

}

Rnp& Rnp::operator=(const Rnp &rhs){
	this->_stack = rhs.getStack();
	return (*this);
}

const std::stack<char> & Rnp::getStack(void) const{
	return(this->_stack);
}

bool Rnp::checkInput(char c){
	char opt[] = {'+', '-', '/', '*'};

	if(!isdigit(c) and !std::count(opt, opt+sizeof(opt), c) and !isspace(c))
		return(false);
	return(true);
}


int Rnp::calculus(void){

	int 	a;
	int 	b;
	char 	c

	for 
	if(isdigit(this->_stack.top())
		
}

std::ostream & operator<<(std::ostream & o, Rnp const & ref){
	std::stack<char> tmp = ref.getStack();
	unsigned int i;
	i = tmp.size() - 1;
	std::cout << std::endl;
	std::cout << "Stack capacity " << tmp.size() << " elementes max" << std::endl;
	std::cout << GREEN << "####################" << RESET << std::endl;
	  while (tmp.size()){
		std::cout << "[" << i << "]" << tmp.top() << std::endl;
		tmp.pop();
		i--;
	  }
	std::cout << RED << "####################" << RESET << std::endl;
	std::cout << std::endl;
	return (o);
}
/* const std::stack<std::string, double> & Rnp::getInput(void) const{ */
/* 	return(this->_input); */
/* } */
