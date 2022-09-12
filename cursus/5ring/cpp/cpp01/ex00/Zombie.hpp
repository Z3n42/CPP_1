/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:31:58 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/22 17:07:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie{

	private:
		std::string _name;
	
	public:
		void announce(void);
		Zombie(std::string name);
		Zombie(void);
		~Zombie(void);
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif
