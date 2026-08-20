/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 20:17:25 by issa              #+#    #+#             */
/*   Updated: 2026/08/20 13:14:52 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
int main(void)
{
	FragTrap ft("issa");
	ft.attack("anime");
	ft.takeDamage(50);
	ft.beRepaired(3);
	ft.highFivesGuys();
	return 0;
}