#include "sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "the input should be filename str1 str2" << std::endl;
		return 1;
	}
	if (std::string(av[2]).empty())
	{
		std::cerr << "the str1 shouldn't be empty" << std::endl;
		return 1;
	}
	std::string fn = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::string line;
	std::ifstream f(fn.c_str());
	std::ofstream newfile((fn + ".replace").c_str());
	if (!f.is_open() || !newfile.is_open())
	{
		std::cerr<<"there are error with open file try again" << std::endl;
		return 1;
	}
	while (getline(f, line))
	{
		ft_replace(line, s1, s2, newfile);
		if (!f.eof())
			newfile << '\n';
	}
	f.close();
	newfile.close();
	return 0;
}