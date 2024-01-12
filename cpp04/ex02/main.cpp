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
	Animal *dog = new Dog();
	Animal *cat = new Cat();
	//Animal *animal = new Animal();

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
}