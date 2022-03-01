/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:28:22 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/16 10:28:23 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {};
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif