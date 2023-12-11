/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:42 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 16:59:42 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon *arme;
		std::string name;
	public:
		HumanA(std::string name2, Weapon &arme2);
		void setName(std::string name);
		std::string getName(void);
		void attack(void);
		~HumanA();
};