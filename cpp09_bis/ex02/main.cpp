/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:43:10 by cmichez           #+#    #+#             */
/*   Updated: 2024/09/03 17:29:23 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		PmergeMe coucou;

		std::cout << "Before : ";
		for(int i = 1 ; i < ac; i++)
		{
			std::cout << av[i] << " ";
		}
		// if (av[5])
		// 	std::cout << "[...]\n";
		// else
		 	std::cout << "\n";

		
		coucou.sortVector(av);
		coucou.sortDeque(av);

	}
	return 0;
}