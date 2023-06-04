/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:06:09 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/04 15:02:18 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iostream>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv){
	if (argc == 2){
		std::string toConvert = static_cast<std::string>(argv[1]);
		ScalarConverter::convert(toConvert);
	}
	else
		std::cout << "Bad Arguments amount" << std::endl;
}
