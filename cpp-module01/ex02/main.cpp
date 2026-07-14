/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:50:37 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:50:38 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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