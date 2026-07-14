/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:51:35 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:51:36 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
private:
	/* data */
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	void complain(std::string level);
};


#endif