/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 23:50:48 by issa              #+#    #+#             */
/*   Updated: 2026/08/31 23:23:34 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
public:
    Dog(/* args */);
    Dog(const Dog &obj);
	Dog &operator=(const Dog &obj);
	void makeSound() const;
    std::string getType() const;
    ~Dog();
};

#endif