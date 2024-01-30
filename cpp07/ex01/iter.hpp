/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:57:23 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/25 22:57:23 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T *addr, int len, F fct)
{
	for (int i = 0; i < len; i++)
		fct(addr[i]);
}