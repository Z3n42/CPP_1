/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:04:48 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 19:04:49 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
WrongCat::WrongCat(void) : WrongAnimal("Cat"){
    std::cout << "(WrongCat) Default constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
    std::cout << "(WrongCat) Destructor called" << std::endl;
}
WrongCat::WrongCat(WrongCat const &src){
    std::cout << "(WrongCat) Copy constructor called" << std::endl;
    *this = src;
}
// ************************************************************************** //
//                    	     	 Overload                                     //
// ************************************************************************** //
WrongCat &WrongCat::operator=(WrongCat const & raw){
     std::cout << "(WrongCat) Assigment operator" << std::endl;
     if (this != &raw)
        type = raw.getType();
    return (*this);
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //
void WrongCat::makeSound(void) const{
    std::cout << "[🐱] Miau-miau" << std::endl;
}
