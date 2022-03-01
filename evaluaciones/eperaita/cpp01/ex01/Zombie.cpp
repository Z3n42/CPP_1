/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:45:03 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/17 20:22:18 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void){};//Contructor??
Zombie::~Zombie(void)
{
	std::cout << z_name << " destroyed" << std::endl;
};//Destructor??


void Zombie::announce(void)
{
    std::cout << "<" << z_name << "> " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie( std::string name )
{
    Zombie *z;

    z = new Zombie;
    z->z_name = name;
    return (z);
}


