/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:32:10 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/05 19:32:26 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{

	private:
		AMateria	*(_inventory[4]);

	public:
		MateriaSource();
		MateriaSource(MateriaSource const & ref);
		~MateriaSource();

		MateriaSource & operator=(MateriaSource const & ref);

		void learnMateria(AMateria *m);
		AMateria* createMateria(std::string const & type);
};

#endif
