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
Dog::Dog(void) : Animal("Dog"), _brain(new Brain()){
    std::cout << "(Dog) Default constructor called" << std::endl;
}
Dog::~Dog(void){
    delete _brain;
    std::cout << "(Dog) Destructor called" << std::endl;
}
Dog::Dog(Dog const &src) {
    std::cout << "(Dog) Copy constructor called" << std::endl;
    if (this != &src)
        *this = src;
}
// ************************************************************************** //
//                    	     	 Overload                                     //
// ************************************************************************** //
Dog &Dog::operator=(Dog const & raw){
    std::cout << "(Dog) Assigment operator called" << std::endl;
    this->_brain = raw._brain;
    return (*this);
}
// ************************************************************************** //
//                    	     	 Actions                                       //
// ************************************************************************** //
void Dog::makeSound(void) const {
    std::cout << "[🐶] Guau-guau!" << std::endl;
}

std::string Dog::getIdeaBrain(int idx)
{   return (_brain->getIdea(idx));
}
void Dog::setIdeaBrain(int idx, std::string idea){
    _brain->setIdea(idx, idea);
}