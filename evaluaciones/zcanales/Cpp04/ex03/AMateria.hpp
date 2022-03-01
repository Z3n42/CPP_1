/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:23:12 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/15 18:23:14 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP
class ICharacter;
#include "ICharacter.hpp"
# include <string>
# include <iostream>
class AMateria {
    protected:
        std::string _type;
        int         _available;
    public:
        //Basic
        AMateria(std::string const & type);
        AMateria();
        AMateria(AMateria const &src);
        virtual ~AMateria();    //Virtual 
        //OBLIGATORIO
        //Accesories
        std::string const & getType() const; 
        int const & getAvailable() const; 
        void setAvailable(int available); 
        //Actions
        virtual AMateria *clone() const = 0; 
        virtual void use(ICharacter & target); 
       //Overload operators
        AMateria &operator=(const AMateria &raw);
};
std::ostream & operator<<(std::ostream &o, AMateria const &rhs);
#endif
