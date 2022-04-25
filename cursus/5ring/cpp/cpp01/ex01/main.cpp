/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:58:15 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/23 15:40:56 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N;

	std::cout << "How many Zombies want at your horde Lord Necromancer => ";
	std::cin >> N;

	Zombie* tom = zombieHorde(N,"Tom from the heap");

	delete [] tom;

	return (0);
}
