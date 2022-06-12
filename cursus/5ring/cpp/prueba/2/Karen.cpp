/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:57:45 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/06 12:40:40 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

Karen::Karen()
{

}
		
void	Karen::_debug(void)
{
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void	Karen::_info(void)
{
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void	Karen::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void	Karen::_error(void)
{
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

void	Karen::complain(std::string level)
{
	void	(Karen::*fct[4])(void) = { &Karen::_debug, &Karen::_info, &Karen::_warning, &Karen::_error };
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	i = 0;
	while (i < 4)
	{
		if (lvl[i] == level)
		{
			std::cout << "[ " << lvl[i] << " ]" << std::endl;
			(this->*(fct[i]))();
			std::cout << std::endl << std::endl;
			break;
		}
		i++;	
	}
}

Karen::~Karen()
{
	
}
