/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 18:20:01 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/20 16:59:15 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"


Rpn::Rpn(void){

}

Rpn::Rpn(std::string input) : _input(input){

}

Rpn::Rpn(Rpn const & src){
	*this = src;
}

Rpn::~Rpn(void){

}

Rpn& Rpn::operator=(const Rpn &rhs){
	this->_input = rhs.getInput();
	this->_stack = rhs.getStack();
	return (*this);
}

const std::stack<int> & Rpn::getStack(void) const{
	return(this->_stack);
}

const std::string & Rpn::getInput(void) const{
	return(this->_input);
}

bool Rpn::checkInput(char c){
	char opt[] = {'+', '-', '/', '*'};

	if(!isdigit(c) and !std::count(opt, opt+sizeof(opt), c) and !isspace(c))
		return(false);
	return(true);
}


void Rpn::calculus(void){

	for(std::string::iterator it = this->_input.begin();
			it != this->_input.end(); it++){
		if (!checkInput(*it)){
			std::string c(1, *it);
			throw std::runtime_error("Error: bad input => " + c + "\n");
		}
		if (!isspace(*it)){
			if (isdigit(*it))
				this->_stack.push(*it - '0');
			else {
				int num2;
			    num2 = this->_stack.top();
				this->_stack.pop();
				int num1; 
				num1 = this->_stack.top();
				this->_stack.pop();
				switch(*it){
					case '+':
						this->_stack.push(num1 + num2);
						break;
					case '-':
						this->_stack.push(num1 - num2);
						break;
					case '/':
						this->_stack.push(num1 / num2);
						break;
					default:
						this->_stack.push(num1 * num2);
					}
			}
		}
	}
	std::cout << GREEN << this->_stack.top() << RESET << std::endl;
}

