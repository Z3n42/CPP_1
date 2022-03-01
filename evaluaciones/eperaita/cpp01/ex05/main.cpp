/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:32:53 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 16:21:14 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main()
{
	Karen k;
	std::string level;
	
	std::cout << "Hi, I´m Karen!" << std::endl;

	while (1)	
	{
		std::cout << std::endl;
		std::cout << "I´m gonna complain again!" << std::endl;
		std::cout << "Set my level please: [DEBUG] [INFO] [WARNING] [ERROR]" << std::endl;
		std::cin >> level;
		if (std::cin.eof() || !level.size())
            break;
		k.complain(level);
	}

	return (0);
}
