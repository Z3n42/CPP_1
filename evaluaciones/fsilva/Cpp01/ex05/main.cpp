#include "Karen.hpp"
#include <iostream>

int main()
{
	Karen kraken;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < NUM_LEVELS; i++)
		kraken.complain(levels[i]);
	return (0);
}
