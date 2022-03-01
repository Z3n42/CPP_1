/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:21:44 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:21:45 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <string>
# include <iostream>

class Animal{
    protected:
        std::string type;
    public:
       Animal(void);
        Animal(std::string atype);
       virtual ~Animal(void);
       Animal(Animal const &src);
       //Accesors
       std::string getType(void) const;
       virtual void makeSound(void) const;
        //Operatrors
        Animal	&operator=(const Animal &raw);
};
//Overload operator
std::ostream & operator<<(std::ostream &o, Animal const &rhs);
#endif
