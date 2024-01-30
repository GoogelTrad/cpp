/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:42:24 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/26 16:42:24 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> tab = Array<int>(3);
	Array<int> vide = Array<int>();

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 56;
	
	Array<int> copy = Array<int>(tab);

	std::cout << "Size tab = " << tab.size() << std::endl;
	std::cout << "Size tab = " << vide.size() << std::endl;
	std::cout << "Size tab = " << copy.size() << std::endl;

	vide = tab;
	std::cout << "Size tab = " << vide.size() << std::endl;
	
	return 0;
}