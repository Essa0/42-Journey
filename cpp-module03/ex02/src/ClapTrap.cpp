/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 23:23:03 by issa              #+#    #+#             */
/*   Updated: 2026/10/13 10:45:15 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("player"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << Name << " successfully created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : Name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap " << Name << " successfully created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : Name(obj.Name),
										  hitPoints(obj.hitPoints), energyPoints(obj.energyPoints),
										  attackDamage(obj.attackDamage)

{
	std::cout << "ClapTrap " << Name << " successfully created" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &obj)
	{
		Name = obj.Name;
		attackDamage = obj.attackDamage;
		hitPoints = obj.hitPoints;
		energyPoints = obj.energyPoints;
	}
	return *this;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints > 0 && this->energyPoints > 0)
	{
		this->energyPoints -= 1;
		std::cout << "ClapTrap " << this->Name << " attacks " << target << " and causing "
				  << this->attackDamage << " points of damage" << std::endl;
	}
	std::cout << "ClapTrap " << Name << " can't attack right now" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints > 0)
	{
		if (amount >= hitPoints)
			hitPoints = 0;
		else
			hitPoints -= amount;
		std::cout << "ClapTrap " << Name << " takes " << amount
				  << " of damage and hp is now " << hitPoints << std::endl;
		return;
	}
	else
	{
		std::cout << "ClapTrap " << Name << " is already died" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
	{
		std::cout << "ClapTrap " << Name << " can't repaired right now because they doesn't have points" << std::endl;
		return;
	}
	this->energyPoints -= 1;
	this->hitPoints = hitPoints + amount;
	std::cout << "ClapTrap " << Name << " repair for " << amount << " hitPoints" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << Name << " successfully destroyed" << std::endl;
}