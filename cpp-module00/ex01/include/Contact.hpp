/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:08:14 by issa              #+#    #+#             */
/*   Updated: 2026/06/24 19:16:37 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string f_name;
	std::string l_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

public:
	// setter
	void set_contact(const std::string &fname,
					 const std::string &lname,
					 const std::string &kname,
					 const std::string &phone,
					 const std::string &secret);
	// getter
	const std::string& get_fname(void) const;
	const std::string& get_lname(void) const;
	const std::string& get_nick_name(void) const;
	const std::string& get_phone_number(void) const;
	const std::string& get_darkest_secret(void) const;
};

#endif