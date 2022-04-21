/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blacklist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:29:17 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/21 18:19:33 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.hpp"

int main (void)
{
	Phonebook phonebook;
	std::string command;
	int	exit;
	int max;
	int	i;

	std::cout << "\x1B[2J\x1B[H\n";
	std::cout << std::endl << "******* Wellcome to your awesome blacklist *******" << std::endl;
	std::cout << std::endl << "Press ENTER to Continue";
	std::cin.ignore();
	i = 0;
	max = 0;
	exit = 0;
	while (exit == 0)
	{
		std::cout << std::endl << "Type a command : ";
		std::getline(std::cin >> std::ws, command);
		std::cout << std::endl;
		if (command.compare("ADD") == 0)
		{
			std::cout << "\x1B[2J\x1B[H\n";
			std::cout << "**Adding Contact**" << std::endl << std::endl;
			phonebook.ft_add(&phonebook, i);
			i++;
			max++;
			std::cout << "\x1B[2J\x1B[H\n";
		}
		else if (command.compare("SEARCH") == 0)
			phonebook.ft_search(&phonebook, max);
		else if (command.compare("EXIT") == 0)
			exit = 1;
		else
			std::cout << "Authorized commands: ADD - SEARCH - EXIT" << std::endl;
		if (i == 8)
		{
			i = 0;
			max = 8;
		}
	}
}
