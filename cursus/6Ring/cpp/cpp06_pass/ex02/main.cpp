/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:16:33 by ingonzal          #+#    #+#             */
/*   Updated: 2023/06/30 20:01:19 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serialization.hpp"

int	main(void)
{
	Base *basePtr;

	basePtr = generate();
	Base &baseRef = *basePtr;
	identify(basePtr);
	identify(baseRef);

	delete(basePtr);
	return (0);
}
