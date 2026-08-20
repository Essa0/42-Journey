/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 14:24:15 by issa              #+#    #+#             */
/*   Updated: 2026/08/19 17:58:25 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#endif

#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
private:
	
public:
	ScavTrap();
	ScavTrap(const std::string &name);
	ScavTrap(const ScavTrap &obj);
	ScavTrap &operator=(const ScavTrap &obj);
	void attack(const std::string &target);
	void guardGate();
	~ScavTrap();
};
