/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:59:47 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 16:59:47 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string name);
		void setType(std::string type);
		std::string getType(void);
		~Weapon();
};
