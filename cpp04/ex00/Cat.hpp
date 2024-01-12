/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:33:03 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/19 15:33:03 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

class Cat : public Animal
{
private:
	/* data */
public:
	Cat();
	Cat(const Cat &copy);

	Cat &operator=(const Cat &copy);
	void makeSound(void) const;

	virtual ~Cat();
};

