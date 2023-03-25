/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 15:08:59 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/05 19:08:52 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <unistd.h>

int	main(void)
{
	Karen	karen;
	std::string level;
	std::string lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	std::cout << "A Karen just entered into the store." << std::endl << std::endl;
	sleep(3);
	while(1)
	{
		level = lvl[rand () % 4];
		std::cout << "[ " << level << " ]" << std::endl;
		karen.complain(level);
		std::cout << std::endl;
		sleep(3);
	}
	return (0);
}
