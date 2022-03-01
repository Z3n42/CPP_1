/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:21:55 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 17:21:56 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal{
    private:
        Brain *_brain;
    public:
        Dog();
        Dog(Dog const &src);
        virtual ~Dog();
        //Overload 
        Dog &operator=(Dog const & raw);
        //Actions
        virtual void makeSound(void) const;
        std::string getIdeaBrain(int idx);
        void setIdeaBrain(int idx, std::string idea);
};
#endif
