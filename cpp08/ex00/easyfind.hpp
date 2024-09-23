/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:32:29 by cmichez           #+#    #+#             */
/*   Updated: 2024/09/06 15:58:34 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <algorithm>

template <typename T>
int easyfind(T& container, int integer)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), integer);
	
	if (it != container.end())
	{
		int i = 0;
		typename T::iterator end = container.begin();

		while(end != it)
		{
			end++;
			i++;
		}
		return i;
	}
	throw std::exception();
}