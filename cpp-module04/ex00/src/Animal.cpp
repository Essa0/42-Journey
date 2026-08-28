/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/25 21:53:39 by issa              #+#    #+#             */
/*   Updated: 2026/08/26 04:06:03 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const std::string &value) : type(value)
{
    std::cout << "Animal String Constructor called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Copy Constructor called" << std::endl;
    *this = obj;
}

Animal &Animal::operator=(const Animal &obj)
{
    if (this != &obj)
        *this = obj;
    return *this;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::makeSound() const
{
    std::cout << "this Animal doesn't make any sound" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}