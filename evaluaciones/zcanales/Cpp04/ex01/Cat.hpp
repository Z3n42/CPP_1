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
# include "Brain.hpp"

class Cat : public Animal {
    private:
        Brain *_brain; 
    public:
        Cat();
        Cat(Cat const &src);
        virtual ~Cat();
        //Overload
        Cat &operator=(Cat const & raw);
        //Actions
       virtual void makeSound(void) const;
       //Accesories
    std::string getIdeaBrain(int idx);
    void setIdeaBrain(int idx, std::string idea);
};
#endif
