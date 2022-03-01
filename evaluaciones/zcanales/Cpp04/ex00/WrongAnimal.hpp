/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:05:11 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 19:05:12 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <string>
# include <iostream>
class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal(void);
        WrongAnimal(std::string atype);
        virtual ~WrongAnimal();
        //Accesories
       std::string getType(void) const;
       //Actions
       void makeSound(void) const;
};


#endif
