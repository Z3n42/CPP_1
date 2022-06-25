/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:51:50 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/19 19:01:46 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){
	/* ClapTrap unnamed; */
	ClapTrap Bip("Bip");
	ClapTrap Bop("Bop");
	
	ClapTrap Bup(Bip);

	Bup = Bop;

	Bip.attack("Bop");
	Bop.takeDamage(0);
	Bup.beRepaired(0);

return(0);
}
