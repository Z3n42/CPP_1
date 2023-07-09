/* **************************************************************************** */
/*                                                                              */
/*                                                          :::      ::::::::   */
/*     Array.tpp                                          :+:      :+:    :+:   */
/*                                                      +:+ +:+         +:+     */
/*     By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                  +#+#+#+#+#+   +#+           */
/*     Created: 2023/07/09 14:05:22 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/09 16:24:19 by ingonzal         ###   ########.fr       */
/*                                                                              */
/* **************************************************************************** */


#include "Array.hpp"

Array::Array(void){

	this->_t = new T[0];
	this->_t = {} ;
}

Array::Array(unsigned int n): _n(n) { 

	this->_t = new T[n];
}

Array::Array(Array const & src) : _n(src.size()){

		this->_t = new T[src.size()];
		for (unsigned int i = 0; i < src.size(); i++)
			this->_t[i] = src[i];

}

Array::~Array(void){

	delete [] this->_t;
}

Array & Array::operator=(Array const & ref){

	this->_n = ref.size();
	delete [] this->_t;

	this->_t = new T[_n];
	for (unsigned int i = 0; i < _n; i++)
		this->_t[i] = ref[i];

	return (*this);
}

T & Array::operator[](unsigned int i){

	if (i > this->size())
		throw (std::exception());
	else
		return (this->_t[i])
}


T *getData( void ) const { 

	return (this->_t); 
}

unsigned int size(){

		return (this->_n);
}
