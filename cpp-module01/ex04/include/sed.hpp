#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <string>
#include <fstream>

void ft_replace(const std::string &container, 
				const std::string &s1, 
				const std::string &s2, 
				std::ofstream &newfile);

#endif