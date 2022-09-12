/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:58:15 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/17 21:12:13 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N;

	std::cout << "How many Zombies want at your horde Lord Necromancer => ";
	std::cin >> N;
	if (N <= 0)
	{
		std::cout << std::endl << "The resurrection spell doesn't work this way." << std::endl;
		std::cout << std::endl << "TRY AGAIN." << std::endl;
		return (1);
	}

	Zombie* toms = zombieHorde(N, "Tom from the heap");

	delete [] toms;

	return (0);
}
