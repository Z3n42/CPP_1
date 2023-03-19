/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:14:09 by ingonzal          #+#    #+#             */
/*   Updated: 2023/03/19 18:24:17 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria{

	private:
		std::string _type;

	public:
		Ice(void);
		Ice(std::string const type);
		Ice(Ice const & src);
		~Ice(void);

		Ice & operator=(Ice const & rhs);

		std::string const & getType() const;
		Ice *clone() const;
		void use(ICharacter& target);
};

#endif
