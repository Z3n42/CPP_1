/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:08:59 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/05 20:14:45 by ingonzal         ###   ########.fr       */
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

		/* switch (i) */
		/* { */
		/* 	case 1: */
		/* 		karen.complain(argv[1]); */
		/* 	break; */
		/* 	case 2: */
		/* 		karen.complain(argv[1]); */
		/* 	break; */
		/* 	case 3: */
		/* 		karen.complain(argv[1]); */
		/* 	break; */
		/* 	case 4: */
		/* 		karen.complain(argv[1]); */
		/* 	break; */
		/* 	default : */
		/* 		std::cout <<  "[ Probably complaining about insignificant problems ]" << std::endl; */
		/* } */
