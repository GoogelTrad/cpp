/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:31:06 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/19 15:31:06 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Animal
{
	protected:
		std::string type;
	private:
	public:
		Animal();
		Animal(const Animal &copy);

		void setType(std::string type);
		std::string getType(void) const;

		Animal &operator=(const Animal &copy);
		virtual void makeSound(void) const = 0;

		virtual ~Animal();

};



