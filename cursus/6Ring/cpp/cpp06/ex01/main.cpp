/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:16:33 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/29 17:24:45 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"
#include <iostream>
#include <ctype.h>
#include <string.h>

/* int main(void){ */
/* 	if (argc == 2){ */
/* 		std::string toSerialize = static_cast<std::string>(argv[1]); */
/* 		Serializer::convert(toSerialize); */
/* 	} */
/* 	else */
/* 		std::cerr << "Bad Arguments amount" << std::endl; */
/* } */
int	main(void)
{
	Serializer::Data data;
	data.count = 4;
	data.chars = 'a';

	std::cout << "data structure attributes: " << std::endl << "Integer: " << data.count << " Character: " << data.chars << std::endl;
	uintptr_t	serializedData = Serializer::serialize(&data);
	std::cout << "serialized data in uintptr_t: " << serializedData << std::endl;
	Serializer::Data	testData = *Serializer::deserialize(serializedData);
	std::cout << "New data structure attributes: " << std::endl << "Integer: " << testData.count << " Character: " << testData.chars << std::endl;
	testData.chars = 'B';
	std::cout << "After change data structure attributes: " << std::endl << "Integer: " << testData.count << " Character: " << testData.chars << std::endl;
	/* delete (testData); */
	return (0);
}
