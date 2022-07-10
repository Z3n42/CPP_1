/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:34:16 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 18:18:13 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat(void){
	this->type = "Cat";
	std::cout << this->type << " has been born" << std::endl;
}

Cat::Cat(std::string Type) : Animal(Type){
	std::cout << this->type << " has been released" << std::endl;
} 

Cat::~Cat(void){
	std::cout << this->type << " has been captured" << std::endl;
}

Cat::Cat(Cat const &src){
	this->type = src.type;
	std::cout << this->type << " has been copied." << std::endl;
}

Cat & Cat::operator=(Cat const & rhs){
	if (this != &rhs){
		std::cout << this->type << " Equalized to " << rhs.type << std::endl;
		this->type = rhs.getType();
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
