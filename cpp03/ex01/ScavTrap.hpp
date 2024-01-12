/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:32:26 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/18 17:32:26 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &copy);
		ScavTrap(std::string name);

		ScavTrap &operator=(const ScavTrap &copy);
		void guardGate(void);
		void attack(const std::string& target);

		~ScavTrap();
};
