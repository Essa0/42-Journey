/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/01 13:36:32 by iabiesat          #+#    #+#             */
/*   Updated: 2026/07/01 13:56:09 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->idx = 0;
	this->count = 0;
}

PhoneBook::~PhoneBook(void)
{
}
int isValid(std::string str)
{
	if (str.empty())
		return 0;
	if (str.length() != 1 || str[0] < '0' || str[0] > '7')
		return 0;
	return 1;
}

int validate_field(std::string str)
{
	if (str.empty())
		return 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return 1;
	}
	return 0;
}

int PhoneBook::add(void)
{
	std::string firstname;
	std::string lastname;
	std::string phonenumber;
	std::string nickname;
	std::string darkestsecret;

	std::cout << "Enter contact info in this order\n1-first name\n2-last name\n3-nick name\n4-phone number\n5-darkest secret\n";

	getline(std::cin, firstname);
	getline(std::cin, lastname);
	getline(std::cin, nickname);
	getline(std::cin, phonenumber);
	getline(std::cin, darkestsecret);

	if (!validate_field(firstname) || !validate_field(lastname) ||
		!validate_field(nickname) || !validate_field(phonenumber) ||
		!validate_field(darkestsecret))
	{
		std::cout << "invalid information" << std::endl;
		return 0;
	}
	this->contacts[this->idx].set_contact(firstname, lastname,
										  nickname, phonenumber,
										  darkestsecret);
	this->idx = (this->idx + 1) % 8;
	if (this->count < 8)
		this->count++;
	return 1;
}

void print_header()
{
	std::cout << std::setw(10) << "index" << "|"
			  << std::setw(10) << "first name" << "|"
			  << std::setw(10) << "last name" << "|"
			  << std::setw(10) << "nickname" << "|" << std::endl;
}

std::string check_formater(const std::string &str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::display(void) const
{
	int i = 0;
	print_header();
	while (i < this->count)
	{
		std::cout << std::setw(10) << i << "|"
				  << std::setw(10) << check_formater(this->contacts[i].get_fname()) << "|"
				  << std::setw(10) << check_formater(this->contacts[i].get_lname()) << "|"
				  << std::setw(10) << check_formater(this->contacts[i].get_nick_name()) << "|"
				  << std::endl;
		i++;
	}
}

void PhoneBook::search(void) const
{
	int idx;
	std::string str_idx;

	display();
	if (this->count <= 0)
	{
		std::cout << std::setfill('*') << std::setw(20) << "there's no contact yet" << std::setfill(' ') << std::endl;
		return;
	}
	std::cout << "enter index that u want to view" << std::endl;
	getline(std::cin, str_idx);
	if (!isValid(str_idx))
	{
		std::cout << "enter valid index next time :(" << std::endl;
		return;
	}
	idx = str_idx[0] - '0';
	if (idx >= this->count)
	{
		std::cout << "contact not found" << std::endl;
		return;
	}
	std::cout << "first name: " << this->contacts[idx].get_fname() << std::endl;
	std::cout << "last name: " << this->contacts[idx].get_lname() << std::endl;
	std::cout << "nick name: " << this->contacts[idx].get_nick_name() << std::endl;
	std::cout << "phone number: " << this->contacts[idx].get_phone_number() << std::endl;
	std::cout << "darkest secret: " << this->contacts[idx].get_darkest_secret() << std::endl;
}