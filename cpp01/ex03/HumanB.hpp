/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:46 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 16:59:46 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *arme;
		std::string name;
	public:
		HumanB(std::string name2);
		void setName(std::string name);
		void setWeapon(Weapon &type);
		std::string getName(void);
		void attack(void);
		~HumanB();
};

