/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 02:06:00 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/24 02:06:00 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange btc; 
	if (ac != 2)
	{
		std::cout << "Use ./btc <file>" << std::endl;
		return 0;
	}

	btc.finalPrinting(av[1]);

	return 0;
}