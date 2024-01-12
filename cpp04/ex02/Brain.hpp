/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 02:20:52 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/21 02:20:52 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"

#define COUNT 100

class Brain
{
	private:
		std::string ideas[COUNT];
	public:
		Brain();
		Brain(const Brain &copy);
		~Brain();

		Brain &operator=(const Brain &copy);
};

