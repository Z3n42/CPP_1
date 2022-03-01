/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:30:46 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/15 13:21:05 by eperaita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FILE_HPP 
# define FILE_HPP 

#include <iostream>

class File
{
	private:
		std::string _fileName;
		std::string _tofind;
		std::string _toreplace;
		std::string _line;
		std::ifstream *_infile;
		std::ofstream *_outfile;
		void replace();
	public:
		File(std::string name);
		void setStrings(std::string s1, std::string s2);
		void get_file(std::ifstream &file);
};

#endif
