/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:22:03 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:22:04 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// ************************************************************************** //
//                    	   	 Basic                                             //
// ************************************************************************** //
Cat::Cat(void) : Animal("Cat"){
    std::cout << "(Cat) Default constructor called" << std::endl;
}

Cat::~Cat(void) {
    std::cout << "(Cat) Destructor called" << std::endl;
}
Cat::Cat(Cat const &src){
    std::cout << "(Cat) Copy constructor called" << std::endl;
    *this = src;
}
// ************************************************************************** //
//                    	     	 Overload                                     //
// ************************************************************************** //
Cat &Cat::operator=(Cat const & raw){
     std::cout << "(Cat) Assigment operator" << std::endl;
     if (this != &raw)
        type = raw.getType();
    return (*this);
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //
void Cat::makeSound(void) const{
    std::cout << "[🐱] Miau-miau" << std::endl;
}
