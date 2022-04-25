/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:50:15 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/23 15:24:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i;
	std::stringstream stream[N];
	std::string c;

	Zombie* Raise = new Zombie[N]; 

	i = 0;
	while (i < N)
	{
		stream[i] << i + 1;
		stream[i] >> c;
		Raise[i].set_name(name + " Num: " + c);
		Raise[i].announce();
		i++;
	}

	return (Raise);
}
