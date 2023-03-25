/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:46:42 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/24 15:11:53 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << std::endl;
	std::cout << "//////////// ADDRESS /////////// "<< std::endl;
	std::cout << "StringADD: " << &string << std::endl;
	std::cout << "StringPTR: " << stringPTR << std::endl;
	std::cout << "StringREF: " << &stringREF << std::endl;
	std::cout << "//////////////////////////////// "<< std::endl;
	std::cout << std::endl;
	std::cout << "///////////// VALUE //////////// "<< std::endl;
	std::cout << "StringVAL: " << string << std::endl;
	std::cout << "StringPTR: " << *stringPTR << std::endl;
	std::cout << "StringREF: " << stringREF << std::endl;
	std::cout << "//////////////////////////////// "<< std::endl;
	std::cout << std::endl;

	return (0);
}
