/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:34:16 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/22 20:13:14 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void){
	this->type = "Cat";
	this->_Brain = new Brain();
	std::cout << this->type << " has been born with his brain full of ideas" << std::endl;
}

Cat::Cat(std::string Type) : AAnimal(Type){
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


/* ####### TEST METHODS ######## */

Brain *Cat::getBrain( void ) const{
	return (this->_Brain);
}

void Cat::compareTo(Cat const & other_cat) const{
	std::cout << std::endl;
	std::cout << "Now comparing two cats\n";
	std::cout << "My brain's heap address: " << static_cast<void*>(this->_Brain) << std::endl;
	std::cout << "Other's heap address: " << static_cast<void*>(other_cat.getBrain()) << std::endl;
	std::cout << std::endl;
	std::cout << "######### My brain's ideas ##########" << std::endl;
	this->getIdeasFromBrain();
	std::cout << "###### Other brain's ideas ##########" << std::endl;
	other_cat.getIdeasFromBrain();
	std::cout << std::endl;
}
