/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:53:34 by issa              #+#    #+#             */
/*   Updated: 2026/08/30 06:59:27 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	*this = obj;
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog Sound" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}

Dog::~Dog() 
{
	std::cout << "Dog Destructor Called" << std::endl;
}