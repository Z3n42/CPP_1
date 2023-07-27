/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:44:48 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/27 18:09:20 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main(void){
	std::string line;
	std::ifstream myfile ("data.csv");
	if (myfile.is_open()){
		while (std::getline(myfile,line)){
			std::cout << line << '\n';
		}
		myfile.close();
	  }
	  else std::cout << "Unable to open file" << std::endl; 
	  return 0;
}
