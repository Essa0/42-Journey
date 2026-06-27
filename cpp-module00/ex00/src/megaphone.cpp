
#include <iostream>
#include <string>

int main(int ac, char **av)
{
	int i = 0;
	int j = 1;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			if (av[j][i] >= 97 && av[j][i] <= 122)
				av[j][i] = av[j][i] - 32;
			std::cout << av[j][i];
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return 0;
}
