/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:59:43 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/06 15:58:15 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Span
{
private:
	unsigned int N;
	int *values;
public:
	Span(unsigned int _N);
	~Span();

	Span(const Span &copy);
};

