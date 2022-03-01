/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:21:50 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:21:51 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
Dog::Dog(void) : Animal("Dog"){
    std::cout << "(Dog) Default constructor called" << std::endl;
}
Dog::~Dog(void){
    std::cout << "(Dog) Destructor called" << std::endl;
}
Dog::Dog(Dog const &src){
    std::cout << "(Dog) Copy constructor called" << std::endl;
    *this = src;
}
// ************************************************************************** //
//                    	     	 Overload                                     //
// ************************************************************************** //
Dog &Dog::operator=(Dog const & raw){
     std::cout << "(Dog) Assigment operator" << std::endl;
     if (this != &raw)
        type = raw.getType();
    return (*this);
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //
void Dog::makeSound(void) const {
    std::cout << "[🐶] Guau-guau!" << std::endl;
}

