/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:21:39 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:21:40 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
Animal::Animal(void){
    type = "Default";
    std::cout << "(Animal) Default constructor called" << std::endl;
}
Animal::Animal(std::string atype) : type(atype) {
    std::cout << "(Animal) Parameter constructor called" << std::endl;
}
Animal::Animal(Animal const &src){
    std::cout << "(Animal) Copy constructor called" << std::endl;
    *this = src;
}
Animal::~Animal(void){
    std::cout << "(Animal) Destructor called" << std::endl;
}
// ************************************************************************** //
//                    	       Accesories                                     //
// ************************************************************************** //
std::string Animal::getType(void) const {
    return (this->type);
}
// ************************************************************************** //
//                    	   	 Overload operators                               //
// ************************************************************************** //
Animal &Animal::operator=(Animal const & raw){
    type = raw.getType();
    return (*this);
}

std::ostream & operator<<(std::ostream &o, Animal const &rhs){
    o << "Type: " << rhs.getType() << std::endl;
    return (o);
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //
void  Animal::makeSound(void) const{
    std::cout << "[🔈] Animal sound!" << std::endl;
}