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

	int i = 0;
	while (!rep[i].getFname().empty())
		i++;
	rep[i] = ct;
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

void PhoneBook::limit(std::string str)
{
	int size;
	int space;
	int div;

	size = str.size();
	space = size / 2;
	if (size > 9)
	{
		for (int j = 0; j < 9; j++)
			std::cout << str[j];
		std::cout << ".";
	}
	else
	{
		if (space % 2 == 0)
			div = space / 2;
		else
			div = space / 2 + 1;
		for (int k = 0; k < div / 2; k++)
			std::cout << " ";
		std::cout << str;
		for (int k = 0; k < space / 2; k++)
			std::cout << " ";
	}
}

void PhoneBook::affiche(Contact *ct)
{
	int i = 0;
	int j;

	std::cout << "|   index   |    name   | lastaname | nickname |" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (!ct[i].getFname().empty())
		{
			std::cout << "| ";
			PhoneBook::limit(ct[i].getFname());
			std::cout << " | ";
			PhoneBook::limit(ct[i].getLname());
			std::cout << " | ";
			PhoneBook::limit(ct[i].getNickname());
			std::cout << " | ";
			PhoneBook::limit(ct[i].getPhone());
			std::cout << " | ";
			PhoneBook::limit(ct[i].getSecret());
			std::cout << " |";
		}
		else
		{
			std::cout << "| ";
			for (int j = 0; j < 4; j++)
			{
				PhoneBook::limit("       ");
				if (j != 3)
					std::cout << " |";
				else
					std::cout << " | ";
			}
		}
		std::cout << std::endl;
	}
}

void PhoneBook::search()
{
	Contact ct;
	int index;

	PhoneBook::affiche(PhoneBook::rep);

	std::cout << "\n";
	std::cout << "Index : ";
	std::cin >> index;
	if (index < 0 || index > 8)
	{
		std::cout << "index out of range\n";
		return ;
	}
	ct = PhoneBook::getInfo(index);

	std::cout << "First name : " << ct.getFname() << std::endl;
	std::cout << "Last name : " << ct.getLname() << std::endl;
	std::cout << "Nickname: " << ct.getNickname() << std::endl;
	std::cout << "Phone number : " << ct.getPhone() << std::endl;
	std::cout << "Darkest secret : " << ct.getSecret() << std::endl;
}