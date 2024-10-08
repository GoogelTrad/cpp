/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:29:22 by cmichez           #+#    #+#             */
/*   Updated: 2024/01/12 03:29:22 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma	once
#include <iostream>
#include <string>

struct Data
{
	int nb;
	std::string string;
};

class Serializer
{
private:
	Serializer();
	Serializer(const Serializer &copy);
	
public:
	~Serializer();

	Serializer &operator=(const Serializer &copy);

	static uintptr_t	serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};


