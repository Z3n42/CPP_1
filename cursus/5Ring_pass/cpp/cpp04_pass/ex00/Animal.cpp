/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:33:06 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 18:18:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void){
	this->type = "Animal";
	std::cout << this->type << " has been born" << std::endl;
}

Animal::Animal(std::string Type) : type(Type){
	std::cout << this->type << " has been released" << std::endl;
} 

Animal::~Animal(void){
	this->type = "Animal";
	std::cout << this->type << " has been captured" << std::endl;
}

Animal::Animal(Animal const &src){
	this->type = src.type;
	std::cout << this->type << " has been copied." << std::endl;
}

Animal & Animal::operator=(Animal const & rhs){
	if (this != &rhs){
		std::cout << this->type << " Equalized to " << rhs.type << std::endl;
		this->type = rhs.getType();
	}
	return(*this);
}

std::string Animal::getType(void) const{
	return(this->type);
}

void Animal::setType(std::string new_type){
	this->type = new_type;
}

void Animal::makeSound(void) const{
	std::cout << this->type << " says: \"I'm an animal\"" << std::endl;
}
