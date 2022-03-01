/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:33:13 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 16:31:42 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen()
{
    _str[0] = "DEBUG";
    _str[1]  = "INFO";
    _str[2] = "WARNING";
    _str[3] = "ERROR";

};



void Karen::_set_functions(void )
{
	ptr p[] = {&Karen::debug, &Karen::info, &Karen::warning, &Karen::error, &Karen::isdefault};
	f = p;
}

void Karen::complain( std::string complain )
{
	int i;
	std::string found;

	// MAP NO ESTA AUTORIZADO //
	/*map["DEFAULT"] = 0;
	map["DEBUG"] = 1;
	map["INFO"] = 2;
	map["WARNING"] = 3;
	map["ERROR"] = 4;
	i = map.count(complain) ? map.find(complain)->second : 0; //ternaria. */
	//_set_functions();
	//(this->*(f[map.find(complain)->second]))(); 


	
	i = -1;
	while (i < 4 && complain != _str[++i])		
		continue;
		
	_set_functions();
	
	(this->*(f[i]))(); 
};

void Karen::isdefault( void )
{
	//Funcion trampa o default, por si se pasa del bucle siempre queda en i=4 y no hace nada
}
void Karen::debug( void )
{
	std::cout << std::endl;
	std::cout << "-> I would like someone to help me" << std::endl;
};
void Karen::info( void )
{
	std::cout << std::endl;
	std::cout << "-> I need help, please!" << std::endl;
};
void Karen::warning( void )
{
	std::cout << std::endl;
	std::cout << "-> You must help me now!" << std::endl;
};
void Karen::error( void )
{
	std::cout << std::endl;
	std::cout << "-> Help me or I´ll kill you" << std::endl;
};
