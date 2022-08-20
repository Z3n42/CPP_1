#include "Karen.hpp"
#include <string>
#include <iostream>

Karen::Karen(void){
	std::cout << "A Karen was created\n";
}

Karen::~Karen(void){
	std::cout << "A Karen was destroyed\n";
}

void Karen::complain(std::string level)
{
	void	(Karen::*funcs_[4])(void);
	std::string	my_level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	funcs_[0] = &Karen::_debug;
	funcs_[1] = &Karen::_info;
	funcs_[2] = &Karen::_warning;
	funcs_[3] = &Karen::_error;
	int	i;

	for (i = 0; i < NUM_LEVELS; i++){
		if (level == my_level[i])
			break;
	}
	if (i != NUM_LEVELS)
		(this->*funcs_[i])();
}

void Karen::_debug(void){
	std::cout << "DEBUG: I love to get extra bacon for my " 
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< " I just love it!\n";
}

void Karen::_info(void){
	std::cout << "INFO: I cannot believe adding bacon cost more money."
	   << "You don't put enough!\n";
}

void Karen::_warning(void){
	std::cout << "WARNING: I think I deserve to have some extra bacon for free."
	   << " I've been coming here for years and you just started working\n"; 
}

void Karen::_error(void){
	std::cout << "ERROR: This is unacceptable, "
		<< "I want to speak to the manager now.\n";
}
