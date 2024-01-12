/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:20:35 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/21 02:20:35 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &copy)
{
	for(int i = 0; i < COUNT; i++)
		this->ideas[i] = copy.ideas[i];

	return *this;
}