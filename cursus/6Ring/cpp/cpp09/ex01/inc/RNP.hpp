/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:26:41 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/19 20:44:59 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
# define RNP_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <algorithm> 
#include <iostream>
#include <stack>

class Rnp{

	private:
			Rnp(void);
			/* std::string _input; */
			std::stack<char> _stack;	

	public:
			Rnp(std::string input);
			Rnp(Rnp const & src);
			~Rnp(void);

			Rnp& operator=(const Rnp &rhs);

			const std::stack<char> & getStack(void) const;
			
			int calculus(void);

			bool checkInput(char c);
};

std::ostream & operator<<(std::ostream & o, Rnp const & ref);

#endif
