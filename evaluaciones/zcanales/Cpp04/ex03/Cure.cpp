/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:22:03 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:22:04 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
Cure::Cure(void) : AMateria("cure"){
    std::cout << "(Cure) Default constructor called" << std::endl;
}
Cure::~Cure(void) {
    std::cout << "(Cure) Destructor called" << std::endl;
}
Cure::Cure(Cure const &src){
    std::cout << "(Cure) Copy constructor called" << std::endl;
    *this = src;
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //

Cure *Cure::clone() const{
    Cure *temp = new Cure(*this);
    return (temp);
}
void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}