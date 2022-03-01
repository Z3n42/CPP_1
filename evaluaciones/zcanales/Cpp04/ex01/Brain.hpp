/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:43:38 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/14 19:43:38 by zcanales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <string>

class Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain();
        ~Brain();
        std::string getIdea(int idx) const ;
        void    setIdea(int idx, std::string idea);
};

#endif

