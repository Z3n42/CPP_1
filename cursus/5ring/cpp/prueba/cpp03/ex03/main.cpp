/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:51:50 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/21 14:15:16 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void){
	std::cout << "-- Summon ClapTraps --" << std::endl;
	std::cout << std::endl;

	ClapTrap Bip("Bip");
	ClapTrap Bop("Bop");
	ClapTrap Bup(Bip);

	std::cout << std::endl;
	std::cout << "-- Summon ScavTraps --" << std::endl;
	std::cout << std::endl;

	ScavTrap ping("Ping");
	ScavTrap pong("Pong");

	std::cout << std::endl;
	std::cout << "-- Summon FragTraps --" << std::endl;
	std::cout << std::endl;

	FragTrap Ding("Ding");
	ScavTrap Dong("Dong");
	std::cout << std::endl;

	std::cout << "-- Equalizing Traps --" << std::endl;
	std::cout << std::endl;

	Bup = Bop;
	ping = pong;

	std::cout << std::endl;
	std::cout << "-- ClapTrap Turn --" << std::endl;
	std::cout << std::endl;

	Bip.attack("Bop");
	Bop.takeDamage(0);
	Bup.beRepaired(0);

	std::cout << std::endl;
	std::cout << "-- ScavTrap Turn --" << std::endl;
	std::cout << std::endl;

	ping.attack("Bip");
	ping.guardGate();
	ping.takeDamage(0);
	ping.beRepaired(0);

	std::cout << std::endl;
	std::cout << "-- FragTrap Turn --" << std::endl;
	std::cout << std::endl;

	Ding.attack("ping");
	Ding.highFiveGuys();
	Ding.takeDamage(0);
	Ding.beRepaired(0);

	std::cout << std::endl;
	std::cout << "-- End Turn --" << std::endl;
	std::cout << std::endl;
	return(0);
}

