/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:39:19 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/20 23:39:19 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class WrongAnimal
{
	protected:
	std::string type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);

		WrongAnimal &operator=(const WrongAnimal &copy);
		void setType(std::string type);
		std::string getType(void) const;

		virtual void makeSound(void) const;
		
		virtual ~WrongAnimal();
};
