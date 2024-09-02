/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 01:16:06 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/11 01:16:06 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{


	if (ac != 2)
	{
		std::cout << "One argument is required!" << std::endl;
		return 0;
	}

	ScalarConverter::convert(av[1]);

	return 0;
}