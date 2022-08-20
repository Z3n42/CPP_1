#include "Karen.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 2){
		std::cout << "Wrong number of arguments\n"
			<< "Usage: ./karen-filter level" << std::endl;
		return (1);
	}
	Karen kraken;
	std::string level = argv[1];
	kraken.complain(level);
	return (0);
}
