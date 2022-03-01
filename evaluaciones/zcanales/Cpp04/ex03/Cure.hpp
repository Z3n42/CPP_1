/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:22:08 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:22:09 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure : public AMateria{
    public:
        Cure();
        Cure(Cure const &src);
        virtual ~Cure();
        //Actions
        virtual Cure *clone() const;
        virtual void use(ICharacter& target);
};
#endif
