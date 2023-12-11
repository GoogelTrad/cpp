/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumainB.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:52 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 16:59:52 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name2)
{
	name = name2;
}

HumanB::~HumanB()
{
}

void HumanB::setName(std::string name)
{
	this->name = name;
}

std::string HumanB::getName(void)
{
	return this->name;
}

void HumanB::attack(void)
{
	std::cout << this->getName() << " attacks with their " << this->arme->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &type)
{
	this->arme = &type;
}