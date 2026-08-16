/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:58:09 by issa              #+#    #+#             */
/*   Updated: 2026/08/17 01:44:36 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath>
class Fixed
{
private:
	int fixedPoint;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &obj);
	Fixed(const int val);
	Fixed(const float val);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void)	const;
	int toInt(void) const;
	Fixed &operator=(const Fixed &obj);
	// arithmetic operator
	Fixed operator+(const Fixed &obj);
	Fixed operator-(const Fixed &obj);
	Fixed operator*(const Fixed &obj);
	Fixed operator/(const Fixed &obj);
	// comparison operator
	bool operator>(const Fixed &obj) const;
	bool operator<(const Fixed &obj) const;
	bool operator>=(const Fixed &obj) const;
	bool operator<=(const Fixed &obj) const;
	bool operator==(const Fixed &obj) const;
	bool operator!=(const Fixed &obj) const;
	// increment & decrement
	Fixed &operator++(); //pre
	Fixed operator++(int); //post
	Fixed &operator--();
	Fixed operator--(int);
	// min & max
	static Fixed &min(Fixed &pointOne, Fixed &pointTwo);
	static const Fixed &min(const Fixed &pointOne, const Fixed &pointTwo);
	static Fixed &max(Fixed &pointOne, Fixed &pointTwo);
	static const Fixed &max(const Fixed &pointOne, const Fixed &pointTwo);
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);



#endif