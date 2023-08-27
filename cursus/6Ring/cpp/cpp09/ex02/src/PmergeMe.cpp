/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:29:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/27 19:57:43 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(void){

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


bool isNumber(const std::string & s){

	int i;

	i = 0;
    while (s[i]) {
        if (std::isdigit(s[i]) == 0) 
            return false;
		i++;
    }
    return true;
 }

void PmergeMe::initPmergeMe(int max, char** nums){

	int 			i;
	unsigned int 	temp;

	for (i = 1; i <= (max - 1); i++){
		std::istringstream ss(nums[i]);
		if(!isNumber(nums[i]) or !(ss >> temp) or temp > INT_MAX)
			throw std::runtime_error("Error: not a positive integer");
		if ((max - 1) % 2 != 0 and i == (max - 1)){
			this->_straggler = temp;
			this->_isOdd = true;
			break;
		}
		this->_vector.push_back(temp);
		this->_deque.push_back(temp);
	}
}

void PmergeMe::printContainers(void){
	std::cout << std::endl;
	std::cout << typeid(this->_vector).name() << std::endl;
	/* std::sort(this->_vector.begin(), this->_vector.end()); */
	for(std::vector<unsigned int>::const_iterator vit = this->_vector.begin();
	vit != this->_vector.end(); ++vit)
		std::cout << (*vit) << " ";
	std::cout << std::endl;
	std::cout << this->_isOdd << std::endl;
	std::cout << "straggler => " << this->_straggler; 
	std::cout << std::endl;

	std::cout << typeid(this->_deque).name() << std::endl;
	for(std::deque<unsigned int>::const_iterator dit = this->_deque.begin();
	dit != this->_deque.end(); ++dit)
		std::cout << (*dit) << " ";
	std::cout << std::endl;
	std::cout << this->_isOdd << std::endl;
	std::cout << "straggler => " << this->_straggler; 
	std::cout << std::endl;
}



/* TODO: upper_bound to insert using binary search */
