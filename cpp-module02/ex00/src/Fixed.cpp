/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:51:57 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:51:58 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixedPoint = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout<<"getRawBits member function called" << std::endl;
	return this->fixedPoint;
}

void Fixed::setRawBits(const int raw)
{
	this->fixedPoint = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
