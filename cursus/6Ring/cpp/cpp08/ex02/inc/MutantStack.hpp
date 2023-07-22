/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:01:42 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/22 19:15:41 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <iostream>
#include <stack>
#include <algorithm>
#include <exception>

template<typename T>
class MutantStack : public std::stack<T>{

/* 	private: */
/* 		unsigned int _n; */
/* 		T 	    	 *_t; */

/* 	public: */
/* 		Array(void){ */

/* 			this->_t = new T[1]; */
/* 			this->_t[0] = 0; */
	
/* 		} */

/* 		Array(unsigned int n) : _n(n) { */ 

/* 			this->_t = new T[n]; */
/* 		} */

/* 		Array(Array const & src) : _n(src.size()){ */

/* 			this->_t = new T[this->_n]; */
/* 			for (unsigned int i = 0; i < this->_n; i++) */
/* 				this->_t[i] = src[i]; */

/* 		} */

/* 		~Array(void){ */

/* 			delete [] this->_t; */
/* 		} */

		
/* 		Array & operator=(Array const & rhs){ */

/* 			this->_n = rhs.size(); */
/* 			delete [] this->_t; */

/* 			this->_t = new T[_n]; */
/* 			for (unsigned int i = 0; i < _n; i++) */
/* 				this->_t[i] = rhs[i]; */

/* 			return (*this); */
/* 		} */

/* 		T & operator[](unsigned int i){ */

/* 			if (i > this->size()) */
/* 				throw (NotAllowed()); */
/* 			else */
/* 				return (this->_t[i]); */
/* 		} */

		
/* 		T *getData( void ) const { */ 

/* 			return (this->_t); */ 
/* 		} */

/* 		unsigned int size() const{ */

/* 			return (this->_n); */
		
/* 		} */
};

std::ostream & operator<<(std::ostream & o, MutantStack<int>const & ref);

#endif
