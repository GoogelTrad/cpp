/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:12:01 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/06 13:29:08 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> tab;
	tab.assign(values, values + 10);

	try
	{
		std::cout << "2 se trouve a la position : " << easyfind(tab, 2) << std::endl;
		std::cout << "8 se trouve a la position : " << easyfind(tab, 8) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Error Value not found!" << std::endl;
	}
	try
	{
		std::cout << "22 se trouve a la position : " << easyfind(tab, 22) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << "Error Value not found!" << std::endl;
	}	
}