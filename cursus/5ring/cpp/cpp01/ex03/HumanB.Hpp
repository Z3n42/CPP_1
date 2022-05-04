/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:31:58 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/27 19:36:51 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB{

	private:
		std::string 	_name;
		Weapon		*_weapon;
	
	public:
		HumanB(std::string name);
		void attack(void);
		void setWeapon(Weapon &other_weapon);
		~HumanB(void);
};

#endif
