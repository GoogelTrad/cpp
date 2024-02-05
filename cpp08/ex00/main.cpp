/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:12:01 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/05 22:26:04 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void)
{
	std::vector<int> tab;
	tab.assign({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

	try
	{
		std::cout << "2 se trouve a la position : " << easyfind(tab, 2) << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}