/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 19:09:14 by issa              #+#    #+#             */
/*   Updated: 2026/08/20 13:29:12 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    /* data */
public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &obj);
    FragTrap &operator=(const FragTrap &obj);
    void attack(const std::string &target);
    void highFivesGuys(void);
    ~FragTrap();
};
