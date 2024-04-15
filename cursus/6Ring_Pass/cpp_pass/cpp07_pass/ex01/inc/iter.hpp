/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:37:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/09 19:24:28 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
#include <cstdlib>
#include <iostream>

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

template<typename T>
void iter(T *array, size_t size, void function(T const &ref))
{
	for(size_t i = 0; i < size; i++)
		function(array[i]);
}

template<typename T>
void	colorize(T const &ref)
{
	if (static_cast<int>(ref) % 2 == 0)
		std::cout << GREEN << ref << RESET << std::endl;
	else
		std::cout << RED << " " << ref << RESET << std::endl;
}

#endif
