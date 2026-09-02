/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:53:34 by issa              #+#    #+#             */
/*   Updated: 2026/09/01 00:24:56 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj), brain(new Brain(*obj.brain))
{
	this->type = "Dog";
	std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
		Animal::operator=(obj);
		*this->brain = *obj.brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog Sound <_>" << std::endl;
}

std::string Dog::getType() const
{
	return this->type;
}

Dog::~Dog()
{
	delete(this->brain);
	std::cout << "Dog Destructor Called" << std::endl;
}