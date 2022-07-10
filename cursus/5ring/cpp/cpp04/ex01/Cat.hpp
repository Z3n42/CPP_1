/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:32:34 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 16:38:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal{

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
