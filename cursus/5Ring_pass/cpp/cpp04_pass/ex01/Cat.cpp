/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:34:16 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/20 21:19:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void){
	this->type = "Cat";
	this->_Brain = new Brain();
	std::cout << this->type << " has been born with his brain full of ideas" << std::endl;
}

Cat::Cat(std::string Type) : Animal(Type){
	std::cout << this->type << " has been released" << std::endl;
} 

Cat::~Cat(void){
	delete this->_Brain;
	std::cout << this->type << " has been captured" << std::endl;
}

Cat::Cat(Cat const &src){
	_Brain = NULL;
	*this = src;
	std::cout << this->type << " has been copied." << std::endl;
}

Cat & Cat::operator=(Cat const & rhs){
	if (this != &rhs){
		std::cout << this->type << " Equalized to " << rhs.type << std::endl;
		this->type = rhs.getType();
		if (this->_Brain)
			delete (this->_Brain);
		this->_Brain = new Brain(*rhs._Brain);
	}
	return(*this);
}

std::string Cat::getType(void) const{
	return(this->type);
}

void Cat::setType(std::string new_type){
	this->type = new_type;
}

void Cat::makeSound(void) const{
	std::cout << this->type << " says: \"MEOOOOW\"" << std::endl;
}

void Cat::getIdeasFromBrain(void) const{
	std::cout << "From " << this->type << std::endl;
	(this->_Brain->getIdeas());
}
