/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 23:53:02 by issa              #+#    #+#             */
/*   Updated: 2026/06/29 20:19:11 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
private:
	/* data */
	Weapon *weapon;
	std::string name;
public:
	HumanB(const std::string &name);
	void attack(void);
	void setWeapon(Weapon &weapon);
	~HumanB();
};

#endif