/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blacklist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:29:17 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/16 14:42:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "blacklist.hpp"

/* implentar en la clase phonebook el array de contactos */


Contact::Contact(void){
	return;
}

Contact::~Contact(void){
	return;
}

static int	ft_integer(const char *str)
{
	int	integer;

	integer = 0;
	while (*str > 47 && *str < 58)
	{
		integer = (integer * 10) + (*str - '0');
		str++;
	}
	return (integer);
}

int	ft_atoi(const char *str)
{
	int	minus;
	int	plus;
	int	integer;

	while (*str == ' ' || (*str > 8 && *str < 14))
		str++;
	minus = 0;
	plus = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus++;
		plus++;
		str++;
	}
	if (minus > 1 || plus > 1)
		return (0);
	integer = ft_integer(str);
	if ((minus % 2) != 0)
		integer = integer * (-1);
	return (integer);
}

void ft_show(Contact *list, int i)
{
	std::cout << "Contact Name: " << list[i].name << std::endl;
	std::cout << "Contact Surname: " << list[i].surname << std::endl;
	std::cout << "Contact Nickname: " << list[i].nickname << std::endl;
	std::cout << "Contact Phone: " << list[i].phone << std::endl;
	std::cout << "Contact Darkest Secret: " << list[i].ds << std::endl;
}

void ft_search(Contact *list)
{
	int i;
	char index[1024];

	std::cout << std::setfill(' ') << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "First Name";
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "Last Name";
	std::cout << "|";
	std::cout << std::setfill(' ') << std::setw(10) << "Nickname";
	std::cout << "|";
	std::cout << std::endl;
	i = 0;
	while (i < 8)
	{
		std::cout << std::setfill(' ') << std::setw(9) << i + 1 << ".";
		std::cout << "|";
		if (list[i].name.size() > 10)
			std::cout << std::setw(9) << list[i].name.substr(0,9) << '.';
		else
			std::cout << std::setfill(' ') << std::setw(10) << list[i].name;
		std::cout << "|";
		if (list[i].surname.size() > 10)
			std::cout << std::setw(9) << list[i].surname.substr(0,9) << '.';
		else
			std::cout << std::setfill(' ') << std::setw(10) << list[i].surname;
		std::cout << "|";
		if (list[i].nickname.size() > 10)
			std::cout << std::setw(9) << list[i].nickname.substr(0,9) << '.';
		else
			std::cout << std::setfill(' ') << std::setw(10) << list[i].nickname;
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}
	std::cout << std::endl;
	std::cout << "Show Contact Number: ";
	std::cin  >> index;
	i = ft_atoi(index);
	std::cout << std::endl;
	if (i > 0 && i < 9)
		ft_show(list, i - 1);
	else
	{
		std::cout << std::endl << "Invalid Index!!!" << std::endl << std::endl;
		ft_search(list);
	}
}

void ft_add(Contact *list, int i)
{
	int c;

	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, list[i].name);
	std::cout << "Last name: ";
	std::getline(std::cin >> std::ws, list[i].surname);
	std::cout << "Nickname: ";
	std::getline(std::cin >> std::ws, list[i].nickname);
	std::cout << "Phone: ";
	std::getline(std::cin >> std::ws, list[i].phone);
	c = 0;
	while(list[i].phone[c]) 
	{
        if (std::isdigit(list[i].phone[c]) == 0) 
		{
			std::cout << std::endl << "WRONG NUMBER!!!" << std::endl << "Retry only with numbers!!!" << std::endl << std::endl;
			std::cout << "Phone: ";
			std::getline(std::cin >> std::ws, list[i].phone);
			c = -1;
		}
		c++;
    }
	std::cout << "Darkest Secret: ";
	std::cin >> std::ws >> list[i].ds;
	std::cout << std::endl;
}

int main (void)
{
	/* Phonebook phonebook; */
	Contact list[8];
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
			ft_add(list, i);
			i++;
		}
		else if (command.compare("SEARCH") == 0)
			ft_search(list);
		else if (command.compare("EXIT") == 0)
			exit = 1;
		else
			std::cout << "Authorized commands: ADD - SEARCH - EXIT" << std::endl;
		if (i == 8)
			i = 0;
	}
}
