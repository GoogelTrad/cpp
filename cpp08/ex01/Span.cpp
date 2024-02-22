/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:00:00 by cmichez           #+#    #+#             */
/*   Updated: 2024/02/06 16:01:08 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int _N) : N(_N)
{
	this->values = new int[N];
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span::~Span()
{
}