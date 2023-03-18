/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:13:11 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/18 19:37:11 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include "IMateriaSource.hpp"

Ice::Ice(void) : AMateria("ice"){
	/* this->_type = "ice"; */
	std::cout << this->_type << " crafted\n";
}

Ice::Ice(Ice const & ref) : _type(ref.getType()){
	std::cout << this->_type << " copied\n";
}

Ice & Ice::operator=(Ice const & ref){
	std::cout << "Equalized from " << ref.getType() << std::endl;
	return (*this);
}

Ice::~Ice(void){
	std::cout << this->_type << " uncrafted\n";
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
