#include <iostream>

int main()
{
	std::string name = "HI THIS IS BRAIN";
	std::string *stringPTR = &name;
	std::string &stringREF = name;

	// p0
	std::cout << &name << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &(stringREF) << std::endl;

	// p1
	std::cout << name << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;
}