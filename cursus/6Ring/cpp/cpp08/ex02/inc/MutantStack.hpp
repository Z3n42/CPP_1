/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:01:42 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/23 18:08:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{

	 public:
			MutantStack(void) {};
			MutantStack(MutantStack const & src){
				*this = src;
			};
			~MutantStack(void){};

			MutantStack & operator=(MutantStack const & rhs){
				if (rhs != *this){
					this->c = rhs.c;
				}
				return *this;
			};


			typedef typename std::stack<T>::container_type::iterator iterator;	
			typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
			typedef typename std::stack<T>::container_type::const_iterator const_iterator;
			typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

			iterator begin(){
				return this->c.begin();
			}
			iterator end(){
				return this->c.end();
			}
			reverse_iterator rbegin(){
				return this->c.rbegin();
			}
			reverse_iterator rend(){
				return this->c.rend();
			}
			const_iterator begin() const{
				return this->c.begin();
			}
			const_iterator end() const{
				return this->c.end();
			}
			const_reverse_iterator rbegin() const{
				return this->c.rbegin();
			}
			const_reverse_iterator rend() const{
				return this->c.rend();
			}

};

template<typename T>
std::ostream & operator<<(std::ostream & o, MutantStack<T> & ref){
	int i;
	i = 0;
	MutantStack<int>::iterator itstart = ref.begin();
	MutantStack<int>::iterator itend = ref.end();
	std::cout << std::endl;
	std::cout << "MutantStack capacity " << ref.size() << " elementes max" << std::endl;
	std::cout << GREEN << "####################" << RESET << std::endl;
	  while (itstart != itend){
		std::cout << "[" << i << "]" << *itstart << std::endl;
		++itstart;
		i++;
	  }
	std::cout << RED << "####################" << RESET << std::endl;
	std::cout << std::endl;
	return (o);
}

template<typename T>
std::ostream & operator<<(std::ostream & o, std::stack<T> & ref){
	unsigned int i;
	i = ref.size() - 1;
	std::cout << std::endl;
	std::cout << "Stack capacity " << ref.size() << " elementes max" << std::endl;
	std::cout << GREEN << "####################" << RESET << std::endl;
	  while (ref.size()){
		std::cout << "[" << i << "]" << ref.top() << std::endl;
		ref.pop();
		i--;
	  }
	std::cout << RED << "####################" << RESET << std::endl;
	std::cout << std::endl;
	return (o);
}

#endif
