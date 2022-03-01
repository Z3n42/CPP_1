/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:22:36 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/16 11:22:38 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include <string>
# include "AMateria.hpp"
# include "Ice.hpp"
# include "Cure.hpp"
# include "IMateriaSource.hpp"

//template <typename T>
class MateriaSource : public IMateriaSource
{   protected:
        AMateria *_arrayLearn[4];
        int        _idxLearn;
    public:
        MateriaSource();
        MateriaSource(MateriaSource const &src);
        virtual ~MateriaSource();
        MateriaSource &operator=(const MateriaSource &raw);
        virtual void learnMateria(AMateria*src);        
        virtual AMateria* createMateria(std::string const & type);  
};

#endif