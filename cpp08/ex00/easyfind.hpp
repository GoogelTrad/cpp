/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:32:29 by cmichez           #+#    #+#             */
/*   Updated: 2024/08/30 16:14:40 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>

template <typename T>
int easyfind(T& container, int integer)
{
	typename T::iterator start = container.begin();
	int i = 0;

	while(start != container.end())
	{
		if (*start == integer)
			return i;
		i++;
		start++;
	}
	throw std::exception();
}