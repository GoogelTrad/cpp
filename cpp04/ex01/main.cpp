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
	const Animal *meta = new Animal();
	const Animal *d = new Dog();
	const Animal *c = new Cat();

	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	d->makeSound();
	c->makeSound();
	meta->makeSound();

	delete d;
	delete c;
	delete meta;

	std::cout << std::endl << std::endl;

	const WrongAnimal *wmeta = new WrongAnimal();
	const WrongAnimal *wc = new WrongCat();

	std::cout << wc->getType() << " " << std::endl;
	wc->makeSound();
	wmeta->makeSound();

	delete wc;
	delete wmeta;

	std::cout << std::endl << std::endl;

}