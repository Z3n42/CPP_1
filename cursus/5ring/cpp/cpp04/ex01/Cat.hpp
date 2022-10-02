/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:32:34 by ingonzal          #+#    #+#             */
/*   Updated: 2022/10/02 18:47:39 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{

	private:
		Brain* _Brain;

	public:
		Cat(void);
		Cat(std::string Type);
		~Cat(void);		
		Cat(Cat const & src);

		Cat & operator=(Cat const & rhs);

		std::string getType(void) const;
		void setType(std::string new_type);

		void makeSound() const;
};

#endif
