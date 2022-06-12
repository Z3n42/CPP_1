/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:08:59 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/06 13:26:22 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <unistd.h>

int	main(int argc, char **argv)
{
	Karen	karen;
	std::string level;
	std::string lvl[5] = { " ", "DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	i = 0;
	if (argc == 2)
	{

		while (i < 5)
		{
			if (argv[1] == lvl[i])
				break;
			i++;
		}
		if (i > 0 && i < 5)
			karen.complain(argv[1]);
		else
			std::cout <<  "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	else
		std::cout << "Bad arguments." << std::endl;
	return (0);
}

