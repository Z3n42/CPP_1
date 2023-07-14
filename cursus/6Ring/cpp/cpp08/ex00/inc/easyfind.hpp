/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:45:56 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/14 18:11:27 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

template<typename T>
int easyfind(std::vector<T>vec, int x){
	
	typename std::vector<T>::iterator it;

	it = std::find(vec.begin(), vec.end(), x);
	if (it != vec.end()){
		std::cout << GREEN << "Element " << x <<
					 " found at position : ";
		std::cout << it - vec.begin() + 1 << RESET << std::endl;
		return (1);
	  }
   	else
		throw std::runtime_error("Value not found in container");
	return (0);
}


#endif
