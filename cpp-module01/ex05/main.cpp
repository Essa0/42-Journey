/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 16:33:06 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/14 16:33:07 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl h;
	(h.complain("DEBUG"));
	(h.complain("INFO"));
	(h.complain("WARNING"));
	(h.complain("ERROR"));
}