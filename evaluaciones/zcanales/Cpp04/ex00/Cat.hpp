/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:22:08 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:22:09 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat();
        Cat(Cat const &src);
        ~Cat();
        //Actions
        Cat &operator=(Cat const & raw);
       virtual void makeSound(void) const;
};
#endif
