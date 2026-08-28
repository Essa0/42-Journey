/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 07:43:03 by issa              #+#    #+#             */
/*   Updated: 2026/08/26 13:59:07 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "string"

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &obj);
	Brain &operator=(const Brain &obj);
	~Brain();
};

#endif