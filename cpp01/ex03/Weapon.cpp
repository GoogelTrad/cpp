/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:49 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 16:59:49 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon()
{
	type = "";
}


Weapon::Weapon(std::string name)
{
	type = name;
}

Weapon::~Weapon()
{
}

void Weapon::setType(std::string type)
{
	this->type = type;
}

std::string Weapon::getType(void)
{
	return this->type;
}