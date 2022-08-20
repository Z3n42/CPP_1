#include <iostream>
#include <string>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Address of str: "<< &str << std::endl;
	std::cout << "Address of str using PTR: " << stringPTR << std::endl;
	std::cout << "Address of str using REF: " << &stringREF << std::endl;

	std::cout << "Content of str: " << str << std::endl;
	std::cout << "Content of str using PTR: " << *stringPTR << std::endl;
	std::cout << "Content of str using REF: " << stringREF << std::endl;
}
