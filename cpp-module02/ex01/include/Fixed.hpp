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
    ~Fixed();
    int toInt(void) const;
    float toFloat(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, const Fixed &obj);

#endif


