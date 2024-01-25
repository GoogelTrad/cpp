/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:29:38 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/12 03:29:38 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Serializer s;
	Data data;
	uintptr_t ptr;

	data.nb = 2;
	data.string = "coucou";

	std::cout << "nb = " << data.nb << " string = " << data.string << std::endl;
	ptr = s.serialize(&data);
	std::cout << "ptr = " << ptr << std::endl;
	data = *s.deserialize(ptr);
	std::cout << "nb = " << data.nb << " string = " << data.string << std::endl;
}