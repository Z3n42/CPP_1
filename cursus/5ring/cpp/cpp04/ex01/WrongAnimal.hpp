/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:26:11 by ingonzal          #+#    #+#             */
/*   Updated: 2022/07/10 17:58:53 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
#include <iostream>

class WrongAnimal{

	protected:
		std::string type;

	public:
		WrongAnimal(void);
		WrongAnimal(std::string Type);
		virtual ~WrongAnimal(void);		
		WrongAnimal(WrongAnimal const & src);

		WrongAnimal & operator=(WrongAnimal const & rhs);

		std::string getType(void) const;
		void setType(std::string new_type);

		void makeSound() const;
};

#endif
