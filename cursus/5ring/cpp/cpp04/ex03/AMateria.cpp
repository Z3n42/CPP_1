/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:14:14 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/11 20:18:55 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

AMateria::AMateria(void){
	this->type = "Dark Materia";
	std::cout << this->type << " has been looted" << std::endl;
}

AMateria::AMateria(std::string const & type) : type(type){
	std::cout << this->type << " has been looted" << std::endl;
} 

AMateria::~AMateria(void){
	std::cout << this->type << " has been destroyed" << std::endl;
}

AMateria::AMateria(AMateria const & src){
	*this = src;
	std::cout << this->type << " has been copied." << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs){
	if (this != &rhs){
		std::cout << this->type << " Equalized to " << rhs.type << std::endl;
		this->type = rhs.getType();
	}
	return(*this);
}

std::string const & AMateria::getType(void) const{
	return(this->type);
}

void AMateria::use(ICharacter& target){
	std::cout << "AMateria used against" << target.getName() << std::endl;
}
