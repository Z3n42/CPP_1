/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:10:45 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 16:31:36 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef DOG_HPP
# define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal{

	public:
		Dog(void);
		Dog(std::string Type);
		~Dog(void);		
		Dog(Dog const & src);

		Dog & operator=(Dog const & rhs);

		std::string getType(void) const;
		void setType(std::string new_type);

		void makeSound() const;
};

#endif
