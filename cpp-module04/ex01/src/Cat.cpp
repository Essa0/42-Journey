/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:53:36 by issa              #+#    #+#             */
/*   Updated: 2026/09/02 21:01:18 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat Default Constructor Called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj), brain(new Brain(*obj.brain))
{
	this->type = "Cat";
	std::cout << "Cat Copy Constructor Called" << std::endl;
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
	std::cout << "Cat Sound >_<" << std::endl;
}

std::string Cat::getType() const
{
	return this->type;
}

Cat::~Cat()
{
	delete (this->brain);
	std::cout << "Cat Destructor Called" << std::endl;
}