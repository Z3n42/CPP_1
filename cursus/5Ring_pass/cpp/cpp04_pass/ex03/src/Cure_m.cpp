/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:00:01 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/22 20:37:01 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

/* Comments only with a virtual getter at the base class */

Cure::Cure(void) : AMateria("cure"){
	/* this->_type = "cure"; */
	/* std::cout << getType() << " crafted\n"; */
}

Cure::Cure(Cure const & src) : AMateria(src.getType()){
	/* src.clone() */
	/* std::cout << getType() << " copied\n"; */
}

Cure & Cure::operator=(Cure const & rhs){
	/* std::cout << "Equalized from " << rhs.getType() << std::endl; */
	return (*this);
}

Cure::~Cure(void){
	/* std::cout << getType() << " uncrafted\n"; */
}

/* std::string const & Cure::getType( void ) const{ */
/* 	return (this->_type); */
/* } */

Cure *Cure::clone() const{
	Cure *cure = new Cure;
	return (cure);
}

void Cure::use(ICharacter& target){

	std::cout << "* heals " << target.getName() << "\'s wounds *" << std::endl;
}
