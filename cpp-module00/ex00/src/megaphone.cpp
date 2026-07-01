/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 12:40:37 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/01 12:40:38 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
	int i = 0;
	int j = 1;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	while (j < ac)
	{
		i = 0;
		while (av[j][i])
		{
			std::cout << (char)std::toupper(av[j][i]);
			i++;
		}
		if (j < ac - 1)
			std::cout<<" ";
		j++;
	}
	std::cout << std::endl;
	return 0;
}
