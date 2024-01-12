/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmichez <cmichez@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:30:59 by cmichez           #+#    #+#             */
/*   Updated: 2023/12/19 15:30:59 by cmichez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	Animal *home[12];

	for (int i = 0; i < 6; i++)
		home[i] = new Dog();
	for (int i = 6; i < 12; i++)
		home[i] = new Cat();
	std::cout << std::endl << std::endl;

	for (int i = 0; i < 12; i++)
		home[i]->makeSound();

	std::cout << std::endl << std::endl;
	for(int i = 0; i < 12; i++)
		delete home[i];
}