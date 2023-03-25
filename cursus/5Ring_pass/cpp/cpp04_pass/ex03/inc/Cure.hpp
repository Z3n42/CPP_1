/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:21:01 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/19 18:39:37 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria{
  /* Comments only with a virtual getter at the base class */

	/* private: */
	/* 	std::string _type; */

	public:
		Cure(void);
		Cure(std::string const type);
		Cure(Cure const & src);
		~Cure(void);

		Cure & operator=(Cure const & rhs);

		/* std::string const & getType() const; */
		Cure *clone() const;
		void use(ICharacter& target);
};

#endif
