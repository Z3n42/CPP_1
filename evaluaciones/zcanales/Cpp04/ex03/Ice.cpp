/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:22:03 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:22:04 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
Ice::Ice(void) : AMateria("ice"){
    std::cout << "(Ice) Default constructor called" << std::endl;
}
Ice::~Ice(void) {
   std::cout << "(Ice) Destructor called" << std::endl;
}
Ice::Ice(Ice const &src){
    std::cout << "(Ice) Copy constructor called" << std::endl;
    *this = src;
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //

Ice *Ice::clone() const{
   Ice *temp = new Ice(*this);
   return (temp);
}
void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"<<std::endl;
}