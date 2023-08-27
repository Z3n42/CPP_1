/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:29:08 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/27 19:57:42 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <algorithm>
#include <iostream>
#include <sstream>
#include <limits>
#include <vector>
#include <deque>

class PmergeMe{

	private:
			bool _isOdd;
			unsigned int _straggler;
			std::vector<unsigned int> _vector;
			std::deque<unsigned int> _deque;
	
	public:
			PmergeMe(void);
			PmergeMe(std::string input);
			PmergeMe(PmergeMe const & src);
			~PmergeMe(void);

			PmergeMe& operator=(const PmergeMe &rhs);


			const std::vector<unsigned int> & getVector(void) const;
			const std::deque<unsigned int> & getDeque(void) const;
			const std::string & getInput(void) const;
			void initPmergeMe(int max, char** nums);

			void printContainers(void);
			
};
bool isNumber(const std::string & s);

#endif
