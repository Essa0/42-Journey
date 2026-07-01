/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 20:08:38 by issa              #+#    #+#             */
/*   Updated: 2026/06/29 20:16:10 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) :  weapon(NULL), name(name) //init the weapon with null to avoid garbage val
{
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}

void HumanB::attack(void)
{
	if (weapon)
		std::cout<<this->name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon " << std::endl;
}

HumanB::~HumanB()
{
}