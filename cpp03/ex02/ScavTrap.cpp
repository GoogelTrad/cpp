/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:32:43 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/18 17:32:43 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default ScavTrap constructor called\n";
	this->name = "BoB";
	this->dmg = 20;
	this->hp = 100;
	this->mana = 50;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Name ScavTrap constructor called\n";
	this->name = name;
	this->dmg = 20;
	this->hp = 100;
	this->mana = 50;
}
	
void ScavTrap::attack(const std::string &target)
{
	if (this->getMana() != 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target;
		std::cout << " causing " << this->getDmg() << " points of damage !\n";
		this->mana--;
	}
	else
		std::cout << "Scavtrap " << this->getName() << "has not enough energy !\n";	
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " enter Gate Keeper Mode !\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called\n";
}