/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:01:55 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 16:02:02 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	private:
		Weapon *w;
		std::string _name;
	public:
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon *a);
};


#endif
