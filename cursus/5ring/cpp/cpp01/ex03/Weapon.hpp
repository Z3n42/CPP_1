/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:31:58 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/27 19:27:56 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon{

	private:
		std::string _type;
	
	public:
		Weapon(std::string name);
		std::string const& get_type();
		void setType(std::string other_type);
		~Weapon(void);
};

#endif
