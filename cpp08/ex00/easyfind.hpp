/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 19:32:29 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/06 13:28:17 by cmichez          ###   ########.fr       */
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
	int i;

	while(start != container.end())
	{
		if (*start == integer)
			return i;
		i++;
		start++;
	}
	throw std::exception();
}