/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:52:17 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:52:18 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <string>

class Fixed
{
private:
    int fixedPoint;
    static const int fractionalNumber = 8;

public:
    Fixed();
    Fixed(const Fixed &obj);
    Fixed(const int number);
    Fixed(const float fract);
    Fixed &operator=(const Fixed &obj);

    // comparison operator
    bool operator>(Fixed const &obj);
    bool operator<(Fixed const &obj);
    bool operator>=(Fixed const &obj);
    bool operator<=(Fixed const &obj);
    bool operator==(Fixed const &obj);
    bool operator!=(Fixed const &obj);

    // arithmetic operator
    Fixed operator+(Fixed const &obj) const;
    Fixed operator-(Fixed const &obj) const;
    Fixed operator*(Fixed const &obj) const;
    Fixed operator/(Fixed const &obj) const;

    // inc / dec
    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);
    
    // max / min
    static Fixed &min(Fixed &num1, Fixed &num2);
    static Fixed &max(Fixed &num1, Fixed &num2);
    static Fixed const &min(Fixed const &num1, Fixed const &num2);
    static Fixed const &max(Fixed const &num1, Fixed const &num2);
    
    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
    ~Fixed();
};

std::ostream &operator<<(std::ostream &o, const Fixed &obj);

#endif