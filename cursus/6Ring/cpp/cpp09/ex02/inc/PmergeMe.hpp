/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:29:08 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/20 20:01:15 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <iostream>

class PmergeMe{

	private:
			std::vector<unsigned int> _vector;
			std::deque<unsigned int> _deque;
	
	public:
			PmergeMe(void);
			PmergeMe(std::string input);
			PmergeMe(PmergeMe const & src);
			~PmergeMe(void);

			PmergeMe& operator=(const PmergeMe &rhs);

};

#endif
