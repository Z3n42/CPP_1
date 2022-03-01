/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:12:48 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 15:23:33 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private:
		std::string z_name;
	public:
		Zombie(void);
		~Zombie(void);
		Zombie* newZombie(std::string name);
		void randomChump(std::string name);
		void announce(void);
};



# endif
