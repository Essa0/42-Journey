/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 18:58:09 by issa              #+#    #+#             */
/*   Updated: 2026/06/28 20:36:11 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>
class Zombie
{
private:
	std::string name;
public:
	Zombie(void);
	~Zombie();
	void setName(const std::string& name);
	void announce(void) const;
};

Zombie* newZombie(std:: string name);
void randomChump(std:: string name);

#endif