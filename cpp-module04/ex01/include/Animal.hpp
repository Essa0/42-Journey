/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 23:47:18 by issa              #+#    #+#             */
/*   Updated: 2026/09/02 21:01:04 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "string.h"

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const std::string &value);
	Animal(const Animal &obj);
	Animal &operator=(const Animal &obj);
	virtual void makeSound() const;
	std::string getType() const;

	virtual ~Animal();
};

#endif