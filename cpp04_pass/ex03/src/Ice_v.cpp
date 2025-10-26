/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:13:11 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/22 20:39:26 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

/* Comments only with a virtual getter at the base class */

Ice::Ice(void) : AMateria("ice"){
	/* this->_type = "ice"; */
	std::cout << getType() << " crafted\n";
}

Ice::Ice(Ice const & src) : AMateria(src.getType()){
	/* src.clone() */
	std::cout << getType() << " copied\n";
}

Ice & Ice::operator=(Ice const & rhs){
	std::cout << "Equalized from " << rhs.getType() << std::endl;
	return (*this);
}

Ice::~Ice(void){
	std::cout << getType() << " uncrafted\n";
}

/* std::string const & Ice::getType( void ) const{ */
/* 	return (this->_type); */
/* } */

Ice *Ice::clone() const{
	Ice *ice = new Ice;
	return (ice);
}

void Ice::use(ICharacter& target){
	std::string target_name = target.getName();

	std::cout << " shoots an ice bolt at " << target_name << std::endl;
}
