/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutanStack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:04:07 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/22 18:11:38 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

std::ostream & operator<<(std::ostream & o, MutantStack<int>const & ref){
	std::cout << "Vector capacity " << ref.size() << " elementes max" << std::endl;
	std::cout << GREEN << "####################" << RESET << std::endl;
	  for (unsigned i=0; i < ref.size(); i++)
		std::cout << "[" << i << "]" << ref[i] << std::endl;
	std::cout << RED << "####################" << RESET << std::endl;
	return (o);
}
