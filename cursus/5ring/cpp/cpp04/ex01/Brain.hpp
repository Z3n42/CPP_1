/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:17:29 by ingonzal          #+#    #+#             */
/*   Updated: 2022/10/02 18:22:10 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <iostream>

class Brain{

	private:
		std::string *_ideas;

	public:
		Brain(void);
		~Brain(void);		
		Brain(Brain const & src);

		Brain & operator=(Brain const & rhs);

		std::string *getIdeas(void) const;
		void setIdeas(std::string new_ideas);

};
#endif
