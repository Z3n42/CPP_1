/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:22:57 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 20:40:05 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
	this->ideas = new std::string[100];
	int i = -1;
	while (i++ <= 100)
		this->ideas[i] = " Idea"; 
	std::cout << "An animal has it's own Brain full of ideas" << std::endl;
}

Brain::~Brain(void){
	delete [] (this->ideas);
	std::cout << "An animal loosed his mind" << std::endl;
}

Brain::Brain(Brain const &src){
	this->ideas = src.ideas;
	std::cout << "Animal's brain has been copied." << std::endl;
}

Brain & Brain::operator=(Brain const & rhs){
	if (this != &rhs){
		std::cout << "Brain is equalized " << std::endl;
		this->ideas = rhs.ideas;
		int i = -1;
		while (i++ <= 100)
			this->ideas[i] = rhs.ideas[i]; 
	}
	return(*this);
}

std::string *Brain::getIdeas(void) const{
	return(this->ideas);
}

void Brain::setIdeas(std::string new_ideas){
	this->ideas = & new_ideas;
}
