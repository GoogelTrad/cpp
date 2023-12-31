/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:02:01 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/18 18:03:23 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap Coucou("Coucou");
	ClapTrap Oui;

	Coucou.setDmg(5);
	Coucou.attack(Oui.getName());

	Oui.beRepaired(3);
	Oui.takeDamage(2);
	Oui.attack(Coucou.getName());	
}