/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 20:17:25 by issa              #+#    #+#             */
/*   Updated: 2026/08/20 12:56:40 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap scav("issa");
	scav.attack("ali");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	
	ScavTrap dead("test");
	dead.takeDamage(170);
	dead.attack("none");
	dead.beRepaired(15);
	dead.guardGate();
	return 0;
}
