/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:53:36 by issa              #+#    #+#             */
/*   Updated: 2026/08/26 16:27:38 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Cat Default Constructor called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj), brain(new Brain(*obj.brain))
{
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{
		Animal::operator=(obj);
		*this->brain = *obj.brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat Sound" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat Destructor Called" << std::endl;
}

std::string Cat::getType() const
{
	return type;
}