/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 18:19:14 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/18 18:19:14 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << "Default FragTrap constructor called\n";
	this->name = "Frag";
	this->hp = 100;
	this->mana = 100;
	this->dmg = 30;
}

FragTrap::FragTrap(const std::string name)
{
	std::cout << "Name FragTrap constructor called\n";
	this->name = name;
	this->hp = 100;
	this->mana = 100;
	this->dmg = 30;	
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor FragTrap called\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->getName() << " request high fives !\n";
}