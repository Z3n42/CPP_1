/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:36:03 by ingonzal          #+#    #+#             */
/*   Updated: 2022/05/04 14:59:24 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <iomanip>

int	main(int argc, char **argv)
{
	if(argc != 4)
	{
		std::cout << "Bad Arguments" << std::endl;
		return (-1);
	}

	std::string	name = argv[1];
	std::string 	insrt = argv[2];
	std::string 	erase = argv[3];
	int len = erase.length();

	std::ifstream 	ifs;

	ifs.open (argv[1]);
	if (!ifs.is_open ())
	{
		std::cout << "Open infile Error" << std::endl;
		return (-1);
	}

	std::ofstream 	ofs;
	std::string	outname = name + ".replace";

	ofs.open (outname);
	if (!ofs.is_open ())
	{
		std::cout << "Open outfile Error" << std::endl;
		return (-1);
	}

	std::string line;
	int pos;

	while (std::getline(ifs, line))
	{
		/* ft_replace(&line, insrt, erase); */
		pos = ine.find(erase, )
		ofs << line << std::endl;
	}	


	ifs.close();
	ofs.close();
}
