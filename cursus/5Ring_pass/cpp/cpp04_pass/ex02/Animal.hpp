/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:56:35 by ingonzal          #+#    #+#             */
/*   Updated: 2023/02/25 19:48:44 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <iostream>

class AAnimal{

	protected:
		std::string type;

	public:
		AAnimal(void);
		AAnimal(std::string Type);
		virtual ~AAnimal(void);		
		AAnimal(AAnimal const & src);

		AAnimal & operator=(AAnimal const & rhs);

		virtual std::string getType(void) const;
		void setType(std::string new_type);

		virtual void makeSound() const = 0;
};

#endif
