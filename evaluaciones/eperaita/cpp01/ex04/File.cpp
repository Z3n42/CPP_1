/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:14:06 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 16:17:57 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "File.hpp"
#include <fstream>

File::File(std::string name)
{
    _fileName = name;
};

void File::setStrings(std::string s1, std::string s2)
{
	 _tofind = s1;
	 _toreplace = s2;	
};


void File::get_file(std::ifstream &file)
{
	std::ofstream outfile;
	std::string line;

	_infile = &file;
	_outfile = &outfile;

	_infile->open(_fileName);

	if (_infile->is_open())
	{
		_outfile->open(_fileName.append(".replaced"));
		while (!_infile->eof())
    	{
            std::getline(*_infile, line);
			if (_infile->eof())
				break;
			_line.append(line);
			_line.append("\n");
		}
		replace();
    	_infile->close();
    	_outfile->close();
	}
	else
		std::cout << "Error : File not found" << std::endl;
};

void File::replace()
{
	size_t found;

	found = 0;
	std::cout << _line  << std::endl;

	while(1)
	{
		found = _line.find(_tofind, found);
		if (found == std::string::npos)
			break;
		_line.erase(found, _tofind.length());
		_line.insert(found, _toreplace);
		found += _toreplace.length();
	}
	*_outfile << _line;

	//ESTA VERSION SIN TOCAR LA _LINE HACE COSAS RARAS///	
	/*while ( _line.find(_tofind, found) != std::string::npos)
	{
		*_outfile << _line.substr(found ,  _line.find(_tofind, found) - found);
		*_outfile << _toreplace;
		found = _line.find(_tofind, found + 1) + _tofind.size();
	}
	*_outfile << std::endl;*/
};
