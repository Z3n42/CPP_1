/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 18:36:03 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/17 18:57:45 by ingonzal         ###   ########.fr       */
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
	std::string 	erase = argv[2];
	std::string 	insrt = argv[3];
	size_t len = erase.length();
	size_t inlen = insrt.length();

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
	size_t pos;

	pos = 0;
	while (std::getline(ifs, line))
	{
		pos = line.find(erase);
		while (pos != std::string::npos)
		{
			line.erase(pos, len);
			line.insert(pos, insrt);
			pos = line.find(erase, pos + inlen);
		}
		ofs << line << std::endl;
	}	
	ifs.close();
	ofs.close();
}
