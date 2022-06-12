/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:38:07 by ingonzal          #+#    #+#             */
/*   Updated: 2022/06/05 15:16:32 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN_HPP
# define KAREN_HPP

#include <iostream>

class Karen{

	private:
		void _debug(void);
		void _info(void);
		void _warning(void);
		void _error(void);

	public:
		Karen(void);
		void complain(std::string level);
		~Karen(void);
};

#endif
