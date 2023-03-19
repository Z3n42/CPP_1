/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:03:03 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/19 18:23:30 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria{

	protected:
		const std::string _type;
	
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria(void);
		
		AMateria & operator=(AMateria const & rhs);

		/* std::string const & getType() const; //Returns the materia type */
		virtual std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
