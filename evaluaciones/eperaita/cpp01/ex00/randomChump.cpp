/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:38:44 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 15:30:21 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::randomChump( std::string name )
{
    //Zombie z; //no hace falta crear otro objeto, viene dado y accedo con el puntero this

    this->z_name = name;
    this->announce();
    return;
}
