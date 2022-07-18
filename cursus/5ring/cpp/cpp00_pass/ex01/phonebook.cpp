/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:33:24 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/21 15:25:44 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include "Phonebook.hpp"

Phonebook::Phonebook(void){
	return;
}

Phonebook::~Phonebook(void){
	return;
}

void Phonebook::ft_show(Phonebook *list, int i)
{
	std::cout << "Contact Name: " << list->contact[i].name << std::endl;
	std::cout << "Contact Surname: " << list->contact[i].surname << std::endl;
	std::cout << "Contact Nickname: " << list->contact[i].nickname << std::endl;
	std::cout << "Contact Phone: " << list->contact[i].phone << std::endl;
	std::cout << "Contact Darkest Secret: " << list->contact[i].ds << std::endl;
}

void Phonebook::ft_search(Phonebook *list, int  max)
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
	while (i < 8 && i < max)
	{
		std::cout << std::setfill(' ') << std::setw(9) << i + 1 << ".";
		std::cout << "|";
		if (list->contact[i].name.size() > 10)
			std::cout << std::setw(9) << list->contact[i].name.substr(0,9) << '.';
		else
			std::cout << std::setfill(' ') << std::setw(10) << list->contact[i].name;
		std::cout << "|";
		if (list->contact[i].surname.size() > 10)
			std::cout << std::setw(9) << list->contact[i].surname.substr(0,9) << '.';
		else
			std::cout << std::setfill(' ') << std::setw(10) << list->contact[i].surname;
		std::cout << "|";
		if (list->contact[i].nickname.size() > 10)
			std::cout << std::setw(9) << list->contact[i].nickname.substr(0,9) << '.';
		else
			std::cout << std::setfill(' ') << std::setw(10) << list->contact[i].nickname;
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}
	if (max > 0)
	{
		std::cout << std::endl;
		std::cout << "Show Contact Number: ";
		std::cin  >> index;
		i = std::atoi(index);
		std::cout << std::endl;
		if (i > 0 && i < 9 && i <= max)
			list->ft_show(list, i - 1);
		else
		{
			std::cout << std::endl << "Invalid Index!!!" << std::endl << std::endl;
			ft_search(list, max);
		}
	}
}


void Phonebook::ft_add(Phonebook *list, int i)
{
	int c;

	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, list->contact[i].name);
	std::cout << "Last name: ";
	std::getline(std::cin >> std::ws, list->contact[i].surname);
	std::cout << "Nickname: ";
	std::getline(std::cin >> std::ws, list->contact[i].nickname);
	std::cout << "Phone: ";
	std::getline(std::cin >> std::ws, list->contact[i].phone);
	c = 0;
	while(list->contact[i].phone[c]) 
	{
        if (std::isdigit(list->contact[i].phone[c]) == 0) 
		{
			std::cout << std::endl << "WRONG NUMBER!!!" << std::endl << "Retry only with numbers!!!" << std::endl << std::endl;
			std::cout << "Phone: ";
			std::getline(std::cin >> std::ws, list->contact[i].phone);
			c = -1;
		}
		c++;
    }
	std::cout << "Darkest Secret: ";
	std::cin >> std::ws >> list->contact[i].ds;
	std::cout << std::endl;
}
