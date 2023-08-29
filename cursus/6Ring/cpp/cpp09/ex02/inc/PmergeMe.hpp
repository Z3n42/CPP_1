/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:29:08 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/29 16:23:06 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"

#include <sys/time.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <chrono>
#include <limits>
#include <time.h>
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
			const unsigned int & getStraggler(void) const;
			const bool & getIsOdd(void) const;

			void initPmergeMe(int max, char** nums);

			void mergeInsertSort(void);
			void MisVector(void);
			void MisDeque(void);

			void printContainers(void);
			
};
bool isNumber(const std::string & s);
bool sortpair(const std::pair<unsigned int,unsigned int> &a,
			const std::pair<unsigned int,unsigned int> &b);

#endif
