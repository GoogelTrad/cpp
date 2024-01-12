/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:21:35 by cmichez           #+#    #+#             */
/*   Updated: 2023/10/24 03:21:35 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook Book;
	std::string tmp;
	
	while (1)
	{
		tmp = "";
		std::cout << "PhoneBook : ";
		std::cin >> tmp;

		if (tmp.compare("ADD") == 0)
			Book.add();
		else if (tmp.compare("SEARCH") == 0)
			Book.search();
		else if (tmp.compare("EXIT") == 0)
			break ;
		else
			tmp = "";
		std::cout << std::endl << std::endl;
	}
}