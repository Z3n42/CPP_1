/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:43:33 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 19:43:34 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
// ************************************************************************** //
//                    	     	 Basics                                       //
// ************************************************************************** //
Brain::Brain(void) {
    std::cout << "(Brain) Default constructor called" << std::endl;
    int i;
    
    i = -1;
    while (++i < 100)
        _ideas[i] = "I should sleep more";
}

Brain::~Brain(){
    std::cout << "(Brain) Destructor called" << std::endl;
}
std::string Brain::getIdea(int idx) const {
    return (this->_ideas[idx]);
}
void    Brain::setIdea(int idx, std::string idea){
    _ideas[idx] = idea;
}
