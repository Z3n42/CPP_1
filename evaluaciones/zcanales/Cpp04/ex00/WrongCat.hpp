/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:05:01 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 19:05:03 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        WrongCat();
        WrongCat(WrongCat const &src);
        ~WrongCat();
        WrongCat &operator=(WrongCat const & raw);
        //Actions
       virtual void makeSound(void) const;
};
#endif

