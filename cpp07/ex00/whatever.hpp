/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:43:28 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/25 22:43:28 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
T min(T a, T b)
{
	if (a < b)
		return a;
	else if (a > b)
		return b;
	else
		return b;
}

template <typename T>
T max(T a, T b)
{
	if (a < b)
		return b;
	else if (a > b)
		return a;
	else
		return b;
}