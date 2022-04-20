/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blacklist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:37:13 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/16 14:43:06 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BLACKLIST_H
# define BLACKLIST_H

class Phonebook{

	public :
		
		/* Contact list[8]; */
		
		Phonebook(void);
		~Phonebook(void);
};

class Contact{

public :
	std::string name;
	std::string surname;
	std::string nickname;
	std::string phone;
	std::string ds;

	Contact(void);
	~Contact(void);
};

#endif
