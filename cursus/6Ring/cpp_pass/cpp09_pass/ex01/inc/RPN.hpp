/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:26:41 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/20 16:59:16 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <algorithm> 
#include <iostream>
#include <stdlib.h>
#include <stack>

class Rpn{

	private:
			Rpn(void);
			std::string _input;
			std::stack<int> _stack;	

	public:
			Rpn(std::string input);
			Rpn(Rpn const & src);
			~Rpn(void);

			Rpn& operator=(const Rpn &rhs);

			const std::stack<int> & getStack(void) const;
			const std::string & getInput(void) const;
			
			bool checkInput(char c);
			void calculus(void);
};
void test(void);
void initRpn(std::string input);

#endif
