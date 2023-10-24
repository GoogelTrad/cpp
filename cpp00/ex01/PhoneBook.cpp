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
