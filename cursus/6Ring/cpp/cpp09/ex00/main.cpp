/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:44:48 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/24 19:01:18 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(void){
	std::string line;
	std::ifstream myfile ("example.txt");
	if (myfile.is_open()){
		while (std::getline(myfile,line)){
			std::cout << line << '\n';
		}
		myfile.close();
	  }
	  else std::cout << "Unable to open file" << std::endl; 
	  return 0;
}
