/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 17:08:19 by issa              #+#    #+#             */
/*   Updated: 2026/06/26 03:57:33 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
	Contact contacts[8];
	int idx;
	int count;

public:
	PhoneBook(void);
	~PhoneBook(void);
	int add(void);
	void search(void) const;
	void display(void) const;
};
#endif