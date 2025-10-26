/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:16:20 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/22 20:06:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void){
	this->type = "Dog";
	this->_Brain = new Brain();
	std::cout << this->type << " has been born with his brain full of ideas" << std::endl;
}

Dog::Dog(std::string Type) : AAnimal(Type){
	this->_Brain = new Brain();
	std::cout << this->type << " has been released" << std::endl;
} 

Dog::~Dog(void){
	delete this->_Brain;
	std::cout << this->type << " has been captured" << std::endl;
}

Dog::Dog(Dog const &src){
	_Brain = NULL;
	*this = src;
	std::cout << this->type << " has been copied." << std::endl;
}

Dog & Dog::operator=(Dog const & rhs){
	if (this != &rhs){
		std::cout << this->type << " Equalized to " << rhs.type << std::endl;
		this->type = rhs.getType();
		if (this->_Brain)
			delete (this->_Brain);
		this->_Brain = new Brain(*rhs._Brain);
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

void Dog::getIdeasFromBrain(void) const{
	std::cout << "From " << this->type << std::endl;
	(this->_Brain->getIdeas());
}

/* ####### TEST METHODS ######## */

Brain *Dog::getBrain( void ) const{
	return (this->_Brain);
}

void Dog::compareTo(Dog const & other_dog) const{
	std::cout << std::endl;
	std::cout << "Now comparing two dogs\n";
	std::cout << "My brain's heap address: " << static_cast<void*>(this->_Brain) << std::endl;
	std::cout << "Other's heap address: " << static_cast<void*>(other_dog.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "######### My brain's ideas ##########" << std::endl;
	this->getIdeasFromBrain();
	std::cout << "###### Other brain's ideas ##########" << std::endl;
	other_dog.getIdeasFromBrain();
	std::cout << std::endl;
}
