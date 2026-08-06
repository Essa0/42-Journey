/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 20:08:13 by issa              #+#    #+#             */
/*   Updated: 2026/06/28 20:09:36 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{

};

void Zombie::setName(const std::string& name)
{
    this->name = name;
}

void Zombie::announce(void) const
{
    std::cout<<this->name<<": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "destroy " << this->name << std::endl;
}