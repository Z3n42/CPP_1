/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:40:12 by zcanales          #+#    #+#             */
/*   Updated: 2022/02/25 14:41:29 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include <string>

int main(void)
{

	int iter;
	int n = 4;
	Animal *array[n]; 
	iter = -1;
		std::cout << "-------[🆕]CREATE ANIMALS-------" << std::endl;
	while (++iter < n)
	{
		if (iter < n/2)
			array[iter] =  new Cat;
		else
			array[iter] =  new Dog;
	}
	std::cout << "-------[🆓]DESTROY ANIMALS-------" << std::endl;
	iter = -1;
	while (++iter < n)
	{
		if (iter < n/2)
			delete array[iter];
		else
			delete array[iter];
	}
	std::cout << "-------[📇]DEEP COPY-------" << std::endl;
	Cat  a;
    Cat   b(a);
	
	std::cout << "[❔] A: " << a.getIdeaBrain(0) << std::endl; 
    std::cout << "[❔] B: " << b.getIdeaBrain(0) << std::endl;

    a.setIdeaBrain(0,"I want to eat more");
	
    std::cout << "[❔] A: " << a.getIdeaBrain(0) << std::endl; 
    std::cout << "[❔] B: " << b.getIdeaBrain(0) << std::endl; 
    
	/* std::cout << "-------[📝]SHALLOW COPY-------" << std::endl; */
	/* Dog c; */
	/* Dog d(c); */

    /* std::cout << "[❔] C: " << c.getIdeaBrain(0) << std::endl; */ 
    /* std::cout << "[❔] D: " << d.getIdeaBrain(0) << std::endl; */ 

	/* c.setIdeaBrain(0,"I want to eat more"); */
    
	/* std::cout << "[❔] C: " << c.getIdeaBrain(0) << std::endl; */
    /* std::cout << "[❔] D: " << d.getIdeaBrain(0) << std::endl; */ 
	

	return (0);
}
