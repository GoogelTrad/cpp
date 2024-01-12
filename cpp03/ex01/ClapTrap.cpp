/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:47:29 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/07 01:53:47 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default ClapTrap constructor called !" << std::endl;;
	name = "Tartenpion";
	hp = 10;
	mana = 10;
	dmg = 0;
}

ClapTrap::ClapTrap(std::string target)
{
	std::cout << "Named ClapTrap constructor called !" << std::endl;;
	name = target;
	hp = 10;
	mana = 10;
	dmg = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy ClapTrap constructor called !" << std::endl;;
	this->hp = copy.hp;
	this->mana = copy.mana;
	this->dmg = copy.dmg;
	this->name = copy.name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called !" << std::endl;;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	this->hp = copy.hp;
	this->mana = copy.mana;
	this->dmg = copy.dmg;
	this->name = copy.name;

	return *this;
}


void ClapTrap::attack(const std::string& target)
{
	if (this->getMana() != 0)
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target;
		std::cout << " causing " << this->getDmg() << " points of damage !" << std::endl;;
		this->mana--;
	}
	else
		std::cout << "ClapTrap " << this->getName() << "has not enough energy !" << std::endl;;	
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHp() >= 0)
	{
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " damage(s) !" << std::endl;;
		if (this->getHp() - (int)amount >= 0)
			this->setHp(this->getHp() - amount);
		else
			this->setHp(0);
		std::cout << "ClapTrap " << this->getName() << " has " << this->getHp() << " left !" << std::endl;;
	}
	else
		std::cout << "ClapTrap " << this->getName() << " has no HP left !" << std::endl;;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	while (this->getMana() > 0 && amount)
	{
		std::cout << "ClapTrap " << this->getName() << " is repaired !" << std::endl;;
		this->setHp(this->getHp() + 1);
		this->setMana(this->getMana() - 1);
		amount--;
	}
	if (this->getMana() == 0)
		std::cout << "ClapTrap " << this->getName() << " has not enough energy !" << std::endl;;

	std::cout << "ClapTrap " << this->getName() << " has " << this->getHp() << " hp !" << std::endl;;
	std::cout << "ClapTrap " << this->getName() << " has " << this->getMana() << " energy !" << std::endl;;
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