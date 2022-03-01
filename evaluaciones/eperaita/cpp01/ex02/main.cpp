/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:49:12 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 15:50:06 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
void print_ptr(const std::string *s)
{
	std::cout << "Add PTR -> " << s <<  std::endl;	
	std::cout << *s << std::endl;	
}
void print_ref(const std::string &s)
{
	std::cout << "Add REF -> " << &s <<  std::endl;	
	std::cout << s << std::endl;	
}

int main()
{
	const std::string *stringPTR;
	const std::string s("HI THIS IS BRAIN");

	stringPTR = &s;
//	stringPTR = new std::string("HI THIS IS BRAIN"); //en heap??

	std::cout << "Add string -> " << &s <<  std::endl;	
	std::cout << s <<  std::endl;	
	print_ptr(stringPTR);
	print_ref(s);
	return (0);
}

//std::string("HI THIS IS BRAIN"); y std::string s = "HI THIS IS BRAIN"; //es lo mismo
//vamos que *ptr (PUNTERO)  apunta a &s (REF), osea donde est aalojada s
//mandando ref o la variable no se puede modificar en esa fucion porque solo accede a su direccion o hace una copia, si mandas puntero si
