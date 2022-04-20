/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blacklist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:29:17 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/19 17:46:53 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

int main (void)
{
	Phonebook phonebook;
	std::string command;
	int	exit;
	int	i;

	std::cout << std::endl << "Wellcome to your awesome blacklist" << std::endl;
	i = 0;
	exit = 0;
	while (exit == 0)
	{
		std::cout << std::endl << "Type a command : ";
		std::getline(std::cin >> std::ws, command);
		std::cout << std::endl;
		if (command.compare("ADD") == 0)
		{
			phonebook.ft_add(&phonebook, i);
			i++;
		}
		else if (command.compare("SEARCH") == 0)
			phonebook.ft_search(&phonebook);
		else if (command.compare("EXIT") == 0)
			exit = 1;
		else
			std::cout << "Authorized commands: ADD - SEARCH - EXIT" << std::endl;
		if (i == 8)
			i = 0;
	}
}
