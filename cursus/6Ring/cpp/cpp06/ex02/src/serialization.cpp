/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:58:35 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/29 20:20:14 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"
#include <iomanip>

Base::~Base(void){

}

std::ostream & operator<<(std::ostream & o, Base const & rhs){
    o << std::endl;
	return (o);
}

