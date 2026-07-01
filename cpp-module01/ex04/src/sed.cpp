#include "sed.hpp"

void ft_replace(const std::string &container, 
				const std::string &s1, 
				const std::string &s2, 
				std::ofstream &newfile)
{
	size_t pos = 0;
	std::string::size_type res = 0;
	while ((res = container.find(s1, pos)) != std::string::npos)
	{
		newfile << container.substr(pos, res - pos);
		newfile << s2;
		pos = res + s1.length();
	}
	newfile << container.substr(pos);
}