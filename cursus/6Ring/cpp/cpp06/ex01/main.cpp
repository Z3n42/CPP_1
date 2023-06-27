/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:16:33 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/27 18:17:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"
#include <iostream>
#include <ctype.h>
#include <string.h>

int main(int argc, char** argv){
	if (argc == 2){
		std::string toSerialize = static_cast<std::string>(argv[1]);
		Serializer::convert(toSerialize);
	}
	else
		std::cerr << "Bad Arguments amount" << std::endl;
}
