/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:04:50 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 19:04:51 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"
// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
WrongDog::WrongDog(void) : WrongAnimal("Dog"){
    std::cout << "(WrongDog) Default constructor called" << std::endl;
}

WrongDog::~WrongDog(void) {
    std::cout << "(WrongDog) Destructor called" << std::endl;
}
WrongDog::WrongDog(WrongDog const &src){
    std::cout << "(WrongDog) Copy constructor called" << std::endl;
    *this = src;
}
// ************************************************************************** //
//                    	     	 Overload                                     //
// ************************************************************************** //
WrongDog &WrongDog::operator=(WrongDog const & raw){
     std::cout << "(WrongDog) Assigment operator" << std::endl;
     if (this != &raw)
        type = raw.getType();
    return (*this);
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //
void WrongDog::makeSound(void) const{
    std::cout << "[🐱] Guau-guau" << std::endl;
}

