/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:04:53 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 19:04:54 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
WrongAnimal::WrongAnimal(void)
{
    type = "Default";
    std::cout << "(WrongAnimal) Default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string atype) : type(atype) {
    std::cout << "(WrongAnimal) Parameter constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "(WrongAnimal) Destructor called" << std::endl;
}
// ************************************************************************** //
//                    	       Accesories                                     //
// ************************************************************************** //
std::string WrongAnimal::getType(void) const {
    return (this->type);
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //
void  WrongAnimal::makeSound(void) const{
    std::cout << "[🔈] WrongAnimal sound!" << std::endl;
}
