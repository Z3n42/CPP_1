/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:26:41 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/20 15:21:57 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
# define RNP_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <algorithm> 
#include <iostream>
#include <stdlib.h>
#include <stack>

class Rnp{

	private:
			Rnp(void);
			std::string _input;
			std::stack<int> _stack;	

	public:
			Rnp(std::string input);
			Rnp(Rnp const & src);
			~Rnp(void);

			Rnp& operator=(const Rnp &rhs);

			const std::stack<int> & getStack(void) const;
			
			bool checkInput(char c);
			void calculus(void);
};

#endif
