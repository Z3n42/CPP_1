/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:14:05 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/18 11:49:40 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void){};//Constructor->inicializar??

Zombie::~Zombie(void)//Destructor
{
	std::cout << z_name << " died" << std::endl;
};

void Zombie::announce(void)
{
    std::cout << "<" << z_name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
