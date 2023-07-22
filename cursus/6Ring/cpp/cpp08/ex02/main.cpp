/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:31:16 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/22 18:47:13 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	std::cout << mstack.c << std::endl;


	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	/* MutantStack<int>::iterator it = mstack.begin(); */
	/* MutantStack<int>::iterator ite = mstack.end(); */

	/* ++it; */
	/* --it; */
	/* while (it != ite) */
	/* { */
	/* 	std::cout << *it << std::endl; */
	/* 	++it; */
	/* } */
	/* std::stack<int> s(mstack); */
	return 0;
}
