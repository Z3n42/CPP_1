/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:05:07 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 19:05:08 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGDOG_HPP
# define WRONGDOG_HPP
# include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal{
    public:
        WrongDog();
        WrongDog(WrongDog const &src);
        ~WrongDog();
        WrongDog &operator=(WrongDog const & raw);
        //Actions
       void makeSound(void) const;
};
#endif


