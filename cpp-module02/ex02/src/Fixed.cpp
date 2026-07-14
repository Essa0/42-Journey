/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:52:14 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:52:15 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	fixedPoint = 0;
	std::cout<<"Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &obj)
{
	std::cout<<"Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(const int number)
{
	std::cout<<"Int constructor called" << std::endl;
	fixedPoint = number << fractionalNumber;
}

Fixed::Fixed(const float fract)
{
	std::cout<<"Float constructor called" << std::endl;
	fixedPoint = roundf(fract * (1 << fractionalNumber));
}

int Fixed::getRawBits() const
{
	return this->fixedPoint;
}

void Fixed::setRawBits(const int raw)
{
	this->fixedPoint = raw;
}

int Fixed::toInt(void) const
{
	return (fixedPoint >> fractionalNumber);
}

float Fixed::toFloat(void) const
{
	return ((float)fixedPoint / (1 << fractionalNumber));
}

Fixed &Fixed::operator=(const Fixed &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
		this->fixedPoint = obj.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Fixed &obj)
{
	o << obj.toFloat();
	return(o);
}

// comparison operator
bool Fixed::operator>(Fixed const &obj)
{
	return this->fixedPoint > obj.fixedPoint;
}

bool Fixed::operator<(Fixed const &obj)
{
	return this->fixedPoint < obj.fixedPoint;
}

bool Fixed::operator<=(Fixed const &obj)
{
	return this->fixedPoint <= obj.fixedPoint;
}

bool Fixed::operator>=(Fixed const &obj)
{
	return this->fixedPoint >= obj.fixedPoint;
}

bool Fixed::operator==(Fixed const &obj)
{
	return this->fixedPoint == obj.fixedPoint;
}

bool Fixed::operator!=(Fixed const &obj)
{
	return this->fixedPoint != obj.fixedPoint;
}

// // arithmetic operator
Fixed Fixed::operator+(Fixed const &obj)const{
	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator-(Fixed const &obj)const{
	return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator*(Fixed const &obj)const{
	return (this->toFloat() * obj.toFloat());
}

Fixed Fixed::operator/(Fixed const &obj)const{
	return (this->toFloat() / obj.toFloat());
}

// // inc / dec
Fixed &Fixed::operator++()
{
	this->fixedPoint++;
	return (*this);
}

Fixed &Fixed::operator--()
{
	this->fixedPoint--;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed val(*this);
	this->fixedPoint++;
	return (val);
}

Fixed Fixed::operator--(int)
{
	Fixed val(*this);
	this->fixedPoint--;
	return (val);
}

Fixed &Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1.fixedPoint < num2.fixedPoint)
		return (num1);
	return (num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1.fixedPoint > num2.fixedPoint)
		return (num1);
	return (num2);
}

Fixed const &Fixed::min(Fixed const &num1, Fixed const &num2)
{
	if (num1.fixedPoint < num2.fixedPoint)
		return num1;
	return num2;
}

Fixed const &Fixed::max(Fixed const &num1, Fixed const &num2)
{
	if (num1.fixedPoint > num2.fixedPoint)
		return num1;
	return num2;
}

Fixed::~Fixed(void)
{
	std::cout<<"Destructor called" << std::endl;
}