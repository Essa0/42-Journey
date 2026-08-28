/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 23:49:06 by issa              #+#    #+#             */
/*   Updated: 2026/08/25 22:13:32 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
	
public:
	Cat();
	Cat(const Cat &obj);
	Cat &operator=(const Cat &obj);
	void makeSound() const;
	std::string getType() const;
	~Cat();
};

#endif
