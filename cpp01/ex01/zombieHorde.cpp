/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:32:19 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 16:32:19 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name)
{
	Zombie *Foo = new Zombie[n];

	for (int i = 0; i < n; i++)
	{
		Foo[i].setName(name);
		Foo[i].annonce();
	}

	return Foo;
}