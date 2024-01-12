/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:33:18 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/19 15:33:18 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Dog : public Animal
{
private:
	/* data */
public:
	Dog();
	Dog(const Dog &copy);

	Dog &operator=(const Dog &copy);
	void makeSound(void) const;

	virtual ~Dog();
};
