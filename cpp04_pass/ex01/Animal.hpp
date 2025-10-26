/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:56:35 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 17:55:16 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>

class Animal{

	protected:
		std::string type;

	public:
		Animal(void);
		Animal(std::string Type);
		virtual ~Animal(void);		
		Animal(Animal const & src);

		Animal & operator=(Animal const & rhs);

		virtual std::string getType(void) const;
		void setType(std::string new_type);

		virtual void makeSound() const;
};

#endif
