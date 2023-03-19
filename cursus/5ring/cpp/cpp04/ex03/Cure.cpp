/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:00:01 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/19 18:25:13 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Cure::Cure(void) : AMateria("cure"){
	this->_type = "cure";
	std::cout << this->_type << " crafted\n";
}

Cure::Cure(Cure const & src) : _type(src.getType()){
	std::cout << this->_type << " copied\n";
}

Cure & Cure::operator=(Cure const & rhs){
	std::cout << "Equalized from " << rhs.getType() << std::endl;
	return (*this);
}

Cure::~Cure(void){
	std::cout << this->_type << " uncrafted\n";
}

std::string const & Cure::getType( void ) const{
	return (this->_type);
}

Cure *Cure::clone() const{
	Cure *cure = new Cure;
	return (cure);
}

void Cure::use(ICharacter& target){
	std::string target_name = target.getName();

	std::cout << " heals " << target_name << "\'s wounds" << std::endl;
}
