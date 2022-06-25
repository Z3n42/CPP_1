/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:51:50 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/23 18:31:06 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void){
	std::cout << "-- Summon ClapTraps --" << std::endl;
	std::cout << std::endl;

	ClapTrap clip("Clip");
	ClapTrap clop("Clop");
	ClapTrap clup(clip);

	std::cout << std::endl;
	std::cout << "Class =>" << clip.getClass() << std::endl;
	std::cout << "Nombre =>" << clip.getname() << std::endl;
	std::cout << "Hit =>"  << clip.getHit() << std::endl;
	std::cout << "Energy =>" << clip.getEnergy() << std::endl;
	std::cout << "Attack =>" << clip.getDamage() << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-- Summon ScavTraps --" << std::endl;
	std::cout << std::endl;

	ScavTrap sing("Sing");
	ScavTrap song("Song");

	std::cout << std::endl;
	std::cout << "Class =>" << sing.getClass() << std::endl;
	std::cout << "Nombre =>" << sing.getname() << std::endl;
	std::cout << "Hit =>"  << sing.getHit() << std::endl;
	std::cout << "Energy =>" << sing.getEnergy() << std::endl;
	std::cout << "Attack =>" << sing.getDamage() << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-- Summon FragTraps --" << std::endl;
	std::cout << std::endl;

	FragTrap fing("fing");
	FragTrap fong("fong");

	std::cout << std::endl;
	std::cout << "Class =>" << fing.getClass() << std::endl;
	std::cout << "Nombre =>" << fing.getname() << std::endl;
	std::cout << "Hit =>"  << fing.getHit() << std::endl;
	std::cout << "Energy =>" << fing.getEnergy() << std::endl;
	std::cout << "Attack =>" << fing.getDamage() << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-- Summon DiamondTraps --" << std::endl;
	std::cout << std::endl;

	DiamondTrap Ding("Ding");
	DiamondTrap Dong("Dong");

	std::cout << std::endl;
	std::cout << "Class =>" << Ding.getClass() << std::endl;
	std::cout << "Nombre =>" << Ding.getname() << std::endl;
	std::cout << "Hit =>"  << Ding.getHit() << std::endl;
	std::cout << "Energy =>" << Ding.getEnergy() << std::endl;
	std::cout << "Attack =>" << Ding.getDamage() << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-- Equalizing Traps --" << std::endl;
	std::cout << std::endl;

	clup = clop;
	sing = song;

	std::cout << std::endl;
	std::cout << "-- ClapTrap Turn --" << std::endl;
	std::cout << std::endl;

	clip.attack("Clop");
	clop.takeDamage(0);
	clup.beRepaired(0);

	std::cout << std::endl;
	std::cout << "-- ScavTrap Turn --" << std::endl;
	std::cout << std::endl;

	sing.attack("Clip");
	sing.guardGate();
	sing.takeDamage(0);
	sing.beRepaired(0);

	std::cout << std::endl;
	std::cout << "-- FragTrap Turn --" << std::endl;
	std::cout << std::endl;

	fing.attack("fing");
	/* fing.highFiveGuys(); */
	fing.takeDamage(0);
	fing.beRepaired(0);

	std::cout << std::endl;
	std::cout << "-- DiamondTrap Turn --" << std::endl;
	std::cout << std::endl;

	Ding.whoAmI();
	Ding.attack("fing");
	Ding.guardGate();
	/* Ding.highFiveGuys(); */
	Ding.takeDamage(0);
	Ding.beRepaired(0);

	std::cout << std::endl;
	std::cout << "-- End Turn --" << std::endl;
	std::cout << std::endl;
	return(0);
}

