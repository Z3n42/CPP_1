#include "Karen.hpp"
#include <iostream>
#include <string>

Karen::Karen(void){
	std::cout << "A Karen was created\n";
}

Karen::~Karen(void){
	std::cout << "A Karen was destroyed\n";
}

void Karen::complain(std::string level) const 
{
	std::string my_levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	
	for (i = 0; i < NUM_LEVELS; i++){
		if (level == my_levels[i])
			break;
	}
	switch (i)
	{
		case 0:
			std::cout << "[ DEBUG ]" << std::endl 
				<< "I love to get extra bacon for my " 
				<< "7XL-double-cheese-triple-pickle-special-ketchup burger."
				<< " I just love it!\n";
		case 1:
			std::cout << "[ INFO ]" << std::endl 
				<< "I cannot believe adding bacon cost more money."
				<< "You don't put enough!\n";
		case 2:
			std::cout << "[ WARNING ]" << std::endl 
			<< "I think I deserve to have some extra bacon for free."
			<< " I've been coming here for years and you just started working"
			<< std::endl;
		case 3:
			std::cout << "[ ERROR ]" << std::endl
				<< "This is unacceptable, "
				<< "I want to speak to the manager now.\n";
			break;
		default:
			std::cout << "[Probably complaining about insignificant problems]"
				<< std::endl;
			break;
	}
}
