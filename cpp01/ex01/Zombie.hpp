/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:07:19 by cmichez           #+#    #+#             */
/*   Updated: 2023/11/27 16:07:19 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>


class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		void setName(std::string name);
		std::string getName(void);
		void annonce(void);
		~Zombie();
		
};

Zombie *zombieHorde(int n, std::string name);