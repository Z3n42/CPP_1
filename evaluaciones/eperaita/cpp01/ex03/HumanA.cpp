/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:22:56 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 16:02:05 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &a) :  _name(name), w(a) {};

void HumanA::attack(void)
{
	std::cout << _name << " attacks with his " << w.getType() << std::endl;
	return ;
};

