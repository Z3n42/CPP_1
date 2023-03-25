/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:22:57 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/20 21:19:44 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
	/* this->_ideas = std::string[100]; */
	int i = -1;
	while (++i < 100)
		this->_ideas[i] = " Idea"; 
	std::cout << "An animal has it's own Brain full of ideas" << std::endl;
}

Brain::~Brain(void){
	/* delete [] (this->_ideas); */
	std::cout << "An animal loosed his mind" << std::endl;
}

Brain::Brain(Brain const &src){
	*this  = src;
	std::cout << "Animal's brain has been copied." << std::endl;
}

Brain & Brain::operator=(Brain const & rhs){
	if (this != &rhs){
		std::cout << "Brain is equalized " << std::endl;
		/* this->_ideas = rhs._ideas; */
		int i = -1;
		while (++i < 100)
			this->_ideas[i] = rhs._ideas[i]; 
	}
	return(*this);
}

void Brain::getIdeas(void) const{
	int i = -1;
	while (++i < 100)
		std::cout << this->_ideas[i] << " n-" << i+1 << std::endl;
}

/* void Brain::setIdeas(std::string new_ideas){ */
/* 	this->_ideas = & new_ideas; */
/* } */
