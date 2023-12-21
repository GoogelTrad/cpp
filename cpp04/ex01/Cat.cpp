/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:32:48 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/19 15:32:48 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	cerveau = new Brain();
	std::cout << "Default Cat constructor called\n";
	this->setType("Cat");
}

Cat::~Cat()
{
	delete cerveau;
	std::cout << "Cat destructor called\n";
}

void Cat::makeSound(void) const
{
	std::cout << "Cat sounds\n";
}
