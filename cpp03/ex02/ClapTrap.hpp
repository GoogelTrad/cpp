/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:47:06 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/07 01:14:54 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string name;
	int hp;
	int mana;
	int dmg;
public:
	ClapTrap();
	ClapTrap(const ClapTrap &copy);
	ClapTrap(std::string target);
	
	ClapTrap &operator=(const ClapTrap &copy);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setHp(const int amount);
	void setMana(const int amount);
	void setDmg(const int amount);
	
	int getDmg(void);
	int getHp(void);
	int getMana(void);
	std::string getName(void);
	
	~ClapTrap();
};

