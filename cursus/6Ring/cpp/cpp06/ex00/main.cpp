/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:06:09 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/02 19:57:17 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iostream>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv){
	if (argc == 2){
		int i = 0;
		int j = 0;
		int k = 0;
		int f = 0;
		int m = 0;
		std::string str = static_cast<std::string>(argv[1]);
		int len = str.length(); 

		while(str[i]){
		   	if (std::isalpha(str[i]))
				i++;
			else if (std::isdigit(str[j]))
				j++;
			else if (str[j] == '.' and std::isdigit(str[j - 1]) and (str[j + 1] != '\0' and str[j + 1] != 'f')){
				j++;
				k++;
			}
			else if (str[j] == '-' and std::isdigit(str[j + 1])){
				j++;
				m++;
			}
			else if (str[j] == 'f' and str[j + 1] == '\0' and str[j + 1] == '.'){
				j++;
				f++;
			}
			else 
				break;
		}
		ScalarConverter::checkInput(i, j, k, f, m, len);
		ScalarConverter::convert(str);
	}
	else
		std::cout << "Bad Arguments amount" << std::endl;
}
