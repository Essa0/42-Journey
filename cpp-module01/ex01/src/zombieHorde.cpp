/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:47:37 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:47:38 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return NULL;
	Zombie* zombie = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombie[i].setName(name);
	return zombie;
}