/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:16:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/21 20:01:26 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span{

	private:
		unsigned int _N;
		std::vector<int> *_vec;
		Span(void);

	public:
		Span(unsigned int N);
		Span(Span const & src);
		~Span(void);

		Span & operator=(Span const & rhs);

		const unsigned int & getN(void) const;
		std::vector<int> & getVec(void) const;

		void addNumber(int n);

		int shortestSpan();
		int longestSpan();
		void generator();	
};

int RandomNumber();
std::ostream & operator<<(std::ostream & o, Span const & ref);

#endif
