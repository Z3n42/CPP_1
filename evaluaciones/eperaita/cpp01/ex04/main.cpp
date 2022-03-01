/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:38:36 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/17 20:44:58 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "File.hpp"

int main(int argc, char **argv)
{
	std::ifstream infile;

    if (argc != 4)
	{
		std::cout << "Error: invalid arguments \n ./replaced [file] [str to_find] [str to_replace]" << std::endl;
		return (1);
	}
    File replace(argv[1]);
	replace.setStrings(argv[2], argv[3]);
	replace.get_file(infile);
    return (0);
}
