/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:06:09 by ingonzal          #+#    #+#             */
/*   Updated: 2023/05/27 19:25:28 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iostream>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv){
	if (argc == 2){
		int i;
		int j;
		int k;
		int f;
		int m;
		int len; 
		std::string str = static_cast<std::string>(argv[1]);

		i = 0;
		j = 0;
		k = 0;
		f = 0;
		len = str.length();
		while(str[i]){
		   	if (std::isalpha(str[i]))
				i++;
			else if (std::isdigit(str[j]))
				j++;
			else if (str[j] == '.' and std::isdigit(str[j - 1]) and str[j + 1] != '\0'){
				j++;
				k++;
			}
			else if (str[j] == '-' and std::isdigit(str[j + 1])){
				j++;
				m++;
			}
			else if (str[j] == 'f' and str[j + 1] == '\0'){
				j++;
				f++;
			}
			else 
				break;
		}
		if (i == len)
			std::cout << "ALL CHAR" << std::endl;
		else if (j == len and k < 2 and f < 2 and m < 2){
			if (f != 0)
				std::cout << "ALL FLOAT" << std::endl;
			else if (k != 0 and f == 0)
				std::cout << "ALL DOUBLE" << std::endl;
			else
				std::cout << "ALL NUM" << std::endl;
		}
		else
			std::cout << "Bad Arguments" << std::endl;
		ScalarConverter::convert(str);
	}
	else
		std::cout << "Bad Arguments amount" << std::endl;
}
