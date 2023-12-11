/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:51 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 16:59:51 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name2, Weapon &arme2)
{
	name = name2;
	arme = &arme2;
}

HumanA::~HumanA()
{
}

void HumanA::setName(std::string name)
{
	this->name = name;
}

std::string HumanA::getName(void)
{
	return this->name;
}

void HumanA::attack(void)
{
	std::cout << this->getName() << " attacks with their " << this->arme->getType() << std::endl;
}