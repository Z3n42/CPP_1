/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:06:09 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/20 20:37:47 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"

int main(int argc, char** argv){
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Bad Arguments" << std::endl;
}
