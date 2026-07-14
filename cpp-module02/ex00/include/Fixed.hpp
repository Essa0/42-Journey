/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:51:52 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:51:53 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
    int fixedPoint;
    static const int fractionalNumber = 8;
public:
    Fixed();
    Fixed(const Fixed &obj);
    Fixed &operator = (const Fixed &obj);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif