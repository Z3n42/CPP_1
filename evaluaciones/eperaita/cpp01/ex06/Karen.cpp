/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperaita <eperaita@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:33:13 by eperaita          #+#    #+#             */
/*   Updated: 2022/02/19 16:37:11 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <map>

Karen::Karen()
{
	_str[0] = "DEBUG";
    _str[1]  = "INFO";
    _str[2] = "WARNING";
    _str[3] = "ERROR";	
};


void Karen::complain( std::string complain )
{
	int i;

	i = -1;
    while (i < 4 && complain != _str[++i])
        continue;

//int i = map.count(complain) ? map.find(complain)->second : 0;
	
	switch(i)
   	{
       	case 0:
		{	
			f= &Karen::debug;
			(Karen().*Karen::f)();
		}
       	case 1:
		{	
           	f= &Karen::info;
			(Karen().*Karen::f)();
		}
		case 2:
		{	
     		 f= &Karen::warning;
			(Karen().*Karen::f)();
		}
   		 case 3:
		{	
       		f= &Karen::error;
			(Karen().*Karen::f)();
			break;
		}
		default:
		{
       		f= &Karen::isdefault;
			(Karen().*Karen::f)();
			break;
		}
    }


};

void Karen::isdefault( void )
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void Karen::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I would like someone to help me" << std::endl;
};
void Karen::info( void )
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I need help, please!" << std::endl;
};
void Karen::warning( void )
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "You must help me now!" << std::endl;
};
void Karen::error( void )
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "Help me or i´ll kill you" << std::endl;
};
