/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:14:14 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/19 20:58:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void){
	/* std::cout << "Dark Materia has been looted" << std::endl; */
}

AMateria::AMateria(std::string const & type) : _type(type){
	/* std::cout << "Dark Materia has been looted" << std::endl; */
} 

AMateria::~AMateria(void){
	/* std::cout << "Dark Materia has been destroyed" << std::endl; */
}

AMateria::AMateria(AMateria const & src) : _type(src._type){
	/* *this = src; */
	/* std::cout << "Dark Materia has been copied." << std::endl; */
}

/* AMateria & AMateria::operator=(AMateria const & rhs){ */
/* 	if (this != &rhs){ */
/* 		std::cout << this->_type << " Equalized to " << rhs._type << std::endl; */
/* 		this->_type = rhs.getType(); */
/* 	} */
/* 	return(*this); */
/* } */

std::string const & AMateria::getType(void) const{
	return(this->_type);
}

void AMateria::use(ICharacter& target){
	/* std::cout << "Dark Materia used against" << target.getName() << std::endl; */
}
