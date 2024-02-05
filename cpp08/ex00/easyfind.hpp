/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:32:29 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/05 22:24:03 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>

template <typename T>
typename T::iterator easyfind(T& container, int integer)
{
	typename T::iterator start = container.begin();
	int i;

	while(start != container.end())
	{
		if (*start == integer)
			return start;
		i++;
		start++;
	}
	throw std::exception();
}