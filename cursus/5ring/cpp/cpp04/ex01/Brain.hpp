/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:17:29 by ingonzal          #+#    #+#             */
/*   Updated: 2022/10/03 14:10:12 by ingonzal         ###   ########.fr       */
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
