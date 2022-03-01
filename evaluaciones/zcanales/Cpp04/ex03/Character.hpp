/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:18:17 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/16 11:18:18 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <string>
class AMateria;
# include "AMateria.hpp"
# include "ICharacter.hpp"
class Character : public ICharacter
{
    protected:
        AMateria *_array_materia[4];  
        int     _idx;
        std::string _name;

    public:
        Character(void);
        Character(std::string name);
        Character(Character const &src);
        Character &operator=(const Character &raw);
        //ICHARACTER
        virtual ~Character();
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif
