/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:02:11 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/23 18:04:56 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

class FragTrap : virtual public ClapTrap{

private:
	static const std::string _Class;

public:
	FragTrap(void);
	FragTrap(std::string name);
	~FragTrap(void);
	FragTrap(FragTrap const &src);

	FragTrap & operator=(FragTrap const & rhs);
	std::string getClass(void) const;
	void attack(std::string const & target);
	void highFiveGuys(void);
};
#endif
