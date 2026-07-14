/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:51:47 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:51:48 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl h;
	int level = -1;
	if (ac < 2)
	{
		std::cout << "please enter level next time" << std::endl;
		return 1;
	}
	if (std::string(av[1]) == "DEBUG")
		level = 0;
	else if (std::string(av[1]) == "INFO")
		level = 1;
	else if (std::string(av[1]) == "WARNING")
		level = 2;
	else if (std::string(av[1]) == "ERROR")
		level = 3;
	else
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	switch (level)
	{
	case 0:
		std::cout << "[DEBUG]" << std::endl;
		(h.complain("DEBUG"));
		// fallthrough
	case 1:
		std::cout << "[INFO]" << std::endl;
		(h.complain("INFO"));
		// fallthrough
	case 2:
		std::cout << "[WARNING]" << std::endl;
		(h.complain("WARNING"));
		// fallthrough
	case 3:
		std::cout << "[ERROR]" << std::endl;
		(h.complain("ERROR"));
		// fallthrough
	}
	return 0;
}