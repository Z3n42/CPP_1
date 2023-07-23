/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 13:27:48 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/23 14:52:39 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

template<typename T>
class Array{

	private:
		unsigned int _n;
		T 	    	 *_t;

	public:
		Array(void){

			this->_t = new T[1];
			this->_t[0] = 0;
	
		}

		Array(unsigned int n) : _n(n) { 

			this->_t = new T[n];
		}

		Array(Array const & src) : _n(src.size()){

			this->_t = new T[this->_n];
			for (unsigned int i = 0; i < this->_n; i++)
				this->_t[i] = src[i];

		}

		~Array(void){

			delete [] this->_t;
		}

		
		Array & operator=(Array const & rhs){

			this->_n = rhs.size();
			delete [] this->_t;

			this->_t = new T[_n];
			for (unsigned int i = 0; i < _n; i++)
				this->_t[i] = rhs[i];

			return (*this);
		}

		T & operator[](unsigned int i){

			if (i > this->size())
				throw (NotAllowed());
			else
				return (this->_t[i]);
		}

		
		T *getData( void ) const { 

			return (this->_t); 
		}

		unsigned int size() const{

			return (this->_n);
		
		}

		class NotAllowed : public std::exception {

			public:
				virtual const char* what(void) const throw(){

					return("Not Allowed");
				}
		};
};

template< typename T >
std::ostream & operator<<(std::ostream & o, Array<T> const & ref)
{
	std::cout << GREEN << "####################" << RESET << std::endl;
	for (unsigned int i = 0; i < ref.size(); i++)
		std::cout << "   [" << i << "] : " << (ref.getData())[i] << std::endl;
	std::cout << RED << "####################" << RESET << std::endl;
	return (o);
}

#endif
