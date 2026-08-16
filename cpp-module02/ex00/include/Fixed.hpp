/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:58:09 by issa              #+#    #+#             */
/*   Updated: 2026/08/13 02:38:31 by issa             ###   ########.fr       */
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
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &obj);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed &operator=(const Fixed &obj);
	~Fixed();
};

#endif