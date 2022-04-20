/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:15:57 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/19 17:48:52 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class Phonebook{

	public :
		
		Contact contact[8];
		
		
		void ft_show(Phonebook *list, int i);
		void ft_add(Phonebook *list, int i);
		void ft_search(Phonebook *list);

		Phonebook(void);
		~Phonebook(void);
};

int	ft_atoi(const char *str);

#endif
