/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 20:17:25 by issa              #+#    #+#             */
/*   Updated: 2026/07/14 16:47:06 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie *tt = newZombie("HeapZombie");
    tt->announce();
    delete tt;
    randomChump("StackZombie");
    return 0;
}