/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 20:08:13 by issa              #+#    #+#             */
/*   Updated: 2026/08/17 01:45:12 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixedPoint = 0;
}

Fixed::Fixed(const int val)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPoint = val * (1 << this->fractionalBits);
}

Fixed::Fixed(const float val)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPoint = roundf(val * (1 << this->fractionalBits));
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj) // to avoid self assignment
		fixedPoint = obj.fixedPoint;
	return *this;
}

// arithmetic op
Fixed Fixed::operator+(const Fixed &obj)
{
	Fixed res;
	res.fixedPoint = this->fixedPoint + obj.fixedPoint;
	return res;
}

Fixed Fixed::operator-(const Fixed &obj)
{
	Fixed res;
	res.fixedPoint = this->fixedPoint - obj.fixedPoint;
	return res;
}

Fixed Fixed::operator*(const Fixed &obj)
{
	Fixed res;
	res.fixedPoint = (this->fixedPoint * obj.fixedPoint) / (1 << this->fractionalBits);
	return res;
}

Fixed Fixed::operator/(const Fixed &obj)
{
	Fixed res;
	res.fixedPoint = (this->fixedPoint * (1 << this->fractionalBits)) / obj.fixedPoint;
	return res;
}

// comparaison operator
bool Fixed::operator>(const Fixed &obj) const
{
	if (this->fixedPoint > obj.fixedPoint)
		return true;
	return false;
}

bool Fixed::operator<(const Fixed &obj) const
{
	return (this->fixedPoint < obj.fixedPoint);
}

bool Fixed::operator>=(const Fixed &obj) const
{
	return (this->fixedPoint >= obj.fixedPoint);
}

bool Fixed::operator<=(const Fixed &obj) const
{
	return (this->fixedPoint <= obj.fixedPoint);
}

bool Fixed::operator==(const Fixed &obj) const
{
	return (this->fixedPoint == obj.fixedPoint);
}

bool Fixed::operator!=(const Fixed &obj) const
{
	return (this->fixedPoint != obj.fixedPoint);
}

// increment & decrement
Fixed &Fixed::operator++()//pre
{
	this->fixedPoint += 1;
	return *this;
}

Fixed Fixed::operator++(int)//post
{
	Fixed temp(*this);
	this->fixedPoint += 1;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->fixedPoint -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fixedPoint -= 1;
	return temp;
}

// min & max
Fixed &Fixed::min(Fixed &pointOne, Fixed &pointTwo)
{
	if (pointOne.fixedPoint < pointTwo.fixedPoint)
		return pointOne;
	return pointTwo;
}

const Fixed &Fixed::min(const Fixed &pointOne, const Fixed &pointTwo)
{
	if (pointOne.fixedPoint < pointTwo.fixedPoint)
		return pointOne;
	return pointTwo;
}

Fixed &Fixed::max(Fixed &pointOne, Fixed &pointTwo)
{
	if (pointOne.fixedPoint > pointTwo.fixedPoint)
		return pointOne;
	return pointTwo;
}

const Fixed &Fixed::max(const Fixed &pointOne, const Fixed &pointTwo)
{
	if (pointOne.fixedPoint > pointTwo.fixedPoint)
		return pointOne;
	return pointTwo;
}

int Fixed::getRawBits(void) const
{
	return this->fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

int Fixed::toInt(void) const
{
	return this->fixedPoint / (1 << this->fractionalBits);
}

float Fixed::toFloat(void) const
{
	return this->fixedPoint / (float)(1 << this->fractionalBits);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
	out << obj.toFloat();
	return (out);
}