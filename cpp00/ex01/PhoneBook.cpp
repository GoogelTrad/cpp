/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 23:41:36 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/23 23:41:36 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::add()
{
	Contact ct;
	std::string temp;

	std::cout << "First name : ";
	std::cin >> temp;
	ct.setFname(temp);

	std::cout << "Last name : ";
	std::cin >> temp;
	ct.setLname(temp);

	std::cout << "Nickname : ";
	std::cin >> temp;
	ct.setNickname(temp);

	std::cout << "Phone number : ";
	std::cin >> temp;
	ct.setPhone(temp);

	std::cout << "Darkest secret : ";
	std::cin >> temp;
	ct.setSecret(temp);

	if (rep->getIndex() >= 8)
	{
		int tmp = -rep->getIndex();
		rep->setIndex(tmp);
	}
	rep[rep->getIndex()] = ct;
	rep->setIndex(1);
}

Contact PhoneBook::getInfo(int index)
{
	std::string tmp;
	Contact ct;

	ct.setFname(PhoneBook::rep[index].getFname());
	ct.setLname(PhoneBook::rep[index].getLname());
	ct.setNickname(PhoneBook::rep[index].getNickname());
	ct.setPhone(PhoneBook::rep[index].getPhone());
	ct.setSecret(PhoneBook::rep[index].getSecret());

	return ct;
}

void PhoneBook::affiche(Contact *ct)
{
	int i = 0;
	int j;

	std::cout << "     index|      name|  lastname|  nickname|" << std::endl;
	for (int i = 0; i < 8; i++)
		std::cout << std::setw(10) << std::setfill(' ') << i << "|" << ct[i].affInfo() << std::endl;
}

void PhoneBook::search()
{
	Contact ct;
	std::string string;
	int index = 10;

	PhoneBook::affiche(PhoneBook::rep);

	std::cout << std::endl;
	std::cout << "Index : ";
	std::cin >> string;
	index = atoi(string.c_str());
	if ((index >= 0 || index < 8) && string.size() == 1 && isdigit(string[0]))
	{
		ct = PhoneBook::getInfo(index);

		std::cout << "First name : " << ct.getFname() << std::endl;
		std::cout << "Last name : " << ct.getLname() << std::endl;
		std::cout << "Nickname: " << ct.getNickname() << std::endl;
		std::cout << "Phone number : " << ct.getPhone() << std::endl;
		std::cout << "Darkest secret : " << ct.getSecret() << std::endl;
	}
	else
		std::cout << "Wrong index" << std::endl;
}