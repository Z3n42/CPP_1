/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:45:56 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/12 20:05:13 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
int easyfind(T *array, T x){
	
	std::vector<T> vec = array;
	std::vector<int>::iterator it;

	it = std::find(vec.begin(), vec.end(), x);
	if (it != vec.end()){
		std::cout << "Element " << x <<
					 " found at position : ";
		std::cout << it - vec.begin() << std::endl;
	  }
   	else
		throw ("kkkkk");
}


#endif
