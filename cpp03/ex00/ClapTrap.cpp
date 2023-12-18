/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:47:29 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/16 18:10:46 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called !\n";
	name = "Tartenpion";
	hp = 10;
	mana = 10;
	dmg = 0;
}

ClapTrap::ClapTrap(std::string target)
{
	std::cout << "Named constructor called !\n";
	name = target;
	hp = 10;
	mana = 10;
	dmg = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called !\n";
}

void ClapTrap::attack(const std::string& target)
{
	ClapTrap cible(target);
	
	if (this->mana != 0)
	{
		if (this->getDmg() <= 0)
			std::cout << "ClapTrap " << this->getName() << " has not enough damage !/n";
		else
		{
			std::cout << "ClapTrap " << this->getName() << " attacks " << cible.getName() << std::endl;
			cible.takeDamage(this->dmg);
		}
	}
	else
		std::cout << "Not enough energy left !\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHp() >= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " damage !\n";
		this->setHp(this->getHp() - amount);
		std::cout << "ClapTrap " << this->getName() << " has " << this->getHp() << " left !\n";
	}
	else
		std::cout << "ClapTrap " << this->getName() << " has no HP left !\n";
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	
}

void ClapTrap::setDmg(const int amount)
{
	this->dmg = amount;
}

void ClapTrap::setHp(const int amount)
{
	this->hp = amount;
}

void ClapTrap::setMana(const int amount)
{
	this->mana = amount;
}

int ClapTrap::getDmg(void)
{
	return this->dmg;
}

int ClapTrap::getHp(void)
{
	return this->hp;
}

int ClapTrap::getMana(void)
{
	return this->mana;
}

std::string ClapTrap::getName(void)
{
	return this->name;
}