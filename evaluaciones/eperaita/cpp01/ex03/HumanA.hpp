/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:01:35 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 16:02:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    private:
        std::string _name;
        Weapon &w;
    public:
        HumanA(std::string name, Weapon &a);// {_name(name), w = &a};
        void attack(void);//tiene que ser publica
};

#endif
