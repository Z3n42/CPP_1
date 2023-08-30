/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:31:16 by ingonzal          #+#    #+#             */
/*   Updated: 2023/07/23 18:08:07 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack << std::endl;
	std::cout << "Mstack Top=> " << mstack.top() << std::endl;


	mstack.pop();

	std::cout << "Mstack Size=> " << mstack.size() << std::endl;
	std::cout << "Mstack Top post Pop()=> " << mstack.top() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	++it;
	--it;

	std::cout << std::endl;
	std::cout << "Mstack Example:" << std::endl;
	std::cout << GREEN << "####################" << RESET << std::endl;
	int i = 0;
	while (it != ite)
	{
		std::cout << "[" << i << "]" << *it << std::endl;
		i++;
		++it;
	}
	std::cout << RED << "####################" << RESET << std::endl;
	std::cout << std::endl;
	std::cout << "Mstack Top=> " << mstack.top() << std::endl;

	std::cout << std::endl;
	std::cout << "Mstack reverse Example:" << std::endl;
	std::cout << GREEN << "####################" << RESET << std::endl;
	int j = 0;
	while (rit != rite)
	{
		std::cout << "[" << j << "]" << *rit << std::endl;
		j++;
		++rit;
	}
	std::cout << RED << "####################" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << mstack << std::endl;
	std::stack<int> s(mstack);
	std::cout << s << std::endl;

	std::cout << std::endl;
	std::cout << "Leaks Summary :" << std::endl;
	system("leaks MutantStack");
	return 0;
}
