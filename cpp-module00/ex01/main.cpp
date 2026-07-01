#include <iostream>
#include "PhoneBook.hpp"

std::string ct_tolower(std::string str)
{
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] = str[i] + 32;
	}
	return str;
}

int main()
{
	PhoneBook test;
	std::string prompt;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT):" << std::endl;
		if (!std::getline(std::cin, prompt))
		{
			std::cout << "\nreach eof. exit :(\n";
			break;
		}
		if (ct_tolower(prompt) == "add")
			test.add();
		else if (ct_tolower(prompt) == "search")
			test.search();
		else if (ct_tolower(prompt) == "exit")
			break;
	}
	return 0;
}