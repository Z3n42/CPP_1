/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:29:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/20 20:01:17 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(void){

}

PmergeMe::PmergeMe(std::string input) : _input(input){

}

PmergeMe::PmergeMe(PmergeMe const & src){
	*this = src;
}

PmergeMe::~PmergeMe(void){

}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs){
	this->_vector = rhs.getVector();
	this->_deque = rhs.getDeque();
	return (*this);
}

const std::vector<unsigned int> & PmergeMe::getVector(void) const{
	return(this->_vector);
}

const std::deque<unsigned int> & PmergeMe::getDeque(void) const{
	return(this->_deque);
}

const std::string & PmergeMe::getInput(void) const{
	return(this->_input);
}
