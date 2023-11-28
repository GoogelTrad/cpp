/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:53 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/28 13:53:53 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl Harl;

	Harl.complain("DEBUG");
	std::cout << std::endl << std::endl;
	Harl.complain("INFO");
	std::cout << std::endl << std::endl;
	Harl.complain("WARNING");
	std::cout << std::endl << std::endl;
	Harl.complain("ERROR");
	std::cout << std::endl << std::endl;
	Harl.complain("coucou");
}