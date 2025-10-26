/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:31:58 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/25 14:37:18 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA{

	private:
		std::string _name;
		Weapon		&_weapon;
	
	public:
		HumanA(std::string name, Weapon &weapon);
		void attack(void);
		~HumanA(void);
};

#endif
