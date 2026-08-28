/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:53:34 by issa              #+#    #+#             */
/*   Updated: 2026/08/26 16:33:48 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain)
{
	std::cout << "Dog Default Constructor called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj), brain(new Brain(*obj.brain))
{
	std::cout << "Dog Copy Constructor called" << std::endl;
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
	std::cout << "Dog Sound" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog Destructor Called" << std::endl;
}