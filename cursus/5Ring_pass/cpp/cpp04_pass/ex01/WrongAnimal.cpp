/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:31:09 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 17:31:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(void){
	this->type = "WrongAnimal";
	std::cout << this->type << " has been born" << std::endl;
}

WrongAnimal::WrongAnimal(std::string Type) : type(Type){
	std::cout << this->type << " has been released" << std::endl;
} 

WrongAnimal::~WrongAnimal(void){
	this->type = "WrongAnimal";
	std::cout << this->type << " has been captured" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src){
	*this = src;
	std::cout << this->type << " has been copied." << std::endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs){
	std::cout << this->type << " Equalized to " << rhs.type << std::endl;
	this->type = rhs.getType();

	return(*this);
}

std::string WrongAnimal::getType(void) const{
	return(this->type);
}

void WrongAnimal::setType(std::string new_type){
	this->type = new_type;
}

void WrongAnimal::makeSound(void) const{
	std::cout << this->type << " says: \"I'm NOT an animal\"" << std::endl;
}
