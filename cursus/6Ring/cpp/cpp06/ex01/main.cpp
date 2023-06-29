/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:16:33 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/29 19:45:47 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialize.hpp"
#include <iostream>
#include <ctype.h>
#include <string.h>

int	main(void)
{
	Serializer::Data data;
	data.num = 4;
	data.chars = 'a';

	uintptr_t			ptr;
	Serializer::Data	result;

	std::cout << "Init struct: " << std::endl;
    std::cout << data << std::endl;

	std::cout << "Serialize: " << std::endl;
	ptr = Serializer::serialize(&data);

	std::cout << "Serialized struct: " << ptr << std::endl;
	std::cout << "Memory allocation: " << &ptr << std::endl;
	std::cout << std::endl;

	std::cout << "Deserialize struct: " << std::endl;
	result = *Serializer::deserialize(ptr);

    std::cout << result << std::endl;


	std::cout << "Change result Data: " << std::endl;
	result.num = 5;
	result.chars = 'b';
    std::cout << result << std::endl;
	return (0);
}
