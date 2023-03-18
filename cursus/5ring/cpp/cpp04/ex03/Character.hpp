/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:56:49 by ingonzal          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2023/03/18 13:47:32 by ingonzal         ###   ########.fr       */
=======
/*   Updated: 2023/03/11 18:52:14 by ingonzal         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
#include "ICharacter.hpp"

class Character : public ICharacter{

	private:
		std::string const 	_name;
		AMateria		*(_inventory[4]);
		
	public:
		Character(void);
		Character(std::string const name);
		Character(Character const & src);
		~Character(void);

		Character & operator=(Character const & rhs);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria *getMateria(int idx);
};

# endif
