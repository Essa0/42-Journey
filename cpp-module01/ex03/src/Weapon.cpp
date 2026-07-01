/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 20:10:18 by issa              #+#    #+#             */
/*   Updated: 2026/06/29 20:18:10 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Weapon.hpp"

Weapon::Weapon(const std::string name)
{
	this->type = name;
}

const std::string &Weapon::getType(void) const
{
	return this->type;
}

void Weapon::setType(const std::string &type)
{
	this->type = type;
}

Weapon::~Weapon()
{
}

