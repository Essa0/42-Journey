/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:50:53 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:50:54 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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