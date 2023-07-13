/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:16:26 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/09 19:18:14 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whatever_HPP
# define whatever_HPP
#include <iostream>

template<typename T> 
void swap(T &x, T &y) {
	T t;	
	t = x;
	x = y;
	y = t;
}

template<typename T> 
T const & max(T const & x, T const & y) {
	return (y >= x? y : x);
}

template<typename T> 
T const & min(T const & x, T const & y) {
	return (y <= x? y : x);
}

#endif
