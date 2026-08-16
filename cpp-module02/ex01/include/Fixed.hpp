/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:58:09 by issa              #+#    #+#             */
/*   Updated: 2026/08/13 04:04:15 by issa             ###   ########.fr       */
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
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);



#endif