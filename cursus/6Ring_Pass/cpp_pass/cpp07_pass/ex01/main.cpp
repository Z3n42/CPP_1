/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:11:57 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/09 12:49:55 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	char		chars[5] = "abcd";
	int			ints[5] = {0, 1, 2, 3, 4};
	float		floats[5] = {0.2f, 1.3f, 2.4f, 3.5f, 4.6f};

	std::cout << "___CHAR___" << std::endl;
	iter(chars, 4, colorize);
	std::cout << std::endl;

	std::cout << "___INT___" << std::endl;
	iter(ints, 4, colorize);
	std::cout << std::endl;

	std::cout << "___FLOAT___" << std::endl;
	iter(floats, 4, colorize);
	std::cout << std::endl;

	return (0);
}
