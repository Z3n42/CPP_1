/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:16:20 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 18:17:52 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
	this->type = "Dog";
	std::cout << this->type << " has been born" << std::endl;
}

Dog::Dog(std::string Type) : Animal(Type){
	std::cout << this->type << " has been released" << std::endl;
} 

Dog::~Dog(void){
	std::cout << this->type << " has been captured" << std::endl;
}

Dog::Dog(Dog const &src){
	this->type = src.type;
	std::cout << this->type << " has been copied." << std::endl;
}

Dog & Dog::operator=(Dog const & rhs){
	if (this != &rhs){
		std::cout << this->type << " Equalized to " << rhs.type << std::endl;
		this->type = rhs.getType();
	}
	return(*this);
}

std::string Dog::getType(void) const{
	return(this->type);
}

void Dog::setType(std::string new_type){
	this->type = new_type;
}

void Dog::makeSound(void) const{
	std::cout << this->type << " says: \"WOOOOF\"" << std::endl;
}
