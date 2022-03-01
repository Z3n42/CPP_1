/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:26:07 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/16 10:26:08 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP
# include <string>
class AMateria;
# include "AMateria.hpp"
class ICharacter 
{
    protected:
        std::string _name;
        AMateria *array_materia[4];    
        int     idx;

    public:
        virtual ~ICharacter() {}
        virtual std::string const & getName() const = 0;
       virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};

#endif
