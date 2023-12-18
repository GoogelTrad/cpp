/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:01 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/18 18:32:38 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "ClapTrap var\n";
	ClapTrap Coucou("Coucou");
	ClapTrap Oui;
	std::cout << std::endl;

	std::cout << "ScavTrap var\n";
	ScavTrap BoB("Albert");
	
	std::cout << std::endl;
	std::cout << "FragTrap var\n";
	FragTrap Yop("Adrien");
	std::cout << std::endl << std::endl;


	std::cout << "Function\n";
	Coucou.setDmg(5);
	Coucou.attack(Oui.getName());

	Oui.beRepaired(3);
	Oui.takeDamage(2);
	Oui.attack(Coucou.getName());	

	BoB.guardGate();
	Yop.highFivesGuys();
}