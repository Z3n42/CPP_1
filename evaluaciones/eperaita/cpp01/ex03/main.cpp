/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:36:18 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 16:07:14 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(&club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
}

//en el A mando como ref el Weapon porque lo tengo declarado como puntero en la clase. 
//
// a -> & necesita inicializarse en el e constructor, por lo que no puedo hacerlo en dos pasos como en el HumanB 
//
