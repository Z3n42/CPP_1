/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:27:53 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/22 18:32:39 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie karl = Zombie("Karl from the stack");
	Zombie* tom = newZombie("Tom from the heap");

	randomChump("Random");

	delete tom;
	return (0);
}
