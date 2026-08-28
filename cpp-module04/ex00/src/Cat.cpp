/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:53:36 by issa              #+#    #+#             */
/*   Updated: 2026/08/26 16:12:58 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
	*this = obj;
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat Sound" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor Called" << std::endl;
}

std::string Cat::getType() const
{
	return type;
}