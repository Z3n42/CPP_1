/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 14:19:19 by ingonzal          #+#    #+#             */
/*   Updated: 2022/04/18 16:57:04 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef CONTACT_H
# define CONTACT_H

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
