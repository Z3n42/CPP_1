/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:50:15 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/17 21:03:42 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int i;
	std::stringstream stream;
	std::string c;

	Zombie* Raise = new Zombie[N]; 

	i = 0;
	while (i < N)
	{
		stream << i + 1;
		stream >> c;
		Raise[i].set_name(name + " Num: " + c);
		Raise[i].announce();
		stream.clear();
		i++;
	}

	return (Raise);
}
