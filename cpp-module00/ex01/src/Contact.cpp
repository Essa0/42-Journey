/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:08:17 by issa              #+#    #+#             */
/*   Updated: 2026/07/01 13:37:46 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::set_contact(const std::string &fname,
						  const std::string &lname,
						  const std::string &kname,
						  const std::string &phone,
						  const std::string &secret)
{
	f_name = fname;
	l_name = lname;
	nick_name = kname;
	phone_number = phone;
	darkest_secret = secret;
}

const std::string& Contact::get_fname(void) const
{
	return (f_name);
}
const std::string& Contact::get_lname(void) const
{
	return (l_name);
}
const std::string& Contact::get_nick_name(void) const
{
	return (nick_name);
}
const std::string& Contact::get_phone_number(void) const
{
	return (phone_number);
}
const std::string& Contact::get_darkest_secret(void) const
{
	return (darkest_secret);
}