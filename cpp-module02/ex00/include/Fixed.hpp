/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:58:09 by issa              #+#    #+#             */
/*   Updated: 2026/07/23 04:07:48 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
class Fixed
{
private:
	int fixedPoint;
	static const int fractBits = 8;

public:
	Fixed();
	Fixed(const Fixed &obj);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	~Fixed();
};

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixedPoint = obj.fixedPoint;
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

#endif