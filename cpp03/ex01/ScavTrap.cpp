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
	std::cout << "Default ScavTrap constructor called" << std::endl;;
	this->name = "BoB";
	this->dmg = 20;
	this->hp = 100;
	this->mana = 50;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Name ScavTrap constructor called" << std::endl;;
	this->name = name;
	this->dmg = 20;
	this->hp = 100;
	this->mana = 50;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "Copy ScavTrap constructor called !" << std::endl;;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
	this->dmg = copy.dmg;
	this->hp = copy.hp;
	this->name = copy.name;
	this->mana = copy.mana;

	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->getMana() != 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target;
		std::cout << " causing " << this->getDmg() << " points of damage !" << std::endl;;
		this->mana--;
	}
	else
		std::cout << "Scavtrap " << this->getName() << "has not enough energy !" << std::endl;;	
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->getName() << " enter Gate Keeper Mode !" << std::endl;;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor ScavTrap called" << std::endl;;
}
