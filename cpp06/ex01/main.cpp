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
	Data data;
	Data data2;
	uintptr_t ptr;

	data.nb = 2;
	data.string = "coucou";

	std::cout << "nb = " << data.nb << " string = " << data.string << std::endl;
	ptr = Serializer::serialize(&data);
	std::cout << "ptr = " << ptr << std::endl;
	data2 = *Serializer::deserialize(ptr);
	std::cout << "nb = " << data2.nb << " string = " << data2.string << std::endl;
}