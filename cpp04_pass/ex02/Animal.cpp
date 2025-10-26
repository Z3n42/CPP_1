/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:33:06 by ingonzal          #+#    #+#             */
/*   Updated: 2023/02/25 19:50:46 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void){
	this->type = "Animal";
	std::cout << this->type << " has been born" << std::endl;
}

AAnimal::AAnimal(std::string Type) : type(Type){
	std::cout << this->type << " has been released" << std::endl;
} 

AAnimal::~AAnimal(void){
	this->type = "Animal";
	std::cout << this->type << " has been captured" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src){
	*this = src;
	std::cout << this->type << " has been copied." << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & rhs){
	if (this != &rhs){
		std::cout << this->type << " Equalized to " << rhs.type << std::endl;
		this->type = rhs.getType();
	}
	return(*this);
}

std::string AAnimal::getType(void) const{
	return(this->type);
}

void AAnimal::setType(std::string new_type){
	this->type = new_type;
}

void AAnimal::makeSound(void) const{
	std::cout << this->type << " says: \"I'm an animal\"" << std::endl;
}
