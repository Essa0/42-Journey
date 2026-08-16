/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 20:08:13 by issa              #+#    #+#             */
/*   Updated: 2026/08/10 21:59:09 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}


Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
    fixedPoint = obj.fixedPoint;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    if (this != &obj) // to avoid self assignment
        fixedPoint = obj.fixedPoint;
    return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}