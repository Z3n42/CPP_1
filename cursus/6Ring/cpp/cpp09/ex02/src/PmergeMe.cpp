/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ingonzal <ingonzal@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:29:24 by ingonzal          #+#    #+#             */
/*   Updated: 2023/08/29 16:23:03 by ingonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe(void){

}


PmergeMe::PmergeMe(PmergeMe const & src){
	*this = src;
}

PmergeMe::~PmergeMe(void){

}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs){
	this->_vector = rhs.getVector();
	this->_deque = rhs.getDeque();
	return (*this);
}

const std::vector<unsigned int> & PmergeMe::getVector(void) const{
	return(this->_vector);
}

const std::deque<unsigned int> & PmergeMe::getDeque(void) const{
	return(this->_deque);
}

const unsigned int & PmergeMe::getStraggler(void) const{
	return(this->_straggler);
}

const bool & PmergeMe::getIsOdd(void) const{
	return(this->_isOdd);
}

bool isNumber(const std::string & s){

	int i;

	i = 0;
    while (s[i]) {
        if (std::isdigit(s[i]) == 0) 
            return false;
		i++;
    }
    return true;
 }

void PmergeMe::initPmergeMe(int max, char** nums){

	int 			i;
	unsigned int 	temp;

	clock_t start = clock();
	for (i = 1; i <= (max - 1); i++){
		std::istringstream ss(nums[i]);
		if(!isNumber(nums[i]) or !(ss >> temp) or temp > INT_MAX)
			throw std::runtime_error("Error: not a positive integer");
		if ((max - 1) % 2 != 0 and i == (max - 1)){
			this->_straggler = temp;
			this->_isOdd = true;
			break;
		}
		this->_vector.push_back(temp);
		this->_deque.push_back(temp);
	}
	clock_t end = clock();
	double elapsed = double(end - start)/CLOCKS_PER_SEC;
	std::cout << std::endl;
	/* the unit of time is wrongly expressed in the example. */
	std::cout << "Time to data management part of " << max - 1 << " elements " << std::fixed << elapsed << " s" << std::endl;
	std::cout << std::endl;
}

bool sortpair(const std::pair<unsigned int,unsigned int> &a,
		const std::pair<unsigned int,unsigned int> &b){
    return (a.second < b.second);
}

void PmergeMe::MisVector(void){

	clock_t start = clock();

	/* Another time measurement tryout */
	/* struct timeval begin, end; */
    /* gettimeofday(&begin, 0); */

	std::vector<std::pair<unsigned int, unsigned int> > tmp;
	std::vector<unsigned int> ord;
	std::vector<unsigned int> pend;
	for(std::vector<unsigned int>::const_iterator vit = this->_vector.begin();
	vit != this->_vector.end(); vit = vit + 2)
		if(*(vit) < *(vit + 1))
			tmp.push_back(std::make_pair(*(vit), *(vit + 1)));
		else
			tmp.push_back(std::make_pair(*(vit + 1), *(vit)));

	sort(tmp.begin(), tmp.end(), sortpair);
	for(std::vector<std::pair<unsigned int, unsigned int> > ::const_iterator tit = tmp.begin();
	tit != tmp.end(); ++tit){
		pend.push_back((*tit).first); 
		ord.push_back((*tit).second);
	}

	for(std::vector<unsigned int> ::const_iterator pit = pend.begin();
		pit != pend.end(); ++pit)
		ord.insert((std::upper_bound(ord.begin(), ord.end(), (*pit)))--, (*pit));
	if(this->_isOdd)
		ord.insert((std::upper_bound(ord.begin(), ord.end(), this->_straggler))--, this->_straggler);

	this->_vector = ord;

	/* gettimeofday(&end, 0); */
    /* long seconds = end.tv_sec - begin.tv_sec; */
    /* long microseconds = end.tv_usec - begin.tv_usec; */
    /* double elapsed = seconds + microseconds*1e-6; */

	clock_t end = clock();
	std::cout << "After:	";
	for(std::vector<unsigned int> ::const_iterator oit = this->_vector.begin();
	oit != this->_vector.end(); ++oit)
		std::cout << (*oit) << " ";
	std::cout << std::endl;
	double elapsed = double(end - start)/CLOCKS_PER_SEC;
	/* the unit of time is wrongly expressed in the example. */
	std::cout << "Time to process a range of " << this->_vector.size() << " elements with std::vector : ";
	std::cout << std::fixed << elapsed << " s" << std::endl;
}

void PmergeMe::MisDeque(void){

	clock_t start = clock();

	/* Another time measurement tryout */
	/* struct timeval begin, end; */
    /* gettimeofday(&begin, 0); */

	std::deque<std::pair<unsigned int, unsigned int> > tmp;
	std::deque<unsigned int> ord;
	std::deque<unsigned int> pend;
	for(std::deque<unsigned int>::const_iterator vit = this->_deque.begin();
	vit != this->_deque.end(); vit = vit + 2)
		if(*(vit) < *(vit + 1))
			tmp.push_back(std::make_pair(*(vit), *(vit + 1)));
		else
			tmp.push_back(std::make_pair(*(vit + 1), *(vit)));

	sort(tmp.begin(), tmp.end(), sortpair);
	for(std::deque<std::pair<unsigned int, unsigned int> > ::const_iterator tit = tmp.begin();
	tit != tmp.end(); ++tit){
		pend.push_back((*tit).first); 
		ord.push_back((*tit).second);
	}

	for(std::deque<unsigned int> ::const_iterator pit = pend.begin();
		pit != pend.end(); ++pit)
		ord.insert((std::upper_bound(ord.begin(), ord.end(), (*pit)))--, (*pit));
	if(this->_isOdd)
		ord.insert((std::upper_bound(ord.begin(), ord.end(), this->_straggler))--, this->_straggler);

	this->_deque = ord;

	/* gettimeofday(&end, 0); */
    /* long seconds = end.tv_sec - begin.tv_sec; */
    /* long microseconds = end.tv_usec - begin.tv_usec; */
    /* double elapsed = seconds + microseconds*1e-6; */
    /* double elapsed = seconds*1e6 + microseconds; */

	clock_t end = clock();
	double elapsed = (double(end - start)/CLOCKS_PER_SEC);
	/* the unit of time is wrongly expressed in the example. */
	std::cout << "Time to process a range of " << this->_deque.size() << " elements with std::deque  : ";
	std::cout << std::fixed << elapsed << " s" << std::endl;

	/* sorted deque unnecesarry printing */
	/* for(std::deque<unsigned int> ::const_iterator oit = this->_deque.begin(); */
	/* oit != this->_deque.end(); ++oit) */
	/* 	std::cout << (*oit) << " "; */
	/* std::cout << std::endl; */
}

void PmergeMe::mergeInsertSort(void){
	MisVector();
	MisDeque();
}

void PmergeMe::printContainers(void){
	std::cout << "Before:	";
	for(std::vector<unsigned int>::const_iterator vit = this->_vector.begin();
	vit != this->_vector.end(); ++vit)
		std::cout << (*vit) << " ";
	if(this->_isOdd)
		std::cout << this->_straggler << " ";
	std::cout << std::endl;

	/* unsorted deque solve unnecesarry printing */
	/* std::cout << typeid(this->_deque).name() << std::endl; */
	/* for(std::deque<unsigned int>::const_iterator dit = this->_deque.begin(); */
	/* dit != this->_deque.end(); ++dit) */
	/* 	std::cout << (*dit) << " "; */
	/* std::cout << std::endl; */
	/* std::cout << this->_isOdd << std::endl; */
	/* std::cout << "straggler => " << this->_straggler; */ 
	/* std::cout << std::endl; */
}



/* TODO: upper_bound to insert using binary search */
