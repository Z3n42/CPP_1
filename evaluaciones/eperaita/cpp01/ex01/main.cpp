/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 01:45:38 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 15:38:26 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *p;
	//size_t i = -1;

	p = NULL;
	p = p->zombieHorde(10, "Zombie"); //el int quien lo manda? 
	delete []p; //manera guay de eliminar array de clases
	return (0);
}
	//en la funcion zombieHorde() porque solo devuleve el puntero al primero???
	//porque solo manda una string a zombieHorde??-> p = p->zombieHorde(5, ["Zombie", "fkhvh", "kjv", "geg", "ege"]); ???
	////tengo array de objetos, no me deja eliminar cada zombie
