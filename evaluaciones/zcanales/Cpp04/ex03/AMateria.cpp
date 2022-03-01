/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:21:39 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:21:40 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
AMateria::AMateria(void): _available(0){
    _type = "Default";
    std::cout << "(AMateria) Default constructor called" << std::endl;
}
AMateria::AMateria(std::string const & type) : _type(type) , _available(0) {
    std::cout << "(AMateria) Parameter constructor called" << std::endl;
}
AMateria::AMateria(AMateria const &src){ 
    
    std::cout << "(AMateria) Copy constructor called" << std::endl;
    *this = src;
}
AMateria::~AMateria(void){
    std::cout << "(AMateria) Destructor called" << std::endl;
}
// ************************************************************************** //
//                    	       Accesories                                     //
// ************************************************************************** //
std::string const & AMateria::getType(void) const {
    return (this->_type);
}
 int const & AMateria::getAvailable() const{
     return (this->_available);
 }
 void AMateria::setAvailable(int available){
     this->_available = available;
 }
// ************************************************************************** //
//                    	   	 Overload operators                               //
// ************************************************************************** //
std::ostream & operator<<(std::ostream &o, AMateria const &rhs){
    o << "Type: " << rhs.getType() << std::endl;
    return (o);
}
AMateria	&AMateria::operator=(const AMateria& raw){
    std::cout << "(AMateria) Assigment operator called" << std::endl; 
    if (this != &raw)
        _type = raw.getType();
    return (*this);
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //
void AMateria::use(ICharacter & target){
    std::cout << "This function is never called" << std::endl;
    target.getName();
}