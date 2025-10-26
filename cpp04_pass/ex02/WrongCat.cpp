/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:45:35 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 17:45:59 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void){
	this->type = "WrongCat";
	std::cout << this->type << " has been born" << std::endl;
}

WrongCat::WrongCat(std::string Type) : WrongAnimal(Type){
	std::cout << this->type << " has been released" << std::endl;
} 

WrongCat::~WrongCat(void){
	std::cout << this->type << " has been captured" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src){
	*this = src;
	std::cout << this->type << " has been copied." << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs){
	std::cout << this->type << " Equalized to " << rhs.type << std::endl;
	this->type = rhs.getType();

	return(*this);
}

std::string WrongCat::getType(void) const{
	return(this->type);
}

void WrongCat::setType(std::string new_type){
	this->type = new_type;
}

void WrongCat::makeSound(void) const{
	std::cout << this->type << " says: \"WrongMEOOOOW\"" << std::endl;
}
