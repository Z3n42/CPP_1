/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:10:53 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/27 19:32:51 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP
#include <iostream>

class Serializer{
	
	private:
		std::string _input;
		
		Serializer(void);
		Serializer(std::string input);
		Serializer(Serializer const & src);
		~Serializer(void);

		Serializer & operator=(Serializer const & rhs);

		std::string const & getInput(void) const;
		void setInput(std::string const &input);

	public:
		struct Data {
		  uintptr_t	ptr;
		  int    	count;
		};

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
