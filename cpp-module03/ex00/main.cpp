/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 20:17:25 by issa              #+#    #+#             */
/*   Updated: 2026/08/20 06:39:01 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
int main()
{
	ClapTrap a("issa");

	a.attack("Target");
	a.takeDamage(5);
	a.beRepaired(7);
	a.takeDamage(10);
	ClapTrap d("RepairBot");
	d.takeDamage(5);
	d.beRepaired(3);

	d.takeDamage(100);
	d.attack("Target");
	d.beRepaired(10);

	return 0;
}