/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:22:08 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:22:09 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria{
    public:
        Ice();
        Ice(Ice const &src);
        virtual ~Ice();
        //AMateria Actions
         virtual Ice *clone() const;
        //ICharacter Actions
         virtual void use(ICharacter& target);
};
#endif
