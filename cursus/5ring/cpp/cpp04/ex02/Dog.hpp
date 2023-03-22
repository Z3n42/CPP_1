/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:10:45 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/22 19:55:37 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{

	private:
		Brain* _Brain;

	public:
		Dog(void);
		Dog(std::string Type);
		~Dog(void);		
		Dog(Dog const & src);

		Dog & operator=(Dog const & rhs);

		std::string getType(void) const;
		void setType(std::string new_type);

		void makeSound() const;
		void getIdeasFromBrain() const;

	/* ####### TEST METHODS ######## */
		Brain *getBrain( void ) const;
		void compareTo(Dog const & other_dog) const;
};

#endif
