/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:32:53 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 14:01:32 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main(int argc, char **argv)
{
	Karen k;
	std::string level;
	
	if (argc != 2)
	{
		std::cout << "Invalid arguments: ./KarenFilter [DEBUG] [INFO] [WARNING] [ERROR]" << std::endl;
		return (1);
	}
	std::cout << "Hi, I´m Karen!" << std::endl;
	k.complain(argv[1]);
	return (0);
}
